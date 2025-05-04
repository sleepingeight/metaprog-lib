#ifndef METAPROGRAMMING_H
#define METAPROGRAMMING_H

#include <iostream>
#include <type_traits>


// testing purpose
template <typename ...>
struct list2
{
};

// Implementing type list

// convention
template <typename T>
struct has_type{
    using type = T;
};

// Templated IF using types
template <bool condition, typename THEN, typename ELSE>
struct if_;

template <typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> : has_type<THEN>
{
};

template <typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> : has_type<ELSE>
{
};


// initialising typelist
template <typename ...>
struct type_list
{
};


/* UTILITIES FOR TYPELIST */

// empty
template <typename LIST>
struct empty: std::false_type
{
};

template <template<typename...> class TLIST>
struct empty<TLIST<>>: std::true_type
{
};

template <typename LIST>
static constexpr bool empty_v = empty<LIST>::value;


static_assert(empty_v<type_list<>>);
static_assert(empty_v<type_list<int, float, bool>> == false);
list2<> l1;
static_assert(empty_v<decltype(l1)>);

// front
template <typename LIST>
struct front 
{
};

template <template<typename...> class TLIST, typename T0, typename ... T1toN>
struct front <TLIST<T0, T1toN...>> : has_type <T0>
{
};

template <typename LIST>
using front_t = typename front<LIST>::type;

static_assert(std::is_same_v<front_t<type_list<int, float>>, int>);


// pop_front
template <typename LIST>
struct pop_front
{
};

template <template<typename...> class TLIST, typename T0, typename ... T1toN>
struct pop_front<TLIST<T0, T1toN...>> : has_type<TLIST<T1toN...>>
{
};

template <typename LIST>
using pop_front_t = typename pop_front<LIST>::type;


static_assert(std::is_same_v<pop_front_t<type_list<int, float, bool>>, type_list<float, bool>>);
list2<int, bool, float> l2;
list2<bool, float> l3;
static_assert(std::is_same_v<pop_front_t<decltype(l2)>, decltype(l3)>);


// at
template <typename LIST, size_t index>
struct at : has_type <typename at<pop_front_t<LIST>, index-1>::type>
{
};


template <typename LIST>
struct at<LIST, 0> : has_type <front_t<LIST>>
{
};

template <typename LIST, size_t index>
using at_t = typename at<LIST, index>::type;

static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 1>, bool>);
static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 0>, bool> == false);
list2<bool, float> l4;
static_assert(std::is_same_v<at_t<decltype(l4), 1>, float>);


// back
template <typename LIST>
struct back : has_type < typename back<pop_front_t<LIST>>::type>
{
};

template <template<typename...> class TLIST, typename T0>
struct back <TLIST<T0>> : has_type<T0>
{
};   

template <typename LIST>
using back_t = typename back<LIST>::type;

static_assert(std::is_same_v<back_t<type_list<int, bool, float>>, float>);


// push_back
template <typename LIST, typename T>
struct push_back
{
};

template <template<typename...> class TLIST, typename ... T0toN, typename T>
struct push_back<TLIST<T0toN...>, T> : has_type<TLIST<T0toN ..., T>>
{
};

template <typename LIST, typename T>
using push_back_t = typename push_back<LIST, T>::type;

static_assert(std::is_same_v<push_back_t<type_list<>, int>, type_list<int>>);


// pop_back
template <typename LIST, typename RET_LIST = type_list<>>
struct pop_back
{
};

template <template<typename...> class TLIST, typename T0, typename T1, typename... T2toN, typename RET_LIST>
struct pop_back<TLIST<T0, T1, T2toN...>, RET_LIST> : 
    pop_back<TLIST<T1, T2toN...>, push_back_t<RET_LIST, T0>>
{
};

// recursion base case
template <template<typename...> class TLIST, typename TN, typename RET_LIST>
struct pop_back<TLIST<TN>, RET_LIST> : has_type<RET_LIST>
{
};

template <typename LIST>
using pop_back_t = typename pop_back<LIST>::type;

static_assert(std::is_same_v<pop_back_t<type_list<int>>, type_list<>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool, float>>, type_list<int, bool>>);


/////////////// NOT  ///////////////
template <template <typename...> class PREDICATE>
struct not_
{
    template <typename... Ts>
    using type = std::integral_constant<bool, !PREDICATE<Ts...>::value>;
};

/* END OF UTILITIES */


// any
template<template<typename> class PREDICATE, typename LIST>
struct any;

template<template<typename> class PREDICATE, template<typename...> class TLIST>
struct any<PREDICATE, TLIST<>> : std::false_type
{
};

template<template<typename> class PREDICATE, typename TLIST>
struct any : if_<
                PREDICATE<front_t<TLIST>>::value,
                std::true_type,
                typename any<PREDICATE, pop_front_t<TLIST>>::type
                >::type
{
};


template<template<typename> class PREDICATE, typename LIST>
static constexpr bool any_v = any<PREDICATE, LIST>::value;

static_assert(!any_v<std::is_integral, type_list<float, double, std::string>>);


template<typename T>
struct same_as_pred
{
    template<typename U>
    struct predicate : std::is_same<T, U>
    {
    }; 
};


template <typename SEARCH, typename LIST>
static constexpr bool contains_type_v = any<same_as_pred<SEARCH>::template predicate, LIST>::value;

static_assert(contains_type_v<int, type_list<int, bool, float>>);






///////// STATIC_FOR ////////
template <int FIRST, int LAST, typename LAMBDA>
constexpr void static_for(const LAMBDA &f) {
	if constexpr (FIRST < LAST) {
		f(std::integral_constant<int, FIRST>{});
		static_for<FIRST + 1, LAST>(f);
	}
}

#endif
