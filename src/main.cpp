#include <iostream>
#include "../inc/vector.hpp"
#include "../inc/map.hpp"
#include "../inc/stack.hpp"

int map_test();
int vector_test();
int stack_test();

#include "../tester-3/srcs/map/common.hpp"
#include <list>

#define T1 char
#define T2 foo<std::string>

int main()
{
	// vector_test();
	// stack_test();
	// map_test();
	//debugging testers
	TESTED_NAMESPACE::map<T1, T2> mp;

	mp['a'] = "an element";
	mp['b'] = "another element";
	mp['c'] = mp['b'];
	mp['b'] = "old element";

	printSize(mp);

	std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

	printSize(mp);
return (0);
}
