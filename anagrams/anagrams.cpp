#include<iostream> 
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
	string string1, string2;

	getline(cin, string1);
	getline(cin, string2);

	char *str1 = new char[string1.size() + 1];
	char *str2 = new  char[string2.size() + 1];

	strcpy(str1,string1.c_str());
	strcpy(str2, string2.c_str());//c_str gives const char*. This step is used to convert convert const char * to char*
	//or other way can be 	char *strPtr = (char*)str.c_str();

	int i, j;
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	int c = 0;
	//char *nextToken = "";
	//char *str1Tok=strtok_s(str1," ",&nextToken);
	//cout << "--" << str1Tok;

	if (n1 != n2)
	{ //base condition
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