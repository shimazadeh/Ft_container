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


int vector_test()
{
	vector<int> JOHN;
	vector<int> BOB(5, 8);
	std::cout << "BOB(5, 8) : ";
	for (size_t i = 0; i < BOB.size(); i++)
		std::cout << BOB[i] << ' ';
	std::cout << '\n';
	vector<int> MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;


	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;

	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, 3);
	/*






	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 5;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 83;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	/*






	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2) << '\n';
		std::cout << MIKE.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n";
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	BOB.assign(42, 7);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	vector<int>	assign_range;
	assign_range.assign(8, 5);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(41) : " << BOB.at(41) << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	BOB.push_back(53);
	std::cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	vector<int>	insert_in_me;
	for (int i = 0; i < 15; i++)
		insert_in_me.push_back(i);
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	vector<int>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, 42);
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	vector<int>::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it : " << std::endl;
	std::cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator


	//INSERT
	std::cout << "\nINSERT\n";
	vector<int>	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(i);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i) << ' ';
	std::cout << '\n';

	vector<int>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, 42);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i) << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	vector<int>	insert_bis;
	for (int i = 0; i < 7; i++)
		insert_bis.push_back(3 * i);
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i] << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i] << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	vector<int>	erase_in_me;
	for (int i = 0; i < 15; i++)
		erase_in_me.push_back(2 * i);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		if (erase_in_me[i] < 10)
			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		if (erase_in_me[i] < 10)
			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		if (erase_in_me[i] < 10)
			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	BOB.swap(MIKE);
	/*




	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	MIKE.swap(JOHN);
	/*




	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	/*




	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	/*




	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	vector<int> MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	std::cout << "\nReal Vector\n";
	vector<int> real;
	real.assign(5, 7);
	for (vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';

	std::cout << std::endl;
	return (0);
}

