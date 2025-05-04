#ifndef TESTS
#define TESTS


#include "TypeList.h"
#include "naive_eager.h"
#include "naive_lazy.h"
#include "composed_2.h"
#include "composed_fasttrack64.h"
#include "composed_defaults64.h"
#include "composed_selection64.h"
#include "composed_selection1024.h"

#include <tuple>
#include <type_traits>

#define remove_if_tests                                                                                             \
	static_assert(std::is_same_v<remove_if_t<std::is_floating_point, type_list<int, bool, float, double, char>>,      \
	                             type_list<int, bool, char>>);                                                        \
                                                                                                                    \
	static_assert(                                                                                                    \
	    std::is_same_v<remove_if_t<std::is_floating_point, type_list<int, bool, char>>, type_list<int, bool, char>>); \
                                                                                                                    \
	static_assert(std::is_same_v<remove_if_t<std::is_floating_point, type_list<float, double, float>>, type_list<>>)



namespace ss::eager
{
    remove_if_tests;
} // namespace ss::eager

namespace ss::lazy
{
    remove_if_tests;
} // namespace ss::lazy

namespace ss::composed
{
	remove_if_tests;
}

namespace ss::composed_fasttrack
{
	remove_if_tests;
}


namespace ss::composed_defaults
{
	remove_if_tests;
}

namespace ss::composed_selection
{
	remove_if_tests;
}

namespace ss::composed_selection1024
{
	remove_if_tests;
}


#endif