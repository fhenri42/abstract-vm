#include "executioner.hpp"

Executioner::Executioner(void){
  return;
}

Executioner::Executioner(Executioner const &src) {
  return;
}

Executioner &Executioner::operator=(Executioner const & src) {
  return *this;
}

Executioner::~Executioner(void) {
  return;
}
void Executioner::startVm(Parseur *parse) {

  std::list<VM_List>::const_iterator start;

  for(start = parse->vmList.begin(); start != parse->end; ++start)
  {
    if(start->info == "pop") { this->pop(); }
    if(start->info == "dump") { this->dump(); }
    if(start->info == "exit") { this->exitE(); }
    if(start->info == "push") { this->push(start->value); }
    if(start->info == "print") { this->print(); }
  }
  // std::list<double>::const_iterator start2;
  // this->start = this->stack.begin();
  // this->end = this->stack.end();
  //
  // // for(start2 = this->start; start2 != this->end; ++start2)
  // // {
  // //   std::cout << "=======" << std::endl;
  // //   std::cout << *start2 << std::endl;
  // //   std::cout << "=======" << std::endl;
  // // }
  // // std::cout << this->getLastAndPop() << '\n';
  // // std::cout << this->getLast() << '\n';
}

void Executioner::push(double value) {
  this->stack.push_back(value);
}

void Executioner::pop() {
  if(this->stack.size() == 0) {
        throw std::logic_error( "list is empty we can\'t pop" );
  } else {
    this->stack.pop_back();

  }
}

void Executioner::dump() {
  std::list<double>::const_iterator end = this->stack.end();
  end--;
  std::cout << "Dump:" << '\n';
  while(end != this->stack.begin())
  {
    std::cout << *end << std::endl;
    end--;
  }
  std::cout << this->stack.front() << '\n';
}

double Executioner::getLast() {
  return this->stack.back();
}

double Executioner::getLastAndPop() {
  double tmp = this->stack.back();
  this->stack.pop_back();
  return tmp;
}
//TODO A finir
void Executioner::print() {
  std::cout << "Print: " << this->getLast() << '\n';
}
void Executioner::exitE() {
  std::cout << "Bye Bye" << '\n';
  std::exit(0);
}
