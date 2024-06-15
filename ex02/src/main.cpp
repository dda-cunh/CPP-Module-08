#include <iostream>
#include <vector>
#include <list>

#include "../inc/MutantStack.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define DO_TEST(name, test_scope)\
	do\
	{\
		testHeader(std::cout, name);\
		test_scope\
		testFooter(std::cout);\
	} while(0)

void	testFooter(std::ostream &o)
{
	o << std::endl << CLI_GREEN;
	o << std::string(TEST_LINE_LEN, '-');
	o << CLI_RESET << std::endl;
}

void	testHeader(std::ostream &o, std::string name)
{
	size_t		len;

	testFooter(std::cout);
	if (name.length() > TEST_LINE_LEN / 2)
		name = "  " + name.substr(TEST_LINE_LEN / 2) + " test  ";
	else
		name = "  " + name + " test  ";
	o << std::endl << CLI_GREEN;
	len = (TEST_LINE_LEN / 2) - (name.length() / 2);
	o << std::string(len, '-') << name;
	if (name.length() & 1)
		len--;
	o << std::string(len, '-') << std::endl << std::endl << CLI_CYAN;
}

int main()
{
	MutantStack<int, std::vector<int> >		vector_mstack;
	MutantStack<int, std::list<int> >		list_mstack;
	MutantStack<int>						deque_mstack;

	DO_TEST("MutantStack using deck [0, 9]",
	{
		for (int i = 0; i < 10; i++)
			deque_mstack.push(i);
		std::cout << "listing items using iterators" << std::endl;
		for (MutantStack<int>::iterator it = deque_mstack.begin();
				it != deque_mstack.end(); it++)
			std::cout << *it << " " << std::endl;
	});
	DO_TEST("MutantStack using vector [0, 9]",
	{
		for (int i = 0; i < 10; i++)
			vector_mstack.push(i);
		std::cout << "listing items using iterators" << std::endl;
		for (MutantStack<int, std::vector<int> >::iterator it = vector_mstack.begin();
				it != vector_mstack.end(); it++)
			std::cout << *it << " " << std::endl;
	});
	DO_TEST("MutantStack using list [0, 9]",
	{
		for (int i = 0; i < 10; i++)
			list_mstack.push(i);
		std::cout << "listing items using iterators" << std::endl;
		for (MutantStack<int, std::list<int> >::iterator it = list_mstack.begin();
				it != list_mstack.end(); it++)
			std::cout << *it << " " << std::endl;
	});
	DO_TEST("Subject Main ",
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	});
	return  (0);
}
