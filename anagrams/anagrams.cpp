#include<iostream> 
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
	char *str1="";
	char *str2 = "";
	cin>>str1;
	cin >> str2;

	int i, j;
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	int c = 0;
	char *nextToken = NULL;
	char *str1Tok=strtok_s(str1," ",&nextToken);
	cout << "--" << str1Tok;
	if (n1 != n2)
	{
		cout << "\nThey are not anagrams------------------------- ! ";
		cin.get();

		return 0;
	}
	else
	{
		for (i = 0; i < n1; i++)
		{

			for (j = 0; j < n2; j++)
			{
			
				if (str1[i] == str2[j])
				{
					++c;
					break;
				}
			}
		}
	}
	if (c == n1)
	{
		cout << "yes ! anagram !!!!!!!!!!!!!!!!!!!!! ";
		cin.get();
	}
	else
		cout << "no ! ";
	system("pause");
	return 0;
}