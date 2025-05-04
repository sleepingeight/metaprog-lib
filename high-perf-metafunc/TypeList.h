#ifndef TYPE_LIST_H
#define TYPE_LIST_H

#include <type_traits>

namespace ss
{

template <typename...>
struct type_list
{
};

}


// Copied only few from metaprogramming.h, so that the whole library is not compiled
// which might distort the benchmarks


///////////////////  IF  ///////////////////
namespace ss
{

template <bool condition, typename THEN, typename ELSE>
struct if_
{
    using type = THEN;
};

template<typename THEN, typename ELSE>
struct if_<false, THEN, ELSE>
{
    using type = ELSE;
};

}

///////////////////  PUSH_BACK  ///////////////////
namespace ss
{

template <typename LIST, typename T>
struct push_back;

template <template <typename...> class LIST, typename... T0toN, typename T>
struct push_back<LIST<T0toN...>, T> {
    using type = LIST<T0toN..., T>;
};

template <typename LIST, typename T>
using push_back_t = typename push_back<LIST, T>::type;

}

namespace ss
{

// helper
namespace detail
{
    template <typename T>
    struct to_void
    {
        using type = void;
    };
}

}


#endif