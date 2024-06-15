#pragma  once

#include <vector>

#include "ExceptionMaker.hpp"

class Span
{
	public:
		Span(void);
		Span(Span const & src);
		Span	&operator=(Span const & rhs);
		~Span(void);

		Span(unsigned int);

		void				addNumber(int const&);
		void				addIntVector(std::vector<int> const&);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		unsigned int const&	getMaxSize()	const;

	private:
		std::vector<int>	_numbers;
		unsigned int		_max_size;

		class NotEnoughSpaceException : public ExceptionMaker
		{
			public:
				NotEnoughSpaceException();
		};
		class CantGetSpanException : public ExceptionMaker
		{
			public:
				CantGetSpanException();
		};
};
