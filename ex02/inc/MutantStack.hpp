#pragma once

#include <deque>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	using std::stack<T, Container>::c;

	public:
		typedef typename Container::const_iterator	const_iterator;
		typedef typename Container::iterator		iterator;

		const_iterator	begin()	const
		{
			return (this->c.begin());
		}

		const_iterator	end()	const
		{
			return (this->c.end());
		}

		iterator		begin()
		{
			return (this->c.begin());
		}

		iterator		end()
		{
			return (this->c.end());
		}
};
