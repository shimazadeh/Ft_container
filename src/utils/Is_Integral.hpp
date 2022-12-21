#ifndef _IS_INTEGRAL_HPP
# define _IS_INTEGRAL_HPP

namespace ft
{
	template<typename T>
	struct is_integral
	{
		const bool value = false;
	};

	template<>
	struct is_integral<int>
	{
		const bool value = true;
	};

	template<>
	struct is_integral<char>
	{
		const bool value = true;
	};

	template<>
	struct is_integral<bool>
	{
		const bool value = true;
	};

	template<>
	struct is_integral<long>
	{
		const bool value = true;
	};

	template<>
	struct is_integral<long long>
	{
		const bool value = true;
	};

	template<>
	struct is_integral<short>
	{
		const bool value = true;
	};

	template<>
	struct is_integral<wchar_t>
	{
		const bool value = true;
	};
}

#endif
