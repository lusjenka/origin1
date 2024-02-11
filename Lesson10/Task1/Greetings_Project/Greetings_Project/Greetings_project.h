#pragma once

class Greeter
{
public:
	std::string name;

	Greeter(std::string name);
	
	Greeter();

	void greet(std::string name_);
};