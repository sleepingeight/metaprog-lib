#include "BenchmarkInputs.h"
#include "naive_eager.h"
#include "naive_lazy.h"
#include "composed_2.h"
#include "composed_fasttrack64.h"
#include "composed_defaults64.h"
#include "composed_selection64.h"
#include "composed_selection1024.h"

#ifndef BENCHMARK
#include "Tests.h"
#endif

using namespace ss;

template <typename T>
struct same_as_pred {
	template <typename U>
	struct predicate : std::is_same<T, U> {};
};



#ifndef ALGO
#define ALGO 2
#endif

#ifndef INPUT
#define INPUT input128_different
#endif

template <typename T>
void run_test() {
	constexpr int i = ALGO;
	if constexpr (i == 1) {
		[[maybe_unused]] eager::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 2) {
		[[maybe_unused]] lazy::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 3) {
	  	[[maybe_unused]] composed::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 4) {
	  	[[maybe_unused]] composed_fasttrack::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 5) {
	  	[[maybe_unused]] composed_defaults::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 6) {
	  	[[maybe_unused]] composed_selection::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
	}
	if constexpr (i == 7) {
		[[maybe_unused]] composed_selection1024::remove_if<same_as_pred<T>::template predicate, INPUT> t{};
  }
	// if constexpr (i == 6) {
	//   namespace hp = high_performance;
	//   [[maybe_unused]] hp::unpack<hp::remove_if<hp::to_lazy_predicate<std::is_void>>>::template f<INPUT> t{};
	// }
}





int main()
{
	INPUT dummy{};
	run_test<void>();
    return 0;
}

