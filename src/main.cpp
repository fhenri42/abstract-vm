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
  std::string value;
  std::string nextValue = "";

  if(argc >= 2) {

    try {
    std::ifstream fd;

    fd.open(argv[1]);

    while(!fd.eof()) {

//TODO a verifier de ouf petit fix vite fais
      getline(fd,value);
      if (parse->exit) { nextValue = value; }
      if((erreur.needToStopFd(parse->checkeur(value), parse->exit, nextValue, !fd.eof()) == 1 ||  erreur.needToStopFd(parse->lexeur(value), parse->exit, nextValue, !fd.eof()) == 1) && !fd.eof() != 0) {
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
    try
    {
      for (std::string line; std::getline(std::cin, line);) {
        if(";;" == line) { break; }
        if(parse->exit) { nextValue = line; }

        if((erreur.needToStopCin(parse->checkeur(line), parse->exit, nextValue) == 1
          ||  erreur.needToStopCin(parse->lexeur(line), parse->exit, nextValue) == 1)) {

          std::cout << line << '\n';
          return 0;
        }
    }
      exec.startVm(parse);
    } catch (const std::exception & e) {
      std::cerr << e.what();
    }
  }
  return 0;
}
