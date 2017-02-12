#ifndef CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H
#define CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H

#include <iostream>
#include <cassert>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iterator>
#include <future>
#include <tuple>
#include <string>

/*********Crono*************/
std::chrono::system_clock::time_point start, end;
std::chrono::duration<double> elapsed_seconds;

/**********random**************/
std::random_device rd;  // only used once to initialise (seed) engine

/********cvs file*************/
std::ofstream outfile;

#define Print_time(fun, ...)\
     start = std::chrono::system_clock::now();\
     fun(__VA_ARGS__);\
     end = std::chrono::system_clock::now();\
     elapsed_seconds = end-start;\
	 std::cout<< "  -elapsed time: " << elapsed_seconds.count() << " s\n";

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
template<typename T>
std::vector<T> generate_random_vector(T ini, T end, int num=0){

    assert(ini <= end && end >= num && num >=0);
    std::vector<T> random_vec;
    std::mt19937 g(rd());
    if(!num){
        // generate values
        for(auto value = ini; value <= end; value++) {
            random_vec.push_back(value);
        }
        // shuffle vector values
        std::shuffle(random_vec.begin(), random_vec.end(), g);
    }else{
        std::uniform_int_distribution<T> distr(ini, end);
        for(auto i=0; i < num; i++){
            random_vec.push_back(distr(g));
        }
    }
    return random_vec;
}


template <typename It>
void shuffle_container(It begin, It end){
    std::mt19937 g(rd());
    std::shuffle(begin, end, g);
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
//	assert(is_set(cont));  // is_set(cont) || is_unset(cont)
	for (auto& value : src_cont) {
		cont.find(value);
	}
}

/***************test************************/
namespace testc {

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
//	auto operation_time(Container& cont, const T& src_cont, unsigned int n_operations ,fParam<Container&, T> foo) {
    auto operation_time(Container cont, T src_cont, unsigned int n_operations ,fParam<Container, T> foo) {
		std::chrono::system_clock::time_point start, end;
		std::chrono::duration<double> elapsed_seconds;

		start = std::chrono::system_clock::now();
		foo(cont, src_cont);
		end = std::chrono::system_clock::now();

		elapsed_seconds = end - start;
		std::cout << "  -elapsed time: " << elapsed_seconds.count() << " s\n";
		//Print_time(foo, cont, src_cont);
		return std::make_tuple(n_operations, elapsed_seconds.count());
	}

    template<typename F, typename... TS>
    std::vector<std::chrono::duration<double>> uni_alg_test(F function, TS... args){
        std::vector< std::chrono::duration<double> > values;

        start = std::chrono::system_clock::now();
        function(args...);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        //std::cout<<elapsed_seconds.count()<<'\n';
        values.push_back(elapsed_seconds);
        return values;
    };


    template<typename C, typename F, typename... TS>
    std::vector<graph> doTest_new(C container, F function, TS... args){
        std::vector<graph> values;

        for(const auto& val : container){
            start = std::chrono::system_clock::now();
            function(args..., val);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end-start;
            std::cout<<elapsed_seconds.count()<<'\n';
            //elapsed_seconds += end-start;
        }
        //values.push_back(elapsed_seconds);
        return values;
    };



	template<typename Container, typename T >
	std::vector<graph> doTests(int ntest, Container& cont, const T& src_cont, fParam<Container&, T> foo) {
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
//*
//	template<typename Container, typename T >
//	std::vector<graph> doTests_async(int ntest, Container& cont, const T& src_cont, fParam<Container&, T> foo) {
//		assert(ntest <= src_cont.size());
//		std::vector<graph> values;
//
//		auto steps = src_cont.size() / ntest;
//		std::vector<std::future< std::tuple<unsigned int, double> >> fut_res; // return tuple<unsigned int, double>
//		for (auto operations = steps; operations <= src_cont.size(); operations += steps) {
//			auto copyContainer = cont;  // copy the container
//			T src_aux(std::begin(src_cont), std::begin(src_cont) + operations);  // range of values
//			// using 'insert' instead of 'push_back' because std::future<> objects are not CopyConstructible
//			fut_res.insert(std::cend(fut_res), std::async(std::launch::async, operation_time<decltype(cont), decltype(src_cont)>, copyContainer, src_aux, operations, foo));
//		}
//		for (auto& fut : fut_res) {
//			auto tuple = fut.get();
//			values.push_back(graph(std::get<0>(tuple), std::get<1>(tuple))); // 0 -> operation, 1 -> time
//		}
//		return values;
//	}//*/

} // testc

/*************files cvs*************************/
void cvs_columns(std::string file_name, const std::vector<graph> data, std::string op_col = "operations", std::string time_col = "time") {
	outfile.open(file_name, std::ios_base::app);
	assert(outfile.is_open());
	outfile << op_col << "," << time_col << '\n';
	for (const graph& res : data) {  // testc::graph&
		outfile << res.noperations << "," << res.time << '\n';
	}
	outfile.close();
}



/// read/write source(random, sequencial) data to files
template<typename T>
void write_src(std::string file_name, const std::vector<T>& src_container) {
	outfile.open(file_name, std::ios_base::app);
	assert(outfile.is_open());
	for (const auto& val : src_container) {
		outfile << val << '\n';
	}
	outfile.close();
}

template<typename T>
std::vector<T> read_src(std::string file_name) {
	std::ifstream infile;
	infile.open(file_name, std::ios_base::in );
	assert(infile.is_open());

	std::vector<T> src_container;
	T value;
	infile >> value; infile.get();
	while (!infile.eof()) {
		src_container.push_back(value);
		infile >> value;
		infile.get();		
	}
	return src_container;
}

// does not append and it will not
template<typename T>
void write_src_bin(std::string file_name, const std::vector<T>& src_container) {
	outfile.open(file_name, std::ios_base::app | std::ios_base::binary);
	assert(outfile.is_open());
	for (const auto& val : src_container) {
		outfile.write(reinterpret_cast<const char*>(&val), sizeof(val));
	}
	outfile.close();
}
 
template<typename T>
std::vector<T> read_src_bin(std::string file_name) {
	std::ifstream infile;
	infile.open(file_name, std::ios_base::in | std::ios_base::binary);
	assert(infile.is_open());

	std::vector<T> src_container;
	T value;
	infile.read(reinterpret_cast<char*>(&value), sizeof value);
	while (!infile.eof()) {
		src_container.push_back(value);
		infile.read(reinterpret_cast<char*>(&value), sizeof value);		
	}
	return src_container;
}

#endif //CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H