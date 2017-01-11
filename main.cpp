// 20Anagrams.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int main()
{
	int wordTable[10][27] = { 0 };

	int rowSize = (sizeof(wordTable) / sizeof(wordTable[1])); ////how many rows (10)
	int colSize = ((sizeof(wordTable) / rowSize)/sizeof(wordTable[0][0]))-1; 
	cout << rowSize << '\n';
	int i = 0;
	int z = 1;
	int j;
	char c;

	exitLoop:
	while(i < rowSize)
	{
		cout << "enter word " << i + 1 << ": ";
		c = getchar();

		for (; c != '\n';)//puts letters of word into table array
		{
			c = toupper(c);
			wordTable[i][c - 'A'] += 1; //converts letters into decimal equivalent, adds 1 to position in array
			c = getchar();
		}
		for (j = i; j > 0; j--) //j = current position (j-- goes up 1 row)
		{
			for (int x = 0; x < colSize; x++)
			{
				if (wordTable[i][x] != wordTable[j][x])
				{
					z++;
					wordTable[i][26] = z;
					cout << wordTable[i][26] << '\n';
					i++;
					goto exitLoop;
				}
			}
		}
		wordTable[i][26] = wordTable[j][26];
		cout << wordTable[i][26] << '\n';
		i++;

	}
	//cout << wordTable;



}

