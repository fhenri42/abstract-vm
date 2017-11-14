# ifndef EXECUTIONER_HPP
# define EXECUTIONER_HPP

#include <string>
#include <list>

#include <iostream>
#include <sstream>
#include <regex>
#include "parseur.hpp"
#include "operaterControler.hpp"
#include "IOperand.hpp"
#include "operandFactory.hpp"
#include "stack.hpp"

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
     void add();
    // void pop(void);
    void dump(void);
    // void exitE(void);
    // void print(void);
      IOperand const * getLast(void);
      IOperand const * getLastAndPop(void);
    //Stack<IOperand const*> stack;
    void push(std::string type, std::string const & value);

  private:
//    Stack stack;
    OperandFactory factory;
};

#endif
