// 20Anagrams.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int main()
{
	int wordTable[20][26] = { 0 };
	int rowSize = sizeof(wordTable) / sizeof(wordTable[1]);
	int colSize = sizeof(wordTable) / rowSize;
	cout << rowSize << '\n';
	int i = 0;
	char c;


	for (i; i < rowSize; i++)
	{
		cout << "enter word " << i + 1 << ": ";
		c = getchar();

		for (; c != '\n';)
		{
			c = toupper(c);
			wordTable[i][c - 'A'] += 1;
			c = getchar();
		}
		for (int j = 0; j < rowSize; j++)
		{
			if(a[i][j] == )
		}
	}
}

