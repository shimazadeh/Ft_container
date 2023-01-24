#include "../inc/vector.hpp"
#include "../inc/stack.hpp"

using namespace ft;

template <typename T>
void	print_vector(ft::vector<T>	_vector, std::string msg)
{
	std::cout << msg << ": {";
	for(typename ft::vector<T>::iterator i = _vector.begin(); i != _vector.end(); i++)
		std::cout << *i << ",";
	std::cout << "}" << std::endl;
}

int vector_test()
{
    // testing default constructor + insert + push_back + iterator + basic getters
	ft::vector<int>	test1;

	for (size_t i = 0; i < 10; i++)
	{
		test1.insert(test1.begin(), 3);
		test1.push_back(i);
	}
    std::cout << "test1 vector info: " << std::endl;
    std::cout << "max_size: " << test1.max_size() << std::endl;
    std::cout << "capacity: " << test1.capacity() << std::endl;
    std::cout << "size: " << test1.size() << std::endl;
    std::cout << "is empty?: " << test1.empty() << std::endl;

	std::cout << "begin is " << *(test1.begin()) << " end is " << *(test1.end() - 1) << std::endl;
	print_vector(test1, "test1 v");

	// //testing at + operator[] + front + back
	try
	{
		std::cout << "test1 front: " << test1.front() << std::endl;
		std::cout << "test1 back: " << test1.back() << std::endl;
		std::cout << "test1 at 4: " << test1. at(4) << std::endl;
		std::cout << "test1[4]: " << test1[4] << std::endl;
		std::cout << "test1 at 0: " << test1. at(0) << std::endl;
		std::cout << "test1[0]: " << test1[0] << std::endl;
		std::cout << "test1 at 9: " << test1. at(9) << std::endl;
		std::cout << "test1[9]: " << test1[9] << std::endl;
		std::cout << "test1 at 100: " << test1.at(100) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//testing copy constructor
	ft::vector<int>	test2(test1.begin(), test1.end());

	print_vector(test2, "test2 v");

	//testing constructor + assign function
	ft::vector<int>	test3(2, 17);

	print_vector(test3, "test3 original v");

	test3.clear();
	test3.assign(test2.begin(), test2.end());

	print_vector(test3, "assigning test2 to test3 vector: v");

	test3.assign(5, 18);
	print_vector(test3, "replacing test3 by 5 18s: v");

	//testing erase + operator= + swap + resize
	ft::vector<int>	test4(5, 90);

	print_vector(test1, "test1 before swap v");
	print_vector(test4, "test4 before swap v");

	test4.swap(test1);

	print_vector(test1, "test1 after swap v");
	print_vector(test4, "test4 after swap v");

	test1.erase(test1.begin(), test1.begin() + 2);

	print_vector(test1, "test1 after erase v:");

	// testing reverse iterator && underlying expand

	ft::vector<int>	test5(5, 1);
	for (int i = 0; i < 1; i++)
		test5.push_back(i);
	print_vector(test5, "test5: in order");
	std::cout << "reverse start: " <<  *(test5.rbegin()) << std::endl;
	std::cout << "reverse end: " << *(--test5.rend()) << std::endl;
	std::cout << "printing test5 using rev it: {";
	for(ft::vector<int>::reverse_iterator i = test5.rbegin(); i != test5.rend(); i--)
		std::cout << *i << ",";
	std::cout << "}" << std::endl;

	return (0);
}
