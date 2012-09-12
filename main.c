#include <stdio.h>

void printfsudoku(int s[9][9]);
int check(int s[9][9]);
//int generate(int s[9][9]);

int main()
{
	int t;
	int sudoku[9][9] =
	{
		{ 7, 4, 1, 6, 9, 8, 3, 2, 5},
		{ 5, 3, 8, 2, 4, 1, 6, 7, 9},
		{ 9, 2, 6, 3, 7, 5, 4, 1, 8},
		{ 4, 1, 3, 8, 2, 6, 9, 5, 7},
		{ 2, 6, 7, 5, 3, 9, 8, 4, 1},
		{ 8, 5, 9, 4, 1, 7, 2, 3, 6},
		{ 1, 9, 2, 7, 8, 3, 5, 6, 4},
		{ 3, 7, 5, 9, 6, 4, 1, 8, 2},
		{ 6, 8, 4, 1, 5, 2, 7, 9, 3}
	};

	printfsudoku(sudoku);
	t = check(sudoku);

	while (t==1)
	{
		//generate(sudoku);
		t = check(sudoku);
	}
	printf ("la solucion es:\n");

	printfsudoku(sudoku);

	return 0;
}

void printfsudoku(int s[9][9])
{
	int i, j, k;

	for(i=0; i < 15; i++)
		printf("#");
	printf("\n");

	for(i=0; i<9; i++)
	{
		if (i == 3 || i == 6)
		{
			printf("# ");
			for(k=0; k < 11; k++)
				printf("-");
			printf(" #\n");
		}
		printf ("# ");
		for(j=0; j<9; j++)
		{
			if(j == 3 || j == 6)
				printf("|");
			if(s[i][j] == 0)
				printf (" ");
			else
				printf("%d", s[i][j]);

		}
		printf(" #\n");
	}

	for(i=0; i < 15; i++)
		printf("#");
	printf("\n");
}

int check(int s[9][9])
{

	int i, j, k, l, suma;

	for(i=0; i<9; i++)
	{
		suma = 0;
		for(j=0; j<9; j++)
			suma += s[i][j];
		if (suma != 45)
			return 1;
	}
	for(i=0; i<9; i++)
	{
		suma = 0;
		for(j=0; j<9; j++)
			suma += s[j][i];
		if (suma != 45)
			return 1;
	}

	suma = 0;
	for(i=0; i < 3; i++)
		for (j=0; j < 3 ; j++)
		{
			suma=0;
			for (k=0; k < 3; k++)
				for(l=0; l < 3; l++)
					suma += s[i*3+k][j*3+l];
			if(suma != 45)
				return 1;
		}


	return 0;


/*	int i, j, k, l;

	for(i=0; i < 9; i++)
	{
		for(j=0; j < 9; j++)
		{
			for(k=0; k < 9; k++)
			{
				printf ("%d\n", k);
				if(s[i][j] == s[i][k] && j!=k)
					return 1;
				else if(s[i][j] == s[k][j] && i!=k)
					return 1;

				for(l=0; l < 9; l++)
				{
					if(s[i][j] == s[k][l] && (i!=j!=k!=l) && i<4 && j<4 && k<4 && l<4) //square (1,1)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && 3<i<7 && 3<j<7 && 3<k<7 && 3<l<7) //square (2,2)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && 6<i && 6<j && 6<k && 6<l) //square (3,3)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && 3<i<7 && j<4 && 3<k<7 && l<4) //square (2,1)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && 6<i && j<4 && 6<k && l<4) //square (3,1)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && i<4 && 3<j<7 && k<4 && 3<l<7) //square (1,2)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && i<4 && 6<j && k<4 && 6<l) //square (1,3)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && 3<i<7 && 6<j && 3<k<7 && 6<l) //squares (2,3)
						return 1;
					else if(s[i][j] == s[k][l] && (i!=j!=k!=l) && 6<i && 3<j<7 && 6<k && 3<l<7) //square (3,2)
						return 1;
				}
			}
		}
	}

	return 0;*/
}
