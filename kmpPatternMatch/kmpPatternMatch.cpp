//kmp string pattern searching algorithm
#include<iostream>
using namespace std;

void kmpAlgo(char *text, char *pattern);
void compareTable(char *pattern, int patterlen,int *compTable);

void kmpAlgo(char *text, char *pattern)
{
	int textLen = strlen(text);
	int patternLen = strlen(pattern);
	//this table tracks the repeated char in pattern.
	int *compTable = new int[patternLen];
	int i = 0;
	int j = 0;
	int count = 0;
	compareTable(pattern, patternLen,compTable);
	
	while (i < textLen)
	{
		if (pattern[j] == text[i])
		{
			i++;
			j++;
		}
		if (j == patternLen)
		{
			count++;
			cout << "string found at " << i - j << " index" << endl;
		}
		if (pattern[j] != text[i])
		{
			if (j != 0)
				j = compTable[j - 1];
			else
				i++;
		
		}
	}
	cout << "Total # of occurances of pattern " << count << endl;

	cin.get();

}
void compareTable(char *pattern, int patternlen, int *compTable)
{
	int tableLen = 0;
	compTable[tableLen] = 0;
	int i = 1;

	while (i < patternlen)
	{ //ABABCABAB
		if (pattern[i] == pattern[tableLen])
		{
			tableLen++;
			compTable[i] = tableLen;
			i++;
		}
		else
		{
			if (tableLen != 0)
			{
				tableLen = compTable[tableLen - 1];
			}
			else
			{
				compTable[i] = 0;
				i++;
			}
		}
	}
	cin.get();
}

int main()
{
	char *text = "ABCBDABACDABABCABAB";
	char *pattern = "ABC";
	kmpAlgo(text, pattern);
	return 0;

}