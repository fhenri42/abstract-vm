#include "operandFactory.hpp"

OperandFactory::OperandFactory( void ) {}
OperandFactory::OperandFactory( OperandFactory const & obj ) { static_cast<void>(obj); }
OperandFactory::~OperandFactory( void ) {}


OperandFactory & OperandFactory::operator=( OperandFactory const & rhs ) { static_cast<void>(rhs); return *this; }

IOperand const * OperandFactory::createOperand(int type, std::string const & value)
{
	//switch(type) {
		//case eOperandType::e_int8 : return createInt8(value);
		// case eOperandType::e_int16 : return createInt16(value);
		// case eOperandType::e_int32 : return createInt32(value);
		// case eOperandType::e_float : return createFloat(value);
		// case eOperandType::e_double : return createDouble(value);
		//case eOperandType::e_invalid : return NULL;
	//}
	return createInt8(value);
}

IOperand const * OperandFactory::createInt8(std::string const & value) const {

	return new OperatorControler<int8_t>(std::stoi(value));
}
