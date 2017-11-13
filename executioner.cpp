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
void Executioner::start(Parseur *parse) {

  std::list<VM_List>::const_iterator start;
  for(start = parse->vmList.begin(); start != parse->end; ++start)
  {
    std::cout << "=======" << std::endl;
    std::cout << start->info << std::endl;
    std::cout << start->type << std::endl;
    std::cout << start->value << std::endl;
    std::cout << "=======" << std::endl;
  }
}
