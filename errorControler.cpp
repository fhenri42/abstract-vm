#include "errorControler.hpp"

ErrorControler::ErrorControler(void){
  return;
}

ErrorControler::ErrorControler(ErrorControler const &src) {
  return;
}

ErrorControler &ErrorControler::operator=(ErrorControler const & src) {
  return *this;
}


ErrorControler::~ErrorControler(void) {
  return;
}

int ErrorControler::needToStop(int type, bool isExit, std::string nextValue, int fd) {

  if (type == 1 && fd != 0) { std::cout << "Syntax error on this instrucion:" << '\n'; return 1; }
  if (isExit && nextValue != "") { std::cout << "Exit must be the last instrucion, this instrucion is after the exit:" << '\n'; return 1; }
  if (type == 3) { std::cout << "This instrucion is false:" << '\n'; return 1; }
  return 0;
}
int ErrorControler::endofFile(bool isExit) {
  if (isExit) { std::cout << "You must have an exit at the end of instrucions" << '\n'; return 1; }
  return 0;
}
