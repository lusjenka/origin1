#include <iostream>

class Fraction
{
public:
	int numerator_;
	int denominator_;
	
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	int gcd(int a, int b) {
		a = abs(a), b = abs(b);
		if (b == 0)return a;
		else return gcd(b, a % b);

	}
	void sokr() {
		int x = gcd(numerator_, denominator_);
		int a = numerator_;
		int b = denominator_;
		a /= x;
		b /= x;
		
	}
	
	int Abs(Fraction other) {
		
		int l_numerator_ = numerator_ * other.denominator_;
		return l_numerator_;
		}
	int Abs_r(Fraction other) {

		int r_numerator_ = denominator_ * other.numerator_;
		return r_numerator_;
	}

	bool operator==(Fraction other) 
	{ 
		return Abs(other) == Abs_r(other); 
	}
	bool operator!=(Fraction other)
	{
		return Abs(other) != Abs_r(other);
	}
	bool operator<(Fraction other)
	{
		return Abs(other) < Abs_r(other);
	}
	bool operator>(Fraction other)
	{
		return Abs(other) > Abs_r(other);
	}
	bool operator<=(Fraction other)
	{
		return Abs(other) <= Abs_r(other);
	}
	bool operator>=(Fraction other)
	{
		return Abs(other) >= Abs_r(other);
	}

};

int main()
{
	Fraction f1(6, 4);
	Fraction f2(6, 11);
	f1.sokr();
	f2.sokr();
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}