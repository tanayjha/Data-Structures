#include <bits/stdc++.h>
using namespace std;
int board[100][100];
bool isSafe(int row, int col, int n)  /* Check if it is a SAFE POSITION */
{
	int i, j;
	for(i=0;i<col;i++)       /* Check the ROW to the left */
	{
		if(board[row][i] == 1)
			return false;
	}
	for(i=row, j = col; i>=0 && j>=0; i--, j--)   /* Check the UPPER DIAGONAL elements */
	{
		if(board[i][j] == 1)
			return false;
	}
	for(i = row, j = col; j>=0 && i<n; i++, j--)  /* Check the LOWER DIAGONAL elements */
	{
		if(board[i][j] == 1)
			return false;
	}
	return true;
}
bool solve(int col, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(col>=n)
			return true;
		if(isSafe(i, col, n))
		{
			board[i][col] = 1;

			if(solve(col+1, n) == true){  /* Results in a solution RECURSIVE CALL */
				return true;
				continue;
			}
			board[i][col] = 0;  /* Trigger BACKTRACKING */
		}
	}
	return false;  /* CANNOT be placed in that COLUMN */
}
int main()
{
	int i, j, n;
	bool ans;
	printf("Enter the no. of queens for which you want to solve\n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
		for(j = 0;j<n;j++)
			board[i][j] = 0;
	for(int k = 0; k < n; k++){
		board[k][0] = 1;
		ans = solve(1, n);
		if(ans)
		{
			for(i=0;i<n;i++)
			{
				for(j = 0; j<n; j++)
				{
					if(board[i][j])
						printf("Q ");
					else
						printf("- ");
				}
				printf("\n");

			}
		}
		printf("\n\n");
		memset(board, 0, sizeof (board));
	}
	return 0;
}