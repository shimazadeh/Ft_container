#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // Create a vector containing integers
    vector<int> v = {7, 5, 16, 8};

    // Add two more integers to vector
    cout << "max_size: " << v.max_size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

    v.push_back(25);
    v.push_back(13);
    // Print out the vector
    cout << "v = { ";
	// for (auto i = 0; i != v.end(); i++)
	// 	std::cout << *i << ",";
    cout << "}" << endl;
}
