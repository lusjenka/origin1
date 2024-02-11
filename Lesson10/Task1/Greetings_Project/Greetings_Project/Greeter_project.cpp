#include <iostream>
#include "Greetings_project.h"


	Greeter::Greeter(std::string name)
	{
		this->name = name;
	}
	Greeter::Greeter()
	{
		name = "name";
	}

	void Greeter::greet(std::string name_)
	{
		
		std::cout << "\nЗдравствуйте, " << name_;
		
	}
