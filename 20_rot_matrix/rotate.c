#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10])
{
	char temp[10][10];

	for(int i = 0; i < 10 ; i++)
	{
		for(int j = 0; j < 10;j++)
		{
			temp[i][j] = matrix[10 - j - 1][i];
		}
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10;j++)
		{
			matrix[i][j] = temp[i][j];
		}
	}

}
