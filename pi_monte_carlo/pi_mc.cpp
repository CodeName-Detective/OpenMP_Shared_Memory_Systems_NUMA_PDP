#include <iostream>
#include "random.h"
#include <omp.h>

static long num_trials = 10000;

int main(){
    long i;  long Ncirc = 0;
    double pi, x, y, test, start_time, run_time;

    double r = 1.0;   // radius of circle. Side of squrare is 2*r 

    seed(-r, r);  // The circle and square are centered at the origin
    int n_threads;

    std::cout<<"Enter Number Of Threads:";
    std::cin>>n_threads;
    omp_set_num_threads(n_threads);
    
    start_time = omp_get_wtime();

    for(i=0;i<num_trials; i++){
        x = drandom(); 
        y = drandom();

        test = x*x + y*y;
        if (test <= r*r) Ncirc++;
    }

    run_time = omp_get_wtime() - start_time;

    pi = 4.0 * ((double)Ncirc/(double)num_trials);

    std::cout<<num_trials<<" trials, pi is "<<pi<<" in "<<run_time<<" seconds"<<std::endl;

}