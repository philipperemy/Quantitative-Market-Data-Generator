#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;

inline double closed_interval_rand(double x0, double x1)
{
    return x0 + (x1 - x0) * rand() / ((double) RAND_MAX);
}

inline double random_value()
{
    return closed_interval_rand(0,1);
}

void free_array(double * array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void disp(double * array)
{
    cout << "[ " << array[0] << " ; " << array[1] << " ; " << array[2] << " ; " << array[3] << " ]" << endl;
}

void push(double * array, double open, double high, double low, double close)
{
    array[0] = open;
    array[1] = high;
    array[2] = low;
    array[3] = close;
}

int main(void)
{
    srand(time(NULL));
    double data[4];
    free_array(data, 4);

    double count = 0;
    double barrier_reached_count = 0;
    double barrier_value = 1100;

    double high = 1000;
    double close = high - random_value();
    double low = close - random_value();
    double open = (high - low) * random_value() + low;
    double oldOpen;

    push(data, open, high, low, close);
    //disp(data);

    for(int i = 0; i < 100; i++)
    {

        for(int it_day = 2; it_day <= 200; it_day++)
        {

            if(high>barrier_value)
            {
                cout << "barrier reached" << endl;
                barrier_reached_count++;
                break;
            }

            high = open + random_value();
            close = high - random_value();
            low = close - random_value();
            oldOpen = open;
            open = (high - low) * random_value() + low;

                if (low > oldOpen) {
                    low = oldOpen;
                }

                push(data, open, high, low, close);
                //disp(data);
        }

        count++;
        free_array(data);
    }

    cout << "count = " << count << endl;
    cout << "barrier reached count = " << barrier_reached_count << endl;


    return 0;
}
