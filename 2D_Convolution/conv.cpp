#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <vector>
#include <omp.h>

#include "conv.hpp"


int main() {
    long long int n, m;
    int n_threads;

    std::cout << "Number of Matrix Order:";
    std::cin >> n;
    
    m = n;

    if (n * m < 32) {
        std::cout << "hey, A is too small even for debugging!" << std::endl;
        return -1;
    }

    std::vector<float> A(n * m);
    std::vector<float> C(n*m, 0.0f);

    const int KSIZE = 3 * 3;
    std::vector<float> K(KSIZE);

    // we hard-code const to be deterministic
    std::mt19937 gen(666);
    std::lognormal_distribution<float> N(0.0, 10.0);
    std::generate(std::begin(A), std::end(A), std::bind(N, gen));
    std::generate(std::begin(K), std::end(K), std::bind(N, gen));

    std::cout << "Number of Threads:";
    std::cin >> n_threads;

    omp_set_num_threads(n_threads);
    // now running your awesome code from a0.hpp
    auto t0 = std::chrono::system_clock::now();
    //filter_2d_seq(n, m, K, A, C);
    filter_2d_parallel(n, m, K, A, C);

    auto t1 = std::chrono::system_clock::now();

    auto elapsed_par = std::chrono::duration<double>(t1 - t0);
    std::cout <<"Elapsed time is:"<<elapsed_par.count() << std::endl;

    return 0;
} // main