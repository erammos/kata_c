#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main(void)
{
   int success = 0;
   int array[] = {2,3,4,2,3,9};
   
size_t n =  maxSeq(array,sizeof(array));

success = n == 3;
if(success)
{
 return EXIT_SUCCESS;
}
return EXIT_FAILURE;
}


