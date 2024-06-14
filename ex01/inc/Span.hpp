#pragma  once

#include <set>

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
		unsigned int		shortestSpan()			const;
		unsigned int		longestSpan()			const;
		unsigned int const&	getMaxSize()	const;

	private:
		std::multiset<int>	_numbers;
		unsigned int		_max_size;

		class SpanIsFullException : public ExceptionMaker
		{
			public:
				SpanIsFullException();
		};
		class CantGetSpanException : public ExceptionMaker
		{
			public:
				CantGetSpanException();
		};
};
