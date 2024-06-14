#include <iterator>
#include <cmath>
#include <limits>

#include "../inc/Span.hpp"

//------------------------------  CANONICAL  ------------------------------//
Span::Span(void)
	:_shortest_span((unsigned int)std::numeric_limits<int>::max() + 1),
	_max_size(0) 
{}

Span::Span(Span const & src)
{
	*this = src;
}

Span & Span::operator=(Span const & rhs)
{
	this->_max_size = rhs.getMaxSize();
	return (*this);
}

Span::~Span(void)
{}
//-------------------------------------------------------------------------//

//-----------------------------  CONSTRUCTORS  ----------------------------//
Span::Span(unsigned int N)
	: _numbers(std::multiset<int>()),
	_shortest_span((unsigned int)std::numeric_limits<int>::max() + 1),
	_max_size(N)
{}
//-------------------------------------------------------------------------//

//---------------------------  MEMBER FUNCTIONS  --------------------------//
void	Span::addNumber(int const& i)
{
	std::multiset<int>::const_iterator	it;
	unsigned int						lower_span;
	unsigned int						upper_span;
	bool								has_lower;
	bool								has_upper;

	if(this->_numbers.size() + 1 > this->getMaxSize())
		throw (Span::NotEnoughSpaceException());
	it = this->_numbers.insert(i);
	if (this->_shortest_span == 0)
		return ;
	has_lower = (it != this->_numbers.begin());
	it++;
	has_upper = (it != this->_numbers.end());
	if (has_upper)
		upper_span = *it - i;
	it--;
	if (has_lower)
	{
		it--;
		lower_span =  i - *it; 
	}
	if (has_upper && upper_span < this->_shortest_span)
		this->_shortest_span = upper_span;
	if (has_lower && lower_span < this->_shortest_span)
		this->_shortest_span = lower_span;
}

void	Span::addIntVector(std::vector<int> const& arr)
{
	if(this->_numbers.size() + arr.size() > this->getMaxSize())
		throw (Span::NotEnoughSpaceException());
	for (unsigned long i = 0; i < arr.size(); i++)
		this->addNumber(arr[i]);
}

unsigned int	Span::shortestSpan()	const
{
	if (this->_numbers.size() <= 1)
		throw (CantGetSpanException());
	return (this->_shortest_span);
}

unsigned int	Span::longestSpan() const
{
	int	lower;
	int	upper;

	if (this->_numbers.size() <= 1)
		throw (CantGetSpanException());
	lower = *(this->_numbers.begin());
	upper = *(this->_numbers.rbegin());
	return (upper - lower);
}

unsigned int	const&Span::getMaxSize()	const
{
	return (this->_max_size);
}
//-------------------------------------------------------------------------//

//------------------------------  EXCEPTIONS  -------------------------------//
Span::NotEnoughSpaceException::NotEnoughSpaceException()
	: ExceptionMaker("Not enough space to insert into Span")
{}

Span::CantGetSpanException::CantGetSpanException()
	: ExceptionMaker("Not enough numbers to get a span")
{}
//-------------------------------------------------------------------------//
