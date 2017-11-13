#include "parseur.hpp"

Parseur::Parseur(void){
  //  std::cout << "on est all aussi enfain, surtout ! " << '\n';

  //this->instrucions =
  this->exit = false;
  //  this->start = NULL;
  //  this->end = this->vmList.end();
  //  this->instrucions->instrucion = NULL;
  return;
}

Parseur::Parseur(Parseur const &src) {
  return;
}

// Parseur &Parseur::operator=(Parseur const & src) {
//
//   this->ennemyDead = src.ennemyDead;
//   return *this;
// }


Parseur::~Parseur(void) {
  std::cout << "MDR on est alll" << '\n';
  //   struct EnnemyList *tmp;
  //   std::string *tmp2;
  //   while (this->ennemyList != NULL)
  //   {
  //       tmp = this->ennemyList;
  //       tmp2 = this->ennemyList->ennemy;
  //       this->ennemyList = this->ennemyList->next;
  //       delete tmp2;
  //       delete tmp;
  //   }
  //   delete this->ennemyList;
  // return;
}

//TODO
//chek exit is  the last one
//chek value of int
//CHek double and float no need decimal

int Parseur::checkeur(std::string instrucion) {
  std::regex elRegex("(push (?![ ]{1,})|pop|dump|assert (?![ ]{1,})|add|sud|mul|div|mod|print|exit)((?=\\n|$)|int8\\([0-9][^)|\\s]*\\)|int16\\([0-9][^)|\\s]*\\)|int32\\([0-9][^)|\\s]*\\)|float\\(\\d+(\\.[0-9]\\d*?\\))?|\\.[0-9]\\d+|double\\(\\d+(\\.[0-9]\\d*?\\))?|\\.[0-9]\\d+)");
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

int Parseur::lexeur(std:: string instrucion) {

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
      tmp.value = std::stod(instrucion);
      if (tmp.type == "int8" && (tmp.value <=  -128 || tmp.value >= 128 )) { return 3; }
      if (tmp.type == "int16" && (tmp.value <=  -32768 || tmp.value >= 32767 )) { return 3; }
      if (tmp.type == "int32" && (tmp.value <=  -2147483648 || tmp.value >= 2147483647 )) { return 3;}

    } else {
      tmp.type = "null";
      tmp.value = 0;
      tmp.info = instrucion;
    }

    this->vmList.push_back(tmp);
  return 0;
}

//int Parseur::executioner(std::string instrucion) {
//}

// void Parseur::push(std::string instrucion)
// {
//   this->vmList.push_back(instrucion)
// }
//
// vmList *Parseur::pop(std::string *ennemy)
// {
//     struct EnnemyList *tmp = NULL;
//     if (this->ennemyList->ennemy == ennemy)
//     {
//         delete this->ennemyList->ennemy;
//         tmp = this->ennemyList;
//         this->ennemyList = this->ennemyList->next;
//         delete tmp;
//         return this->ennemyList;
//     }
//     else
//     {
//         while (this->ennemyList->next && this->ennemyList->next->ennemy != ennemy)
//         {
//             this->ennemyList = this->ennemyList->next;
//         }
//         if (this->ennemyList->next)
//         {
//             tmp = this->ennemyList->next->next;
//             delete this->ennemyList->next->ennemy;
//             delete this->ennemyList->next;
//             this->ennemyList->next = tmp;
//             return tmp;
//         }
//     }
//     this->ennemyDead +=1;
//     return tmp;
// }
