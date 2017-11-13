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
      if((erreur.needToStop(parse->checkeur(value), parse->exit, nextValue, fd) == 1 ||  erreur.needToStop(parse->lexeur(value), parse->exit, nextValue, fd) == 1) && fd != 0) {
        std::cout << value << '\n';
        fd.close();
        return 0;
      }

    }
    if (erreur.endofFile(!parse->exit) == 1) {
      fd.close();
      return 0;
    }
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
