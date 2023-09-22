#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string find_first_element(const string& xml, string tag_name);
vector<string> find_all_elements(const string& xml, string tag_name);
bool isNumber(string s);

int main() {
	string page, line, location, temperature, tagName, input;
	int option;
	vector<string> array;
	vector<string>str;
	ifstream inputFile("day-ahead-prices.xml");

	while (getline(inputFile, line)) {
		page.append(line);
		line.erase();
	}
	do
	{
		cout << "Enter tag name: ";
		cin >> tagName;
		//if user enters "stop", the program will stop
		if (tagName.compare("stop") == 0)
		{
			cout << "Stop the program! " << endl;
			break;
		}
		cout << "-----Option-----" << endl;
		cout << "[1] Find the first element of the given name." << endl << "[2] Find all the elements of the given name." << endl;
		//prompt user for numerical input
		do
		{
			cout << "Please select one number according to options above: ";
			cin >> input;
			if (isNumber(input))
			{
				option = stoi(input);
				break;
			}
		} while (1);
		//user's option to find the first elemennt or all elements of tag name
		switch (option)
		{
		case 1: //find the first element of tag name
			cout << tagName <<": " << find_first_element(page, tagName) << endl;
			break;
		case 2: //find all elements of tag name
			//find_all_elements(page, tagName);
			array = find_all_elements(page, tagName);
			cout << "Length of the vector: " << array.size() << endl;
			cout << tagName << ": ";
			
			for (int i = 0; i < array.size(); i++)
			{
				if (i == array.size()-1)
				{
					cout << "\"" << array[i] << "\"" << ". ";
				}
				else
				{
					cout << "\"" << array[i] << "\"" << ", ";
				}			
			}
			cout << endl;
			break;
		default:
			cout << "Please select number from range 1-2 only!" << endl;
		}
	} while (1);
	return 0;
}

// Exercise 2A
string find_first_element(const string& xml, string tag_name)
{
	string begin = tag_name;
	string end = tag_name;
	string arr;
	begin.insert(0, "<");
	begin.insert(begin.size(), ">");
	string temp = begin;
	//search for begin name tag. If it is found, continue searching end nae tag
	size_t posBegin = xml.find(begin);
	if (posBegin != string::npos)
	{
		end = temp.insert(1, "/");
		size_t posEnd = xml.find(end);
		if (posEnd != string::npos)
		{
			for (size_t i = (posBegin + begin.size()); i < posEnd; i++)
			{
				arr.push_back(xml[i]);
			}			
			return arr;
		}
		else
			return "not found";
	}
	else
		return "not found"; // return this if tag is not found	 
}

// Exercise 2B
vector<string> find_all_elements(const string& xml, string tag_name)
{
	vector<string> arr;
	string begin = tag_name;
	string end = tag_name;
	string str;
	begin.insert(0, "<");
	begin.insert(begin.size(), ">");
	string temp = begin;
	end = temp.insert(1, "/");

	size_t posBegin = xml.find(begin);
	size_t posEnd = xml.find(end);
	//posBegin != string::npos
	while (posBegin != string::npos && posEnd != string::npos)
	{
		for (size_t i = (posBegin + begin.size()); i < posEnd; i++)
		{
			str.push_back(xml[i]);
		}
		arr.push_back(str);
		str.clear();
		posBegin = xml.find(begin, posEnd + end.size());
		posEnd = xml.find(end, posEnd + end.size());
	} 
	return arr;	
}

//function to check if input in number or not
bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
	return true;
}