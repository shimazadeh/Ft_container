#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // Create a vector containing integers
    vector<int> v = {7, 5, 16, 8};
    vector<int>::iterator   it;

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

// #include <iostream>
// #include <map>
// #include <iterator>
// using namespace std;

// int main ()
// {
//   std::map<char,int> foo,bar;
//   std::_Rb_tree_iterator<std::pair<const char, int>> it;

//   foo['a']=100;
//   foo['b']=1000;
//   foo['c'] = 1;

//   for (std::_Rb_tree_iterator<std::pair<const char, int>> i = foo.begin(); i != foo.end(); i++)
//   {
//     std::cout << i._M_node << std::endl;
//   }

//   // bar['a']=100;
//   // bar['b']=1000;

//   // // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//   // if (foo==bar) std::cout << "foo and bar are equal\n";
//   // if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   // if (foo< bar) std::cout << "foo is less than bar\n";
//   // if (foo> bar) std::cout << "foo is greater than bar\n";
//   // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }


#include "./RedBlackTree/RBtree_node.hpp"
#include "./RedBlackTree/RBtree.hpp"
#include "./RedBlackTree/RBtree_iterator.hpp"
#include "./RedBlackTree/RBtree_ReverseIterator.hpp"
#include "map.hpp"

using namespace ft;

int main ()
{
  map<char,int> foo;
  map<char,int> bar;
  map<char, int>::reverse_iterator  it, ite;


  foo['a']= 100;
  foo['b']= 1000;
  foo['c'] = 1;

  // bar['a']= 100;
  // bar['b']= 1000;
  // bar['c'] = 1;

  it = foo.rbegin();
  ite = foo.rend();

  // map<char, int>::iterator  temp = foo.find('c');
  // std::cout << it.is_end;
  // std::cout << *ite << std::endl;
  // std::cout << *it << std::endl;
  std::cout << *it << std::endl;
  std::cout << *ite << std::endl;
  for (map<char, int>::reverse_iterator i = ite; i != it; ++i)
    std::cout << *i << std::endl;

  map<char, int>::iterator  is, ie;
  is = foo.begin();
  ie = foo.end();

  for (map<char, int>::iterator i = is; i != ie; i++)
    std::cout << *i << std::endl;



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
