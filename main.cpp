#include <iostream>
#include "stdafx.h"
 
int main()
{
	const int wordLength = 30;
	char wordTable[][wordLength] = { "abc", "abcd", "abc", "abcde", "abc", "abcd", "abc", "abcde", "abcd", "abcdef", 
									  "abc", "abcd", "abc", "abcde", "abc", "abcd", "abc", "abcde", "abcd", "abcdef"};
	int occTable[20][26] = { 0 }; //occurence table that converts wordTable to decimal
	int groupTable[20] = { 0 };
	int rowSize = (sizeof(wordTable) / sizeof(wordTable[0])); ////how many rows
	const int alphaLength = 26; //amount of letters in alphabet
	char c; //used to get characters
	int j = 0, counter = 0, x, m = 0; //marks position of character in alphabet



	//putting words into table
	for (int i = 0; i < rowSize; i++)
	{
		//std::cout << "enter word " << i + 1 << ": ";
		for (int j = 0; (c = wordTable[i][j]) && (c != '\n'); j++)
		{
			c = toupper(c);
			wordTable[i][j] = c;
		}
	}
	std::cout << "word table complete" << std::endl;

	//counting occurrences
	
	for (int i = 0; i < rowSize; i++)
	{		
		for (int p = 0; p < wordLength; p++)
		{
			m = wordTable[i][p] - 'A';
			if(m >= 0)
				occTable[i][m]++;
		}
		for (x = 0; x < i; x++)
		{
			j = 0;
			while (occTable[i][j] == occTable[x][j] && (j < alphaLength))
			{
				j++;
			}
			if (j == 26) //if all of row 'i' equals all of row 'x', 
			{
				groupTable[i] = groupTable[x];				
				break;
			}
		}
		if (x == i)
		{
			counter++;
			groupTable[i] = counter;
		}
	}
	


	//printing
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < alphaLength; j++)
		{
			if (wordTable[i][j] != ' ')
			{
				std::cout << wordTable[i][j];
			}
			
		}
		std::cout << " Group: " << groupTable[i] << std::endl;
	}
}


