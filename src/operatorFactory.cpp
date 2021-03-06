#include "operatorFactory.hpp"
#include "operatorControler.hpp"

OperatorFactory::OperatorFactory( void ) {}
OperatorFactory::OperatorFactory( OperatorFactory const & obj ) { static_cast<void>(obj); }
OperatorFactory::~OperatorFactory( void ) {return;}


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
	return new OperatorControler<int8_t>(std::stoi(value), eOperandType::enum_int8, CHAR_MAX, CHAR_MIN);
}

IOperand const * OperatorFactory::createInt16(std::string const & value) const {
	return new OperatorControler<int16_t>(std::stoi(value), eOperandType::enum_int16, SHRT_MAX, SHRT_MIN);
}

IOperand const * OperatorFactory::createInt32(std::string const & value) const {
	return new OperatorControler<int32_t>(std::stoi(value), eOperandType::enum_int32, INT_MAX, INT_MIN);
}

IOperand const * OperatorFactory::createFloat(std::string const & value) const {
	return new OperatorControler<float>(std::stof(value), eOperandType::enum_float,std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest());
}

IOperand const * OperatorFactory::createDouble(std::string const & value) const {
	return new OperatorControler<double>(std::stod(value), eOperandType::enum_double, std::numeric_limits<double>::max(),std::numeric_limits<double>::lowest());
}
