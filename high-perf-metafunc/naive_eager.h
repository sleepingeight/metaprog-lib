#ifndef NAIVE_EAGER
#define NAIVE_EAGER


#include "TypeList.h"


////////////////// REMOVE_IF ////////////////////
namespace ss
{

namespace eager
{
template <template <typename> class PREDICATE, typename LIST, typename NEW_LIST = type_list<>>
struct remove_if;

template <template <typename> class PREDICATE, typename T0, typename... T1toN, typename NEW_LIST>
struct remove_if<PREDICATE, type_list<T0, T1toN...>, NEW_LIST>
    : if_<PREDICATE<T0>::value,
          typename remove_if<PREDICATE, type_list<T1toN...>, NEW_LIST>::type,
          typename remove_if<PREDICATE, type_list<T1toN...>, push_back_t<NEW_LIST, T0>>::type> {};

template <template <typename> class PREDICATE, typename NEW_LIST>
struct remove_if<PREDICATE, type_list<>, NEW_LIST> {
    using type = NEW_LIST;
};

template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;
}


}

/// Here both if_ branches are completely compiled, causing 2^n space complexity
// This is not required, which is dealt in lazy_instantiation
// if_ branches completely compiled in the sense, the type is instantiated as we
// are asking for ::type member, in each case.

#endif


