// Algorithm call with predicate
// Using lambda expression
#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<int> vec{4, 2, 3, 5, 1};
	
	std::cout << "Elements of vector: ";
	
	for (auto i : vec)
		std::cout << i << ", ";
	std::cout << '\n';

    int radix;
    std::cout << "Please enter the radix: ";
    std::cin >> radix;
    if (radix == 0) {
        std::cout << "The radix is 0 which is not divisible\n";
        return 0;
    }
	
	// Call std::count_if() algorithm using a lambda expression as predicate
	auto n_radix = std::count_if(vec.begin(), vec.end(), 
	
		// The lambda definition goes inside the call!
		[radix] (int n)
		{ 
			return (n % radix == 0);
		}
	);

	std::cout << "The vector has " << n_radix << " element(s) with radix values\n";

    return 0;
}