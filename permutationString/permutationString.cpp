# include <stdio.h>
#include<iostream>
#include<string>
using namespace std;
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n) 
{
   int j; 
   if (i == n)
     printf("%s\n", a);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 
void perm(char *str, int len)
{
	char temp;
	string permutation;

	for (int i = 0; i<len; i++)
	{
		for (int j = i; j<len; j++)
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			permutation.append(str);
			permutation.append(" ");
			cout << "  -> " << str << " permutation " << permutation << endl;

		}

	}
	cin.get();
}
 
/* Driver program to test above functions */
int main()
{
   char a[] = "ABC";  
  // int len1 = strlen(a);
   //cout << len1;
   permute(a, 0, 2);//recursive

   string str="";
   cout << "Enter a string" << endl;
   getline(cin,str);
   char *c = (char *)str.c_str();
   int len = strlen(c);
   perm(c, len);//not recursive
   getchar();
   return 0;
}