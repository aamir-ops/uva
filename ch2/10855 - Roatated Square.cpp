#include<iostream>

using namespace std;

int arrValue(int **B, int i, int j, int n)
{
	return *(*(B+i*n) + j);
}
char ** assign(int N)
{
	int i;
	char **A = new char *[N];
	for(i=0; i<N; i++)
		A[i] = new char [N];
	return A;
}

void freeIt(char ** A, int N)
{
	for(int i=0; i<N; i++)
		free(A[i]);
	free(A);
}

void rotate(char **B, int n)
{
	char ** Bt = assign(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			Bt[i][j] = B[i][j];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			B[j][n-i-1] = Bt[i][j];
	freeIt(Bt, n);
}

void printArr(char **A, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}
void printOcc(char **A, int N, char **B, int n)
{
	int i1, j1, i2, j2, counter=0;
	bool flag;

	for(i1=0; i1<N-n+1; i1++)
	{
		for(j1=0; j1<N-n+1; j1++)
		{
			if(A[i1][j1] != B[0][0])
				continue;
			flag=true;
			for(i2=0; i2<n && flag; i2++)
			{
				for(j2=0; j2<n && flag; j2++)
				{
					if(A[i1+i2][j1+j2] != B[i2][j2])
					{
						flag = false;
						break;
					}
				}
			}
			if(flag)
				counter++;
		}
	}
	cout << counter;
}
void getInput(char **A, int N)
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> A[i][j];
}
int main()
{
	int N, n;

	int i, j;
	while(true)
	{
		cin >> N >> n;

		if(N==0 && n==0)
			return 0;

		char **A, **B;
		A = assign(N); 
		B = assign(n);

		getInput(A, N);
		getInput(B, n);
		for(i=1; i<=4; i++)
		{
			printOcc(A, N, B, n);
			if(i!=4)
				cout << " ";
			rotate(B, n);
		}

		freeIt(A, N);
		freeIt(B, n);

		cout << endl;
	}
}
