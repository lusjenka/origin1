#include <iostream>
#include <vector>
#include <algorithm>

struct count {
public:
	int counter;
	int sum = 0;
public:
	count() : counter{ 0 } {}
	void operator()(int x) {
		if (x % 3 == 0)
		{
			counter++;
			sum += x;
		}
		
		//return a + b;
	}
};
int main() {
	count cn;
	std::vector<int> v6{ 4, 1, 3, 6, 25, 54 };
	cn = std::for_each(v6.begin(), v6.end(), count());

	std::cout << "get_sum(): " << cn.sum << "\nget_count() " << cn.counter;
	
	return 0;
}