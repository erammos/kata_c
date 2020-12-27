#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);
int check_arr(int * array, size_t check_value,size_t n)
{
        printf("num %ld ",n);          
	size_t res =  maxSeq(array,n);
	printf("res %ld val %ld\n",res,check_value);
	return  res == check_value;
}
int main(void)
{
	int success = 0;
	int array[] = {20,1,0,2,3,10,2,4,5,6,11};
	 
	size_t n = sizeof(array) / sizeof(array[0]);
	success = check_arr(array,4,n);
	if(success)
	{
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}


