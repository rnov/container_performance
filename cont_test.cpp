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
//#include <boost/intrusive/list.hpp>

#include <algorithm>


// /*
int main(){

	std::vector<int> ve{ 4,1,6,8 };	
	int as = 12;
	testc::alg_wrapper(std::begin(ve), std::end(ve), ez_game2(std::begin(ve), std::end(ve))std::sort);
	//testc::alg_wrapper(std::begin(ve), std::end(ve), ez_game3(std::begin(ve), std::end(ve), as)std::fill);

	// testc::varidic<decltype(std::begin(ve)),decltype(std::end(ve))>


    // create vector with random numbers and shuffle it
    int ini_rand = 1, fin_rand = 20000; // 200000  -> 200k, 500000 -> 500k
    int sorted_ini=1, sorted_fin = 20000; // 500000 -> 500k
    unsigned int n_op = 10;  // nº operations

    // random numbers vector
    auto rand_vector = generate_random_vector(ini_rand, fin_rand, 2000);

    // generate dst container for the values in rand_vector
    std::vector<int> dst_container_vector;
    generate_seq_container(dst_container_vector, sorted_ini, sorted_fin);
	

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
	std::vector<testc::graph> some_5async = testc::doTests_async(n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)search_sets);  // search_sets
    testc::print_measures(some_5async);


    return 0;
}
// */
