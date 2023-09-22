#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	vector<double> numVec;
	double input;
	bool yes;
	do
	{
		//Check if user insert correct input format. Program stops by entering 'stop'
		cout << "Enter a double type of number. Stop the program by entering negative number: ";
		yes = true;
		cin >> input;
		if (!cin)
		{
			yes = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			string str;
			getline(cin, str);
			if (str.find_first_not_of(" ") != string::npos)
				yes = false;
		}

		if (!yes)
			cout << "Invalid input, try again" << endl;
		else
		{
			if (input > 0)
			{
				numVec.push_back(input);
			}
			else
				break;	
		}
	} while (1);
	cout << endl;
	cout << "Numbers in the vectors before sorting: "<<endl;
	for (auto i : numVec)
	{
		cout << i << endl;
	}
	//sorting numbers in vector in ascending order
	sort(numVec.begin(),numVec.end());
	cout << endl;
	cout << "Numbers in the vectors after sorting: " << endl;
	for (auto k : numVec)
	{
		cout << setprecision(3) << fixed << k << endl;
	}	
}