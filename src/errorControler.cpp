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

int ErrorControler::needToStop(int type, bool isExit, std::string nextValue, bool fd) {

  if (type == 1 && fd != 0) { std::cout << "Syntax error on this instrucion:" << '\n'; return 1; }
  if (isExit && nextValue != "") { std::cout << "Exit must be the last instrucion, this instrucion is after the exit:" << '\n'; return 1; }
  if (type == 3) { std::cout << "This instrucion is false:" << '\n'; return 1; }
  return 0;
}
void ErrorControler::endofFile(bool isExit) {
  if (isExit) { throw std::logic_error( "You must have an exit at the end of instrucions" ); }
}

void ErrorControler::overflow(IOperand const *operan,  IOperand const *operan1, eOperandType newType, std::string opertionType) {

//std::cout << operan->getType() << '\n';
//std::cout << operan->getPrecision() << '\n';
std::cout <<"Mdr" << '\n';
long double max;
if (newType == eOperandType::enum_int8) { max = 255; }
if (newType == eOperandType::enum_int16) { max = 32.767; }
if (newType == eOperandType::enum_int32) { max = 2.147.483.647; }

if(opertionType == "add" && std::stod(operan->toString()) + std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a ADD");}
if(opertionType == "mul" && std::stod(operan->toString()) * std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a MUL" );}
if(opertionType == "sub" && std::stod(operan->toString()) - std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a SUB" );}
if(opertionType == "div" && std::stod(operan->toString()) / std::stod(operan1->toString()) > max) { throw std::logic_error( "You have an overflow on a DIV" );}

}
//
// void ErrorControler::underflow(IOperand const &operan) {
//
// }
