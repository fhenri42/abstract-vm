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
    if (start->info == "pop") { this->pop(); }
    if (start->info == "dump") { this->dump(); }
    if (start->info == "exit") { this->exitE(); }
    if (start->info == "push") { this->push(enumId,start->value); }
    // if (start->info == "print") { this->print(); }
    if (start->info == "assert") { this->assertE(enumId, start->value); }
    if (start->info == "add") {this->add();}
    if (start->info == "sub") { this->sub(); }
    if (start->info == "mul") { this->mul(); }
    if (start->info == "div") { this->div(); }
    if (start->info == "mod") { this->mod(); }
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
  if (this->stack.size() < 2) { throw std::logic_error( "Ahh nice try" ); }
  IOperand const * last = this->getLastAndPop();
  IOperand const * beforeLast = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *beforeLast + *last;
  this->stack.push_back(created);
}

void Executioner::sub(){
  if (this->stack.size() < 2) { throw std::logic_error( "Ahh nice try" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs - *rhs;
  this->stack.push_back(created);
}

void Executioner::mul(){
  if (this->stack.size() < 2) { throw std::logic_error( "Ahh nice try" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs * *rhs;
  this->stack.push_back(created);
}

void Executioner::div(){
  if (this->stack.size() < 2) { throw std::logic_error( "Ahh nice try" ); }
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  if (rhs->toString() == "0") { throw std::logic_error( "Ahh nice try you c\'ant divide by 0" ); }
  IOperand const * created = nullptr;
  created = *lhs / *rhs;
  this->stack.push_back(created);
}

void Executioner::mod(){
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  if (rhs->getPrecision() >= 3 && lhs->getPrecision() >= 3) { throw std::logic_error( "You can only modulo an integer" ); }
  IOperand const * created = nullptr;
  created = *lhs % *rhs;
  this->stack.push_back(created);
}

/* END OPERATION */
void Executioner::push(eOperandType enumId, std::string const & value) {
  IOperand const * test = factory.createOperand(enumId, value);
  this->stack.push_back(test);
}

void Executioner::assertE(eOperandType enumId, std::string const & value) {
  IOperand const * last =  this->getLast();
  IOperand const * test = factory.createOperand(enumId, value);
  if (last->toString() != test->toString() || last->getType() != test->getType()) { throw std::logic_error("Error on the assert"); }
  this->stack.push_back(test);
}

void Executioner::pop() {
  if (this->stack.size() == 0) { throw std::logic_error( "list is empty we can\'t pop" ); }
  else { this->stack.pop_back(); }
}

void Executioner::dump() {

  std::list<IOperand const *>:: iterator end = this->stack.end();
  end--;
  std::cout << "Dump:" << '\n';
  while(end != this->stack.begin())
  {
    std::cout << (*end)->toString() << std::endl;
    end--;
  }
  std::cout << this->stack.front()->toString() << '\n';
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
// //TODO A finir
// void Executioner::print() {
//   std::cout << "Print: " << this->getLast() << '\n';
// }
void Executioner::exitE() {
  std::cout << "Bye Bye" << '\n';
  std::exit(0);
}
