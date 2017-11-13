#include "parseur.hpp"
#include <regex>

Parseur::Parseur(void){
  //  std::cout << "on est all aussi enfain, surtout ! " << '\n';

  //this->instrucions =
  this->exit = false;
  //  this->start = NULL;
  //  this->end = this->vmList.end();
  //  this->instrucions->instrucion = NULL;
  return;
}

Parseur::Parseur(Parseur const &src) {
  return;
}

// Parseur &Parseur::operator=(Parseur const & src) {
//
//   this->ennemyDead = src.ennemyDead;
//   return *this;
// }


Parseur::~Parseur(void) {
  std::cout << "MDR on est alll" << '\n';
  //   struct EnnemyList *tmp;
  //   std::string *tmp2;
  //   while (this->ennemyList != NULL)
  //   {
  //       tmp = this->ennemyList;
  //       tmp2 = this->ennemyList->ennemy;
  //       this->ennemyList = this->ennemyList->next;
  //       delete tmp2;
  //       delete tmp;
  //   }
  //   delete this->ennemyList;
  // return;
}

//TODO
//chek exit is  the last one
//chek value of int
//CHek double and float no need decimal
//regex of death
//.*?(push (?![ ]{1,})|pop|dump|assert (?![ ]{1,})|add|sud|mul|div|mod|print|exit)(\s|int8\([0-9][^)]*\)|int16\([0-9][^)]*\)|int32\([0-9][^)]*\)|float\(\d+(\.[0-9]\d*?\))?|\.[0-9]\d+|double\(\d+(\.[0-9]\d*?\))?|\.[0-9]\d+)
int Parseur::checkeur(std::string instrucion) {
  std::regex elRegex("(push (?![ ]{1,})|pop|dump|assert (?![ ]{1,})|add|sud|mul|div|mod|print|exit)((?=\\n|$)|int8\\([0-9][^)]*\\)|int16\\([0-9][^)]*\\)|int32\\([0-9][^)]*\\)|float\\(\\d+(\\.[0-9]\\d*?\\))?|\\.[0-9]\\d+|double\\(\\d+(\\.[0-9]\\d*?\\))?|\\.[0-9]\\d+)");

  if(regex_match(instrucion, elRegex) && instrucion != "exit") {
    vmList.push_back(instrucion);
    return 0;
  } else if (instrucion == "exit") {
    vmList.push_back(instrucion);
    this->exit = true;
    this->end = this->vmList.end();
    this->start = this->vmList.begin();
    return 0;
  }

  return 1;
  //std::cout << "Mdr sa fonctionne" << '\\n';

}

// void Parseur::push(std::string instrucion)
// {
//   this->vmList.push_back(instrucion)
// }
//
// vmList *Parseur::pop(std::string *ennemy)
// {
//     struct EnnemyList *tmp = NULL;
//     if (this->ennemyList->ennemy == ennemy)
//     {
//         delete this->ennemyList->ennemy;
//         tmp = this->ennemyList;
//         this->ennemyList = this->ennemyList->next;
//         delete tmp;
//         return this->ennemyList;
//     }
//     else
//     {
//         while (this->ennemyList->next && this->ennemyList->next->ennemy != ennemy)
//         {
//             this->ennemyList = this->ennemyList->next;
//         }
//         if (this->ennemyList->next)
//         {
//             tmp = this->ennemyList->next->next;
//             delete this->ennemyList->next->ennemy;
//             delete this->ennemyList->next;
//             this->ennemyList->next = tmp;
//             return tmp;
//         }
//     }
//     this->ennemyDead +=1;
//     return tmp;
// }
