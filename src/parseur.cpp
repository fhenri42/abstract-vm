#include "parseur.hpp"

Parseur::Parseur(void){
  this->exit = false;
  return;
}

Parseur::Parseur(Parseur const &src) {
  (void)(src);

  return;
}

Parseur &Parseur::operator=(Parseur const & src) {
  (void)(src);
  
  return *this;
}


Parseur::~Parseur(void) {
   return;
}

//TODO
//Commentaire
//chek exit is  the last one
//chek value of int
//CHek double and float no need decimal

int Parseur::getIndexLine(void) const {
  return Parseur::_indexLine;
}

int Parseur::checkeur(std::string & instrucion) {

  Parseur::_indexLine += 1;
  std::regex elRegex("(push (?![ ]{1,})|pop|dump|assert (?![ ]{1,})|add|sud|mul|div|mod|print|exit)((?=\\n|$)|int8\\([0-9][^)|\\s]*\\)|int16\\([0-9][^)|\\s]*\\)|int32\\([0-9][^)|\\s]*\\)|float\\(\\d+(\\.[0-9]\\d*?\\))?|\\.[0-9]\\d+|double\\(\\d+(\\.[0-9]\\d*?\\))?|\\.[0-9]\\d+)");
  std::stringstream split;
  char char_split = ';';
  split << instrucion;

  std::getline(split, instrucion, char_split);
  if(instrucion.empty()) { return 0; }  
  if (regex_match(instrucion, elRegex) && instrucion != "exit") {
    return 0;
  } else if (instrucion == "exit") {
    this->exit = true;
    this->end = this->vmList.end();
    this->start = this->vmList.begin();
    return 0;
  }
  return 1;
}

int Parseur::lexeur(std::string & instrucion) {
  
  size_t pos = 0;
  std::string info;
  std::string type;
  VM_List tmp;
  std::string delimiter = " ";
  while ((pos = instrucion.find(delimiter)) != std::string::npos) {
      info = instrucion.substr(0, pos);
      instrucion.erase(0, pos + delimiter.length());
  }
    if (info != "" && instrucion != "") {
      pos = 0;
      delimiter= "(";
      while ((pos = instrucion.find(delimiter)) != std::string::npos) {
          type = instrucion.substr(0, pos);
          instrucion.erase(0, pos + delimiter.length());
          instrucion = instrucion.substr(0, instrucion.size()-1);
      }
      tmp.info = info;
      tmp.type = type;
      tmp.value = instrucion;
      long double value = std::stold(instrucion);
      if (tmp.type == "int8" && (value <=  CHAR_MIN || value >= CHAR_MAX )) { return 3; }
      if (tmp.type == "int16" && (value <=  SHRT_MIN || value >= SHRT_MAX)) { return 3; }
      if (tmp.type == "int32" && (value <=  INT_MIN || value >= INT_MAX )) { return 3;}
      if (tmp.type == "float" && (value <= std::numeric_limits<float>::lowest() || value >= std::numeric_limits<float>::max() )) { return 3; }
      if (tmp.type == "double" && (value <= std::numeric_limits<double>::lowest() || value >= std::numeric_limits<double>::max() )) { return 3; }
    } else {
      tmp.type = "null";
      tmp.value = "null";
      tmp.info = instrucion;
    }
    
    this->vmList.push_back(tmp);
  return 0;
}

int Parseur::_indexLine = 0;