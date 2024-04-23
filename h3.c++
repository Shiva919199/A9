#include <iostream>
#include <omp.h>
#include <iomanip>
using namespace std;
int main()
{
    // omp_set_num_threads(4);
    double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double max_val = 0.0;
    double min_val = 100.0;
    float avg = 0.0, sum = 0.0, sum_val = 0.0;
    int i;

    #pragma omp parallel for reduction(min : min_val)
    for (i = 0; i < 10; i++)
    {
        // printf("thread id = %d and i = %d \n", omp_get_thread_num(), i);
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    cout<<"min_val: "<<setprecision(5)<<min_val<<endl<<endl;
    

    #pragma omp parallel for reduction(max : max_val)
    for (i = 0; i < 10; i++)
    {
        // printf("thread id = %d and i = %d \n", omp_get_thread_num(), i);
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    cout<<"max_val: "<<setprecision(5)<< max_val<<endl<<endl;
 
    #pragma omp parallel for reduction(+ : sum_val)
    for (i = 0; i < 10; i++)
    {
        // printf("thread id = %d and i = %d \n", omp_get_thread_num(), i);
        sum_val = sum_val + arr[i];
    }
    cout<<"sum_val: "<<setprecision(5)<< sum_val<<endl<<endl;

#pragma omp parallel for reduction(+ : sum)
    for (i = 0; i < 10; i++)
    {
        // printf("thread id = %d and i = %d \n", omp_get_thread_num(), i);
        sum = sum + arr[i];
    }
    avg = sum / 10;
    cout<<"avg_val: "<<setprecision(5)<< avg<<endl<<endl;
}
