#ifndef OPERATERCONTROLER_HPP
# define OPERATERCONTROLER_HPP

#include <iostream>
#include "IOperand.hpp"
#include "operatorFactory.hpp"
#include "errorControler.hpp"


template <typename T> class OperatorControler : public IOperand {

	private:
		T						value;
		std::string _value;
	 	eOperandType _type;
	public:
		OperatorControler(void);
		OperatorControler(T value, eOperandType type);
		OperatorControler(OperatorControler const &src);
		~OperatorControler(void);
    //TODO Copy

		int						getPrecision( void ) const ;
		IOperand const * operator+( IOperand const & rhs ) const;
		std::string const & toString( void ) const; // String representation of the instance
		eOperandType getType( void ) const; // Type of the instance
};



template<typename T> OperatorControler<T>::OperatorControler( void ) {
	this->_value = std::to_string(static_cast<T>(0));
	this->_type = eOperandType::enum_double;
}
template<typename T> OperatorControler<T>::OperatorControler( T value, eOperandType type) {
	this->_value = std::to_string(value);
	this->_type = type;
}
template<typename T> OperatorControler<T>::OperatorControler( OperatorControler const &src) {
	this->_value = src->value;
	this->_type = src->type;
	return this;
}

template<typename T> OperatorControler<T>::~OperatorControler( void ) {
	return;
}

template<typename T> std::string const & OperatorControler<T>::toString( void ) const {
	return this->_value;
}
template <typename T> IOperand const * OperatorControler<T>::operator+( IOperand const & rhs ) const {

	OperatorFactory factory;
	eOperandType newType;
	ErrorControler error;

	if(this->_type < rhs.getType()) {
		newType = rhs.getType();
	} else {
	 newType = this->_type;
	}
	error.overflow(&rhs, this, newType, "add");
	IOperand const * ret_val = factory.createOperand(newType, std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
	//delete factory;
	return ret_val;
}

template <typename T> int OperatorControler<T>::getPrecision( void ) const {
	return static_cast<int>(this->_type);
}
template<typename T> eOperandType OperatorControler<T>::getType( void ) const {
	return this->_type;
}



#endif
