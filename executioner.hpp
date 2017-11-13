# ifndef EXECUTIONER_HPP
# define EXECUTIONER_HPP

#include <string>
#include <list>

#include <iostream>
#include <sstream>
#include <regex>
#include "parseur.hpp"

struct stack
{
  double value;
};

class Executioner
{
  public:

    Executioner(void);
    Executioner(Executioner const &src); // Copy
    ~Executioner(void);                // Destructeur de recopie

    Executioner &operator=(Executioner const & src);  // operator d'affecationt

    std::list<double> stack;
    std::list<double>::const_iterator start;
    std::list<double>::const_iterator end;
    void startVm(Parseur *parse);
    void pop(void);
    void dump(void);
    void exitE(void);
    void print(void);
    double getLast(void);
    double getLastAndPop(void);
    void push(double value);
};

#endif
