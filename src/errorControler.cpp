#include "errorControler.hpp"

ErrorControler::ErrorControler(void){
  return;
}

ErrorControler::ErrorControler(ErrorControler const &src) {
  (void)(src);
  return;
}

ErrorControler &ErrorControler::operator=(ErrorControler const & src) {
  (void)(src);
  return *this;
}


ErrorControler::~ErrorControler(void) {
  return;
}

int ErrorControler::needToStopFd(int type, bool isExit, std::string nextValue, bool fd, int line) {

  if (type == 1 && fd != 0) { return this->putError(line, SYNTAX_ERROR); }
  if (isExit && nextValue != "") { return this->putError(line,EXIT_ERROR); }
  if (type == 3) { return this->putError(line,FALSE_INST_ERROR); }
  return 0;
}

int ErrorControler::needToStopCin(int type, bool isExit, std::string nextValue, int line) {
  if (type == 1) { return this->putError(line,SYNTAX_ERROR); }
  if (isExit && nextValue != "") { return this->putError(line,EXIT_ERROR); }
  if (type == 3) { return this->putError(line,FALSE_INST_ERROR); }
  return 0;
}

void ErrorControler::endofFile(bool isExit) {
  if (isExit) { throw std::logic_error(EndOF); }
}

int ErrorControler::putError(int line, std::string const & error) const {
  std::cerr << "\033[1;31mLine\033[0m " <<"\033[1;32m" << line << "\033[0m" << "\033[1;31m : " << error <<"\033[0m" << std::endl;
  return 1;
}

void ErrorControler::overflow(IOperand const *operan,  IOperand const *operan1, long double max, std::string opertionType) {

  if (opertionType == "add" && std::stod(operan->toString()) + std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a ADD");}
  if (opertionType == "mul" && std::stod(operan->toString()) * std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a MUL" );}
  if (opertionType == "sub" && std::stod(operan->toString()) - std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a SUB" );}
  if (opertionType == "div" && std::stod(operan->toString()) / std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a DIV" );}
  if (opertionType == "pow" && pow(std::stod(operan1->toString()),std::stod(operan->toString())) > max) { throw std::logic_error( "You have an overflow on a POW" );}

}

void ErrorControler::underflow(IOperand const *operan,  IOperand const *operan1, long double min, std::string opertionType) {

  if (opertionType == "add" && std::stod(operan->toString()) + std::stod(operan1->toString()) < min) { throw std::logic_error( "You have an underflow on a ADD");}
  if (opertionType == "mul" && std::stod(operan->toString()) * std::stod(operan1->toString()) < min) { throw std::logic_error( "You have an underflow on a MUL" );}
  if (opertionType == "sub" && std::stod(operan->toString()) - std::stod(operan1->toString()) < min) { throw std::logic_error( "You have an underflow on a SUB" );}
  if (opertionType == "div" && std::stod(operan->toString()) / std::stod(operan1->toString()) < min) { throw std::logic_error( "You have an underflow on a DIV" );}
  if (opertionType == "pow" && pow(std::stod(operan1->toString()),std::stod(operan->toString())) < min) { throw std::logic_error( "You have an overflow on a POW" );}
}
