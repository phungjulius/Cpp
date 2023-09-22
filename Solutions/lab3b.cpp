#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
vector<string> backwards(vector<string>& arr);

int main()
{
	vector<string> arr;
	string input;
	do
	{
		cout << "Enter a string: ";
		getline(cin, input);
		if (input == "stop")
		{
			break;
		}
		arr.push_back(input);
	} while (1);
	cout << endl;
	cout << "Content of vector before sorting: " << endl;
	for (auto &i : arr)
	{
		cout << i << endl;
	}
	cout << endl;
	cout << "Content of vector after sorting: " << endl;
	//Call backwards function
	backwards(arr);
	for (auto &i : arr)
	{
		cout << i << endl;
	}
}
//function to reverse all strings in the vector and sort them in descending order
vector<string> backwards(vector<string>& arr)
{
	for (string &i:arr)
	{
		reverse(i.begin(), i.end());
	}
	sort(arr.rbegin(), arr.rend());
	return arr;
}