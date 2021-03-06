#include "executioner.hpp"
Executioner::Executioner(void){
  return;
}

Executioner::Executioner(Executioner const &src) {
  (void)(src);

  return;
}

Executioner &Executioner::operator=(Executioner const & src) {
  (void)(src);
  return *this;
}

Executioner::~Executioner(void) {
  return;
}
void Executioner::startVm(Parseur *parse) {
  std::list<VM_List>::const_iterator start;
  eOperandType enumId = eOperandType::enum_double;

  for (start = parse->vmList.begin(); start != parse->end; ++start)
  {
    if (start->type != "null") { enumId = this->getEnumId(start->type); }

    if (start->info == "add") {this->add();}
    if (start->info == "pop") { this->pop(); }
    if (start->info == "sub") { this->sub(); }
    if (start->info == "mul") { this->mul(); }
    if (start->info == "div") { this->div(); }
    if (start->info == "mod") { this->mod(); }
    if (start->info == "pow") {this->power();}
    if (start->info == "dump") { this->dump(); }
    if (start->info == "exit") { this->exitE(); }
    if (start->info == "print") { this->print(); }
    if (start->info == "push") { this->push(enumId,start->value); }
    if (start->info == "assert") { this->assertE(enumId, start->value); }
    if (start->info == "while") {this->whileE(this->getLast(),start->value); }

  }
}

eOperandType Executioner::getEnumId(std:: string type) {
  if (type == "int8") { return eOperandType::enum_int8; }
  if (type == "int16") { return eOperandType::enum_int16; }
  if (type == "int32") { return eOperandType::enum_int32; }
  if (type == "float") { return eOperandType::enum_float; }
  return eOperandType::enum_double;
}

/* OPERATION  */

void Executioner::add() {
  if (this->stack.size() < 2) { throw std::logic_error( "You need at least 2 elements on your stack to do this operation" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs + *rhs;
  this->stack.push_back(created);
}

void Executioner::sub(){
  if (this->stack.size() < 2) { throw std::logic_error( "You need at least 2 elements on your stack to do this operation" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs - *rhs;
  this->stack.push_back(created);
}

void Executioner::mul(){
  if (this->stack.size() < 2) { throw std::logic_error( "You need at least 2 elements on your stack to do this operation" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs * *rhs;
  this->stack.push_back(created);
}

void Executioner::div(){

  if (this->stack.size() < 2) { throw std::logic_error( "You need at least 2 elements on your stack to do this operation" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  if (rhs->toString() == "0") { throw std::logic_error( "You can't divide by 0" ); }
  if (lhs->toString() == "0") {
    OperatorFactory factory;
    this->stack.push_back(factory.createOperand(eOperandType::enum_int8, "0"));
    return;
  }
  IOperand const * created = nullptr;
  created = *lhs / *rhs;

  this->stack.push_back(created);
}

void Executioner::mod(){
  if (this->stack.size() < 2) { throw std::logic_error( "You need at least 2 elements on your stack to do this operation" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  if (rhs->getPrecision() >= 3 && lhs->getPrecision() >= 3) { throw std::logic_error( "You can only modulo an integer" ); }
  IOperand const * created = nullptr;
  created = *lhs % *rhs;
  this->stack.push_back(created);
}

void Executioner::power() {
  if (this->stack.size() < 2) { throw std::logic_error( "You need at least 2 elements on your stack to do this operation" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs ^ *rhs;
  this->stack.push_back(created);
}
/* END OPERATION */


void Executioner::whileE(IOperand const *last, std::string const & value) {
  if (this->stack.size() == 0) { throw std::logic_error("You can't do that on a empty stack"); }
  int i = 0;
  while (i < stod(value)) {
    this->stack.push_back(last);
    i++;
  }
}

void Executioner::push(eOperandType enumId, std::string const & value) {
  IOperand const * tmp = factory.createOperand(enumId, value);
  this->stack.push_back(tmp);
}

void Executioner::assertE(eOperandType enumId, std::string const & value) {
  if (this->stack.size() == 0) { throw std::logic_error("You can't do that on a empty stack"); }

  IOperand const * last =  this->getLast();
  IOperand const * tmp = factory.createOperand(enumId, value);
  if (last->toString() != tmp->toString() || last->getType() != tmp->getType()) { throw std::logic_error("Error on the assert"); }
  this->stack.push_back(tmp);
}

void Executioner::pop() {
  if (this->stack.size() == 0) { throw std::logic_error( "list is empty we can\'t pop" ); }
  else { this->stack.pop_back(); }
}

void Executioner::dump() {

  if (this->stack.size() == 0) { throw std::logic_error("You can't do that on a empty stack"); }

  std::list<IOperand const *>:: iterator end = this->stack.end();
  end--;
    std::cout << "\033[1;33mDump: \033[0m" << '\n';
  while (end != this->stack.begin())
  {
    std::cout << "\033[1;36m"<<(*end)->toString() << "\033[0m" << std::endl;
    end--;
  }
  std::cout << "\033[1;36m" << this->stack.front()->toString() << "\033[0m" << '\n';
}

IOperand const *Executioner::getLast() {
  IOperand const * tmp = this->stack.back();
  return tmp;
}

IOperand const  *Executioner::getLastAndPop() {
  IOperand const * tmp = this->stack.back();
  this->stack.pop_back();
  return tmp;
}

void Executioner::print() {
  if (this->stack.size() == 0) { throw std::logic_error("You can't do that on a empty stack"); }
  IOperand const * lhs = this->getLast();
  if (lhs->getType()!= 0) { throw std::logic_error("impossible to print this elements"); };
  int value = std::stoi(lhs->toString());
  if (value < 0) { throw std::logic_error("impossible to print this negatif elements"); }
  std::cout << static_cast<char>(value) << std::endl;
}

void Executioner::exitE() {
  std::cout << "\033[1;32mBye Bye \033[0m" << std::endl;
  std::exit(0);
}
