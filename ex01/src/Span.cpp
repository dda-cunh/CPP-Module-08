#include "../inc/Span.hpp"

//------------------------------  CANONICAL  ------------------------------//
Span::Span(void)
    : _max_size(0)
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
	: _max_size(N), _numbers(std::multiset<int>())
{}
//-------------------------------------------------------------------------//

//---------------------------  MEMBER FUNCTIONS  --------------------------//
unsigned int	const&Span::getMaxSize()	const
{
    return (this->_max_size);
}

void    Span::addNumber(int const& i)
{
    if (this->_numbers.size() < this->getMaxSize())
        this->_numbers.insert(i);
    else
        throw (Span::SpanIsFullException());
}

//-------------------------------------------------------------------------//

//------------------------------  EXCEPTIONS  -------------------------------//
Span::SpanIsFullException::SpanIsFullException()
	: ExceptionMaker("Span is at capacity")
{}

Span::CantGetSpanException::CantGetSpanException()
	: ExceptionMaker("Not enough numbers to get a span")
{}
//-------------------------------------------------------------------------//
