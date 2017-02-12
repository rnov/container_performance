#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
#include <list>
#include <map>
//#include "container_test.h"

#include<future>
#include<type_traits>
#include<iostream>


/*
int main() {

	// create vector with random numbers and shuffle it
    int ini_rand = 1, fin_rand = 20000; // 200000  -> 200k, 500000 -> 500k
    int sorted_ini=1, sorted_fin = 20000; // 500000 -> 500k
    unsigned int n_op = 10;  // nº operations

    // random numbers vector
    auto rand_vector = generate_random_vector(ini_rand, fin_rand, 2000);

	std::vector<int> dst_container_vector;
    generate_seq_container(dst_container_vector, sorted_ini, sorted_fin);
	
	std::list<int> dst_container_list;
	generate_seq_container(dst_container_list, sorted_ini, sorted_fin);

	std::deque<int> dst_container_dqueue;
	generate_seq_container(dst_container_dqueue, sorted_ini, sorted_fin);

	std::set<int> dst_container_set;
	generate_container(dst_container_set, sorted_ini, sorted_fin);

	std::unordered_set<int> dst_container_unset;
	generate_container(dst_container_unset, sorted_ini, sorted_fin);

	// parallel
	
	auto fut2 = std::async(
	testc::doTests<std::vector<int>, std::vector<int>>, n_op, dst_container_vector, rand_vector, ez_life(dst_container_vector, rand_vector)search);
	auto fut3 = std::async(
	testc::doTests<std::list<int>, std::vector<int>>, n_op, dst_container_list, rand_vector, ez_life(dst_container_list, rand_vector)search);
	auto fut4 = std::async(
	testc::doTests<std::deque<int>, std::vector<int>>, n_op, dst_container_dqueue, rand_vector, ez_life(dst_container_dqueue, rand_vector)search);
	auto fut5 = std::async(
	testc::doTests<std::set<int>, std::vector<int>>, n_op, dst_container_set, rand_vector, ez_life(dst_container_set, rand_vector)search2);
	auto fut6 = std::async(
	testc::doTests<std::unordered_set<int>, std::vector<int>>, n_op, dst_container_unset, rand_vector, ez_life(dst_container_unset, rand_vector)search2);

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
	


return 0;
}
// */