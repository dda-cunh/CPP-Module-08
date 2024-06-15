#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <vector>

#include "../inc/Span.hpp"

//------------------------------  CANONICAL  ------------------------------//
Span::Span(void)
	:	_max_size(0),
		_is_sorted(false)
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
	:	_numbers(std::vector<int>()),
		_max_size(N),
		_is_sorted(false)
{}
//-------------------------------------------------------------------------//

//---------------------------  MEMBER FUNCTIONS  --------------------------//
void	Span::addNumber(int const& i)
{
	if(this->_numbers.size() + 1 > this->getMaxSize())
		throw (Span::NotEnoughSpaceException());
	this->_numbers.push_back(i);
	this->_is_sorted = false;
}

void	Span::addIntVector(std::vector<int> const& arr)
{
	if(this->_numbers.size() + arr.size() > this->getMaxSize())
		throw (Span::NotEnoughSpaceException());
	std::copy(arr.begin(), arr.end(),
				std::insert_iterator<std::vector<int> >(this->_numbers,
				this->_numbers.begin()));
	this->_is_sorted = false;
}

void	Span::sort()
{
	if (!this->_is_sorted)
	{
		std::sort(this->_numbers.begin(), this->_numbers.end());
		this->_is_sorted = true;
	}
}

unsigned int	Span::shortestSpan()
{
	unsigned int		curr_span;
	unsigned int		min_span;

	if (this->_numbers.size() <= 1)
		throw (CantGetSpanException());
	min_span = (unsigned int)std::numeric_limits<int>::max() + 1;
	this->sort();
	for (unsigned long i = 1; i < this->_numbers.size(); i++)
	{
		curr_span = std::abs(this->_numbers[i] - this->_numbers[i - 1]);
		if (curr_span < min_span)
			min_span = curr_span;
	}
	return (min_span);
}

unsigned int	Span::longestSpan()
{
	int	lower;
	int	upper;

	if (this->_numbers.size() <= 1)
		throw (CantGetSpanException());
	this->sort();
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
