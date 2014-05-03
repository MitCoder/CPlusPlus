//Group the anagrams using STL. O(n) solution
/*
VECTORS:vectors are just like arrays however they change their size.
The size of an array is fixed at compile time, but vectors use dynamically allocated array.  The elements are stored in contagious storage location.
When new elements are inserted, the array is reallocated.
Compared to other sequence containers like lists,queues;vectors are efficient just as arrays when it comes to accessing,adding and removing from the end.
Instead of using arraylist(in java),vector is used in c++.

SET:They are containers which store unique elements in order. The value of an element also identifies it (the value is itself the key, of type T), and each value must be unique.
The value in set cannot be modified but can be removed or inserted.They are slower than UNORDERED_SET,since they access using the key.

MULTIMAP:They contain a combination of key and value. Equivalent keys can be stored, and they keys are sorted.

MAP:They contain a combination of key and value. Only unique keys can be stored, and they keys are sorted.
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

void sortFunction(vector<std::string>& arr)
{
	std::vector<std::string> res;
	if (!arr.empty())
	{
		std::multimap<string, string> multiMap;
		std::multimap<string, string>::iterator multiMapIt;
		std::set<string> setOrder;
		std::set<string>::iterator setOrderIt;
		pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ret;

		for (int i = 0; i < arr.size(); i++)
		{
			string str = arr[i];
			sort(str.begin(), str.end());//sort the letters of each word in arr[i]
			multiMap.insert(pair<string, string>(str, arr[i]));//insert in multimap as(sortedWord,originalWord)
			setOrder.insert(str);//insert the key in the set
		}

		//iterate through set. Set will have only distinct keys.
		for (setOrderIt = setOrder.begin(); setOrderIt != setOrder.end(); setOrderIt++)
		{
			if (multiMap.count(*setOrderIt)>1)//for each key in the set,count the total number of keys in multimap
			{
				ret = multiMap.equal_range(*setOrderIt);//grab the pair from multimap for respective key of set.
				for (multiMapIt = ret.first; multiMapIt != ret.second; multiMapIt++)
				{
					res.push_back((*multiMapIt).second);
				}

			}

		}
	}
	for (std::vector<std::string>::iterator it = res.begin(); it != res.end(); it++)
	{
		cout << *it << endl;
	}

	cin.get();
}
int main()
{
	char* arr[] = { "cat", "dog", "tac", "god", "act" };
	vector<std::string> vectArr;

	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		vectArr.push_back(arr[i]);
	}
	sortFunction(vectArr);
	return 0;


}
