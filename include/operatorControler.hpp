#ifndef OPERATERCONTROLER_HPP
# define OPERATERCONTROLER_HPP

#include <iostream>
#include "IOperand.hpp"
#include "operatorFactory.hpp"
#include "errorControler.hpp"
#include <math.h>


template <typename T> class OperatorControler : public IOperand {

	private:
		std::string _value;
	 	eOperandType _type;
		long double _max;
		long double _min;

	public:
		OperatorControler(void);
		OperatorControler(T value, eOperandType type, long double max, long double min);
		OperatorControler(OperatorControler const &src);
		~OperatorControler(void);

		int						getPrecision( void ) const ;
		long double getMax(void) const;
		long double getMin(void) const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		IOperand const * operator^( IOperand const & rhs ) const;

		std::string const & toString( void ) const; // String representation of the instance
		eOperandType getType( void ) const; // Type of the instance
};



template<typename T> OperatorControler<T>::OperatorControler( void ) {
	this->_value = std::to_string(static_cast<T>(0));
	this->_type = eOperandType::enum_double;
}
template<typename T> OperatorControler<T>::OperatorControler( T value, eOperandType type, long double max, long double min) {
	this->_value = std::to_string(value);
	this->_type = type;
	this->_max = max;
	this->_min = min;
}
template<typename T> OperatorControler<T>::OperatorControler(OperatorControler const &src) {
	this->_value = src->_value;
	this->_type = src->_type;
	this->_max = src->_max;
	return this;
}

template<typename T> OperatorControler<T>::~OperatorControler( void ) {
	return;
}


template <typename T> IOperand const * OperatorControler<T>::operator+( IOperand const & rhs ) const {

	OperatorFactory factory;
	ErrorControler error;
	IOperand const * retVal = NULL;

	if(this->getPrecision() < rhs.getPrecision()) {
		error.overflow(&rhs, this, rhs.getMax(), "add");
		error.underflow(&rhs, this, rhs.getMin(), "add");
		retVal =factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
	} else {
		error.overflow(&rhs, this, this->_max, "add");
		error.underflow(&rhs, this, this->_min, "add");
		retVal = factory.createOperand(this->_type, std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
	}
	return retVal;
}

template <typename T> IOperand const * OperatorControler<T>::operator-( IOperand const & rhs ) const {

	OperatorFactory factory;
	ErrorControler error;
	IOperand const * retVal = NULL;

	if (this->getPrecision() < rhs.getPrecision()) {
		error.overflow(&rhs, this, rhs.getMax(), "sub");
		error.underflow(&rhs, this, rhs.getMin(), "sub");
		retVal =factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) - std::stod(rhs.toString())));
	} else {
		error.overflow(&rhs, this, this->_max, "sub");
		error.underflow(&rhs, this, this->_min, "sub");
		retVal = factory.createOperand(this->_type, std::to_string(std::stod(this->_value) - std::stod(rhs.toString())));
	}
	return retVal;
}

template <typename T> IOperand const * OperatorControler<T>::operator*( IOperand const & rhs ) const {

	OperatorFactory factory;
	ErrorControler error;
	IOperand const * retVal = NULL;

	if (this->getPrecision() < rhs.getPrecision()) {
		error.overflow(&rhs, this, rhs.getMax(), "mul");
		error.underflow(&rhs, this, rhs.getMin(), "mul");
		retVal = factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) * std::stod(rhs.toString())));
	} else {
		error.overflow(&rhs, this, this->_max, "mul");
		error.underflow(&rhs, this, this->_min, "mul");
		retVal = factory.createOperand(this->_type, std::to_string(std::stod(this->_value) * std::stod(rhs.toString())));
	}
	return retVal;
}

template <typename T> IOperand const * OperatorControler<T>::operator/( IOperand const & rhs ) const {

	OperatorFactory factory;
	ErrorControler error;
	IOperand const * retVal = NULL;

	if(this->getPrecision() < rhs.getPrecision()) {
		error.overflow(&rhs, this, rhs.getMax(), "div");
		error.underflow(&rhs, this, rhs.getMin(), "div");
		retVal =factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) / std::stod(rhs.toString())));
	} else {
		error.overflow(&rhs, this, this->_max, "div");
		error.underflow(&rhs, this, this->_min, "div");
		retVal = factory.createOperand(this->_type, std::to_string(std::stod(this->_value) / std::stod(rhs.toString())));
	}
	return retVal;
}

template <typename T> IOperand const * OperatorControler<T>::operator%( IOperand const & rhs ) const {

	OperatorFactory factory;
	ErrorControler error;
	IOperand const * retVal = NULL;

	if(this->getPrecision() < rhs.getPrecision()) {
		error.overflow(&rhs, this, rhs.getMax(), "mod");
		error.underflow(&rhs, this, rhs.getMin(), "mod");
		retVal =factory.createOperand(rhs.getType(), std::to_string(std::stoi(this->_value) % std::stoi(rhs.toString())));
	} else {
		error.overflow(&rhs, this, this->_max, "mod");
		error.underflow(&rhs, this, this->_min, "mod");
		retVal = factory.createOperand(this->_type, std::to_string(std::stoi(this->_value) % std::stoi(rhs.toString())));
	}
	return retVal;
}

template <typename T> IOperand const * OperatorControler<T>::operator^( IOperand const & rhs ) const {

	OperatorFactory factory;
	ErrorControler error;
	IOperand const * retVal = NULL;

	if(this->getPrecision() < rhs.getPrecision()) {
		error.overflow(&rhs, this, rhs.getMax(), "pow");
		error.underflow(&rhs, this, rhs.getMin(), "pow");
		retVal =factory.createOperand(rhs.getType(), std::to_string(pow(std::stod(this->_value),std::stod(rhs.toString()))));
	} else {
		error.overflow(&rhs, this, this->_max, "pow");
		error.underflow(&rhs, this, this->_min, "pow");
		retVal = factory.createOperand(this->_type, std::to_string(pow(std::stod(this->_value),std::stod(rhs.toString()))));
	}
	return retVal;
}

template <typename T> int OperatorControler<T>::getPrecision( void ) const {
	return static_cast<int>(this->_type);
}
template<typename T> eOperandType OperatorControler<T>::getType( void ) const {
	return this->_type;
}

template<typename T> long double OperatorControler<T>::getMax( void ) const {
	return this->_max;
}
template<typename T> long double OperatorControler<T>::getMin( void ) const {
	return this->_min;
}
template<typename T> std::string const & OperatorControler<T>::toString( void ) const {
	return this->_value;
}


#endif
