

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string find_first_element(const string &xml, string tag_name);
vector<string> find_all_elements(const string &xml, string tag_name);


int main() {
	string page, line, location, temperature;
	ifstream inputFile("day-ahead-prices.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	// Now page is a string that contains the whole xml page
	
	// Here you need to write a loop that asks user to enter tag name
	// and if tag name is "stop" the program stops
	// otherwise program calls function of 2A or 2B with the tag name
	// and prints the result

	return 0;
}

// Exercise 2A
string find_first_element(const string &xml, string tag_name)
{
	// construct start and end tags from from the tag name 
	// add angle brackets to both tags and also slash to end tag
	// then search for tags 
	// if both are found then return the substring between the tags
	
	return "not found"; // return this if tag is not found
}

// Exercise 2B
vector<string> find_all_elements(const string &xml, string tag_name)
{
	// return an empty vector if tag is not found
}