#ifndef CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H
#define CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H

#include <iostream>
#include <cassert>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iterator>
#include<future>
#include <tuple>

/*********Crono*************/
std::chrono::system_clock::time_point start, end;
std::chrono::duration<double> elapsed_seconds;
//std::time_t end_time;

/**********random**************/
std::random_device rd;  // only used once to initialise (seed) engine

/********cvs file*************/
std::ofstream outfile;

#define ez_life(dst_cont, rand_cont)\
	(testc::fParam<decltype(dst_cont), decltype(rand_cont)>)

#define Print_time(fun, ...)\
     start = std::chrono::system_clock::now();\
     fun(__VA_ARGS__);\
     end = std::chrono::system_clock::now();\
     elapsed_seconds = end-start;\
	 std::cout<< "  -elapsed time: " << elapsed_seconds.count() << " s\n";

// checks if the given container is the right function at compile time.

// vector, deque, list, (forward_list not implemented)
template <template<class T, class =std::allocator<T>> class Container, typename T>
bool is_sequence(Container<T>& container) {
	return true;
}

// set (multiset not implemented)
template<template<class T, class = std::less<T>, class =std::allocator<T>> class Container, typename T>
bool is_set(Container<T>& container) {
	return true;
}

// unordered_set (unordered_multiset not implemented)
template< template<class T, class =std::hash<T>, class =std::equal_to<T>, class =std::allocator<T>> class Container, typename T, typename k>
bool is_unset(k cont) {  // Container<T>& container
	return Container<int> == cont;
}

/*********templates (vector, list, dqueue, set, unordered_set)*************/

template <typename Container>
void print_Container(const Container& vec) {
    if (!vec.size())
        std::cout << "empty container" << std::endl;
    else {
        for (const auto& i: vec) {
            std::cout << i << " ";
        }
    }
    std::cout<<std::endl;
}

// generates src container with values within given range
// short, int, long, long long, unsigned short, unsigned int, unsigned long, or unsigned long long
//***
std::vector<int> generate_random_vector(int ini, int end, int num=0){

    assert(ini <= end && end >= num && num >=0);
    std::vector<int> random_vec;
    std::mt19937 g(rd());
    if(!num){
        // generate values
        for(auto value = ini; value <= end; value++) {
            random_vec.push_back(value);
        }
        // shuffle vector values
        std::shuffle(random_vec.begin(), random_vec.end(), g);
    }else{
        std::uniform_int_distribution<> distr(ini, end);
        for(auto i=0; i < num; i++){
            random_vec.push_back(distr(g));
        }
    }
    return random_vec;
}

// generates sorted container -> vector, list, dqueue.
template <template<class T, class= std::allocator<T>> class Container, typename T>
void generate_seq_container(Container<T>& container, int ini, int end){
    assert(ini <= end);
    // generate values
    for(auto value = ini; value <= end; value++) {
        container.push_back(value);
    }
}

//template <template<class Key, class= std::less<Key>, class= std::allocator<Key>> class Container, typename Key>
//void generate_seq_container(Container<Key>& container, int ini, int end){
template <typename Container>
void generate_container(Container& container, int ini, int end){
    assert(ini <= end);
    // generate values
    for(auto value = ini; value <= end; value++) {
        container.insert(value);
    }
}

template <typename iterator>
std::vector<int> shuffle_container(iterator begin, iterator end){

    std::vector<int> sh_cont;
    for(auto i= begin; i != end; ++i)
        sh_cont.push_back(*i);

    std::mt19937 g(rd());
    std::shuffle(std::begin(sh_cont), std::end(sh_cont), g);
    return sh_cont;
}

/// Insert
// inserts in container, Container can be vector, list, dqueue and (Associative containers and Unordered associative containers)
template <typename Container, typename  Vartype>
void insertSortetedValue(Container& vec, Vartype& value){
    assert(!vec.empty());
    auto it = std::lower_bound(std::begin(vec), std::end(vec), value);
    vec.insert(it, value);
}

// Container can be vector, list, dqueue (Associative containers and Unordered associative containers)
template <typename Container, typename  Srccont>
void insertSortetedContaniner(Container& cont, const Srccont& src_cont){
    assert(!cont.empty());  // better results in vector
    for(const auto& value : src_cont) {
        auto pos = std::lower_bound(std::begin(cont), std::end(cont), value);
        cont.insert(pos, value);
    }
}

// Container can be vector, list, dqueue
template <typename Container, typename  Srccont>
void insertSortetedContaniner_iter(Container& cont, const Srccont& src_cont){
    assert(!cont.empty());
    for(const auto& value : src_cont) {  // mejor para listas, aunque siempre estan por debajo de vector
        auto it = std::begin(cont);
        while (*it < value && it != cont.end()) it.next();
        cont.insert(it, value);
    }
}


/// Delete
template <typename Container, typename  Srccont>
void deletefromContaniner(Container& cont, const Srccont& src_cont){
    assert(!cont.empty());
    for(const auto& value : src_cont) {
        auto pos = std::find(std::begin(cont), std::end(cont), value);
		cont.erase(pos);
    }
}

template <typename Container, typename  Srccont>
void deletefromContaninersafe(Container& cont, const Srccont& src_cont) {
	assert(!cont.empty());
	for (const auto& value : src_cont) {
		auto pos = std::find(std::begin(cont), std::end(cont), value);
		if(pos != std::end(cont))
			cont.erase(pos);
	}
}

template <typename Container, typename  Srccont>
void deletefromContaniner_iter(Container& cont, const Srccont& src_cont){
    assert(!cont.empty());
    for(const auto& value : src_cont) {
        auto it = std::begin(cont);
        while (*it < value && it != cont.end()) it.next();
        cont.erase(it, value);
    }
}

/// Search

// accepts any type of stl container, the return value is not important 
// in case the container does not support random access iterator (like list, set, unordered_set...) the seach is not binary but linear
template <typename Container, typename  Srccont>
void bin_search(const Container& cont, const Srccont& src_cont) { 
	for (auto& value : src_cont) {
		std::binary_search(std::cbegin(cont), std::cend(cont), value);
	}
}

template <typename Container, typename  Srccont>
void search( Container& cont, const Srccont& src_cont) {
	for (auto& value : src_cont) {
		std::find(std::cbegin(cont), std::cend(cont), value);
	}
}

template <typename Container, typename  Srccont>
void search_sets(Container& cont, const Srccont& src_cont) {

	assert(is_unset(cont));  // is_set(cont) || is_unset(cont)
	for (auto& value : src_cont) {
		cont.find(value);
	}
}

/***************test************************/
namespace testc {

	// Data structure time/operation measures
	struct graph {
		graph() = default;
		graph(unsigned int n_operations, double time) : noperations(n_operations), time(time) { };
		unsigned int noperations;  // nº operation (inserts/deletes...)
		double time;  // time took each
	};

	// template pointers to functions
	template<typename Container, typename T>
	using fParam = void(*) ( Container& cont, const T& src_cont);

	void print_measures(const std::vector<graph>& times) {
		for (graph k : times) {
			std::cout << "nº inserted values: " << k.noperations << " time: " << k.time << " sec" << std::endl;
		}
	}

	// auxiliar funtion for measuring time, used for async do test calls
	template<typename Container, typename T >
	decltype(auto) operation_time(Container& cont, const T& src_cont, unsigned int n_operations ,fParam<Container&, T> foo) {
		Print_time(foo, cont, src_cont);
		return std::make_tuple(n_operations, elapsed_seconds.count());
	}

	template<typename Container, typename T >
	std::vector<graph> doTests(int ntest, Container& cont, const T& src_cont, fParam<Container&,T> foo) {
		assert(ntest <= src_cont.size());
		std::vector<graph> values;

		auto steps = src_cont.size() / ntest;
		for (auto operations = steps; operations <= src_cont.size(); operations += steps) {
			auto copyContainer = cont;  // copy the container
			T src_aux(std::begin(src_cont), std::begin(src_cont) + operations);  // range of values
			Print_time(foo, copyContainer, src_aux);
			values.push_back(graph(operations, elapsed_seconds.count()));
		}
		return values;
	}

	template<typename Container, typename T >
	std::vector<graph> doTests_async(int ntest, Container& cont, const T& src_cont, fParam<Container&, T> foo) {
		assert(ntest <= src_cont.size());
		std::vector<graph> values;

		auto steps = src_cont.size() / ntest;
		std::vector<std::future< std::tuple<unsigned int, double> >> fut_res; // return tuple<unsigned int, double>
		
		for (auto operations = steps; operations <= src_cont.size(); operations += steps) {
			auto copyContainer = cont;  // copy the container
			T src_aux(std::begin(src_cont), std::begin(src_cont) + operations);  // range of values
			// using 'insert' instead of 'push_back' becuase std::future<> objects are not CopyConstructible
			fut_res.insert(std::cend(fut_res), std::async(std::launch::async, operation_time<decltype(cont), decltype(src_cont)>, copyContainer, src_aux, operations, foo));
		}

		for (auto& fut : fut_res) {
			auto tuple = fut.get();
			values.push_back(graph(std::get<0>(tuple), std::get<1>(tuple))); // 0 -> operation, 1 -> time
		}
		return values;
	}

} // testc

/*************files cvs*************************/
void cvs_columns(std::string name, const std::vector<testc::graph> data){
    outfile.open(name, std::ios_base::app);
    assert(outfile.is_open());
    for(const testc::graph& res : data) {
        outfile << res.noperations <<"     "<< res.time<<'\n';
    }
    outfile.close();
}

/********Vector***********/

template <typename T>
void insertSorteted2(std::vector<T>& vec, T& value){
    assert(!vec.empty());
    auto it = vec.begin();
    while(*it < value  &&  it != vec.end()){
        ++it;
    }
    vec.insert(it, value);
}

#endif //CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H