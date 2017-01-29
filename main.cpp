#include <iostream>
#include "stdafx.h"

int main()
{
	char wordTable[7][30] = { "abcde", "aba", "abccc", "cccba", "edcba", "cccba", "aba" };
	int occTable[7][26] = { 0 }; //occurence table that converts wordTable to decimal
	int groupTable[7] = { 0 };
	int rowSize = (sizeof(wordTable) / sizeof(wordTable[1])); ////how many rows
	const int alphaLength = 26; //amount of letters in alphabet
	char c; //used to get characters
	int j = 0; //marks position of character in alphabet
	


	//putting words into table
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; (c = wordTable[i][j]) && (c != '\n'); j++)
		{
			c = toupper(c);
			occTable[i][c - 'A'] += 1;
		}
	}


	//counting occurrences 
	groupTable[0]++;
	for (int i = 0; i < rowSize; i++)
	{
		for (int x = i+1; x < rowSize; x++)
		{
			while ((occTable[i][j] == occTable[x][j]) && (j < alphaLength))
			{
				j++;
			}
			if (j == 26) //if all of row 'i' equals all of row 'x', 
			{
				groupTable[i]++;
			}
			j = 0;
		}
	}


	//printing
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < alphaLength; j++)
		{
			if (wordTable[i][j] != ' ' && groupTable[i] != 0)
			{
				std::cout << wordTable[i][j];
			}
		}
		if (groupTable[i] != 0)
		{
			std::cout << " occurs " << groupTable[i] << " times" << std::endl;
		}
	}
}
		



