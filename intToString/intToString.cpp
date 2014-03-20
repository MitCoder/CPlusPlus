#include<iostream>
#include <sstream>
#include<stack>
using namespace std;
int main()
{
	//using library functions
	int i = 346;
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	std::cout << s.length();
	cin.get();

	//without using library functions
	int num = 546;
	int no = num;
	int digit = 0;
	int reverse = 0;
	char strBuffer[30];
	char strStackBuffer[30];
	int countStack = 0;
	stack<int> stackNum;
	//reverse the number, hence you get 645
	for (int i = 0; no>0; i++)
	{
		digit = no % 10;
		reverse = reverse * 10 + digit;
		stackNum.push(digit);
		no = no / 10;
		cout << digit << "--" << reverse << "--" << no << "---" << stackNum.top()<< endl;

	}
	//reverse the number you just reversed back to get 546
	//rather than reversing the second time, the value that we get as reverse the first time, we can put in stack and then pop it out.
	
	for (int i = 0; i<stackNum.size()+1; i++)
	{
		int top=stackNum.top();
		strStackBuffer[i] = char(top + '0');
		countStack++;
		stackNum.pop();
	}
	strStackBuffer[countStack] = '\0';
	cout << "stack" << strStackBuffer;
	cin.get();

	int reverseNum = reverse;
	digit = 0;
	reverse = 0;
	int count = 0;
	for (int i = 0; reverseNum>0; i++)
	{
		digit = reverseNum % 10;
		reverse = reverse * 10 + digit;
		reverseNum = reverseNum / 10;
		strBuffer[i] = char('0' + digit);
		count++;
	}
	strBuffer[count] = '\0';
	cout <<"double reverse"<< strBuffer << endl;
	cin.get();

	return 0;
}