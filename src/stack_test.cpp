#include "../inc/ft_container.hpp"

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
	std::cout << "========================================= STACK TEST ========================================" << std::endl;

	ft::stack<int>	test1;
	ft::stack<int>	test2;

	for (size_t i = 0; i < 10; i++)
		test1.push(i);
	for (size_t i = 0; i < 5; i++)
		test2.push(i);

	if (test1 == test2) std::cout << "test1 and test2 are equal\n";
	if (test1 != test2) std::cout << "test1 and test2 are not equal\n";
	if (test1 < test2) std::cout << "test1 is less than test2\n";
	if (test1 > test2) std::cout << "test1 is greater than test2\n";
	if (test1 <= test2) std::cout << "test1 is less than or equal to test2\n";
	if (test1 >= test2) std::cout << "test1 is greater than or equal to test2\n";

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
