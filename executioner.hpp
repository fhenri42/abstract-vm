# ifndef EXECUTIONER_HPP
# define EXECUTIONER_HPP

#include <string>
#include <list>

#include <iostream>
#include <sstream>
#include <regex>
#include "parseur.hpp"
class Executioner
{
  public:

    Executioner(void);
    Executioner(Executioner const &src); // Copy
    ~Executioner(void);                // Destructeur de recopie

    Executioner &operator=(Executioner const & src);  // operator d'affecationt

    void start(Parseur *parse);
    void pop(void);
    void push(void);
};

#endif
