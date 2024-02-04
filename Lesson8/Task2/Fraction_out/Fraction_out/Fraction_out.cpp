#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;


public:
	int gcd(int a, int b) {
		a = abs(a), b = abs(b);
		if (b == 0)return a;
		else return gcd(b, a % b);

	}

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void operator=(Fraction right)
	{
		numerator_ = right.numerator_;
		denominator_ = right.denominator_;
	}
			
	void print() {
		int x = gcd(numerator_, denominator_);
		int a = numerator_;
		int b = denominator_;
		a /= x;
		b /= x;
		std::cout << a << "/" << b;
	}
	Fraction operator+(Fraction right) {
		int new_numerator_ = numerator_* right.denominator_ + right.numerator_* denominator_;
		int new_denominator_ = denominator_*right.denominator_;
		return Fraction(new_numerator_, new_denominator_);
	}
	Fraction operator-(Fraction right) {
		int new_numerator_ = numerator_ * right.denominator_ - right.numerator_ * denominator_;
		int new_denominator_ = denominator_ * right.denominator_;
		return Fraction(new_numerator_, new_denominator_);
	}
	Fraction operator*(Fraction right) {
		int new_numerator_ = numerator_ * right.numerator_;
		int new_denominator_ = denominator_ * right.denominator_;
		return Fraction(new_numerator_, new_denominator_);
	}
	Fraction operator/(Fraction right) {
		int new_numerator_ = numerator_ * right.denominator_;
		int new_denominator_ = denominator_ * right.numerator_;
		return Fraction(new_numerator_, new_denominator_);
	}
	Fraction operator++() {
		numerator_ = numerator_ + denominator_;
		denominator_ = denominator_;
		return Fraction(numerator_, denominator_);
	}
	Fraction operator++(int) {
		int Vnumerator_ = numerator_;
		int Vdenominator_ = denominator_;
		numerator_ += denominator_;
		denominator_ = denominator_;
		return Fraction(Vnumerator_, Vdenominator_);
	}
	Fraction operator--() {
		numerator_ = numerator_ - denominator_;
		denominator_ = denominator_;
		return Fraction(numerator_, denominator_);
	}
	Fraction operator--(int) {
		numerator_ = numerator_ - denominator_;
		denominator_ = denominator_;
		return Fraction(numerator_, denominator_);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int num1, denom1, num2, denom2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denom1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denom2;
	Fraction f1(num1, denom1);
	Fraction f2(num2, denom2);
	Fraction sum(f2), minus(f2),umn(f2),del(f2), pref_inc(f2),post_inc(f2),pref_dec(f2),post_dec(f2);

	sum = f1 + f2;
	std::cout << num1 << "/" << denom1 << " + " << num2 << "/" << denom2 << " = "; 
	sum.print();

	minus = f1 - f2;
	std::cout <<std::endl<< num1 << "/" << denom1 << " - " << num2 << "/" << denom2 << " = "; 
	minus.print();

	umn = f1 * f2;
	std::cout << std::endl << num1 << "/" << denom1 << " * " << num2 << "/" << denom2 << " = ";
	umn.print();

	del = f1 / f2;
	std::cout << std::endl << num1 << "/" << denom1 << " / " << num2 << "/" << denom2 << " = ";
	del.print();

	
	std::cout << std::endl << "++" << num1 << "/" << denom1 << " * " << num2 << "/" << denom2 << " = ";
	pref_inc = ++f1 * f2;
	pref_inc.print();
	std::cout << std::endl << "Значение дроби 1: ";	f1.print();

	
	std::cout << std::endl; f1.print(); std::cout << "++" << " + " << num2 << "/" << denom2 << " = ";
	post_inc = f1++ + f2;
	post_inc.print();
	std::cout << std::endl << "Значение дроби 1: ";
	f1.print();

	
	std::cout << std::endl << "--"; f1.print(); std::cout << " = ";
	pref_dec = --f1;
	pref_dec.print();
	
	
	std::cout << std::endl; f1.print();	std::cout << "--" << " = ";
	post_dec = f1--;
	post_dec.print();

	

	return 0;
}
