#ifndef NAIVE_LAZY
#define NAIVE_LAZY

#include "TypeList.h"


////////////////// REMOVE_IF ////////////////////
namespace ss
{

namespace lazy
{
template <template <typename> class PREDICATE, typename LIST, typename NEW_LIST = type_list<>>
struct remove_if;

template <template <typename> class PREDICATE, typename T0, typename... T1toN, typename NEW_LIST>
struct remove_if<PREDICATE, type_list<T0, T1toN...>, NEW_LIST> {
	using type = typename if_<PREDICATE<T0>::value,
	                          remove_if<PREDICATE, type_list<T1toN...>, NEW_LIST>,
	                          remove_if<PREDICATE, type_list<T1toN...>, push_back_t<NEW_LIST, T0>>>::type::type;
};


template <template <typename> class PREDICATE, typename NEW_LIST>
struct remove_if<PREDICATE, type_list<>, NEW_LIST> {
    using type = NEW_LIST;
};

template <template <typename> class PREDICATE, typename LIST>
using remove_if_t = typename remove_if<PREDICATE, LIST>::type;
}


}

/*
by moving ::type outside to if_ statements,
only one type is instantiated per if_ statement,
making only n instantiations.
*/

#endif

/*
RULE 1:
Prefer lazy over eager template instantiation
(By deferring instantiation until strictly necessary, we minimise
type instantiations)
*/
