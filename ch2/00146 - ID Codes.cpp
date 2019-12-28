#include<iostream>
#include<cstdio>

#include<algorithm>

using namespace std;

int main()
{
	char arr[52];

	while(true)
	{
		scanf("%[^\n]", arr);
		cin.ignore();

		if(arr[0] == '#')
			return 0;

		
		int count = 0;
		while(arr[count] != '\0')
			count++;

		if(next_permutation(arr, arr+count))
			printf("%s\n", arr);
		else
			printf("No Successor\n");
	}
}
