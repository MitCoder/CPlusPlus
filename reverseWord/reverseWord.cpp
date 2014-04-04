#include<string>
#include<iostream>

using namespace std;

char * reverseWord(char * strToken);

int main()
{ 
	char *strToken;
	char *returnWord;

	string str1,strReverse;

	cout<<"Enter a string to reverse"<<"\n";
	getline(cin,str1);
	char *str = new char[str1.size() + 1];
	strcpy(str, str1.c_str());
	cin.get();

	cout<<"Splitting string into tokens:"<< str<<endl;
	strToken=strtok(str," ");

	cout << strToken << endl;
	while(strToken != NULL)
	{	int len=0;
		len = strlen(strToken);
		returnWord=new char[len+1];
		
		returnWord=reverseWord(strToken);
		strReverse.append(returnWord);
		strReverse.append(" ");

		strToken = strtok(NULL, " ");
		
	}
	cin.get();
	cout<<"String reverse -> "<<strReverse<<endl;
return 0;
}

char * reverseWord(char * strToken)//this can be also written with argument as char strToken[]
{ 		int len=0;
		len=strlen(strToken);
		char * reverseWord=new char[len];
		for(int i=0;i<len;i++)
		{
			reverseWord[i] = strToken[len-i-1];
				
		}
	reverseWord[len]='\0';
	return reverseWord;
}