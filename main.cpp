// 20Anagrams.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int main()
{
	int wordTable[27][20] = { 0 };
	int rowSize = (sizeof(wordTable) / sizeof(wordTable[1])) - 1;
	int colSize = sizeof(wordTable) / rowSize;
	cout << rowSize << '\n';
	int i = 0;
	int z = 1;
	char c;


	for (i; i < rowSize; i++)
	{
		cout << "enter word " << i + 1 << ": ";
		c = getchar();

		for (; c != '\n';)//puts letters of word into table array
		{
			c = toupper(c);
			wordTable[i][c - 'A'] += 1; //converts letters into decimal equivalent, adds 1 to position in array
			c = getchar();
		}
		for (int j = 0; j < rowSize; j++) //check for repeated digits in rows
		{
			for (int x = i; x > 0; x--) //checks for repeated digits in columns
			{
				if (wordTable[j][x] != wordTable[j][x - 1])
				{
					wordTable[27][x] = z;
					z++;
					goto exitLoop;
				}

			}
		}
	exitLoop:
	}
}

