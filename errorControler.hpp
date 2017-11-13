# ifndef ERRORCONTROLER_HPP
# define ERRORCONTROLER_HPP

#include <string>
#include <iostream>

class ErrorControler
{
  public:

    ErrorControler(void);
    ErrorControler(ErrorControler const &src); // Copy
    ~ErrorControler(void);                // Destructeur de recopie

    ErrorControler &operator=(ErrorControler const & src);  // operator d'affecationt
    int needToStop(int type, bool isExit, std::string nextValue, int fds);
    int endofFile(bool isExit);
    bool exit;

};

#endif
