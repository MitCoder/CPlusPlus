//balancedparanthesis check cpp file
#include<iostream>
#include<string>
using namespace std;

int top = -1;
void push(char a, char arr[]);
void pop(char a, char arr[]);


int main()
{
	std::string str;
	int flag = 0;
	cout << "Enter a string" << endl;
	cin >> str;
	char *strPtr = (char*)str.c_str();///having a character pointer point to string

	int len = strlen(strPtr);
	char *arr = new char[len + 1];

	while (*strPtr != NULL)
	{

		if (*strPtr == '[' || *strPtr == '(' || *strPtr == '{')
			push(*strPtr, arr);

		else if (top == -1 || *strPtr == ']' || *strPtr == ')' || *strPtr == '}')
		{
			if ((arr[top] == '[' &&  *strPtr == ']') || (arr[top] == '(' &&   *strPtr == ')') || (arr[top] == '{' &&  *strPtr == '}'))
				pop(*strPtr, arr);
			else
				flag = 1;

		}
		*strPtr++;

	}

	if (flag != 1)//if true
		cout << "balanced" << top << endl;
	else
		cout << "not balanced" << top << endl;
	cin.get();
	return 0;

}

void push(char a, char arr[])
{
	arr[++top] = a;
	cout << a << arr[top] << endl;
	cin.get();
}
void pop(char a, char arr[])
{
	arr[--top];

}
/* My other alternative method
#include<iostream>
#include<string>
using namespace std;

int top=-1;

bool checkParanthesis(char *strPtr,char arr[]);
bool IsPair(char strPtr,char arr[]);
void push(char a,char arr[]);
void pop(char a ,char arr[]);


int main()
{	std::string str;

cout<<"Enter a string"<<endl;
cin >> str;
char *strPtr=(char*)str.c_str();///having a character pointer point to string

int len=strlen(strPtr);
char *arr=new char[len+1];


bool flag=checkParanthesis(strPtr,arr);;
if(flag)//if true
cout<<"balanced"<<top<<endl;
else
cout<<"not balanced"<<top<<endl;
cin.get();
return 0;

}
bool checkParanthesis(char *strPtr,char arr[])
{

while(*strPtr!=NULL)
{
if(*strPtr=='[' || *strPtr=='(' || *strPtr=='{')
push(*strPtr,arr);

else if(top==-1 || *strPtr==']' || *strPtr==')' || *strPtr=='}')
{   bool val=IsPair(*strPtr,arr);
if(!val)//if not true.ie if the pairs dont match
return false;
else
pop(*strPtr,arr);
}
*strPtr++;
}
}
bool IsPair(char a,char arr[])
{
if(arr[top] == '(' && a==')')
{
return true;
}
else if(arr[top] == '[' && a==']')
{
return true;
}
else if(arr[top] == '{' && a=='}')
{
return true;
}
else
return false;
}
void push(char a,char arr[])
{
arr[++top]=a;
cout<<a<<arr[top]<<endl;
cin.get();
}
void pop(char a,char arr[])
{
arr[--top];

}


*/
/*
other method from web
#include<iostream>
#include<stack>
#include<string>
using namespace std;
// Function to check whether two characters are opening
// and closing of same type.
bool ArePair(char opening,char closing)
{
if(opening == '(' && closing == ')') return true;
else if(opening == '{' && closing == '}') return true;
else if(opening == '[' && closing == ']') return true;
return false;
}
bool AreParanthesesBalanced(string exp)
{
stack<char>  S;
for(int i =0;i<exp.length();i++)
{
if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
S.push(exp[i]);
else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
{
if(S.empty() || !ArePair(S.top(),exp[i]))
return false;
else
S.pop();
}
}
return S.empty() ? true:false;
}

int main()
{

string expression;
cout<<"Enter an expression:  "; // input expression from STDIN/Console
cin>>expression;
if(AreParanthesesBalanced(expression))
cout<<"Balanced\n";
else
cout<<"Not Balanced\n";
}

*/