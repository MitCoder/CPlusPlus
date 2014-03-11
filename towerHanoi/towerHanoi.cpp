#include<iostream>
using namespace std;

void hanoi(int disk, char source, char dest, char intermediate);


void hanoi(int disk, char source, char dest, char intermediate)
{
	if (disk > 0)
	{
		cout << source << dest << intermediate << endl;
		hanoi(disk - 1, source, intermediate, dest);
		cout << " Move "<<disk<<" from " << source << " to " << dest << endl;
	//	cin.get();
		hanoi(disk - 1, intermediate,dest , source);
	}
}


int main()
{
	int disks;
	cout << "Enter the number of disks" << endl;
	cin >> disks;

	hanoi(disks, 'A', 'B', 'C');
	return 0;
}