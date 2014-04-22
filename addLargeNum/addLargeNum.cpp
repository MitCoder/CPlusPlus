//adds two large numbers
#include<iostream>
#include<string>
using namespace std;
void addLargeNum(string s1, string s2);

void addLargeNum(string s1, string s2)
{
	int max = (s1.length() > s2.length()) ? s1.length() : s2.length();
	int min = (s1.length() > s2.length()) ? s2.length() : s1.length();

	//converting string to char*
	char *str1 = (char *)s1.c_str();
	char *str2 = (char *)s2.c_str();

	int *arr1 = new int[max];
	int *arr2 = new int[max];

	//populating arrays with each characcter of associated string.
	for (int i = 0; i < max; i++)
	{
		//if char '2'-48 will give int value. This logic is to avoid garbage value for an array, if the associated str length is less than max

		if ((str1[strlen(str1) - 1 - i] - 48)>0)
		{
			arr1[i] = str1[strlen(str1) - 1 - i] - 48;
		}
		else
			arr1[i] = 0;
		cout << "arr1 " << i << " " << arr1[i] << endl;
		//cin.get();
	}
	for (int i = 0; i < max; i++)
	{
		if ((str2[strlen(str2) - 1 - i]-48)>0)
		{

			arr2[i] = str2[strlen(str2) - 1 - i] - 48;
		}
		else
			arr2[i] = 0;
		cout << "arr2 " << i << " " << arr2[i] << endl;
		//cin.get();
	}
	int carry = 0;
	int add;
	int *sum=new int[max+1];
	cout << arr2[5];
	for (int i = 0; i < max; i++)
	{
		add = (arr1[i] + arr2[i] +carry )%10;
		if (arr1[i] + arr2[i] +carry >= 10)
			carry = 1;
		else
			carry = 0;
		sum[i] = add;
		cout << "moudlo" << arr1[i] << " -" << arr2[i] << sum[i] << endl;

	}
	sum[max] = carry;
	cout << "printing sum " << endl;
	for (int i = max; i>=0; i--)
	{
		cout << sum[i];

	}
	cout<<endl;
	cout << "printing over sum" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << i<<endl;
		cin.get();
	}
}
int main()
{
	string s1, s2;
	cout << "Enter first number" << endl;
	cin >> s1;

	cout << "Enter second number" << endl;
	cin >> s2;

	addLargeNum(s1, s2);
	
}