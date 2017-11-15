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

int ErrorControler::needToStopFd(int type, bool isExit, std::string nextValue, bool fd) {

  if (type == 1 && fd != 0) { return this->putError(this->getIndexLine(), SYNTAX_ERROR); }
  if (isExit && nextValue != "") { return this->putError(this->getIndexLine(),EXIT_ERROR); }
  if (type == 3) { return this->putError(this->getIndexLine(),FALSE_INST_ERROR); }
  return 0;
}

int ErrorControler::needToStopCin(int type, bool isExit, std::string nextValue) {
  if (type == 1) { return this->putError(this->getIndexLine(),SYNTAX_ERROR); }
  if (isExit && nextValue != "") { return this->putError(this->getIndexLine(),EXIT_ERROR); }
  if (type == 3) { return this->putError(this->getIndexLine(),FALSE_INST_ERROR); }
  return 0;
}

void ErrorControler::endofFile(bool isExit) {
  if (isExit) { throw std::logic_error(EndOF); }
}

int const ErrorControler::putError(int line, std::string const & error) const {
  std::cerr << "Line " << line << ": " << error << std::endl;
  return 1;
}
