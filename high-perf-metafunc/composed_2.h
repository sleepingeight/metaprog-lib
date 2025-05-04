#ifndef COMPOSED_2
#define COMPOSED_2

#include "TypeList.h"

/*
here - remove_if is defined as transform + join operation
*/


/////////////////////////// JOIN ////////////////////////////////
namespace ss
{

namespace composed
{

template <typename ... LISTS>
struct join
{
};

template <typename ... T1s, typename ... T2s, typename ... MORE_LISTS>
struct join<type_list<T1s...>, type_list<T2s...>, MORE_LISTS...> :
       join<type_list<T1s..., T2s...>, MORE_LISTS...>
{
};

template <typename LIST>
struct join<LIST>
{
    using type = LIST;
};

template <typename ... LISTS>
using join_t = typename join<LISTS...>::type;



// Tests
static_assert(
    std::is_same_v<join_t<type_list<int, bool>, type_list<float, double>>, 
                    type_list<int, bool, float, double>>
);
static_assert(
    std::is_same_v<
                    join_t<
                         type_list<int, bool>, 
                         type_list<float, double>,
                         type_list<double, float>
                        >, 
                    type_list<int, bool, float, double,double, float>
                >
);


}   // composed

}   // ss

////////////////// TRANSFORM ///////////////////////
namespace ss
{

namespace composed
{

template<typename LIST, template<typename> class FUNC>
struct transform
{
};

template<typename... Ts, template<typename> class FUNC>
struct transform<type_list<Ts...>, FUNC>
{
    using type = type_list<typename FUNC<Ts>::type...>;
};

template<typename LIST, template<typename> class FUNC>
using transform_t = typename transform<LIST, FUNC>::type;


// Tests

static_assert(
    std::is_same_v<
                    transform_t<
                            type_list<int, bool, char>,
                            ss::detail::to_void
                            >,
                    type_list<void, void, void>
                    >
);

}   // composed

}   // ss


///////////////////////// REMOVE_IF HELPERS ////////////////////////
// remove_if = transform+join

namespace ss::composed
{

namespace detail
{
    
template <template<typename> class PREDICATE, typename T>
struct wrap_if_not : if_<PREDICATE<T>::value, 
                         type_list<>, 
                         type_list<T>>
{
};


template <template <typename> class PREDICATE>
struct wrap_if_not_func
{
    template <typename T>
    using func = wrap_if_not<PREDICATE, T>;
};


template <typename LIST_OF_LISTS>
struct join_list_of_lists
{
};

template <typename ... Ts>
struct join_list_of_lists<type_list<Ts...>>  :
        composed::join<Ts...>
{
};

template <typename LIST_OF_LISTS>
using join_list_of_lists_t = typename join_list_of_lists<LIST_OF_LISTS>::type;

static_assert(
    std::is_same_v<
                    join_list_of_lists_t
                    <
                    type_list<type_list<int, bool>,
                                type_list<>,    
                                type_list<double>
                            >
                    >,
                    type_list<int, bool, double>
                >
);


}
}


///////////////// REMOVE_IF ///////////////
namespace ss
{

namespace composed
{

template <template <typename> class PREDICATE, typename LIST>
struct remove_if {
    using type = detail::join_list_of_lists_t<transform_t<LIST, detail::wrap_if_not_func<PREDICATE>::template func>>;
};


template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;


}


}








// eager, crashing pc for >= 11
// this is valid due to the exponential nature of the eager version
// crashing for 4096 in clang (stack nearly exhausted)
// in gcc, works better than the lazy one.

#endif