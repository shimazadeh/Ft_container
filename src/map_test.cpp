#include "../inc/ft_container.hpp"

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
  std::cout << "=========================================================== MAP TEST =================================================================" << std::endl;
  std::cout << "===========================================================TEST0: BASIC CONSTRUCTOR, OPERATOR[], ITER, REV_ITER (WITH ++ & --)=================================================================" << std::endl;
  {
    map<char,int> foo;
    map<char,int> bar;

    foo['a']= 1;
    foo['b']= 1000;
    foo['c'] = 6;

    bar['a']= 1;
    bar['b']= 1000;
    bar['c'] = 1;

    map<char, int>::iterator  it, ite;

    it = foo.begin();
    ite = foo.end();
    std::cout << "begin iterator is : " << it->first << ", " << it->second << std::endl;
    std::cout << "end iterator is: " << ite->first << ", " << ite->second << std::endl;

    std::cout << "printing with iterator forward" << std::endl;
    for (map<char, int>::iterator i = it; i != ite; i++)
      std::cout << i->first << ", " << i->second << std::endl;

    std::cout << "printing with iterator backward" << std::endl;
    for (map<char, int>::iterator i = ite; i != it; i--)
    {
        std::cout << i->first << ", " << i->second  << std::endl;
    }

    std::cout << "printing with const iterator forward" << std::endl;
    for (map<char, int>::const_iterator i = foo.begin(); i != foo.end(); i++)
      std::cout << i->first << ", " << i->second << std::endl;

    map<char, int>::reverse_iterator  is, ise;

    is = foo.rbegin();
    ise = foo.rend();

    std::cout << "rend is: " << ise->first << ", " << ise->second << std::endl;
    std::cout << "rbegin is: " << is->first <<  ", " << is->second << std::endl;

    std::cout << "printing with rev_iter forward" << std::endl;
    for (map<char, int>::reverse_iterator i = ise; i != is; i--)
      std::cout << i->first << ", " << i->second << std::endl;

    std::cout << "printing with rev_iter backward" << std::endl;
    for (map<char, int>::reverse_iterator i = is; i != ise; i++)
      std::cout << i->first << ", " << i->second << std::endl;
  }

  std::cout << "=================================================================================TEST1: MAP COMPARISON=========================================================================================" << std::endl;
  {
    std::cout << "FOO and BAR have same size , key and value" << std::endl;
    {
      map<char,int> foo;
      map<char,int> bar;

      foo['a']= 1;
      foo['b']= 1000;
      foo['c'] = 1;

      bar['a']= 1;
      bar['b']= 1000;
      bar['c'] = 1;

      if (foo==bar) std::cout << "                -foo and bar are equal\n";
      if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
      if (foo< bar) std::cout << "                -foo is less than bar\n";
      if (foo> bar) std::cout << "                -foo is greater than bar\n";
      if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
      if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
    }

    std::cout << "FOO and BAR have same size , key but foo last value is greater" << std::endl;
    {
      map<char,int> foo;
      map<char,int> bar;

      foo['a']= 1;
      foo['b']= 1000;
      foo['c'] = 6;

      bar['a']= 1;
      bar['b']= 1000;
      bar['c'] = 1;

      if (foo==bar) std::cout << "                -foo and bar are equal\n";
      if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
      if (foo< bar) std::cout << "                -foo is less than bar\n";
      if (foo> bar) std::cout << "                -foo is greater than bar\n";
      if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
      if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
    }

    std::cout << "FOO and BAR have same size , value but foo last key value is greater" << std::endl;
    {
      map<char,int> foo;
      map<char,int> bar;

      foo['a']= 1;
      foo['b']= 1000;
      foo['d'] = 1;

      bar['a']= 1;
      bar['b']= 1000;
      bar['c'] = 1;

      if (foo==bar) std::cout << "                -foo and bar are equal\n";
      if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
      if (foo< bar) std::cout << "                -foo is less than bar\n";
      if (foo> bar) std::cout << "                -foo is greater than bar\n";
      if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
      if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
    }

    std::cout << "FOO has one extra element than bar" << std::endl;
    {
      map<char,int> foo;
      map<char,int> bar;

      foo['a']= 1;
      foo['b']= 1000;
      foo['c'] = 1;
      foo['d'] = 0;

      bar['a']= 1;
      bar['b']= 1000;
      bar['c'] = 1;

      if (foo==bar) std::cout << "                -foo and bar are equal\n";
      if (foo!=bar) std::cout << "                -foo and bar are not equal\n";
      if (foo< bar) std::cout << "                -foo is less than bar\n";
      if (foo> bar) std::cout << "                -foo is greater than bar\n";
      if (foo<=bar) std::cout << "                -foo is less than or equal to bar\n";
      if (foo>=bar) std::cout << "                -foo is greater than or equal to bar\n";
    }
  }

  std::cout << "===============================================================TEST2: INSERT, ERASE, FIND , LOWER BOUND, UPPER BOUND===========================================================================" << std::endl;
  {
    map<char,int> test0;
    map<char, int> test1;
    map<char, int> test2;

    test1['a'] = 0;
    test1['b'] = 2;
    test1['c'] = 3;

    test0.insert(test1.begin(), test1.end());//insert with two iterator
    test0.insert(test0.find('a'), *(test1.find('a')));//repetative element

    test1['d'] = 4;
    test0.insert(test0.find('c'), *(test1.find('d')));//actual element

    print_map(test0, "before erase: test0");
    print_map(test1, "before erase: test1");

    std::cout << "count of a in test0" << test0.count('a') << std::endl;
    std::cout << "lower bound of a in test1" << test1.lower_bound('a')->first << std::endl;
    std::cout << "upper bound of c in test1" << test1.upper_bound('c')->first << std::endl;

    test2 = test0;
    print_map(test2, "before erase: test2");

    test1.erase('a');//deleting a leaf
    test0.erase('b');//deleting the root /a node with two child
    test2.erase('c');//deleting a middle member

    print_map(test0, "after erase of b: test0");
    print_map(test1, "after erase of a: test1");
    print_map(test2, "after erase of c: test2");
    return (0);
  }
  std::cout << "====================================================================TEST3: SWAP=========================================================================================" << std::endl;
  {
    map<char,int>   test0;
    map<char, int>  test1;

    test1['3'] = 1;
    test1['2'] = 2;
    test1['1'] = 3;

    std::cout << "swaping empty to nonempty" << std::endl;
    print_map(test0, "before first swap: test0");
    print_map(test1, "before first swap: test1");

    test0.swap(test1);

    print_map(test0, "after first swap: test0");
    print_map(test1, "after first swap: test1");

    test1['4'] = 1;
    test1['5'] = 2;
    test1['6'] = 3;

    std::cout << "swaping nonempty to nonempty" << std::endl;
    print_map(test0, "before second swap: test0");
    print_map(test1, "before second swap: test1");

    test0.swap(test1);

    print_map(test0, "after second swap: test0");
    print_map(test1, "after second swap: test1");
  }
  std::cout << "===============================================================TEST4: SAME TYPE PAIR =====================================================================================" << std::endl;
  {
    map<char,char>   test0;
    map<char, char>  test1;

    test1['3'] = '1';
    test1['2'] = '2';
    test1['1'] = '3';

    test0['4'] = '1';
    test0['5'] = '2';
    test0['6'] = '3';

    ft::map<char, char>::iterator tmp = test1.begin()++;
    print_map(test0, "before Insert: test0");

    test0.insert(test1.begin(), tmp++);

    print_map(test0, "after Insert: test0");
  }
  return 0;
}
