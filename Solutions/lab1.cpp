#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

int charCount(string str);
int charCount(string str)
{
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (!isspace(str[i]))
			count++;
	}
	return count;
}

int main()
{
	string arr[SIZE];
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter string number " << i + 1 << ": ";
		getline(cin, arr[i]);
	}
	cout << endl;
	cout << "Printing all the input strings: " << endl;
	cout << endl;

	for (int k = 0; k < SIZE; k++)
	{
		
		cout << "Input string number " << k + 1 << " : " << arr[k] << endl;
		cout << "Total number of characters in string " << k + 1 << ": " << charCount(arr[k]) << endl;
		count = count + charCount(arr[k]);
		cout << endl;
	}
	cout << "Total number of characters in all 10 strings: " << count << endl;

}