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
		long double _max;
		long double _min;
	public:
		OperatorControler(void);
		OperatorControler(T value, eOperandType type, long double max, long double min);
		OperatorControler(OperatorControler const &src);
		~OperatorControler(void);

		int						getPrecision( void ) const ;
		long double getMax(void) const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;

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

template<typename T> std::string const & OperatorControler<T>::toString( void ) const {
	return this->_value;
}
template <typename T> IOperand const * OperatorControler<T>::operator+( IOperand const & rhs ) const {

	OperatorFactory factory;
	eOperandType newType;
	ErrorControler error;
	long double max;
	if(this->_type < rhs.getType()) {
		newType = rhs.getType();
		max = rhs.getMax();
	} else {
	 newType = this->_type;
	 max = this->_max;
	}
	error.overflow(&rhs, this, max, "add");
	IOperand const * ret_val = factory.createOperand(newType, std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
	//delete factory;
	return ret_val;
}

// template <typename T> IOperand const * OperatorControler<T>::operator*( IOperand const & rhs ) const {
//
// 		OperatorFactory factory;
// 		eOperandType newType;
// 		ErrorControler error;
//
// 		if(this->_type < rhs.getType()) {
// 			newType = rhs.getType();
// 		} else {
// 		 newType = this->_type;
// 		}
// 		error.overflow(&rhs, this, newType, "mul");
// 		IOperand const * ret_val = factory.createOperand(newType, std::to_string(std::stod(this->_value) * std::stod(rhs.toString())));
// 		//delete factory;
// 		return ret_val;
// }
//
// template <typename T> IOperand const * OperatorControler<T>::operator-( IOperand const & rhs ) const {
//
// 		OperatorFactory factory;
// 		eOperandType newType;
// 		ErrorControler error;
//
// 		if(this->_type < rhs.getType()) {
// 			newType = rhs.getType();
// 		} else {
// 			newType = this->_type;
// 		}
// 		error.overflow(&rhs, this, newType, "sub");
// 		IOperand const * ret_val = factory.createOperand(newType, std::to_string(std::stod(this->_value) - std::stod(rhs.toString())));
// 		//delete factory;
// 		return ret_val;
// }
//
// template <typename T> IOperand const * OperatorControler<T>::operator/( IOperand const & rhs ) const {
//
// 		OperatorFactory factory;
// 		eOperandType newType;
// 		ErrorControler error;
//
// 		if(this->_type < rhs.getType()) {
// 			newType = rhs.getType();
// 		} else {
// 		 newType = this->_type;
// 		}
// 		error.overflow(&rhs, this, newType, "div");
// 		IOperand const * ret_val = factory.createOperand(newType, std::to_string(std::stod(this->_value) / std::stod(rhs.toString())));
// 		//delete factory;
// 		return ret_val;
// }
//
// template <typename T> IOperand const * OperatorControler<T>::operator%( IOperand const & rhs ) const {
//
// 		OperatorFactory factory;
// 		eOperandType newType;
// 		ErrorControler error;
//
// 		if(this->_type < rhs.getType()) {
// 			newType = rhs.getType();
// 		} else {
// 		 newType = this->_type;
// 		}
// 		error.overflow(&rhs, this, newType, "mod");
// 		IOperand const * ret_val = factory.createOperand(newType, std::to_string(std::stol(this->_value) % std::stol(rhs.toString())));
// 		//delete factory;
// 		return ret_val;
// }

template <typename T> int OperatorControler<T>::getPrecision( void ) const {
	return static_cast<int>(this->_type);
}
template<typename T> eOperandType OperatorControler<T>::getType( void ) const {
	return this->_type;
}

template<typename T> long double OperatorControler<T>::getMax( void ) const {
	return this->_max;
}


#endif
