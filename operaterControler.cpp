#include "operaterControler.hpp"

// template<class T> void OperatorControler<T>::getValue() { return this->value;}
template<class T> OperatorControler<T>::OperatorControler( void ) { this->_value = std::to_string(static_cast<T>(0)); }
template<class T> OperatorControler<T>::OperatorControler( T value ) { this->_value = std::to_string(value); }

template<class T> std::string const & OperatorControler<T>::toString( void ) const {
	return this->_value;
}
template <typename T> IOperand const * OperatorControler<T>::operator+( IOperand const & rhs ) const {

	OperandFactory factory;
 IOperand const * ret_val = factory.createOperand(1, std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
// delete factory;
 return ret_val;
}

template class OperatorControler<int8_t>;
// template class OperatorControler<int16_t>;
// template class OperatorControler<int32_t>;
// template class OperatorControler<float>;
// template class OperatorControler<double>;
