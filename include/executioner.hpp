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

  void startVm(Parseur *parse);

 private:
  std::list<IOperand const *>stack;
  std::list<IOperand const *>::const_iterator start;
  std::list<IOperand const *>::const_iterator end;

  eOperandType getEnumId(std:: string type);
  IOperand const * getLast(void);
  IOperand const * getLastAndPop(void);
  void push(eOperandType enumId, std::string const & value);
  void assertE(eOperandType enumId, std::string const & value);
  void add(void);
  void sub(void);
  void mul(void);
  void div(void);
  void mod(void);
  // void print(void);
  void pop(void);
  void dump(void);
  void exitE(void);
  OperatorFactory factory;
};

#endif
