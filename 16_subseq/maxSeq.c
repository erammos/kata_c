#include <stdlib.h>
#include <stdio.h>
size_t max(size_t a, size_t b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

size_t maxSeq(int * array, size_t n)
{
    if( n <= 0 ) return 0;
    int curr_max = array[0];
    size_t curr_count = 1;
    size_t max_count = 1;

    for(int i = 1; i < n; i++)
    {
        if(curr_max < array[i])
        {
            curr_count++;
        }
        else
        {
            max_count = max(curr_count,max_count); 
            curr_count = 1;
        }
        curr_max = array[i];
    }
    max_count = max(curr_count,max_count); 

    return max_count;
}

