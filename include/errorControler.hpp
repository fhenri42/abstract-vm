# ifndef ERRORCONTROLER_HPP
# define ERRORCONTROLER_HPP

#include <string>
#include <iostream>
#include "IOperand.hpp"

class ErrorControler
{
  public:

    ErrorControler(void);
    ErrorControler(ErrorControler const &src); // Copy
    ~ErrorControler(void);                // Destructeur de recopie

    ErrorControler &operator=(ErrorControler const & src);  // operator d'affecationt
    int needToStop(int type, bool isExit, std::string nextValue, bool fd);
    void endofFile(bool isExit);
    bool exit;
    void overflow(IOperand const *operan, IOperand const *operan1, eOperandType newType, std::string opertionType);
  //  void underflow(IOperand const *operan);
};

#endif
