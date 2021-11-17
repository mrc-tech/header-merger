// this is the beginning of "header2.h" file
#include <iostream>
void header2()
{
	double pi = 3.14159265;
	std::cout << pi;
}
#pragma once
#include "header1.h" // multiple inclusion
// this is the end of "header2.h" file
