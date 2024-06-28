#include <iostream>
static long num_steps = 100000000;
double step = 1.0/(double) num_steps;

int main(){
    double pi, sum=0.0, x;
    double start_time, run_time;


    for(int i=1; i<=num_steps; i++){
        x = (i-0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    } 


    pi = step * sum;

    std::cout<<"pi with "<<num_steps<<" steps is "<<pi<<"\n";
    return 0;
}