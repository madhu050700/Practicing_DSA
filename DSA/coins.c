#include <stdio.h>

// Function to find the total number of distinct ways to get change of N
// from u
int min(int x,int y){
	if(x<y)
		return x;
	else
		return y;
	
}
int count(int S[], int n, int N) {

	int T[n+1][N+1];
	int i,j;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= N; j++)
		{
			if(i==0)
				T[i][j] = 0;
			if (j == 0)
				T[i][j] = 1;
			else if (S[i-1] > j)
				T[i][j] = T[i - 1][j];
			else
				T[i][j] = min(T[i - 1][j],1+T[i][j - S[i-1]]);
		}
	}

	return T[n][N];
}


int main(void)
{
	// n coins of given denominations
	int S[] = { 1, 5, 6, 9 };
	int n = sizeof(S) / sizeof(S[0]);

	// Total Change required
	int N = 10;

	printf("Minimum coins %d", count(S, n, N));

	return 0;
}

