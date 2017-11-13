#include <iostream>
#include <fstream>
#include <string>

#include <list>

#include "parseur.cpp"

int main (int argc, char **argv) {

  Parseur *parse = new Parseur();
  int erreur = 0;
  if(argc >= 2) {


    std::string value;
    std::string nextValue = "";
    std::ifstream fd;
    fd.open (argv[1]);
    while(!fd.eof()) {
      getline(fd,value);

      if (parse->exit) { nextValue = value; }
      erreur = parse->checkeur(value);
    //  std::cout << parse->exit << '\n';
      if (parse->exit && nextValue != "") {
        std::cout << "Exit must be the last instrucion" << '\n';
        fd.close();
        return 0;
      }
    }
    if (!parse->exit) {
      std::cout << "You must have an exit at the end of instrucions" << '\n';
      fd.close();
      return 0;
    }
    fd.close();


    std::list<std::string>::const_iterator start;
    for(start = parse->vmList.begin(); start != parse->end; ++start)
    {
             std::cout << *start << std::endl;
           }
  } else {
    for (std::string line; std::getline(std::cin, line);) {
      std::cout << line << std::endl;
    }
  }

  return 0;
}



// int main()
// {
//     list<std::string> lst;
//     ifstream fd("test.txt", ios::in);
//
//     if (fd)
//     {
//         std::string data;
//         while(std::getline(fd, data))
//             lst.push_back(data);
//         fd.close();
//
//         std::list<std::string>::const_iterator start;
//         std::list<std::string>::const_iterator end = lst.end();
//
//         for(start = lst.begin(); start != end; ++start)
//             std::cout << *start << std::endl;
//     }
//     else
//         std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
//     return 0;
// }
