#include <vector>

#define ez_game(param)\
		(testc::varidic<decltype(param)>)

#define ez_game2(param, para2)\
		(testc::varidic<decltype(param), decltype(para2)>)

#define ez_game3(param, para2, para3)\
		(testc::varidic<decltype(param), decltype(para2), decltype(para3)>)

#define ez_game4(param, para2, para3, param4)\
		(testc::varidic<decltype(param), decltype(para2), decltype(para3), decltype(para4)>)

#define ez_game3b(param, param2, param3)\
		(testc::varidic<decltype(param), decltype(param2), const decltype(param3)&>)

#define ez_game4b(param, param2, param3, param4)\
		(testc::varidic<decltype(param), decltype(param2), const decltype(param3)&, decltype(param4)>)

// find param wrappers

#define Binary_Search(param1, param2, type)\
	(variadic<bool, decltype(param1), decltype(param2),const type&>)

#define Upper_Bound(param1, param2, type)\
	(variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)

#define Lower_Bound(param1, param2, type)\
	(variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)


template <typename ... Ts>
using var = decltype(auto)(*) (Ts ... V_args);// decltype(auto) */

template <typename ... Ts>
using varidic = void(*) (Ts ... V_args);  // void

struct graph {
	graph() = default;
	graph(unsigned int n_operations, double time) : noperations(n_operations), time(time) { };
	unsigned int noperations;  // nº operation (inserts/deletes...)
	double time;  // time took each
};

template <typename K, typename ... Ts>
using variadic = K(*) (Ts ... V_args);  // void

template <typename K, typename T>
void alg_wrapper(T some, variadic<K, T> funcptr) {
	//funcptr(some);
	Print_time(funcptr, some);
}

template <typename K, typename T, typename T2>
void alg_wrapper(T some, T2 some2, variadic<K, T, T2> funcptr) {
	//funcptr(some, some2);
	Print_time(funcptr, some, some2);
}

template <typename K, typename T, typename T2, typename T3>
void alg_wrapper(T some, T2 some2, T3 some3, variadic<K, T, T2, T3> funcptr) {
	//funcptr(some, some2, some3);
	Print_time(funcptr, some, some2, some3);
}

// fixed adapted for 'find' operations (find works for binary_search, lower_bound, upper_bound)
template <typename ReturnVariadic, typename ParamType, typename ParamType2, typename ParamType3>
std::vector<graph> alg_wrapper(int n_op, std::vector<ParamType3>vec, ParamType some, ParamType2 some2, variadic<ReturnVariadic, ParamType, ParamType2, const ParamType3&> funcptr) {
	assert(n_op <= vec.size());
	auto steps = vec.size() / n_op;
	std::vector<graph> values;
	for (auto operations = steps; operations <= vec.size(); operations += steps) {
		//auto copyContainer = vec;  // copy the container , no need in 'find' operations
		std::vector<ParamType3> src_aux(std::begin(vec), std::begin(vec) + operations);  // range values of source container

		start = std::chrono::system_clock::now();
		for (const auto& value : src_aux)
			funcptr(some, some2, value);
		end = std::chrono::system_clock::now();

		elapsed_seconds = end - start;
		std::cout << "  -elapsed time: " << elapsed_seconds.count() << "sec nº operations: " << operations << '\n';  // just for tests
		values.push_back(graph(operations, elapsed_seconds.count()));
	}
	return values;
}

template<typename T, typename K, typename Iterator>
std::vector<graph> find(int n_operation, std::vector<T> source, Iterator first, Iterator last, variadic<K, Iterator, Iterator, const T&> funcptr) {
	return alg_wrapper(n_operation, source, first, last, (variadic<K, decltype(first), decltype(last), const T&>)funcptr);
}