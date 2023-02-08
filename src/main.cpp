#include "../inc/ft_container.hpp"

int main()
{
    clock_t time_req;

    time_req = clock();
	vector_test();
	stack_test();
	map_test();

    time_req = clock() - time_req;
    std::cout << "total processing time: " << (float)time_req/CLOCKS_PER_SEC << std::endl;
    return (0);
}

