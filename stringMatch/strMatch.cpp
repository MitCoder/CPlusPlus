
#include<iostream>
#include<cstring>


using namespace std;
int* shiftTable(char *pattern, int plen, int tlen);
void horsePool(int *table, char* pattern, char* text);

int * shiftTable(char *pattern, int plen, int tlen)
{

	int *table = new int[255];
	//to find the length of table use strlen..and not sizeof.because sizeof pointer is 8 in my architecture
	// int * t=new int[4];
	for (int i = 0; i < 255; i++)
	{
		table[i] = plen;
	}
	for (int i = 0; i < plen-1 ; i++)
	{
		table[pattern[i]] = plen - i - 1;
		//cout << table[pattern[i]] << "---" << (int)pattern[i] << pattern[i] << endl;
	}
	return table;

}
void horsePool(int *table, char* pattern, char* text)
{

	int plen = strlen(pattern);
	int tlen = strlen(text);
	int k;
	for (int i = plen - 1; i <= tlen - 1;)
	{

		for (k = 0; k <= plen-1 && pattern[plen - 1 - k] == text[i - k]; k++)
		{
			cout <<pattern[plen - 1 - k] <<"---"<<text[i - k]<<" k "<<k <<" i "<<i<< endl;//looping till it meets a match
		}

		if (k == plen)
		cout << "string match at location "<<i - plen+1;


		i += table[text[i]];
	}
	cin.get();

}
int main()
{
	char *text = "James Bond went to shop";
	char *pattern = "Bond";

	int plen = strlen(pattern);
	int tlen = strlen(text);

	int *table=	shiftTable(pattern, plen, tlen);
	horsePool(table, pattern, text);
	
	return 0;
}
