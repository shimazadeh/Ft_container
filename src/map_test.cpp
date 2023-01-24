#include "../inc/map.hpp"

using namespace ft;

template <typename Key, typename T>
void	print_map(ft::map<Key, T>	_map, std::string msg)
{
	std::cout << msg << ": ";
	for(typename ft::map<Key, T>::iterator i = _map.begin(); i != _map.end(); i++)
		std::cout << "(" << i->first << "," << i->second << "), ";
  std::cout << std::endl;
}

int map_test()
{
  // std::cout << "test1: basic constructor, operator[], iter & rev-it (with ++ & --), comparison of maps" << std::endl;
  // {
  //   map<char,int> foo;
  //   map<char,int> bar;

  //   foo['a']= 1;
  //   foo['b']= 1000;
  //   foo['c'] = 6;

  //   bar['a']= 1;
  //   bar['b']= 1000;
  //   bar['c'] = 1;

  //   map<char, int>::iterator  it, ite;

  //   it = foo.begin();
  //   ite = foo.end();

  //   std::cout << "begin iterator is : "<< it.get_isend() << it->first << ", " << it->second << std::endl;
  //   std::cout << "end iterator is: " <<  ite.get_isend() << ite->first << ", " << ite->second << std::endl;

  //   std::cout << "printing with iterator forward" << std::endl;
  //   for (map<char, int>::iterator i = it; i != ite; i++)
  //     std::cout << i->first << ", " << i->second << " " << i.get_isend() << std::endl;

  //   std::cout << "printing with iterator backward" << std::endl;
  //   for (map<char, int>::iterator i = ite; i != it; i--)
  //   {
  //       std::cout << i->first << ", " << i->second << " " << i.get_isend() << std::endl;
  //   }

  //   map<char, int>::reverse_iterator  is, ise;

  //   is = foo.rbegin();
  //   ise = foo.rend();

  //   std::cout << "rend is: " << ise->first << ", " << ise->second << std::endl;
  //   std::cout << "rbegin is: " << is->first <<  ", " << is->second << std::endl;


  //   std::cout << "printing with rev_iter forward" << std::endl;
  //   for (map<char, int>::reverse_iterator i = ise; i != is; i--)
  //     std::cout << i->first << ", " << i->second << std::endl;


  //   std::cout << "printing with rev_iter backward" << std::endl;
  //   for (map<char, int>::reverse_iterator i = is; i != ise; i++)
  //     std::cout << i->first << ", " << i->second << std::endl;

  //   if (foo == bar) std::cout << "foo and bar are equal\n";
  //   if (foo!=bar) std::cout << "foo and bar are not equal\n";
  //   if (foo< bar) std::cout << "foo is less than bar\n";
  //   if (foo> bar) std::cout << "foo is greater than bar\n";
  //   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  //   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
  // }

  std::cout << "test2: insert, erase, find, lower bound, upper bound" << std::endl;
  {
    map<char,int> test0;
    map<char, int> test1;

    test1['a'] = 0;
    test1['b'] = 2;
    test1['c'] = 3;

    test0.insert(test1.begin(), test1.end());//insert with two iterator
    test0.insert(test0.find('a'), *(test1.find('a')));//repetative element

    test1['d'] = 4;
    test0.insert(test0.find('c'), *(test1.find('d')));//actual element

    test0.print_tree("before erase: test0");
    test1.print_tree("before erase: test1");

    std::cout << test0.count('a') << std::endl;
    std::cout << test1.lower_bound('a')->first << std::endl;
    std::cout << test1.upper_bound('c')->first << std::endl;

    test0.erase('a');
    // test0.erase('b');
    test0.print_tree("after erase: test0");
    test1.print_tree("after erase: test1");

    // std::cout << test0.count('a') << std::endl;
  }
  std::cout << "test3: swap" << std::endl;
  {
    map<char,int>   test0;
    map<char, int>  test1;

    test1['3'] = 1;
    test1['2'] = 2;
    test1['1'] = 3;

    std::cout << "swaping empty to nonempty" << std::endl;
    test0.print_tree("before first swap: test0");
    test1.print_tree("before first swap: test1");

    test0.swap(test1);

    test0.print_tree("after first swap: test0");
    test1.print_tree("after first swap: test1");

    // test1['4'] = 1;
    // test1['5'] = 2;
    // test1['6'] = 3;

    // std::cout << "swaping nonempty to nonempty" << std::endl;
    // test0.print_tree("before second swap: test0");
    // test1.print_tree("before second swap: test1");

    // test0.swap(test1);

    // test0.print_tree("after second swap: test0");
    // test1.print_tree("after second swap: test1");

  }
  // std::cout << "test4: same type pair" << std::endl;
  // {
  //   map<char,char>   test0;
  //   map<char, char>  test1;

  //   test1['3'] = '1';
  //   test1['2'] = '2';
  //   test1['1'] = '3';

  //   test0['4'] = '1';
  //   test0['5'] = '2';
  //   test0['6'] = '3';

  //   ft::map<char, char>::iterator tmp = test1.begin()++;
  //   test0.insert(test1.begin(), tmp++);

  //   test0.print_tree("test0");
  //   // test1.print_tree("test1");
  // }
  return 0;
}


// #include <iostream>
// #include <map>
// using namespace std;

// int map_test()
// {
//   // {
//   //   std::cout << "testing: basic constructor, operator[], iter & rev-it (with ++ & --), comparison of maps" << std::endl;
//   //   map<char,int> foo;
//   //   map<char,int> bar;

//   //   foo['a']= 1;
//   //   foo['b']= 1000;
//   //   foo['c'] = 6;

//   //   bar['a']= 1;
//   //   bar['b']= 1000;
//   //   bar['c'] = 1;

//   //   map<char, int>::iterator  it, ite;

//   //   it = foo.begin();
//   //   ite = foo.end();

//   //   std::cout << "begin iterator is : "<< it->first << ", " << it->second << std::endl;
//   //   std::cout << "end iterator is: " << ite->first << ", " << ite->second << std::endl;

//   //   std::cout << "printing with iterator forward" << std::endl;
//   //   for (map<char, int>::iterator i = it; i != ite; i++)
//   //     std::cout << i->first << ", " << i->second << " " << std::endl;

//   //   std::cout << "printing with iterator backward" << std::endl;
//   //   for (map<char, int>::iterator i = ite; i != it; i--)
//   //   {
//   //       std::cout << i->first << ", " << i->second << " " << std::endl;
//   //   }

//   //   map<char, int>::reverse_iterator  is, ise;

//   //   is = foo.rbegin();
//   //   ise = foo.rend();

//   //   std::cout << "rend is: " << ise->first << ", " << ise->second << std::endl;
//   //   std::cout << "rbegin is: " << is->first <<  ", " << is->second << std::endl;


//   //   std::cout << "printing with rev_iter forward" << std::endl;
//   //   for (map<char, int>::reverse_iterator i = ise; i != is; i--)
//   //     std::cout << i->first << ", " << i->second << std::endl;


//   //   std::cout << "printing with rev_iter backward" << std::endl;
//   //   for (map<char, int>::reverse_iterator i = is; i != ise; i++)
//   //     std::cout << i->first << ", " << i->second << std::endl;
//   //   // foo.print_tree();
//   //   // bar.print_tree();

//   //   if (foo == bar) std::cout << "foo and bar are equal\n";
//   //   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   //   if (foo< bar) std::cout << "foo is less than bar\n";
//   //   if (foo> bar) std::cout << "foo is greater than bar\n";
//   //   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   //   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//   // }
//   std::cout << "test2: insert, find, lower bound, upper bound" << std::endl;
//   {
//     map<char,int> test0;
//     map<char, int> test1;

//     test1['a'] = 0;
//     test1['b'] = 2;
//     test1['c'] = 3;

//     test0.insert(test1.begin(), test1.end());//insert with two iterator
//     test0.insert(test0.find('a'), *(test1.find('a')));//repetative element

//     test1['d'] = 4;
//     test0.insert(test0.find('c'), *(test1.find('d')));//actual element

//     // test0.print_tree("test0");
//     // test1.print_tree("test1");

//     std::cout << test0.count('a') << std::endl;
//     std::cout << test1.lower_bound('a')->first << std::endl;
//     std::cout << test1.upper_bound('d')->first << std::endl;
//     // test0.print_tree("before erase: test0");

//     // test0.erase('a');
//     // test0.print_tree("after erase: test0");

//     // std::cout << test0.count('a') << std::endl;

//   }
//   return 0;
// }
