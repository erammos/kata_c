#include <stdio.h>
#include <stdlib.h>
unsigned power (unsigned x, unsigned y);

void check(unsigned res1, unsigned res2)
{
       printf("%d %d\n",res1, res2);
	if(res1 != res2)
	{
		exit(EXIT_FAILURE);
	}
}
int main(void)
{
	check(1, power(2, 0));
	check(1, power(0, 0));
	check(0, power(0, 1));
	check(4, power(2, 2));
	check(1048576,power(2, 20)); 
        check(400, power(20,2));
        check(10000, power(100,2));
             	
	return EXIT_SUCCESS;
}
