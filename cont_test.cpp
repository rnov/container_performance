#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include "container_test.h"
//#include <experimental/>

#include<future>

//#include <boost/intrusive/list.hpp>

 ///*
int main(){



    // create vector with random numbers and shuffle it
    int ini_rand = 1, fin_rand = 50000; // 200000  -> 200k
    int sorted_ini=1, sorted_fin = 50000; // 500000 -> 500k
    int n_op = 20;  // nº operations

    // random numbers vector
    auto rand_vector = generate_random_vector(ini_rand, fin_rand, 5000);

    // generate dst container for the values in rand_vector
    std::vector<int> dst_container_vector;
    generate_seq_container(dst_container_vector, sorted_ini, sorted_fin);

//     Operations

    auto rand_vector_2 = shuffle_container(std::begin(dst_container_vector), std::end(dst_container_vector)); // dst_container_vector

    // VECTOR
//    std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector_2,(testc::fParam<std::vector<int>, std::vector<int>>)deletefromContaniner);
    std::vector<testc::graph> some = testc::doTests(n_op, dst_container_vector, rand_vector,(testc::fParam<std::vector<int>, std::vector<int>>)insertSortetedContaniner);
    print_measures(some);
    cvs_columns("insertVectorData.csv", some);

    // LIST
    std::list<int> dst_container_list;
    generate_seq_container(dst_container_list, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_2 = testc::doTests(num_op, dst_container_list, rand_vector_2, (testc::fParam<std::list<int>, std::vector<int>>)deletefromContaniner);
    std::vector<testc::graph> some_2 = testc::doTests(n_op, dst_container_list, rand_vector, (testc::fParam<std::list<int>, std::vector<int>>)insertSortetedContaniner);
    testc::print_measures(some_2);
    cvs_columns("insertListData.csv", some_2);

//    // DQUEUE
    std::deque<int> dst_container_dqueue;
    generate_seq_container(dst_container_dqueue, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector_2, (testc::fParam<std::deque<int>, std::vector<int>>)deletefromContaniner);
    std::vector<testc::graph> some_3 = testc::doTests(n_op, dst_container_dqueue, rand_vector, (testc::fParam<std::deque<int>, std::vector<int>>)insertSortetedContaniner);
    testc::print_measures(some_3);
    cvs_columns("insertDequeData.csv", some_3);

    // SET
    std::set<int> dst_container_set;
    generate_container(dst_container_set, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector_2, (testc::fParam<std::set<int>, std::vector<int>>)deletefromContaniner);
    std::vector<testc::graph> some_4 = testc::doTests(n_op, dst_container_set, rand_vector, (testc::fParam<std::set<int>, std::vector<int>>)insertSortetedContaniner);
    testc::print_measures(some_4);
    cvs_columns("insertSetData.csv", some_4);
//    print_Container(dst_container_set);

    //  Unordered Set
    std::unordered_set<int> dst_container_unset;
    generate_container(dst_container_unset, sorted_ini, sorted_fin);
//    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector_2, (testc::fParam<std::unordered_set<int>, std::vector<int>>)deletefromContaniner);
    std::vector<testc::graph> some_5 = testc::doTests(n_op, dst_container_unset, rand_vector, (testc::fParam<std::unordered_set<int>, std::vector<int>>)insertSortetedContaniner);
//    testc::print_measures(some_5);
    cvs_columns("insertUnsetData.csv", some_5);
//    print_Container(dst_container_set);

    return 0;
}
// */

