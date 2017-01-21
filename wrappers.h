#include <vector>
#include <functional>
#include <iterator>

// alg_wrappers

#define Binary_Search(param1, param2, type)\
	(variadic<bool, decltype(param1), decltype(param2),const type&>)

#define Upper_Bound(param1, param2, type)\
	(variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)

#define Lower_Bound(param1, param2, type)\
	(variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)

#define Find(param1, param2, type)\
	(variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)

#define Count(param1, param2, type)\
	(variadic<std::iterator_traits<decltype(param1)>::difference_type, decltype(param1), decltype(param2), const type&>)

#define Equal_Range(param1, param2, type)\
	(variadic<std::pair<decltype(param1), decltype(param1)>, decltype(param1), decltype(param2), const type&>)

#define Fill(param1, param2, type)\
	(variadic<void, decltype(param1), decltype(param2), const type&>)
 
//-----
#define Sort(param1, param2)\
	(variadic<void, decltype(param1), decltype(param2)>)

#define Is_Sorted(param1, param2)\
	(variadic<bool, decltype(param1), decltype(param2)>)

#define Is_Sorted_Until(param1, param2)\
	(variadic<decltype(param1), decltype(param1), decltype(param2)>)

#define Max_Element(param1, param2)\
	(variadic<decltype(param1), decltype(param1), decltype(param2)>)

#define Reverse(param1, param2)\
	(variadic<void, decltype(param1), decltype(param2)>)


struct graph {
	graph() = default;
	graph(unsigned int n_operations, double time) : noperations(n_operations), time(time) { };
	unsigned int noperations;  // nº operation (inserts/deletes...)
	double time;  // time took each
};

template <typename K, typename ... Ts>
using variadic = K(*) (Ts ... V_args);  // void


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

// fix it
template <typename container,typename ReturnVariadic, typename ParamType, typename ParamType2>
std::vector<graph> alg_wrapper(int n_op, container cont,ParamType some, ParamType2 some2, variadic<ReturnVariadic, ParamType, ParamType2> funcptr) {
	assert(n_op <= vec.size());
	
	std::vector<graph> values;
	for (auto operations = steps; operations <= vec.size(); operations += steps) {
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

/*
template<typename T, typename K, typename Iterator>
std::vector<graph> find_2(int n_operation, std::vector<T> source, Iterator first, Iterator last, variadic<K, Iterator, Iterator, const T&> funcptr) {
	return alg_wrapper(n_operation, source, first, last, (variadic<K, decltype(first), decltype(last), const T&>)funcptr);
}*/