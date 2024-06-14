#include <iostream>
#include <vector>
#include <deque>
#include <list>

#include "../inc/easyfind.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define TRY_CATCH_TEST(name, test_scope)\
	do\
	{\
		testHeader(std::cout, name);\
		try\
			test_scope	\
		catch (std::exception &ex)\
		{\
			std::cout << ex.what() << std::endl;\
		}\
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

int main(void)
{
	std::vector<int>	vec_i;
	std::deque<int>		deq_i;
	std::list<int>		lst_i;
	int const			to_find	= 25;

	TRY_CATCH_TEST("Vector of string",
		{
			std::vector<std::string>	vec_s;
			std::cout << "Found " << easyfind(vec_s, to_find) << std::endl;
		});
	TRY_CATCH_TEST("Empty vector of int",
		{
			std::cout << "Found " << easyfind(vec_i, to_find) << std::endl;
		});
	vec_i.push_back(to_find);
	TRY_CATCH_TEST("Vector of int with to_find",
		{
			std::cout << "Found " << easyfind(vec_i, to_find) << std::endl;
		});
	deq_i.push_back(to_find);
	TRY_CATCH_TEST("Deque of int with to_find",
		{
			std::cout << "Found " << easyfind(deq_i, to_find) << std::endl;
		});
	lst_i.push_back(25);
	TRY_CATCH_TEST("List of int with to_find",
		{
			std::cout << "Found " << easyfind(lst_i, to_find) << std::endl;
		});
}
