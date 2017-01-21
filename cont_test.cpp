#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include "container_test.h"

#include<future>
#include<type_traits>
#include<iostream>

#include <algorithm>
//#include <boost/intrusive/list.hpp>
template<typename T>
int show(T a) { return a; }

template<typename T>
void show(T a) {std::cout<< a<<std::endl; }

template<typename T, typename Z>
void show(T a, Z b) { std::cout << a << std::endl; }

template <typename T,typename ... Ts>
using arko = T(*) (Ts ... V_args);

template <typename K, typename T>
void wrapper(T some, arko<K,T> funcptr) {
	funcptr(some);
}

template <typename K, typename T, typename T2, typename T3>
void wrapper(T some, T2 some2, const T3& some3, arko<K, T,T2,const T3&> funcptr) {
	funcptr(some,some2,some3);
}

/*  // works
template<typename T, typename K, typename Iterator>
std::vector<testc::graph> find(int n_operation, std::vector<T> source, Iterator first, Iterator last, testc::variadic<K, Iterator, Iterator, const T&> funcptr) {
	return testc::alg_wrapper(n_operation, source, first, last, (testc::variadic<K, decltype(first), decltype(last), const T&>)funcptr);
}

#define Binary_Search(param1, param2, type)\
	(testc::variadic<bool, decltype(param1), decltype(param2),const type&>)

#define Upper_Bound(param1, param2, type)\
	(testc::variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)

#define Lower_Bound(param1, param2, type)\
	(testc::variadic<decltype(param1), decltype(param1), decltype(param2), const type&>)
*/
 //*

//*
int main(){

	//wrapper(std::begin(ark),std::end(ark),20, (testc::variadic<bool,decltype(std::begin(ark)), decltype(std::end(ark)), const int&>)std::binary_search);

	//find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), (testc::variadic<bool, decltype(std::begin(dst_container_vector)), decltype(std::end(dst_container_vector)), const int&>)std::binary_search);

    // create vector with random numbers and shuffle it
    int ini_rand = 1, fin_rand = 200000; // 200000  -> 200k, 500000 -> 500k
    int sorted_ini=1, sorted_fin = 200000; // 500000 -> 500k
    unsigned int n_op = 20;  // nº operations

    // random numbers vector
    auto rand_vector = generate_random_vector(ini_rand, fin_rand, 2000);

    // generate dst container for the values in rand_vector
    std::vector<int> dst_container_vector;
    generate_seq_container(dst_container_vector, sorted_ini, sorted_fin);
	
	// find works for binary_search, lower_bound, upper_bound
	//std::vector<graph> res1 = alg_wrapper(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Equal_Range(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::equal_range);

	std::vector<graph> res1 = alg_wrapper(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Fill(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::fill);

	
	//std::vector<graph> res1 = alg_wrapper(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Count(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::count);
	//std::vector<graph> res1 = alg_wrapper(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Find(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::find);
	//std::vector<graph> res1 = alg_wrapper(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Binary_Search(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::binary_search);
	//std::vector<graph> res11 = find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), (variadic<bool, decltype(std::begin(dst_container_vector)), decltype(std::end(dst_container_vector)), const int&>)std::binary_search);
	
	//std::vector<graph> res2 = find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Upper_Bound(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::upper_bound);
	//std::vector<graph> res22 = find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), (variadic<decltype(std::begin(dst_container_vector)), decltype(std::begin(dst_container_vector)), decltype(std::end(dst_container_vector)), const int&>)std::upper_bound);
	//std::vector<graph> res3 = find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), Lower_Bound(std::begin(dst_container_vector), std::end(dst_container_vector), int)std::lower_bound);
	//std::vector<graph> res33 = find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), (variadic<decltype(std::begin(dst_container_vector)), decltype(std::begin(dst_container_vector)), decltype(std::end(dst_container_vector)), const int&>)std::lower_bound);


	start = std::chrono::system_clock::now();
	std::binary_search(std::begin(dst_container_vector), std::end(dst_container_vector), 20);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "  -elapsed time: " << elapsed_seconds.count() << " s\n";

	Print_time(std::binary_search, std::begin(dst_container_vector), std::end(dst_container_vector), 20);

	//testc::find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector), params3b(bool, std::begin(dst_container_vector), std::end(dst_container_vector), int>)std::binary_search);
	//testc::find(20, rand_vector, std::begin(dst_container_vector), std::end(dst_container_vector),(testc::variadic<bool, decltype(std::begin(dst_container_vector)), decltype(std::end(dst_container_vector)), const int&>)std::binary_search);
	
///     Operations
// /*

    // VECTOR
//    std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector_2, ez_life(dst_container_vector, rand_vector_2)deletefromContaniner);
//    std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector,ez_life(dst_container_vector, rand_vector)insertSortetedContaniner);
//	std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector, ez_life(dst_container_vector, rand_vector)bin_search);
//	std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector, ez_life(dst_container_vector, rand_vector>)search); (testc::fParam<std::vector<int>, std::vector<int>>)search
//	print_measures(some);
//	cvs_columns("SearchVectorData.csv", some);

    // LIST
    std::list<int> dst_container_list;
    generate_seq_container(dst_container_list, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_2 = testc::doTests(num_op, dst_container_list, rand_vector_2, ez_life(dst_container_list, rand_vector_2)deletefromContaniner);
//    std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, ez_life(dst_container_list, rand_vector)insertSortetedContaniner);
//	std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, ez_life(dst_container_list, rand_vector)bin_search);
//	std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, ez_life(dst_container_list, rand_vector)search);
//	testc::print_measures(some_2);
//    cvs_columns("SearchListData.csv", some_2);

//    // DQUEUE
    std::deque<int> dst_container_dqueue;
    generate_seq_container(dst_container_dqueue, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector_2, ez_life(dst_container_dqueue, rand_vector_2)deletefromContaniner);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, ez_life(dst_container_dqueue, rand_vector)insertSortetedContaniner);
//	std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, ez_life(dst_container_dqueue, rand_vector)bin_search);
//	std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, ez_life(dst_container_dqueue, rand_vector)search);
//	testc::print_measures(some_3);
//    cvs_columns("SearchDequeData.csv", some_3);

    // SET
    std::set<int> dst_container_set;
    generate_container(dst_container_set, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector_2, ez_life(dst_container_set, rand_vector_2)deletefromContaniner);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, ez_life(dst_container_set, rand_vector)insertSortetedContaniner);
//	std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, ez_life(dst_container_set, rand_vector)bin_search);
//	std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, ez_life(dst_container_set, rand_vector)search);
//	testc::print_measures(some_4);
//    cvs_columns("SearchSetData.csv", some_4);
//    print_Container(dst_container_set);


    //  Unordered Set
    std::unordered_set<int> dst_container_unset;
    generate_container(dst_container_unset, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector_2, ez_life(dst_container_unset, rand_vector_2)deletefromContaniner);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)insertSortetedContaniner);
//	std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)bin_search);
	//std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)search);
	//testc::print_measures(some_5);
//    cvs_columns("SearchUnsetData.csv", some_5);
//    print_Container(dst_container_set);
	
	std::cout << "start now!" << '\n';
	std::vector<graph> some_5async = testc::doTests_async(n_op, dst_container_list, rand_vector, ez_life(dst_container_list, rand_vector)search);  // search_sets
    testc::print_measures(some_5async);

    return 0;
}
// */
