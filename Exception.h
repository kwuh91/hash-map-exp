#pragma once
#ifndef LR3_4_EXCEPTION_H
#define LR3_4_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class [[maybe_unused]] Exception : std::exception {
private:
	std::string msg_;
public:
	//Initializing 
	explicit Exception();

	//Initializing with a message 
	explicit Exception(std::string);

	//Error output 
	[[nodiscard]] const char* what()const noexcept override;

	//Destructor 
	~Exception() override = default;
};

#endif //LR3_4_EXCEPTION_H
