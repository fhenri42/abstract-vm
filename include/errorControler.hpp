# ifndef ERRORCONTROLER_HPP
# define ERRORCONTROLER_HPP

#include <string>
#include <iostream>
#include "./parseur.hpp"

#define EndOF "You must have an exit at the end of instructions"
#define SYNTAX_ERROR "Syntax error on this instruction: "
#define EXIT_ERROR "Exit must be the last instruction: "
#define FALSE_INST_ERROR "This instruction is false: "

class ErrorControler : public Parseur
{
  public:

    ErrorControler(void);
    ErrorControler(ErrorControler const &src); // Copy
    ~ErrorControler(void);                // Destructeur de recopie

    ErrorControler &operator=(ErrorControler const & src);  // operator d'affecationt
    int needToStopFd(int type, bool isExit, std::string nextValue, bool fd);
    int needToStopCin(int type, bool isExit, std::string nextValue);
    void endofFile(bool isExit);
    bool exit;
    
  private:
    int const putError(int line, std::string const & error) const;
};

#endif