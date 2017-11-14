#ifndef OPERATERCONTROLER_HPP
# define OPERATERCONTROLER_HPP

#include <iostream>
#include <string>
#include "IOperand.hpp"
#include "operandFactory.hpp"


template <class T> class OperatorControler : public IOperand {

	public:
		T						value;
		std::string _value;
		OperatorControler(void);
		OperatorControler(T value);
		// void getValue(void);
	//	OperatorControler(OperatorControler const &src);
	//	~OperatorControler(void);
    //TODO Copy
		IOperand const *		operator+( IOperand const & rhs ) const;
		std::string const & toString( void ) const; // String representation of the instance
};


#endif
