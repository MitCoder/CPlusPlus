//Dynamic programming to find the length of longest common substring

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
	int count = 0;
	int** strArr = new int*[strLen];
	for (int i = 0; i <= strLen; ++i)
		strArr[i] = new int[strCompLen];// this is strArr

	for (int i = 0; i <= strLen; i++)
	{
		for (int j = 0; j <= strCompLen; j++)
		{
			if (i == 0 || j == 0)
			{
				strArr[i][j] = 0;
			}
			else if (str[i-1] == strComp[j-1])
			{
				strArr[i][j] = strArr[i-1][j-1]+1;
				count = max(count,strArr[i][j]);
			}
			else
				strArr[i][j] = 0;
		}
        
	}
	cout <<"Length of the longest commom substring '"<<strComp<<"' : "<< count<<endl;
	cin.get();

}
int main()
{
	char *str = "goodgirlgoestoschool";
	char *strComp = "goestohome";

	LCS(str,strComp);

}