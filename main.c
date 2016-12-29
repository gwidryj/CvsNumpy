#include <math.h>
#include <stdio.h>
#include <time.h>

const int N = 10000;
const int x_len = 100000;

int main()
{
    clock_t t_start, t_end;
    double x[x_len], y1[x_len], y2[x_len], res, time;
    int i, j;
    for( i = 0; i < x_len; i++ )
    {
        x[i] = 1.2345;
    }
   
    t_start = clock();
    for( j = 0; j < N; j++ )
    {
        for( i = 0; i < x_len; i++ )
        {
            y1[i] = cos(x[i]);
        }
    }
    t_end = clock();
    time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
    printf("cos: %f s\n", time);
    
    t_start = clock();
    for( j = 0; j < N; j++ )
    {
        for( i = 0; i < x_len; i++ )
        {
            y2[i] = x[i] * 7.9463;
        }
    }
    t_end = clock();
    time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
    printf("multi: %f s\n", time);
    
    t_start = clock();
    for( j = 0; j < N; j++ )
    {
        res = 0.0;
        for( i = 0; i < x_len; i++ )
        {
            res += x[i];
        }
    }
    t_end = clock();
    time = (double)(t_end - t_start) / CLOCKS_PER_SEC;
    printf("sum: %f s\n", time);
    
    return y1[0], y2[0], res;
}

// results
// cos: 20.910590 s
// multi: 0.633281 s
// sum: 1.153001 s
