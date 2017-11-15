#ifndef OPERATERFACTORY_HPP
# define OPERATERFACTORY_HPP

#include "IOperand.hpp"

class OperatorFactory {
  public:
      OperatorFactory(void);
      OperatorFactory(OperatorFactory const &src); // Copy
      ~OperatorFactory(void);                // Destructeur de recopie

      OperatorFactory &operator=(OperatorFactory const & src);  // operator d'affecationt

      IOperand const * createOperand(eOperandType type, std::string const & value);
      IOperand const * createInt8(std::string const & value) const;
      IOperand const * createInt16( std::string const & value ) const;
      IOperand const * createInt32( std::string const & value ) const;
      IOperand const * createFloat( std::string const & value ) const;
      IOperand const * createDouble( std::string const & value ) const;
};

#endif
