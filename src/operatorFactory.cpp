#include "operatorFactory.hpp"
#include "operatorControler.hpp"

OperatorFactory::OperatorFactory( void ) {}
OperatorFactory::OperatorFactory( OperatorFactory const & obj ) { static_cast<void>(obj); }
OperatorFactory::~OperatorFactory( void ) {}


OperatorFactory & OperatorFactory::operator=( OperatorFactory const & rhs ) { static_cast<void>(rhs); return *this; }

IOperand const * OperatorFactory::createOperand(eOperandType type, std::string const & value)
{
	switch(type) {
		case eOperandType::enum_int8: return createInt8(value);
		case eOperandType::enum_int16: return createInt16(value);
		case eOperandType::enum_int32: return createInt32(value);
		case eOperandType::enum_float: return createFloat(value);
		case eOperandType::enum_double: return createDouble(value);
	}
	return NULL;
}

IOperand const * OperatorFactory::createInt8(std::string const & value) const {
	(void)(value);
	return new OperatorControler<int8_t>(std::stoi(value), eOperandType::enum_int8);
}

IOperand const * OperatorFactory::createInt16(std::string const & value) const {
	(void)(value);
	return new OperatorControler<int16_t>(std::stoi(value), eOperandType::enum_int16);
}

IOperand const * OperatorFactory::createInt32(std::string const & value) const {
	(void)(value);
	return new OperatorControler<int32_t>(std::stoi(value), eOperandType::enum_int32);
}

IOperand const * OperatorFactory::createFloat(std::string const & value) const {
	(void)(value);
	return new OperatorControler<float>(std::stoi(value), eOperandType::enum_float);
}

IOperand const * OperatorFactory::createDouble(std::string const & value) const {
	(void)(value);
	return new OperatorControler<double>(std::stoi(value), eOperandType::enum_double);
}
