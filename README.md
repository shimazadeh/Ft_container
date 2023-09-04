# Ft_container
Designed C++ container classes (vector/list/map) from ground up and free from reliance existing libraries, 
using template metaprogramming techniques, that behave exactly like the C++ 98 STL containers.

## Requirmenet and Limitations
They must have all public member functions from C++98. The corresponding iterators must also be implemented.
The project includes the following containers:
  - Vector
  - Map
  - Stack

## How to use:
The containers are templated, meaning you can use them with any type, just like you would any other STL containers. 
Just include the .hpp corresponding to the container you want to use, and use it! The difference is the namespace
where you would call std::vector<T>, you now call ft::vector<T>.
<pre>
<code>
  #include "includes/vector.hpp"
  #include "includes/map.hpp"
  #include "includes/stack.hpp"
  
  // Containers are in the 'ft' namespace
  ft::vector<int> vector;
  ft::map<int, std::string> map;
  ft:stack<int> stack;
</code>
</pre>

## Sources:
  - [C++ Reference](https://cplusplus.com/reference/stl/)
  - [CPP Reference](https://en.cppreference.com/w/)
    
## Testers:
  - [containers_test by @mli42](https://github.com/mli42/containers_test)
  - [ft_container_tester by @Mazoise](https://github.com/Mazoise/42TESTERS-CONTAINERS)

