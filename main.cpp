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

    try {
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
    erreur.endofFile(!parse->exit);

      fd.close();
      exec.startVm(parse);
    } catch ( const std::exception & e ) {
      std::cerr << e.what();
  }
  } else {
    for (std::string line; std::getline(std::cin, line);) {
      std::cout << line << std::endl;
    }
  }
  return 0;
}
