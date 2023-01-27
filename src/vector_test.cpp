#include "../inc/vector.hpp"
#include "../inc/stack.hpp"

using namespace ft;

// template <typename T>
// void	print_vector(ft::vector<T>	_vector, std::string msg)
// {
// 	std::cout << msg << ": {";
// 	for(typename ft::vector<T>::iterator i = _vector.begin(); i != _vector.end(); i++)
// 		std::cout << *i << ",";
// 	std::cout << "}" << std::endl;
// }

// int vector_test()
// {
// 	// std::cout << "==================================TEST0: default constructor + insert + push_back + iterator + basic getters =======================================" << std::endl;
// 	// {
// 	// 	ft::vector<int>	test1;
// 	// 	ft::vector<int>	test0;

// 	// 	for (size_t i = 0; i < 10; i++)
// 	// 	{
// 	// 		test1.insert(test1.begin(), 3);//This is testing if it chooses the right constructor
// 	// 		test1.push_back(i);
// 	// 	}

// 	// 	std::cout << "test1 vector info: " << std::endl;
// 	// 	std::cout << "max_size: " << test1.max_size() << std::endl;
// 	// 	std::cout << "capacity: " << test1.capacity() << std::endl;
// 	// 	std::cout << "size: " << test1.size() << std::endl;
// 	// 	std::cout << "is empty?: " << test1.empty() << std::endl;

// 	// 	std::cout << "begin() is " << *(test1.begin()) << std::endl;
// 	// 	std::cout << " end is " << *(test1.end() - 1) << std::endl;
// 	// 	std::cout << "reverse start: " <<  *(test1.rbegin()) << std::endl;
// 	// 	std::cout << "reverse end: " << *(--test1.rend()) << std::endl;

// 	// 	std::cout << "test1 using iterator forward: {";
// 	// 	for(ft::vector<int>::iterator i = test1.begin(); i != test1.end(); i++)
// 	// 		std::cout << *i << ",";
// 	// 	std::cout << "}" << std::endl;

// 	// 	std::cout << "test1 using iterator backward: {";
// 	// 	for(ft::vector<int>::iterator i = --test1.end(); i != test1.begin(); i--)
// 	// 		std::cout << *i << ",";
// 	// 	std::cout << "}" << std::endl;

// 	// 	std::cout << "test1 using rev-iterator forward: {";
// 	// 	for(ft::vector<int>::reverse_iterator i = test1.rbegin(); i != test1.rend(); i--)
// 	// 		std::cout << *i << ",";
// 	// 	std::cout << "}" << std::endl;

// 	// 	std::cout << "test1 using rev-iterator backward: {";
// 	// 	for(ft::vector<int>::reverse_iterator i = --test1.rend(); i != test1.rbegin(); i++)
// 	// 		std::cout << *i << ",";
// 	// 	std::cout << "}" << std::endl;
// 	// }

// 	// std::cout << "==============================TEST1: VECTOR COMPARISON================================================" << std::endl;
// 	// {
// 	// 	{
// 	// 		ft::vector<int>	test1;
// 	// 		ft::vector<int>	test0;

// 	// 		test1[0] = 0;
// 	// 		test1[1] = 1;
// 	// 		test1[2] = 2;

// 	// 		test0[0] = 0;
// 	// 		test0[1] = 1;
// 	// 		test0[2] = 2;
// 	// 		std::cout << "Equal vectors:" << std::endl;
// 	// 		if (test0 == test1) std::cout << "                -test0 and test1 are equal\n";
// 	// 		if (test0 != test1) std::cout << "                -test0 and test1 are not equal\n";
// 	// 		if (test0 < test1)  std::cout << "                -test0 is less than test1\n";
// 	// 		if (test0 > test1)  std::cout << "                -test0 is greater than test1\n";
// 	// 		if (test0 <= test1) std::cout << "                -test0 is less than or equal to test1\n";
// 	// 		if (test0 >= test1) std::cout << "                -test0 is greater than or equal to test1\n";
// 	// 	}

// 	// 	{
// 	// 		ft::vector<int>	test1;
// 	// 		ft::vector<int>	test0;

// 	// 		test1[0] = 0;
// 	// 		test1[1] = 1;
// 	// 		test1[2] = 3;

// 	// 		test0[0] = 0;
// 	// 		test0[1] = 1;
// 	// 		test0[2] = 2;

// 	// 		std::cout << "test1 last element is greater than test0:" << std::endl;
// 	// 		if (test0 == test1) std::cout << "                -test0 and test1 are equal\n";
// 	// 		if (test0 != test1) std::cout << "                -test0 and test1 are not equal\n";
// 	// 		if (test0 < test1)  std::cout << "                -test0 is less than test1\n";
// 	// 		if (test0 > test1)  std::cout << "                -test0 is greater than test1\n";
// 	// 		if (test0 <= test1) std::cout << "                -test0 is less than or equal to test1\n";
// 	// 		if (test0 >= test1) std::cout << "                -test0 is greater than or equal to test1\n";
// 	// 	}

// 	// 	{
// 	// 		ft::vector<int>	test1;
// 	// 		ft::vector<int>	test0;

// 	// 		test1[0] = 0;
// 	// 		test1[1] = 1;

// 	// 		test0[0] = 0;
// 	// 		test0[1] = 1;
// 	// 		test0[2] = 2;

// 	// 		std::cout << "test1 has less elements than test0:" << std::endl;
// 	// 		if (test0 == test1) std::cout << "                -test0 and test1 are equal\n";
// 	// 		if (test0 != test1) std::cout << "                -test0 and test1 are not equal\n";
// 	// 		if (test0 < test1)  std::cout << "                -test0 is less than test1\n";
// 	// 		if (test0 > test1)  std::cout << "                -test0 is greater than test1\n";
// 	// 		if (test0 <= test1) std::cout << "                -test0 is less than or equal to test1\n";
// 	// 		if (test0 >= test1) std::cout << "                -test0 is greater than or equal to test1\n";
// 	// 	}
// 	// }

// 	// std::cout << "=======================================TEST2: TESTING AT, OPERTOR[], FRONT AND BACK ================================================" << std::endl;
// 	// {
// 	// 	ft::vector<int>	test1;

// 	// 	try
// 	// 	{
// 	// 		for (size_t i = 0; i < 10; i++)
// 	// 			test1.push_back(i);

// 	// 		std::cout << "test1 front: " << test1.front() << std::endl;
// 	// 		std::cout << "test1 back: " << test1.back() << std::endl;
// 	// 		std::cout << "test1 at 4: " << test1. at(4) << std::endl;
// 	// 		std::cout << "test1[4]: " << test1[4] << std::endl;
// 	// 		std::cout << "test1 at 0: " << test1. at(0) << std::endl;
// 	// 		std::cout << "test1[0]: " << test1[0] << std::endl;
// 	// 		std::cout << "test1 at 9: " << test1. at(9) << std::endl;
// 	// 		std::cout << "test1[9]: " << test1[9] << std::endl;
// 	// 		std::cout << "test1 at 100: " << test1.at(100) << std::endl;
// 	// 	}
// 	// 	catch(std::exception &e)
// 	// 	{
// 	// 		std::cout << e.what() << std::endl;
// 	// 	}

// 	// 	//testing copy constructor
// 	// 	ft::vector<int>	test2(test1.begin(), test1.end());

// 	// 	print_vector(test2, "test2 v");
// 	// }

// 	// std::cout << "=======================================TEST3: ASSIGN, OPERATOR=, RESIZE ================================================" << std::endl;
// 	// {
// 	// 	ft::vector<int>	test3(2, 17);
// 	// 	ft::vector<int> test2;

// 	// 	for (size_t i = 0; i < 10; i++)
// 	// 		test2.push_back(i);

// 	// 	print_vector(test2, "test3 original v");
// 	// 	print_vector(test3, "test3 original v");

// 	// 	test3.clear();
// 	// 	test3.assign(test2.begin(), test2.end());

// 	// 	print_vector(test3, "assigned test2 to test3 vector: v");

// 	// 	test3.assign(5, 18);
// 	// 	print_vector(test3, "repalaced test3 by 5 18s: v");

// 	// 	ft::vector<int>	test4(5, 90);
// 	// 	ft::vector<int>	test1(5, 50);

// 	// 	print_vector(test1, "test1 before swap v");
// 	// 	print_vector(test4, "test4 before swap v");

// 	// 	test4.swap(test1);

// 	// 	print_vector(test1, "test1 after swap v");
// 	// 	print_vector(test4, "test4 after swap v");

// 	// 	test1.erase(test1.begin(), test1.begin() + 2);

// 	// 	print_vector(test1, "test1 after erase v:");
// 	// }
// 	// std::cout << "==================================TEST4: INSERT TEST =======================================" << std::endl;
// 	// {
// 	// 	vector<int> myvector (3,100);
// 	// 	vector<int>::iterator it;

// 	// 	it = myvector.begin();
// 	// 	it = myvector.insert ( it , 200 );

// 	// 	myvector.insert (it,2,300);

// 	// 	// "it" no longer valid, get a new one:
// 	// 	it = myvector.begin();

// 	// 	vector<int> anothervector (2,400);

// 	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

// 	// 	int myarray [] = { 501,502,503 };
// 	// 	myvector.insert (myvector.begin(), myarray, myarray+3);

// 	// 	print_vector(myvector, "myvector: ");
// 	// }
// 	// std::cout << "===================================TEST5: reserve ========================================" << std::endl;
// 	// {
// 	// 	vector<int>::size_type sz;

// 	// 	vector<int> foo;
// 	// 	sz = foo.capacity();
// 	// 	std::cout << "making foo grow:\n";
// 	// 	for (int i=0; i<100; ++i) {
// 	// 		foo.push_back(i);
// 	// 		if (sz!=foo.capacity()) {
// 	// 		sz = foo.capacity();
// 	// 		std::cout << "capacity changed: " << sz << '\n';
// 	// 		}
// 	// 	}

// 	// 	vector<int> bar;
// 	// 	sz = bar.capacity();
// 	// 	bar.reserve(100);   // this is the only difference with foo above
// 	// 	std::cout << "making bar grow:\n";
// 	// 	for (int i=0; i<100; i++)
// 	// 	{
// 	// 		bar.push_back(i);
// 	// 		if (sz!=bar.capacity())
// 	// 		{
// 	// 			sz = bar.capacity();
// 	// 			std::cout << "capacity changed: " << sz << '\n';
// 	// 		}
// 	// 	}
// 	// 	try
// 	// 	{
// 	// 		bar.reserve(bar.max_size() * 2);
// 	// 	}
// 	// 	catch(std::exception& e)
// 	// 	{ std::cout << e.what(); }


// 	//testing resize over and over
// 		//  vector<int> myvector;

// 		// // set some initial content:
// 		// for (vector<int>::size_type i=1;i<10;i++) myvector.push_back(i);

// 		// print_vector(myvector, "original");
// 		// myvector.resize(5);
// 		// print_vector(myvector, "first resize");
// 		// myvector.resize(8,100);
// 		// print_vector(myvector, "second resize");
// 		// myvector.resize(12);
// 		// print_vector(myvector, "third resize");

// 	// 	vector<int> myvector;

// 	// 	// set some values (from 1 to 10)
// 	// 	for (int i=1; i<=10; i++) myvector.push_back(i);

// 	// 	// erase the 6th element
// 	// 	myvector.erase (myvector.begin()+5);

// 	// 	// erase the first 3 elements:
// 	// 	myvector.erase (myvector.begin(),myvector.begin()+3);

// 	// 	std::cout << "myvector contains:";
// 	// 	for (unsigned i=0; i<myvector.size(); ++i)
// 	// 		std::cout << ' ' << myvector[i];
// 	// 	std::cout << '\n';
// 	// }
// 	// {
// 	// 	vector<int> foo,bar;

// 	// 	foo.push_back(100);
// 	// 	foo.push_back(200);

// 	// 	bar.push_back(11);
// 	// 	bar.push_back(22);
// 	// 	bar.push_back(33);


// 	// 	vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
// 	// 	vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

// 	// 	swap(bar, foo);
// 	// }

// 	return (0);
// }


template <class T>
void	print_vector(vector<T> &test)
{
	typename vector<T>::iterator		beg = test.begin();
	typename vector<T>::iterator		end = test.end();
	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
	for (typename vector<T>::iterator it = beg; it != end; it++)
	{
		std::cout << *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
int copy_swap_tests()
{
	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
	vector<T> test;

	print_vector<T>(test);

	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
	print_vector<T>(test);


	vector<T> test_copy(test);
	print_vector<T>(test_copy);

	// for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	// print_vector<T>(test_copy);
	// vector<T> test_range(test.begin() + 20, test.begin() + 30);
	// print_vector<T>(test_range);
	// test_copy.swap(test);
	// print_vector<T>(test);
	// print_vector<T>(test_copy);
	// test_copy.swap(test_range);
	// print_vector<T>(test_range);
	// print_vector<T>(test_copy);
	// test.swap(test_copy);
	// print_vector<T>(test);
	// print_vector<T>(test_copy);
	return (0);
}

int vector_test()
{
	copy_swap_tests<int>();
	return (0);
}
