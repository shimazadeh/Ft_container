// #include <vector>
// #include <iostream>

// using namespace std;

// int main()
// {
//     // Create a vector containing integers
//     vector<int> v = {7, 5, 16, 8};

//     // Add two more integers to vector
//     cout << "max_size: " << v.max_size() << endl;
//     cout << "capacity: " << v.capacity() << endl;
//     cout << "size: " << v.size() << endl;

//     v.push_back(25);
//     v.push_back(13);
//     // Print out the vector
//     cout << "v = { ";
// 	// for (auto i = 0; i != v.end(); i++)
// 	// 	std::cout << *i << ",";
//     cout << "}" << endl;
// }

// #include <iostream>
// #include <map>

// int main ()
// {
//   std::map<char,int> foo,bar;
//   foo['a']=100;
//   foo['b']=1000;
//   foo['c'] = 1;

//   bar['a']=100;
//   bar['b']=1000;

//   // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }


#include "./RedBlackTree/RBtree_node.hpp"
#include "./RedBlackTree/RBtree.hpp"
#include "./RedBlackTree/RBtree_iterator.hpp"
#include "map.hpp"

using namespace ft;

int main ()
{
  map<char,int> foo;
  map<char,int> bar;
  map<char, int>::iterator  it, ite;

  foo['a']= 100;
  foo['b']= 1000;
  foo['c'] = 1;

  bar['a']= 100;
  bar['b']= 1000;
  // bar['c'] = 1;

  it = foo.begin();
  ite = foo.end();

  // std::cout << ite.is_end << std::endl;
  // std::cout << it.is_end << std::endl;

  for (map<char, int>::iterator i = it; i != ite; i++)
  {
    std::cout << *i << std::endl;
  }

  // foo.print_tree();
  // bar.print_tree();

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  // if (foo == bar) std::cout << "foo and bar are equal\n";
  // if (foo!=bar) std::cout << "foo and bar are not equal\n";
  // if (foo< bar) std::cout << "foo is less than bar\n";
  // if (foo> bar) std::cout << "foo is greater than bar\n";
  // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
  return 0;
}
