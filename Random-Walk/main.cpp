#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>

#define EXPERIENCES_COUNT 10000
#define ITERATIONS 10000
#define INITIAL_VALUE 1000
#define BARRIER_VALUE 1020

using namespace std;

inline double closed_interval_rand(double x0, double x1)
{
    return x0 + (x1 - x0) * rand() / ((double) RAND_MAX);
}

inline double random_value()
{
    return closed_interval_rand(0,1);
}

inline double random_value_centered()
{
    return random_value()-0.5;
}

int main(void)
{
    srand(time(NULL));
    double value = INITIAL_VALUE;

    double count = 0;
    double barrier_reached_count = 0;
    double barrier = BARRIER_VALUE;

    for(int k = 0; k < EXPERIENCES_COUNT; k++)
    {
        for(int i = 0; i < ITERATIONS; i++)
        {
            if(value > barrier)
            {
                barrier_reached_count++;
                break;
            }

            cout << value << endl;
            value += random_value_centered();
        }
        count++;
        value = INITIAL_VALUE;
    }

    cout << "count = " << count << endl;
    cout << "barrier reached count = " << barrier_reached_count << endl;


    return 0;
}
