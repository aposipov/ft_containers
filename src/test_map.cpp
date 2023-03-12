
//#include "Pair.hpp"
//#include <iostream>
#include "Map.hpp"

int main()
{
	std::pair<std::string, int> pair;
	std::pair<std::string, int> pair1("std pair", 21);
	std::pair<std::string, int> pair2(pair1);

	ft::pair<std::string, int> my_pair;
	ft::pair<std::string, int> my_pair1("ft pair", 42);
	ft::pair<std::string, int> my_pair2(my_pair1);
	my_pair = my_pair1;
	my_pair = ft::make_pair("make", 999);

	std::cout << pair2.first << ", " << pair2.second << std::endl;

	std::cout << my_pair.first << ", " << my_pair.second << std::endl;
	std::cout << my_pair1.first << ", " << my_pair1.second << std::endl;
	std::cout << my_pair2.first << ", " << my_pair2.second << std::endl;
}
