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

  for (start = parse->vmList.begin(); start != parse->end; ++start)
  {
    if (start->info == "pop") { this->pop(); }
    if (start->info == "dump") { this->dump(); }
    if (start->info == "exit") { this->exitE(); }
    if (start->info == "push") { this->push(start->type,start->value); }
    // if (start->info == "print") { this->print(); }
    if (start->info == "add") {this->add();}
  }
}

void Executioner::add() {
  IOperand const * rhs = this->getLastAndPop();
  IOperand const * lhs = this->getLastAndPop();
  IOperand const * created = nullptr;
  created = *lhs + *rhs;
  this->stack.push_back(created);
}

void Executioner::push(std::string type, std::string const & value) {
  eOperandType enumId;
  if (type == "int8") { enumId = eOperandType::enum_int8; }
  if (type == "int16") { enumId = eOperandType::enum_int16; }
  if (type == "int32") { enumId = eOperandType::enum_int32; }
  if (type == "float") { enumId = eOperandType::enum_float; }
  if (type == "double") { enumId = eOperandType::enum_double; }
  IOperand const * test = factory.createOperand(enumId, value);
  this->stack.push_back(test);
}

void Executioner::pop() {
  if(this->stack.size() == 0) {
    throw std::logic_error( "list is empty we can\'t pop" );
  } else {
    this->stack.pop_back();
  }
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
