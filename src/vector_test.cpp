#include "../inc/vector.hpp"
#include "../inc/stack.hpp"

using namespace ft;

int vector_test()
{
    // Create a vector containing integers
	ft::vector<int>	testedVector;
	size_t			numberOfPushes = 10;

	for (size_t i = 0; i < numberOfPushes; i++)
	{
		printf("i is %lu\n", i);
		// testedVector.insert(testedVector.begin(), i);
		testedVector.push_back(i);
	}

	std::cout << "begin is " << *(testedVector.begin()) << "end is " << *(testedVector.end() - 1) << std::endl;
	std::cout << "original v = {";
	for(ft::vector<int>::iterator i = testedVector.begin(); i != testedVector.end(); i++)
		std::cout << *i << ",";
	std::cout << "}" << std::endl;

	ft::vector<int>	test2(testedVector.begin(), testedVector.end());
	// testedVector.clear();
	std::cout << "copy v = {";
	for(ft::vector<int>::iterator i = test2.begin(); i != test2.end(); i++)
		std::cout << *i << ",";
	std::cout << "}" << std::endl;



	// std::cout << "v = { ";
	// for(ft::vector<int>::reverse_iterator i = test2.rbegin(); i != test2.rend(); i++)
	// 	// std::cout << *i << ",";
	// std::cout << "}" << std::endl;

    // vector<int> v (1, 4);
    // vector<int>::iterator   it;

    // std::cout << "max_size: " << v.max_size() << std::endl;
    // std::cout << "capacity: " << v.capacity() << std::endl;
    // std::cout << "size: " << v.size() << std::endl;

    // // Add two more integers to vector
    // v.push_back(25);
    // v.push_back(13);

    // // Print out the vector
    // std::cout << "v = { ";
	// // for (ft::vector<int>::iterator i = 0; i != v.end(); i++)
	// // 	std::cout << *i << ",";
    // std::cout << "}" << std::endl;
	return (0);
}

// #include <vector>
// #include <stdio.h>
// #include <iostream>

// using namespace std;

// int vector_test()
// {
//     // Create a vector containing integers
// 	vector<int>	testedVector;
// 	size_t			numberOfPushes = 10;

// 	for (size_t i = 0; i < numberOfPushes; i++)
// 	{
// 		// testedVector.insert(testedVector.begin(), i);
// 		testedVector.push_back(i);
// 	}

// 	std::cout << "v = {";
// 	for(vector<int>::iterator i = testedVector.begin(); i != testedVector.end(); i++)
// 		std::cout << *i << ",";
// 	std::cout << "}" << std::endl;

// 	return (0);
// }

