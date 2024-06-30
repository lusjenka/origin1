#include "swapData.h"
#include <iostream>




int Data::getValue() const
{
	return Data::value_;
}

void Data::setValue(int value)
{
	Data::value_ = value;
}

