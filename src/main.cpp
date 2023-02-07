#include "../inc/ft_container.hpp"

struct timespec std_start;
struct timespec ft_start;

double   std_time_calculator(void)
{
    struct timespec end;
    double time_taken;

    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - std_start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - std_start.tv_nsec)) * 1e-9;
    std::cout << "<<< " << std::fixed << time_taken << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &std_start);
    return(time_taken);
}

double    ft_time_calculator(void)
{
    struct timespec end;
    double time_taken;

    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - ft_start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - ft_start.tv_nsec)) * 1e-9;
    std::cout << "<<< " << std::fixed << time_taken << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &ft_start);
    return(time_taken);
}

std::string    time_is_ok ( long double ft_t, long double std_t)
{
    if(ft_t < (std_t * 20))
        return("ok");
    else
        return("ko");
}

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

