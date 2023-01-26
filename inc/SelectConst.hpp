#ifndef _SELECTCONST_HPP
#define _SELECTCONST_HPP

namespace ft
{
	template<bool IsConst, typename Const, typename	NotConst>
	struct	select_const
	{};

	template<typename Const, typename	NotConst>
	struct	select_const<true, Const, NotConst>
	{
		typedef	Const	type;
	};

	template<typename Const, typename	NotConst>
	struct	select_const<false, Const, NotConst>
	{
		typedef	NotConst	type;
	};

}
#endif
