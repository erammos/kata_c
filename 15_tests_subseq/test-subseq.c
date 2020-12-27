#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);
int check_arr(int * array, size_t check_value,size_t n)
{
	printf("num %ld ",n);          
	size_t res =  maxSeq(array,n);
	printf("res %ld check %ld\n",res,check_value);
	return  res == check_value;
}
int test1()
{
	int array[] = {-10,-9,-8,0,4 };

	size_t n = sizeof(array) / sizeof(array[0]);
	return check_arr(array,5,n);
}
int test2()
{
      int array[] = {2,5};
	return check_arr(array,0,0);
}

int test3()
{
	int array[] = {1,1,1};
	size_t n = sizeof(array) / sizeof(array[0]);

	return check_arr(array,1,n);

}
int test4()
{
	int array[] = {5,4,3,2,2,2,3,3,3};
	size_t n = sizeof(array) / sizeof(array[0]);
	return check_arr(array,2,n);
}

int test5()
{
	int array2[] = {-1};
	return check_arr(array2,1,1);
}
int main(void)
{
        int success = test1();
        success &= test2();
        success &= test3();
 	success &= test4();
        success &= test5();
	if(success)
	{
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}


