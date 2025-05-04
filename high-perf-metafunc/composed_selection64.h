#ifndef COMPOSED_SELECTION64_H
#define COMPOSED_SELECTION64_H
#include "TypeList.h"

/*
as SFINAE is the costliest, to prevent it
we find the required template using an algorithm
*/


///////////////////  JOIN HELPERS //////////////////////
namespace ss
{
namespace composed_selection
{
namespace detail
{

static constexpr int select_join_size(const int i)
{
    return i <= 4 ? 1 : i <= 16 ? 2 : i <= 64 ? 3 : 4;
}


template <int i>
struct join_select {};

template<>
struct join_select<1>   // upto 4
{   
    template <typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>>
    struct join {};

    template <typename ... T0s, typename ... T1s, typename ... T2s, typename ... T3s>
    struct join<type_list<T0s...>, type_list<T1s...>, type_list<T2s...>, type_list<T3s...>>
    {
        using type = type_list<T0s..., T1s..., T2s..., T3s...>;
    };
};

template<>
struct join_select<2>   // upto 16
{   
    template <typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
              typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
              typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
              typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>>
    struct join {};

    template <typename ... T0s, typename ... T1s, typename ... T2s, 
              typename ... T3s, typename ... T4s, typename ... T5s,
              typename ... T6s, typename ... T7s, typename ... T8s,
              typename ... T9s, typename ... T10s, typename ... T11s,
              typename ... T12s, typename ... T13s, typename ... T14s,
              typename ... T15s>
    struct join<type_list<T0s...>, type_list<T1s...>, type_list<T2s...>, 
                type_list<T3s...>, type_list<T4s...>, type_list<T5s...>, 
                type_list<T6s...>, type_list<T7s...>, type_list<T8s...>, 
                type_list<T9s...>, type_list<T10s...>, type_list<T11s...>, 
                type_list<T12s...>, type_list<T13s...>, type_list<T14s...>, 
                type_list<T15s...>>
    {
        using type = type_list<T0s ..., T1s ..., T2s ..., T3s ..., T4s ..., T5s ..., 
                               T6s ..., T7s ..., T8s ..., T9s ..., T10s ..., T11s ..., 
                               T12s ..., T13s ..., T14s ..., T15s ...>;
    };
};


template<>
struct join_select<3>
{

    template <typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>, typename = type_list<>, typename = type_list<>, 
              typename = type_list<>>
    struct join {};


    template <typename ... T0s, typename ... T1s, typename ... T2s, 
              typename ... T3s, typename ... T4s, typename ... T5s,
              typename ... T6s, typename ... T7s, typename ... T8s,
              typename ... T9s, typename ... T10s, typename ... T11s,
              typename ... T12s, typename ... T13s, typename ... T14s,
              typename ... T15s, typename ... T16s, typename ... T17s, 
              typename ... T18s, typename ... T19s, typename ... T20s,
              typename ... T21s, typename ... T22s, typename ... T23s,
              typename ... T24s, typename ... T25s, typename ... T26s,
              typename ... T27s, typename ... T28s, typename ... T29s,
              typename ... T30s, typename ... T31s, typename ... T32s, 
              typename ... T33s, typename ... T34s, typename ... T35s,
              typename ... T36s, typename ... T37s, typename ... T38s,
              typename ... T39s, typename ... T40s, typename ... T41s,
              typename ... T42s, typename ... T43s, typename ... T44s,
              typename ... T45s, typename ... T46s, typename ... T47s, 
              typename ... T48s, typename ... T49s, typename ... T50s,
              typename ... T51s, typename ... T52s, typename ... T53s,
              typename ... T54s, typename ... T55s, typename ... T56s,
              typename ... T57s, typename ... T58s, typename ... T59s,
              typename ... T60s, typename ... T61s, typename ... T62s,
              typename ... T63s>
    struct join<type_list<T0s...>, type_list<T1s...>, type_list<T2s...>, 
              type_list<T3s...>, type_list<T4s...>, type_list<T5s...>, 
              type_list<T6s...>, type_list<T7s...>, type_list<T8s...>, 
              type_list<T9s...>, type_list<T10s...>, type_list<T11s...>, 
              type_list<T12s...>, type_list<T13s...>, type_list<T14s...>, 
              type_list<T15s...>, type_list<T16s...>, type_list<T17s...>, 
              type_list<T18s...>, type_list<T19s...>, type_list<T20s...>, 
              type_list<T21s...>, type_list<T22s...>, type_list<T23s...>, 
              type_list<T24s...>, type_list<T25s...>, type_list<T26s...>, 
              type_list<T27s...>, type_list<T28s...>, type_list<T29s...>, 
              type_list<T30s...>, type_list<T31s...>, type_list<T32s...>, 
              type_list<T33s...>, type_list<T34s...>, type_list<T35s...>, 
              type_list<T36s...>, type_list<T37s...>, type_list<T38s...>, 
              type_list<T39s...>, type_list<T40s...>, type_list<T41s...>, 
              type_list<T42s...>, type_list<T43s...>, type_list<T44s...>, 
              type_list<T45s...>, type_list<T46s...>, type_list<T47s...>, 
              type_list<T48s...>, type_list<T49s...>, type_list<T50s...>, 
              type_list<T51s...>, type_list<T52s...>, type_list<T53s...>, 
              type_list<T54s...>, type_list<T55s...>, type_list<T56s...>, 
              type_list<T57s...>, type_list<T58s...>, type_list<T59s...>, 
              type_list<T60s...>, type_list<T61s...>, type_list<T62s...>, 
              type_list<T63s...>>
    {
            using type = type_list<T0s ..., T1s ..., T2s ..., T3s ..., T4s ..., T5s ..., 
                                   T6s ..., T7s ..., T8s ..., T9s ..., T10s ..., T11s ..., 
                                   T12s ..., T13s ..., T14s ..., T15s ..., T16s ..., T17s ..., 
                                   T18s ..., T19s ..., T20s ..., T21s ..., T22s ..., T23s ..., 
                                   T24s ..., T25s ..., T26s ..., T27s ..., T28s ..., T29s ..., 
                                   T30s ..., T31s ..., T32s ..., T33s ..., T34s ..., T35s ..., 
                                   T36s ..., T37s ..., T38s ..., T39s ..., T40s ..., T41s ..., 
                                   T42s ..., T43s ..., T44s ..., T45s ..., T46s ..., T47s ..., 
                                   T48s ..., T49s ..., T50s ..., T51s ..., T52s ..., T53s ..., 
                                   T54s ..., T55s ..., T56s ..., T57s ..., T58s ..., T59s ..., 
                                   T60s ..., T61s ..., T62s ..., T63s ...>;
    };
};

template<>
struct join_select<4> // more than 64
{
	template <
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename = type_list<>, typename = type_list<>, typename = type_list<>, typename = type_list<>,
	        typename... MORE_LISTS>
	struct join {};

	template <typename... T0s, typename... T1s, typename... T2s, typename... T3s,
	          typename... T4s, typename... T5s, typename... T6s, typename... T7s,
	          typename... T8s, typename... T9s, typename... T10s, typename... T11s,
	          typename... T12s, typename... T13s, typename... T14s, typename... T15s,
	          typename... T16s, typename... T17s, typename... T18s, typename... T19s,
	          typename... T20s, typename... T21s, typename... T22s, typename... T23s,
	          typename... T24s, typename... T25s, typename... T26s, typename... T27s,
	          typename... T28s, typename... T29s, typename... T30s, typename... T31s,
	          typename... T32s, typename... T33s, typename... T34s, typename... T35s,
	          typename... T36s, typename... T37s, typename... T38s, typename... T39s,
	          typename... T40s, typename... T41s, typename... T42s, typename... T43s,
	          typename... T44s, typename... T45s, typename... T46s, typename... T47s,
	          typename... T48s, typename... T49s, typename... T50s, typename... T51s,
	          typename... T52s, typename... T53s, typename... T54s, typename... T55s,
	          typename... T56s, typename... T57s, typename... T58s, typename... T59s,
	          typename... T60s, typename... T61s, typename... T62s, typename... T63s,
	          typename... MORE_LISTS>
	struct join<
	         type_list<T0s...> , type_list<T1s...> , type_list<T2s...> , type_list<T3s...> , type_list<T4s...> ,
	         type_list<T5s...> , type_list<T6s...> , type_list<T7s...> , type_list<T8s...> , type_list<T9s...> ,
	         type_list<T10s...>, type_list<T11s...>, type_list<T12s...>, type_list<T13s...>, type_list<T14s...>,
	         type_list<T15s...>, type_list<T16s...>, type_list<T17s...>, type_list<T18s...>, type_list<T19s...>,
	         type_list<T20s...>, type_list<T21s...>, type_list<T22s...>, type_list<T23s...>, type_list<T24s...>,
	         type_list<T25s...>, type_list<T26s...>, type_list<T27s...>, type_list<T28s...>, type_list<T29s...>,
	         type_list<T30s...>, type_list<T31s...>, type_list<T32s...>, type_list<T33s...>, type_list<T34s...>,
	         type_list<T35s...>, type_list<T36s...>, type_list<T37s...>, type_list<T38s...>, type_list<T39s...>,
	         type_list<T40s...>, type_list<T41s...>, type_list<T42s...>, type_list<T43s...>, type_list<T44s...>,
	         type_list<T45s...>, type_list<T46s...>, type_list<T47s...>, type_list<T48s...>, type_list<T49s...>,
	         type_list<T50s...>, type_list<T51s...>, type_list<T52s...>, type_list<T53s...>, type_list<T54s...>,
	         type_list<T55s...>, type_list<T56s...>, type_list<T57s...>, type_list<T58s...>, type_list<T59s...>,
	         type_list<T60s...>, type_list<T61s...>, type_list<T62s...>, type_list<T63s...>, MORE_LISTS...> {
	  using type = typename join_select<select_join_size(sizeof...(MORE_LISTS) + 1)>::template join<
		               type_list<
		               T0s... , T1s... , T2s... , T3s... , T4s... , T5s... , T6s... , T7s...,
		               T8s... , T9s... , T10s..., T11s..., T12s..., T13s..., T14s...,
		               T15s..., T16s..., T17s..., T18s..., T19s..., T20s..., T21s...,
		               T22s..., T23s..., T24s..., T25s..., T26s..., T27s..., T28s...,
		               T29s..., T30s..., T31s..., T32s..., T33s..., T34s..., T35s...,
		               T36s..., T37s..., T38s..., T39s..., T40s..., T41s..., T42s...,
		               T43s..., T44s..., T45s..., T46s..., T47s..., T48s..., T49s...,
		               T50s..., T51s..., T52s..., T53s..., T54s..., T55s..., T56s...,
		               T57s..., T58s..., T59s..., T60s..., T61s..., T62s..., T63s...>, MORE_LISTS...>::type;
	};  
};


} // namespace detail
} // namespace composed_selection
} // namespace ss



/////////////////// JOIN //////////////////
namespace ss
{
namespace composed_selection
{

template <typename... LISTS>
struct join {
	using type = typename detail::join_select<detail::select_join_size(sizeof...(LISTS))>::template join<LISTS...>::type;
};

template <typename... LISTS>
using join_t = typename join<LISTS...>::type;

// tests
static_assert(std::is_same_v<join_t<type_list<int, bool>, type_list<float, double>>, type_list<int, bool, float, double>>);
static_assert(std::is_same_v<join_t<type_list<>, type_list<int, bool>>, type_list<int, bool>>);
static_assert(std::is_same_v<join_t<type_list<int, float>, type_list<int, bool>, type_list<float, double>>, type_list<int, float, int, bool, float, double>>);



} // composed_selection
} // namespace ss











////////////////// TRANSFORM ///////////////////////
namespace ss
{

namespace composed_selection
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

}   // composed_selection

}   // ss


///////////////////////// REMOVE_IF HELPERS ////////////////////////
// remove_if = transform+join

namespace ss::composed_selection
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
            composed_selection::join<Ts...>
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


}   // detail
}   // ss::composed_selection


///////////////// REMOVE_IF ///////////////
namespace ss
{

namespace composed_selection
{

template <template <typename> class PREDICATE, typename LIST>
struct remove_if {
    using type = detail::join_list_of_lists_t<transform_t<LIST, detail::wrap_if_not_func<PREDICATE>::template func>>;
};


template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;


}   // composed_selection


}   // ss



#endif