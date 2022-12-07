#include "vector.hpp"

int main()
{
    // Create a vector containing integers
    vector<int> v = {7, 5, 16, 8};

    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);

    // Print out the vector
    std::cout << "v = { ";
	for (int i = 0; i != vector.end(); i++)
		std::cout << *i << ",";
    std::cout << "}" << std::endl;
}
