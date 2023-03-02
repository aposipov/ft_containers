
#include <iostream>
#include <vector>

#include "Vector.hpp"

int main()
{
	std::vector<int> v;
	std::vector<int> second(4, 100);
	std::allocator<int> alloc;
	ft::vector<int> myv(4);
	ft::vector<int> twince(10);

//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//		std::cout << "[" << i + 10 << "] = " << v[i + 10] << std::endl;
//		std::cout << "size = " << v.size() << std::endl;
//		std::cout << "capacity = " << v.capacity() << std::endl;
//	}

	second.at(2) = 33;
	second[3] = 21;
//	std::cout << "capacity = " << v.get_allocator() << std::endl;
	std::cout << "size = " << second.size() << std::endl;
	std::cout << "capacity = " << second.capacity() << std::endl;
	std::cout << "pointer = " << second.data() << std::endl;
	std::cout << "at = " << second.at(1) << std::endl;
	std::cout << "[]  = " << second[3] << std::endl;
	std::cout << "max size  = " << second.max_size() << std::endl;
	std::cout << "capacity  = " << second.capacity() << std::endl;
	// reserve;
//	std::allocator<int>::pointer

	myv[1] = 42;
	std::cout << "*size = " << myv.size() << std::endl;
	std::cout << "*[] = " << myv[1] << std::endl;
	std::cout << "*at = " << myv.at(0) << std::endl;
	std::cout << "*front = " << myv.front() << std::endl;
	std::cout << "*max size  = " << myv.max_size() << std::endl;
	std::cout << "*capacity  = " << myv.capacity() << std::endl;
	myv.reserve(6);
	std::cout << "*capacity  = " << myv.capacity() << std::endl;
	myv.push_back(99);
	std::cout << "*size = " << myv.size() << std::endl;
	std::cout << "*back = " << myv.back() << std::endl;
	std::cout << "*capacity  = " << myv.capacity() << std::endl;
	std::cout << "*at = " << myv.at(4) << std::endl;
	myv.push_back(101);
	std::cout << "*at = " << myv.at(5) << std::endl;
	std::cout << "*size = " << myv.size() << std::endl;
	myv.push_back(109);
	std::cout << "*at = " << myv.at(6) << std::endl;
	std::cout << "*size = " << myv.size() << std::endl;
	std::cout << "*capacity  = " << myv.capacity() << std::endl;
	myv.pop_back();
//	std::cout << "*at = " << myv.at(6) << std::endl;
	std::cout << "*size = " << myv.size() << std::endl;
//	ft::vector<int> myv2(twince);
	ft::vector<int> ex(twince);
	std::cout << "*ex = " << ex.size() << std::endl;
	myv = twince;
	std::cout << "*size = " << myv.size() << std::endl;
	myv.assign(99, 33);
	std::cout << "*size = " << myv.size() << std::endl;
	std::cout << "*at = " << myv.at(6) << std::endl;
	return 0;
}