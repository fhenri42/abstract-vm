# ifndef PARSEUR_HPP
# define PARSEUR_HPP

#include <string>
#include <list>

// struct vmList
// {
//   std::string instrucion;
//   struct vmList *next;
// };

class Parseur
{
  public:

    Parseur(void);
    Parseur(Parseur const &src); // Copy
    ~Parseur(void);                // Destructeur de recopie

    Parseur &operator=(Parseur const & src);  // operator d'affecationt

//    void verife(void);
      int checkeur(std::string instrucion);
      void push(std::string instrucion);
//    vmList *pop(std::string instrucion);

    std::list<std::string> vmList;
    std::list<std::string>::const_iterator start;
    std::list<std::string>::const_iterator end;
    //struct vmList *instrucions;
    bool exit;

};

#endif
