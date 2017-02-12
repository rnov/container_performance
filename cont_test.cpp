#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include "container_test.h"

#include <numeric>
//#include <experimental/>
#include <iterator>
#include<future>
#include<type_traits>
#include<iostream>
#include <algorithm>


int main(){

    std::vector<int> cont {1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,20};
    std::vector<int> src {9,11,12,13,14,15,16,17,18,19,20};
    int fteen = 15;
    //std::vector<std::chrono::duration<double>> res = testc::uni_algo_test(std::binary_search<decltype(cbegin(cont)),int>, cbegin(cont),cend(cont),fteen);
    //auto vec = testc::doTest_new(src, std::binary_search<decltype(cbegin(cont)),int>, cbegin(cont),cend(cont));

    // create vector with random numbers and shuffle it
    unsigned long up_rand = 50000; // 200000  -> 200k, 500000 -> 500k
    unsigned long up_sort = 50000; // 500000 -> 500k
    unsigned int n_op = 20;  // nº operations

    // random numbers vector
    auto rand_vec = generate_random_vector<unsigned long>(0, up_rand, 5000);

    // generate dst container for the values in rand_vec
    std::vector<int> dst_cont_v(up_sort);
    std::iota(dst_cont_v.begin(),dst_cont_v.end(),0);

    std::vector<int> output;
    //testc::uni_algo_test(std::merge<decltype(cbegin(cont)),decltype(cbegin(src)),decltype(std::back_inserter(output))>, cbegin(cont), cend(cont), cbegin(src), cend(src), std::back_inserter(output));
    testc::uni_alg_test(std::merge<decltype(cbegin(rand_vec)),decltype(cbegin(dst_cont_v)),decltype(std::back_inserter(output))>, cbegin(rand_vec), cend(rand_vec), cbegin(dst_cont_v), cend(dst_cont_v), std::back_inserter(output));

///     Operations
// /*
//    auto rand_vec_2 = generate_random_vector(ini_rand, fin_rand, 2000);
    // VECTOR
//    std::vector<graph> some = testc::doTests(n_op, dst_cont_v, rand_vec_2, ez_life(dst_cont_v, rand_vec_2)deletefromContaniner);
//    std::vector<testc::graph> some = testc::doTests(n_op, dst_cont_v, rand_vec,ez_life(dst_cont_v, rand_vec)insertSortetedContaniner);
//	std::vector<testc::graph> some = testc::doTests(n_op, dst_cont_v, rand_vec, ez_life(dst_cont_v, rand_vec)bin_search);
//	std::vector<testc::graph> some = testc::doTests(n_op, dst_cont_v, rand_vec, ez_life(dst_cont_v, rand_vec>)search); (testc::fParam<std::vector<int>, std::vector<int>>)search
//	print_measures(some);
//	cvs_columns("SearchVectorData.csv", some);

    // LIST
//    std::list<int> dst_cont_list;
//    generate_seq_container(dst_cont_list, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_2 = testc::doTests(num_op, dst_cont_list, rand_vec_2, ez_life(dst_cont_list, rand_vec_2)deletefromContaniner);
//    std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_cont_list, rand_vec, ez_life(dst_cont_list, rand_vec)insertSortetedContaniner);
//	std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_cont_list, rand_vec, ez_life(dst_cont_list, rand_vec)bin_search);
//	std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_cont_list, rand_vec, ez_life(dst_cont_list, rand_vec)search);
//	testc::print_measures(some_2);
//    cvs_columns("SearchListData.csv", some_2);

//    // DQUEUE
//    std::deque<int> dst_cont_dqueue;
//    generate_seq_container(dst_cont_dqueue, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_cont_dqueue, rand_vec_2, ez_life(dst_cont_dqueue, rand_vec_2)deletefromContaniner);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_cont_dqueue, rand_vec, ez_life(dst_cont_dqueue, rand_vec)insertSortetedContaniner);
//	std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_cont_dqueue, rand_vec, ez_life(dst_cont_dqueue, rand_vec)bin_search);
//	std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_cont_dqueue, rand_vec, ez_life(dst_cont_dqueue, rand_vec)search);
//	testc::print_measures(some_3);
//    cvs_columns("SearchDequeData.csv", some_3);

    // SET
//    std::set<int> dst_cont_set;
//    generate_container(dst_cont_set, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_cont_set, rand_vec_2, ez_life(dst_cont_set, rand_vec_2)deletefromContaniner);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_cont_set, rand_vec, ez_life(dst_cont_set, rand_vec)insertSortetedContaniner);
//	std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_cont_set, rand_vec, ez_life(dst_cont_set, rand_vec)bin_search);
//	std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_cont_set, rand_vec, ez_life(dst_cont_set, rand_vec)search);
//	testc::print_measures(some_4);
//    cvs_columns("SearchSetData.csv", some_4);
//    print_Container(dst_cont_set);


    //  Unordered Set
//    std::unordered_set<int> dst_cont_unset;
//    generate_container(dst_cont_unset, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_cont_unset, rand_vec_2, ez_life(dst_cont_unset, rand_vec_2)deletefromContaniner);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_cont_unset, rand_vec, ez_life(dst_cont_unset, rand_vec)insertSortetedContaniner);
//	std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_cont_unset, rand_vec, ez_life(dst_cont_unset, rand_vec)bin_search);
	//std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_cont_unset, rand_vec, ez_life(dst_cont_unset, rand_vec)search);
	//testc::print_measures(some_5);
//    cvs_columns("SearchUnsetData.csv", some_5);
//    print_Container(dst_cont_set);

    return 0;
}
// */
