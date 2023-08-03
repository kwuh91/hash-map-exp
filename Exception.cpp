#include "Exception.h"

//Initializing
Exception::Exception() = default;

//Initializing with a message
Exception::Exception(std::string error) : msg_(std::move(error)) {}

//Error output
const char* Exception::what()const noexcept {
	return msg_.c_str();
}
