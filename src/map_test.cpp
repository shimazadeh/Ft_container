#include "../inc/RedBlackTree/RBtree_node.hpp"
#include "../inc/RedBlackTree/RBtree.hpp"
#include "../inc/RedBlackTree/RBtree_iterator.hpp"
#include "../inc/RedBlackTree/RBtree_ReverseIterator.hpp"
#include "../inc/map.hpp"

using namespace ft;

int map_test()
{
  map<char,int> foo;
  map<char,int> bar;
  map<char, int>::reverse_iterator  it, ite;


  foo['a']= 100;
  foo['b']= 1000;
  foo['c'] = 1;

  bar['a']= 100;
  bar['b']= 1000;
  bar['c'] = 1;

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
  if (foo == bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
  return 0;
}
