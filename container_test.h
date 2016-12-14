#ifndef CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H
#define CONTAINER_PERFORMANCE_CONTAINER_TEST_H_H

#include <iostream>
#include <cassert>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iterator>

/*********Crono*************/
std::chrono::system_clock::time_point start, end;
std::chrono::duration<double> elapsed_seconds;
std::time_t end_time;

/**********random**************/
std::random_device rd;  // only used once to initialise (seed) engine

/********cvs file*************/
std::ofstream outfile;

#define Print_time(type_container,fun, ...)\
     std::cout<<"Measuring "<<type_container<<":"<<'\n';\
     start = std::chrono::system_clock::now();\
     fun(__VA_ARGS__);\
     end = std::chrono::system_clock::now();\
     elapsed_seconds = end-start;\
     end_time = std::chrono::system_clock::to_time_t(end);\
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

//template<
//
//        class Key,
//        class Compare = std::less<Key>,
//        class Allocator = std::allocator<Key>
//> class set;
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

// retruns a copy of the suffled container.
//template <typename Container, typename T>
//std::vector<T> shuffle_container(const Container& cont){
//
//    std::vector<T> sh_cont;
//
//    for(const auto& value: cont) sh_cont.push_back(value);
//    std::mt19937 g(rd());
//    std::shuffle(std::begin(sh_cont), std::end(sh_cont), g);
//    return sh_cont;
//}

template <typename Container, typename  Srccont>
void deletefromContaniner(Container& cont, const Srccont& src_cont){
    assert(!cont.empty());
    for(const auto& value : src_cont) {
        auto pos = std::find(std::begin(cont), std::end(cont), value);
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

/***************test************************/
namespace testc {

    // Data structure time/operation measures
    struct graph {
        graph() = default;
        graph(unsigned int n_operations, double time) : noperations(n_operations), time(time) { };

        unsigned int noperations;  // nº operation (inserts/deletes...)
        double time;  // time took each
    };

    // template pointer function
    template<typename Container, typename T>
    using fParam = void (*) (Container& cont, const T& src_cont);

    void print_measures(const std::vector<graph>& times){
        for(graph k : times){
            std::cout<<"nº inserted values: "<<k.noperations<<" time: "<<k.time<<" sec"<<std::endl;
        }
    }

    //std::vector<graph> doTests(int ntest, const Container &cont, const std::vector<T>& src_cont, fParam<Container,T> foo) {
    template<typename Container, typename T >
    std::vector<graph> doTests(int ntest, const Container& cont, const T& src_cont, fParam<Container,T> foo) {
        assert(ntest <= src_cont.size());
        std::vector<graph> values;

        auto steps = src_cont.size() / ntest;
        for (auto operations = steps; operations <= src_cont.size(); operations += steps) {
            auto copyContainer = cont;  // copy the container
            T src_aux(std::begin(src_cont), std::begin(src_cont) + operations);  // range of values

//                std::cout << "copyContainer before operation " << copyContainer.size() << '\n';
            Print_time("container", foo, copyContainer, src_aux);
//                std::cout << "copyContainer after operation " << copyContainer.size() << " value of i: " << operations <<
//                " value of steps: " << steps << "\n\n";
            values.push_back(graph(operations, elapsed_seconds.count()));
        }
        return values;
    }
}


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
