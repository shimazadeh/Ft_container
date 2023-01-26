#include "../inc/stack.hpp"

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

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

	if (test1 == test2) std::cout << "a and b are equal\n";
	if (test1 != test2) std::cout << "b and c are not equal\n";
	if (test1 < test2) std::cout << "b is less than c\n";
	if (test1 > test2) std::cout << "c is greater than b\n";
	if (test1 <= test2) std::cout << "a is less than or equal to b\n";
	if (test1 >= test2) std::cout << "a is greater than or equal to b\n";


	// std::cout << _WHITE << "# test_stack" << _END << std::endl;
	// std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	// std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	// std::cout << "/* ********************************************************************** */" << _END << std::endl;
	// stack<int> mystack;

	// std::cout << "stack<" << _PURPLE << "int" << _END << "> mystack" << std::endl;
	// std::cout << std::endl;


	// std::cout << _WHITE << "# empty" << _END << std::endl;
	// std::cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	// std::cout << "mystack.size(): " << mystack.size() << std::endl;
	// std::cout << _WHITE << "# one element" << _END << std::endl;
	// mystack.push(42);
	// std::cout << "mystack.push(42)" << std::endl;
	// std::cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	// std::cout << "mystack.size(): " << mystack.size() << std::endl;
	// std::cout << "mystack.top(): " << mystack.top() << std::endl;
	// std::cout << _WHITE << "# two element" << _END << std::endl;
	// mystack.push(2);
	// std::cout << "mystack.push(2)" << std::endl;
	// std::cout << "mystack.size(): " << mystack.size() << std::endl;
	// std::cout << "mystack.top(): " << mystack.top() << std::endl;
	// std::cout << _WHITE << "# pop element" << _END << std::endl;
	// mystack.pop();
	// std::cout << "mystack.pop()" << std::endl;
	// std::cout << "mystack.size(): " << mystack.size() << std::endl;
	// std::cout << "mystack.top(): " << mystack.top() << std::endl;
	// std::cout << std::endl;

	// stack<int, ft::vector<int> > mystack2;

	// std::cout << "stack<" << _PURPLE << "int" << _END << ", " << _PURPLE << "ft::vector" << _END << "> mystack2" << std::endl;
	// std::cout << std::endl;


	// std::cout << _WHITE << "# empty" << _END << std::endl;
	// std::cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	// std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	// std::cout << _WHITE << "# one element" << _END << std::endl;
	// mystack2.push(42);
	// std::cout << "mystack2.push(42)" << std::endl;
	// std::cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	// std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	// std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	// std::cout << _WHITE << "# two element" << _END << std::endl;
	// mystack2.push(2);
	// std::cout << "mystack2.push(2)" << std::endl;
	// std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	// std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	// std::cout << _WHITE << "# pop element" << _END << std::endl;
	// mystack2.pop();
	// std::cout << "mystack2.pop()" << std::endl;
	// std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	// std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	// std::cout << std::endl;

	// std::cout << _WHITE << "# test cpy and equality" << _END << std::endl;
	// stack<int>	cpystack = mystack;
	// std::cout << "stack<" << _PURPLE << "int" << _END << "> cpystack = mystack" << std::endl;
	// std::cout << std::endl;

	// std::cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;
	// cpystack.push(7);
	// std::cout << "cpystack.push(7)" << std::endl;
	// std::cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;

	return (0);
}
