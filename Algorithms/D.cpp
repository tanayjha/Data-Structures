#include <bits/stdc++.h>
using namespace std;
int board[100][100], c = 0;
bool isSafe(int row, int col, int n)  
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
void printMat(){
	int i, j;
	for(i=0;i<8;i++)
			{
				for(j = 0; j<8; j++)
				{
					if(board[i][j])
						printf("Q ");
					else
						printf("- ");
				}
				printf("\n");

			}
		printf("\n\n");
}
void solve(int col, int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(isSafe(i, col, n))
		{
			board[i][col] = 1;
			if(col == n-1){
				c++;
				printMat();
			}
			solve(col+1, n);
			for(int k = col; k < n; k++){
				for(int r = 0; r < n; r++){
					board[r][k] = 0;
				}
			}
			board[i][col] = 0;  
		}
	}
	return;  
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
		solve(1, n);	
		memset(board, 0, sizeof (board));
	}
	cout<<c<<endl;
	return 0;
}