#include <bits/stdc++.h>
using namespace std;
int lcs[1000][1000];
char s1[1000000], s2[1000000];
int longest_common_subsequence()
{
	int l1, l2, i, j;
	l1 = strlen(s1);
	l2 = strlen(s2);
	for(i=0;i<=l1;i++)
	{
		for(j=0;j<=l2;j++)
		{
			if(i == 0 || j == 0)
				lcs[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	return lcs[l1][l2];
}
void print_lcs(int l1, int l2)
{
	int i, j;
	if(l1 == 0 || l2 == 0)
		return;
	if(lcs[l1][l2] == lcs[l1-1][l2-1]+1)
	{
		print_lcs(l1-1, l2-1);
		printf("%c", s1[l1-1]);
	}
	else if(lcs[l1][l2] == lcs[l1-1][l2])
		print_lcs(l1-1, l2);
	else
		print_lcs(l1, l2-1);
}
int main()
{
	printf("Enter the first string ");
	scanf("%s", s1);
	printf("Enter the second string ");
	scanf("%s", s2);
	printf("The length of lcs is %d\nThe lcs is ", longest_common_subsequence());
	print_lcs(strlen(s1), strlen(s2));
	printf("\n");
return 0;
}