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
  int stop = 0;
  std::string value;
  std::string nextValue = "";

  if (argc >= 2) {
    try {

    std::ifstream fd;
    fd.open(argv[1]);
    if(!fd.is_open()) { std::cout <<"\033[1;33mWow !!! we can't open this type of file !!\033[0m\n"; return 0; }
    while (!fd.eof()) {

      std::getline(fd,value);
      if (parse->exit) { nextValue = value; }
      if ((erreur.needToStopFd(parse->checkeur(value), parse->exit, nextValue, !fd.eof(), parse->getIndexLine()) == 1 ||  erreur.needToStopFd(parse->lexeur(value), parse->exit, nextValue, !fd.eof(), parse->getIndexLine()) == 1) && !fd.eof() != 0) {
        std::cout <<"\033[1;33m" << value << "\033[0m\n";
        stop = 1;
      }
    }
      if (stop == 1) {
        fd.close();
        return 0;
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
        if (";;" == line) {
          if (!parse->exit) { throw std::logic_error( "you miss exit"); }
          break;
        }
        if (parse->exit) { nextValue = line; }
        if ((erreur.needToStopCin(parse->checkeur(line), parse->exit, nextValue, parse->getIndexLine()) == 1 || erreur.needToStopCin(parse->lexeur(line), parse->exit, nextValue, parse->getIndexLine()) == 1)) {
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
