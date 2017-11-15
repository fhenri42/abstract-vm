# ifndef EXECUTIONER_HPP
# define EXECUTIONER_HPP

#include <string>
#include <list>

#include <iostream>
#include <sstream>
#include <regex>
#include "parseur.hpp"
#include "operatorControler.hpp"
#include "IOperand.hpp"
#include "operatorFactory.hpp"
#include "errorControler.hpp"

class Executioner {
public:

  Executioner(void);
  Executioner(Executioner const &src); // Copy
  ~Executioner(void);                // Destructeur de recopie

  Executioner &operator=(Executioner const & src);  // operator d'affecationt

  std::list<IOperand const *>stack;
  std::list<IOperand const *>::const_iterator start;
  std::list<IOperand const *>::const_iterator end;
  void startVm(Parseur *parse);
  void add(void);
  void sub(void);
  void pop(void);
  void dump(void);
  void exitE(void);
  // void print(void);
  IOperand const * getLast(void);
  IOperand const * getLastAndPop(void);

  void push(std::string type, std::string const & value);
  void assertE(std::string type, std::string const & value);

private:
  OperatorFactory factory;
};

#endif
