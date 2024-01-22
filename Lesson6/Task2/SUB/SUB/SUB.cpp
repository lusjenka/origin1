#include <iostream>

using namespace std;

#define SUB(a,b) \
((a)-(b))


int main(int argc, char** argv)

{

#if !defined SUB

	std::cout << "Ne opredelen" << std::endl;

#error Ne opredelen

#endif

#if defined SUB

	int a = 6;
	int b = 5;
	int c = 2;

	cout << SUB(a, b);
	cout << endl;
	cout << SUB(a, b) * c;
	cout << endl;
	cout << SUB(a, b + c) * c;

#endif



}