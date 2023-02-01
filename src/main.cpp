#include <iostream>
#include "../inc/vector.hpp"
#include "../inc/map.hpp"
#include "../inc/stack.hpp"

int map_test();
int vector_test();
int stack_test();

template <typename T>
void print_vec(ft::vector <T> &v)
{
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "capacity:" << v.capacity();
    std::cout << " size:" << v.size() << std::endl;
    std::cout << std::endl;
}

int main()
{
	// vector_test();
	// stack_test();
	// map_test();
	//debugging testers

    ft::vector<int> v(5,6);
    ft::vector<int> w(4,6);
    print_vec(v);
    print_vec(w);
    std::cout << "v < w ? " << (v < w) << std::endl;
    std::cout << "w < v ? " << (v < w) << std::endl;
    v.clear();
    w.clear();
    for (size_t i = 0; i < 5; i++){
        if (i==4)
            v.push_back(2);
        else
            v.push_back(i);
        w.push_back(i);
    }
    print_vec(v);
    print_vec(w);
    std::cout << "v < w ? " << (v < w) << std::endl;
    std::cout << "w < v ? " << (v < w) << std::endl;
    ft::vector<int> x;
    print_vec(v);
    print_vec(x);
    std::cout << "v < x ? " << (v < x) << std::endl;
    std::cout << "x < v ? " << (x < v) << std::endl;
	return (0);
}
