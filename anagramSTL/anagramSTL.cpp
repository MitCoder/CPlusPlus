//Group the anagrams using STL. O(n) solution
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
				ret=multiMap.equal_range(*setOrderIt);//grab the pair from multimap for respective key of set.
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
