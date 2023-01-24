#include "../inc/stack.hpp"

using namespace ft;
template <typename T, typename Container>
void	print_stack(ft::stack<T, Container>	_stack, std::string msg)
{
	size_t	size = _stack.size();
	std::cout << msg << ": {";
	for(size_t i = 0; i < size; i++)
	{
		std::cout << _stack.top() << ",";
		_stack.pop();
	}
	std::cout << "}" << std::endl;
}

int stack_test()
{
	//testing basics
	ft::stack<int>	test1;
	ft::stack<int>	test2;

	for (size_t i = 0; i < 10; i++)
		test1.push(i);
	for (size_t i = 0; i < 5; i++)
		test2.push(i);

    std::cout << "stack1 info: " << std::endl;
    std::cout << "size is: " << test1.size() << std::endl;
    std::cout << "top of the stack is: " << test1.top() << std::endl;
    std::cout << "is empty?: " << test1.empty() << std::endl;
	print_stack(test1, "stack1");

    std::cout << "stack2 info: " << std::endl;
    std::cout << "size is: " << test2.size() << std::endl;
    std::cout << "top of the stack is: " << test2.top() << std::endl;
    std::cout << "is empty?: " << test2.empty() << std::endl;
	print_stack(test2, "stack2");
	return (0);
}
