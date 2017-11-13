#include <iostream>
#include <fstream>
#include <string>

#include <list>

#include "parseur.hpp"
#include "errorControler.hpp"
#include "executioner.hpp"

int main (int argc, char **argv) {

  Parseur *parse = new Parseur();
  ErrorControler erreur;
  Executioner exec;


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
    exec.start(parse);
  } else {
    for (std::string line; std::getline(std::cin, line);) {
      std::cout << line << std::endl;
    }
  }
  return 0;
}
