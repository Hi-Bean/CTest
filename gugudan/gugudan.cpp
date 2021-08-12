#include <iostream>

int main()
{
	int i, j, k;
	int row = 3;

	// N X M 구구단 프로그램
	for (i = 2; i < 9; i += row) // row : 가로 방향 열 수
	{
		for (j = 1; j <= 9; j++)
		{
			for (k = 0; k < row; k++)  // row : 가로 방향 열 수
			{
				printf("%2d * %2d = %3d   ", i + k, j, (i + k) * j);
			}
			printf("\n");
		}
		printf("\n");
	}
}