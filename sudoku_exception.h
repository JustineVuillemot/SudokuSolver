#include <exception>
#include <string>

#pragma once

class Cell_exists : public std::exception
{
private:
	std::string message;
public:
	Cell_exists(const std::string& what_arg) : message(what_arg)
	{

	}
	Cell_exists(const char* what_arg) : message(what_arg)
	{

	}
	virtual const char* what() const noexcept
	{
		return message.c_str();
	}
};