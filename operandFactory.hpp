#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

# include "IOperand.hpp"
# include "operaterControler.hpp"

class OperandFactory {
  public:
      OperandFactory(void);
      OperandFactory(OperandFactory const &src); // Copy
      ~OperandFactory(void);                // Destructeur de recopie

      OperandFactory &operator=(OperandFactory const & src);  // operator d'affecationt

      IOperand const * createOperand(int type, std::string const & value);
      IOperand const * createInt8(std::string const & value) const;
      // IOperand const * createInt16( std::string const & value ) const;
      // IOperand const * createInt32( std::string const & value ) const;
      // IOperand const * createFloat( std::string const & value ) const;
      // IOperand const * createDouble( std::string const & value ) const;
};

#endif
