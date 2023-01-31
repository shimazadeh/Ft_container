#include "../inc/map.hpp"

// using namespace ft;

// template <typename Key, typename T>
// void	print_map(ft::map<Key, T>	_map, std::string msg)
// {
// 	std::cout << msg << ": ";
// 	for(typename ft::map<Key, T>::iterator i = _map.begin(); i != _map.end(); i++)
// 		std::cout << "(" << i->first << "," << i->second << "), ";
//   std::cout << std::endl;
// }

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


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;


#include <map>
#include <cstdio>
#include <iomanip>


template <class Key, class T>
void	print(map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int map_test()
{
    // std::cout << "=====TESTER BUG FIXED================"
  {
      std::cout << _WHITE << "# test_map" << _END << std::endl;
      std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
      std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
      std::cout << "/* ********************************************************************** */" << _END << std::endl;
      std::cout << std::endl;

      map<std::string, int> mymap;
      print(mymap);

      std::cout << "mymap<" << _PURPLE << "string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

      std::cout << std::endl;
      std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
      print(mymap);
      std::cout << std::endl;

      print(mymap);
      mymap.insert(pair<std::string, int>("ft", 42));

      print(mymap);
      mymap.insert(pair<std::string, int>("one", 1));

      std::cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
      map<std::string, int>::iterator mit;
      map<std::string, int>::iterator it;
      print(mymap);
      it = mymap.lower_bound("aaa");
      print(mymap);
      std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
      std::cout << std::endl;
      print(mymap);
      it = mymap.lower_bound("one");
      print(mymap);
      std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
      std::cout << std::endl;
      print(mymap);
      it = mymap.lower_bound("oae");
      print(mymap);
      std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
      std::cout << std::endl;
      print(mymap);
      it = mymap.lower_bound("ft");
      print(mymap);
      std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
      std::cout << std::endl;
      print(mymap);
      it = mymap.lower_bound("zzz");
      print(mymap);

      if (it == mymap.end())
        std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
      std::cout << std::endl;
      print(mymap);
      it = mymap.upper_bound("aaa");

      print(mymap);
      std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
      std::cout << std::endl;
      print(mymap);
      it = mymap.upper_bound("oae");
      print(mymap);
      std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
      std::cout << std::endl;
      print(mymap);
      it = mymap.upper_bound("one");

      if (it == mymap.end())
        std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
      print(mymap);
      std::cout << std::endl;
      it = mymap.upper_bound("ft");
      print(mymap);
      std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
      std::cout << std::endl;
      print(mymap);
      it = mymap.upper_bound("zzz");

      if (it == mymap.end())
        std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
      print(mymap);
      std::cout << std::endl;

      print(mymap);
      mymap.erase("undefined");
      print(mymap);
      mymap.erase("ft");
      print(mymap);
      std::cout << _WHITE << "# double clear" << _END << std::endl;
      mymap.clear();
      print(mymap);
      mymap.clear();
      print(mymap);
      mymap["lol"];
      print(mymap);
      mymap.insert(pair<std::string, int>("xD", 123));
      print(mymap);
      mymap.insert(mymap.end(), pair<std::string, int>("uch", 442));
      print(mymap);
      mymap.insert(mymap.begin(), pair<std::string, int>("uch", 22));
      print(mymap);
      mymap.insert(mymap.end(), pair<std::string, int>("uch", 23));
      print(mymap);
      mymap.insert(pair<std::string, int>("uch", 23));
      print(mymap);
      mymap["lol"] = 8;


      print(mymap);
      map<std::string, int> map2;

      print(mymap);
      print(map2);
      std::cout << "mymap<" << _PURPLE << "string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
      print(mymap);
      std::cout << "empty line\n";
      print(map2);
      std::cout << "empty line2\n";

      swap(mymap, map2);
      std::cout << "empty line3\n";
      print(mymap);
      std::cout << "empty line4\n";
      print(map2);
      std::cout << "empty line5\n";

      mymap = map2;
      print(mymap);
      print(map2);

      std::cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl;
      print(mymap);
      print(map2);
      std::cout << std::endl;

      mymap.clear();
      print(mymap);
      print(map2);

      mymap["satan"] = 666;
      print(mymap);
      print(map2);
      std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
      print(mymap);
      print(map2);
      std::cout << std::endl;
      std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
      print(mymap);
      print(map2);
      std::cout << std::endl;
      std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
      print(mymap);
      print(map2);
      std::cout << std::endl;
      std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
      print(mymap);
      print(map2);
      std::cout << std::endl;
      std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
      print(mymap);
      print(map2);
      std::cout << std::endl;
    return (0);
  }
  //insert debugging
  // {
  //   map<char,int> mymap;

  //   // first insert function version (single parameter):
  //   mymap.insert ( pair<char,int>('a',100) );
  //   mymap.insert ( pair<char,int>('z',200) );

  //   pair<map<char,int>::iterator,bool> ret;
  //   ret = mymap.insert ( pair<char,int>('z',500) );
  //   if (ret.second==false) {
  //     std::cout << "element 'z' already exists";
  //     std::cout << " with a value of " << ret.first->second << '\n';
  //   }

  //   // second insert function version (with hint position):
  //   map<char,int>::iterator it = mymap.begin();
  //   mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
  //   mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

  //   // third insert function version (range insertion):
  //   map<char,int> anothermap;
  //   std::cout << "find is " << mymap.find('c')->first << std::endl;
  //   anothermap.insert(mymap.begin(),mymap.find('c'));

  //   // showing contents:
  //   std::cout << "mymap contains:\n";
  //   for (it=mymap.begin(); it!=mymap.end(); ++it)
  //     std::cout << it->first << " => " << it->second << '\n';

  //   std::cout << "anothermap contains:\n";
  //   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
  //     std::cout << it->first << " => " << it->second << '\n';

  //   return (0);
  // }
  // std::cout << "===========================================================TEST0: BASIC CONSTRUCTOR, OPERATOR[], ITER, REV_ITER (WITH ++ & --)=================================================================" << std::endl;
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

  //   // std::cout << "printing with const iterator forward" << std::endl;
  //   // for (map<char, int>::const_iterator i = foo.begin(); i != foo.end(); i++)
  //   //   std::cout << i->first << ", " << i->second << " " << i.get_isend() << std::endl;


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

  // }

  // std::cout << "=================================================================================TEST1: MAP COMPARISON=========================================================================================" << std::endl;
  // {
  //   std::cout << "FOO and BAR have same size , key and value" << std::endl;
  //   {
  //     map<char,int> foo;
  //     map<char,int> bar;

  //     foo['a']= 1;
  //     foo['b']= 1000;
  //     foo['c'] = 1;

  //     bar['a']= 1;
  //     bar['b']= 1000;
  //     bar['c'] = 1;

  //     if (foo == bar) std::cout << "                -foo and bar are equal\n";
  //     if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
  //     if (foo< bar) std::cout << "                -foo is less than bar\n";
  //     if (foo> bar) std::cout << "                -foo is greater than bar\n";
  //     if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
  //     if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
  //   }

  //   std::cout << "FOO and BAR have same size , key but foo last value is greater" << std::endl;
  //   {
  //     map<char,int> foo;
  //     map<char,int> bar;

  //     foo['a']= 1;
  //     foo['b']= 1000;
  //     foo['c'] = 6;

  //     bar['a']= 1;
  //     bar['b']= 1000;
  //     bar['c'] = 1;

  //     if (foo == bar) std::cout << "                -foo and bar are equal\n";
  //     if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
  //     if (foo< bar) std::cout << "                -foo is less than bar\n";
  //     if (foo> bar) std::cout << "                -foo is greater than bar\n";
  //     if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
  //     if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
  //   }

  //   std::cout << "FOO and BAR have same size , value but foo last key value is greater" << std::endl;
  //   {
  //     map<char,int> foo;
  //     map<char,int> bar;

  //     foo['a']= 1;
  //     foo['b']= 1000;
  //     foo['d'] = 1;

  //     bar['a']= 1;
  //     bar['b']= 1000;
  //     bar['c'] = 1;

  //     if (foo == bar) std::cout << "                -foo and bar are equal\n";
  //     if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
  //     if (foo< bar) std::cout << "                -foo is less than bar\n";
  //     if (foo> bar) std::cout << "                -foo is greater than bar\n";
  //     if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
  //     if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
  //   }

  //   std::cout << "FOO has one extra element than bar" << std::endl;
  //   {
  //     map<char,int> foo;
  //     map<char,int> bar;

  //     foo['a']= 1;
  //     foo['b']= 1000;
  //     foo['c'] = 1;
  //     foo['d'] = 0;

  //     bar['a']= 1;
  //     bar['b']= 1000;
  //     bar['c'] = 1;

  //     if (foo == bar) std::cout << "                -foo and bar are equal\n";
  //     if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
  //     if (foo< bar) std::cout << "                -foo is less than bar\n";
  //     if (foo> bar) std::cout << "                -foo is greater than bar\n";
  //     if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
  //     if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
  //   }


  // }

  // std::cout << "===============================================================TEST2: INSERT, ERASE, FIND , LOWER BOUND, UPPER BOUND===========================================================================" << std::endl;
  // {
  //   map<char,int> test0;
  //   map<char, int> test1;
  //   map<char, int> test2;

  //   test1['a'] = 0;
  //   test1['b'] = 2;
  //   test1['c'] = 3;

  //   test0.insert(test1.begin(), test1.end());//insert with two iterator
  //   test0.insert(test0.find('a'), *(test1.find('a')));//repetative element

  //   test1['d'] = 4;
  //   test0.insert(test0.find('c'), *(test1.find('d')));//actual element

  //   test0.print_tree("before erase: test0");
  //   test1.print_tree("before erase: test1");

    // std::cout << "count of a in test0" << test0.count('a') << std::endl;
    // std::cout << "lower bound of a in test1" << test1.lower_bound('a')->first << std::endl;
    // std::cout << "upper bound of c in test1" << test1.upper_bound('c')->first << std::endl;

    // test2 = test0;
    // test2.print_tree("before erase: test2");

    // test1.erase('a');//deleting a leaf
    // test0.erase('b');//deleting the root /a node with two child
    // test2.erase('c');//deleting a middle member

    // test0.print_tree("after erase of b: test0");
    // test1.print_tree("after erase of a: test1");
    // test2.print_tree("after erase of c: test2");
  //   return (0);
  // }
  // std::cout << "====================================================================TEST3: SWAP=========================================================================================" << std::endl;
  // {
  //   map<char,int>   test0;
  //   map<char, int>  test1;

  //   test1['3'] = 1;
  //   test1['2'] = 2;
  //   test1['1'] = 3;

  //   std::cout << "swaping empty to nonempty" << std::endl;
  //   test0.print_tree("before first swap: test0");
  //   test1.print_tree("before first swap: test1");

  //   test0.swap(test1);

  //   test0.print_tree("after first swap: test0");
  //   test1.print_tree("after first swap: test1");

  //   test1['4'] = 1;
  //   test1['5'] = 2;
  //   test1['6'] = 3;

  //   std::cout << "swaping nonempty to nonempty" << std::endl;
  //   test0.print_tree("before second swap: test0");
  //   test1.print_tree("before second swap: test1");

  //   test0.swap(test1);

  //   test0.print_tree("after second swap: test0");
  //   test1.print_tree("after second swap: test1");

  // }
  // std::cout << "===============================================================TEST4: SAME TYPE PAIR =====================================================================================" << std::endl;
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
  //   test1.print_tree("test1");
  // }
  // return 0;
}

/*

int tab[5] = {1, 2, 3, 4, 5};
int *last_elem = &tab[4];

int tab2 = tab;
{
  int newTab[5];
  for (int i = 0; i < 5; ++i)
  {
    newTab[i] = tab[i];
  }
  NEWlast_elem = &newTab[4];
}



*/
