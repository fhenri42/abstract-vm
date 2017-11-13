#include <iostream>
#include <fstream>
#include <string>

#include <list>

#include "parseur.cpp"
#include "errorControler.cpp"

int main (int argc, char **argv) {

  Parseur *parse = new Parseur();
  ErrorControler erreur;
  if(argc >= 2) {


    std::string value;

    std::string nextValue = "";
    std::ifstream fd;

    fd.open(argv[1]);

    while(!fd.eof()) {
      getline(fd,value);

      if (parse->exit) { nextValue = value; }

      //erreur  = parse->checkeur(value)
      //erreur = parse->lexeur(value);
      if((erreur.needToStop(parse->checkeur(value), parse->exit, nextValue, fd) == 1 ||  erreur.needToStop(parse->lexeur(value), parse->exit, nextValue, fd) == 1) && fd != 0) {
        std::cout << value << '\n';
        fd.close();
        return 0;
      }
      // if (parse->exit && nextValue != "") {
      //   std::cout << "Exit must be the last instrucion" << '\n';
      //   fd.close();
      //   return 0;
      // }
      //
      // if(erreur == 1) {
      //   std::cout << "ERROR" << '\n';
      //   fd.close();
      //   return 0;
      // }
      //
      // if(erreur == 3) {
      //   std::cout << "One of your int is to big" << '\n';
      //   fd.close();
      //   return 0;
      // }
    }
    if (erreur.endofFile(!parse->exit) == 1) {
      fd.close();
      std::exit(0);
    }
    // if (!parse->exit) {
    //   std::cout << "You must have an exit at the end of instrucions" << '\n';
    //   fd.close();
    //   return 0;
    // }


    fd.close();

    std::list<VM_List>::const_iterator start;
    for(start = parse->vmList.begin(); start != parse->end; ++start)
    {
      std::cout << "=======" << std::endl;
      std::cout << start->info << std::endl;
      std::cout << start->type << std::endl;
      std::cout << start->value << std::endl;
      std::cout << "=======" << std::endl;
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
