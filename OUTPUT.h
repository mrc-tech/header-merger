// this is the beginning of the "test.h" file

//in the next line includes another header file
// this is the beginning of "header1.h" file
void header1()
{
	int a = 1;
	int b = 1;
	int c = a + b;
}
// this is the beginning of "header2.h" file
#include <iostream>
void header2()
{
	double pi = 3.14159265;
	std::cout << pi;
}
// this is the end of "header2.h" file
// this is the end of "header1.h" file

// this is the end of "test.h" file
