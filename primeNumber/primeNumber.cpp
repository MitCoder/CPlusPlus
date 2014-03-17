/* 1. List if a particular number is prime or not
   2. List all the prime numbers between two given numbers
*/
#include<iostream>
#include<cmath>
using namespace std;

void isPrime(int number);
void listPrimes(int start, int end);
void isPrime(int number)
{
	bool prime = true;
	if (number < 2)
	{
		prime = false;
	}
	else
	{
		for (int i = 2; i <= sqrt(number); i++)
		{
			if (number%i == 0)
				prime = false;
		}

	}

	if (prime == true)
		cout << number << " number is prime" << endl;
	else
		cout << number << " number is not prime" << endl;
}
void listPrimes(int start, int end)
{
	if (start > end)
	{
		cout << "start value " << start << " is greater than end number " << endl;
		return ;
	}
	bool	prime = true;
	if (start < 2)
	{
		prime = false;
	}
	else
	{
		for (int i = start; i < end; i++)
		{
			prime = true;
			for (int j = 2; j <=sqrt(i); j++)
			{
				if (i%j == 0)
					prime = false;
			}
			if (prime == true)
			{
				cout << i << " ";
			}
			
		}
		cout << endl;
	}

}
int main()
{
	int number;

	cout << "Enter a number" << endl;
	cin >> number;
	isPrime(number);
	listPrimes(2, 50);
	return 0;
}