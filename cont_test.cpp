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


// /*
int main(){

    // create vector with random numbers and shuffle it
    int ini_rand = 1, fin_rand = 20000; // 200000  -> 200k, 500000 -> 500k
    int sorted_ini=1, sorted_fin = 20000; // 500000 -> 500k
    unsigned int n_op = 10;  // nº operations

    // random numbers vector
    auto rand_vector = generate_random_vector(ini_rand, fin_rand, 2000);

    // generate dst container for the values in rand_vector
    std::vector<int> dst_container_vector;
    generate_seq_container(dst_container_vector, sorted_ini, sorted_fin);

	bin_search(dst_container_vector, rand_vector);
	

//     Operations
// /*
	// multiprocessing
	//auto fut = std::async(car<std::vector<int>, std::vector<int>>, dst_container_vector, rand_vector);
	//auto fut2 = std::async(testc::doTests<std::vector<int>, std::vector<int>>, n_op, dst_container_vector, rand_vector, (testc::fParam<std::vector<int>, std::vector<int>>)insertSortetedContaniner);
    //auto rand_vector_2 = shuffle_container(std::begin(dst_container_vector), std::end(dst_container_vector)); // dst_container_vector

    // VECTOR
//    std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector_2,(testc::fParam<std::vector<int>, std::vector<int>>)deletefromContaniner);
//    std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector,(testc::fParam<std::vector<int>, std::vector<int>>)insertSortetedContaniner);
//	std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector, (testc::fParam<std::vector<int>, std::vector<int>>)bin_search);
//	std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector, (testc::fParam<std::vector<int>, std::vector<int>>)search);
//	print_measures(some);
//	cvs_columns("SearchVectorData.csv", some);

    // LIST
    std::list<int> dst_container_list;
    generate_seq_container(dst_container_list, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_2 = testc::doTests(num_op, dst_container_list, rand_vector_2, (testc::fParam<std::list<int>, std::vector<int>>)deletefromContaniner);
//    std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, (testc::fParam<std::list<int>, std::vector<int>>)insertSortetedContaniner);
//	std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, (testc::fParam<std::list<int>, std::vector<int>>)bin_search);
//	std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, (testc::fParam<std::list<int>, std::vector<int>>)search);
//	testc::print_measures(some_2);
//    cvs_columns("SearchListData.csv", some_2);

//    // DQUEUE
    std::deque<int> dst_container_dqueue;
    generate_seq_container(dst_container_dqueue, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector_2, (testc::fParam<std::deque<int>, std::vector<int>>)deletefromContaniner);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, (testc::fParam<std::deque<int>, std::vector<int>>)insertSortetedContaniner);
//	std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, (testc::fParam<std::deque<int>, std::vector<int>>)bin_search);
//	std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, (testc::fParam<std::deque<int>, std::vector<int>>)search);
//	testc::print_measures(some_3);
//    cvs_columns("SearchDequeData.csv", some_3);

    // SET
    std::set<int> dst_container_set;
    generate_container(dst_container_set, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector_2, (testc::fParam<std::set<int>, std::vector<int>>)deletefromContaniner);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, (testc::fParam<std::set<int>, std::vector<int>>)insertSortetedContaniner);
//	std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, (testc::fParam<std::set<int>, std::vector<int>>)bin_search);
//	std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, (testc::fParam<std::set<int>, std::vector<int>>)search);
//	testc::print_measures(some_4);
//    cvs_columns("SearchSetData.csv", some_4);
//    print_Container(dst_container_set);


    //  Unordered Set
    std::unordered_set<int> dst_container_unset;
    generate_container(dst_container_unset, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector_2, (testc::fParam<std::unordered_set<int>, std::vector<int>>)deletefromContaniner);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, (testc::fParam<std::unordered_set<int>, std::vector<int>>)insertSortetedContaniner);
//	std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, (testc::fParam<std::unordered_set<int>, std::vector<int>>)bin_search);
	//std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)search);  // std::unordered_set<int>, std::vector<int>
	//testc::print_measures(some_5);
	std::cout << "start now!" << '\n';
	std::vector<testc::graph> some_5async = testc::doTests_async(n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)search_sets);  // search_sets
    testc::print_measures(some_5async);
//    cvs_columns("SearchUnsetData.csv", some_5);
//    print_Container(dst_container_set);

	

	// parallel
	/*
	auto fut2 = std::async(
		testc::doTests<std::vector<int>, std::vector<int>>, n_op, dst_container_vector, rand_vector, (testc::fParam<std::vector<int>, std::vector<int>>)search);
	auto fut3 = std::async(
		testc::doTests<std::list<int>, std::vector<int>>, n_op, dst_container_list, rand_vector, (testc::fParam<std::list<int>, std::vector<int>>)search);
	auto fut4 = std::async(
		testc::doTests<std::deque<int>, std::vector<int>>, n_op, dst_container_dqueue, rand_vector, (testc::fParam<std::deque<int>, std::vector<int>>)search);
	auto fut5 = std::async(
		testc::doTests<std::set<int>, std::vector<int>>, n_op, dst_container_set, rand_vector, (testc::fParam<std::set<int>, std::vector<int>>)search2);
	auto fut6 = std::async(
		testc::doTests<std::unordered_set<int>, std::vector<int>>, n_op, dst_container_unset, rand_vector, (testc::fParam<std::unordered_set<int>, std::vector<int>>)search2);

	std::vector<testc::graph> someq = fut2.get();
	std::vector<testc::graph> someq2 = fut3.get();
	std::vector<testc::graph> someq3 = fut4.get();
	std::vector<testc::graph> someq4 = fut5.get();
	std::vector<testc::graph> someq5 = fut6.get();
	
	cvs_columns("pVectorData.csv", someq);
	cvs_columns("plistData.csv", someq2);
	cvs_columns("pdequeData.csv", someq3);
	cvs_columns("psetData.csv", someq4);
	cvs_columns("punsetData.csv", someq5);
	*/

    return 0;
}
// */
