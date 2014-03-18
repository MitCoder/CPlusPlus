/*the letters are not suppose to be contiguous in the subsequence problem
O(strlen * strCompLen) is the time complexity
*/

#include<iostream>
#include<string>
using namespace std;

void LCS(char *str, char *strComp);
int max(int a, int b);

int max(int a, int b)
{
	return (a > b) ? a : b;
}
void LCS(char *str, char *strComp)
{
	int strCompLen = strlen(strComp);
	int strLen = strlen(str);
	
    int** strArr = new int*[strLen];
	for (int i = 0; i <= strLen; ++i)
		strArr[i] = new int[strCompLen];// this is 2d strArr array which is created dynamically

	for (int i = 0; i < strLen; i++)
	{
		strArr[i][0] = 0;//initializing i'th part such that all rows with first j'th column (col 0) will be 0
	}
	for (int j = 0; j < strCompLen; j++)
	{
		strArr[0][j] = 0;//initializing j'th part such that all columns with first i'th row (row 0) will be 0
	}

	for (int i = 1; i <= strLen; i++)
	{
		for (int j = 1; j <= strCompLen; j++)
		{
            if (str[i] == strComp[j])
			{
				strArr[i][j] = strArr[i - 1][j - 1] + 1;
			}
			else
				strArr[i][j] = max(strArr[i-1][j], strArr[i][j-1]);
		}

	}
	cout << "Length of the longest commom subsequence '" << strArr[strLen][strCompLen]  << endl;
	cin.get();

}
int main()
{
	char *str = "ABA";
	char *strComp = "ACA";

	LCS(str, strComp);

}