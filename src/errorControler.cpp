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

int ErrorControler::putError(int line, std::string const & error) const {
  std::cerr << "Line " << line << ": " << error << std::endl;
  return 1;
}

void ErrorControler::overflow(IOperand const *operan,  IOperand const *operan1, eOperandType newType, std::string opertionType) {

//std::cout << operan->getType() << '\n';
//std::cout << operan->getPrecision() << '\n';
long double max;
if (newType == eOperandType::enum_int8) { max = CHAR_MAX; }
if (newType == eOperandType::enum_int16) { max = SHRT_MAX; }
if (newType == eOperandType::enum_int32) { max = INT_MAX; }
if (newType == eOperandType::enum_float) { max = std::numeric_limits<float>::max(); }
if (newType == eOperandType::enum_double) { max = std::numeric_limits<double>::max(); }

if(opertionType == "add" && std::stod(operan->toString()) + std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a ADD");}
if(opertionType == "mul" && std::stod(operan->toString()) * std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a MUL" );}
if(opertionType == "sub" && std::stod(operan->toString()) - std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a SUB" );}
if(opertionType == "div" && std::stod(operan->toString()) / std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a DIV" );}

}

void ErrorControler::underflow(IOperand const *operan,  IOperand const *operan1, eOperandType newType, std::string opertionType) {
  
  //std::cout << operan->getType() << '\n';
  //std::cout << operan->getPrecision() << '\n';
  long double min;
  if (newType == eOperandType::enum_int8) { min = CHAR_MIN; }
  if (newType == eOperandType::enum_int16) { min = SHRT_MIN; }
  if (newType == eOperandType::enum_int32) { min = INT_MIN; }
  if (newType == eOperandType::enum_float) { min = std::numeric_limits<float>::lowest(); }
  if (newType == eOperandType::enum_double) { min = std::numeric_limits<double>::lowest(); }
  
  if(opertionType == "add" && std::stod(operan->toString()) + std::stod(operan1->toString()) > min) { throw std::logic_error( "You have an underflow on a ADD");}
  if(opertionType == "mul" && std::stod(operan->toString()) * std::stod(operan1->toString()) > min) { throw std::logic_error( "You have an underflow on a MUL" );}
  if(opertionType == "sub" && std::stod(operan->toString()) - std::stod(operan1->toString()) > min) { throw std::logic_error( "You have an underflow on a SUB" );}
  if(opertionType == "div" && std::stod(operan->toString()) / std::stod(operan1->toString()) > min) { throw std::logic_error( "You have an underflow on a DIV" );}
}