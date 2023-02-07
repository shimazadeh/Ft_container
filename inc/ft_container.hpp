#ifndef _FT_CONTAINER_HPP
#define _FT_CONTAINER_HPP
#include <iostream>

#if 1 //create a
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../inc/vector.hpp"
	#include "../inc/map.hpp"
	#include "../inc/stack.hpp"
#endif

int map_test();
int vector_test();
int stack_test();
using namespace ft;

#endif
