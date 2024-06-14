#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "../inc/Span.hpp"

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
	int const rand_range = 2000001;

	std::srand(std::time(NULL));
	TRY_CATCH_TEST("Adding array with 15000 random ints",
		{
			std::vector<int>	vec;
			Span sp = Span(15000);

			for (int i = 0; i < 15000; i++)
				vec.push_back((std::rand() % rand_range) - rand_range / 2);
			sp.addIntVector(vec);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		});
	TRY_CATCH_TEST("Adding array with 50000 random ints",
			{
				std::vector<int>	vec;
				Span sp = Span(50000);

				for (int i = 0; i < 50000; i++)
					vec.push_back((std::rand() % rand_range) - rand_range / 2);
				sp.addIntVector(vec);
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			});
	TRY_CATCH_TEST("Sequential set [0,1024[",
		{
			int const	size = 1024;
			Span sp = Span(size);

			for (int i = 0; i < size; i++)
				sp.addNumber(i);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		});
	TRY_CATCH_TEST("Simple case",
		{
			Span sp = Span(7);
			sp.addNumber(2);
			sp.addNumber(22);
			sp.addNumber(42);
			sp.addNumber(62);
			sp.addNumber(82);
			sp.addNumber(102);
			sp.addNumber(121);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		});
	TRY_CATCH_TEST("Empty Span",
		{
			Span sp;

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		});
	return 0;
}
