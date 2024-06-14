#pragma once

#include <algorithm>
#include <iostream>

template
<
	typename TT,
	typename Allocator,
	template
	<
		typename,
		typename
	>
	class T
>
TT	const&easyfind(T<TT, Allocator> const& container, int const& to_find)
{
	(void) container;
	(void) to_find;
	std::cerr << "Not an int container" << std::endl;
	throw(std::exception());
}

template
<
	typename Allocator,
	template
	<
		typename,
		typename
	>
	class T
>
int	const&easyfind(T<int, Allocator> const& container, int const& to_find)
{
	typename T<int, Allocator>::const_iterator	it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return (*it);
	throw(std::exception());
}

