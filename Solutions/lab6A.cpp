#include <iostream>
#include <iomanip>
#include "Time.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

ostream& operator<<(ostream& out, const Time& time) //OVERIRDE <<
{
	out << setiosflags(ios::right);				  // ALIGN OUTPUT SPACING RIGHT
	out << setfill('0') << setw(2) << time.hours; // ADD ZEROES TO FILL A CHARACTER SPACE OF 2
	out << ":" << setfill('0') << setw(2) << time.minutes;
	return out; // RETURN FORMATTED ostream
}

istream& operator>>(istream& in, Time& time) //OVERRIDE >>
{
	char c = ':';
	in >> time.hours >> c >> time.minutes;
	return in;
}

Time operator+(const Time& t1, const Time& t2) // OVERRIDE +
{
	Time result;
	result.minutes = t1.minutes + t2.minutes;
	result.hours = t1.hours + t2.hours;
	if (result.minutes >= 60) // ADD A HOUR IF MINUTES ARE OVER 60
	{
		result.hours++;
		result.minutes -= 60;
	}
	if (result.hours >= 24) // IMPLEMENT 24h LIMIT, MOVE TO THE NEXT DAY
	{
		result.hours -= 24;
	}
	return result;
}

Time operator-(const Time& t1, const Time& t2) // OVERRIDE -
{
	Time result;
	result.minutes = t1.minutes - t2.minutes;
	result.hours = t1.hours - t2.hours;
	if (result.minutes < 0) // REMOVE A HOUR IF MINUTES ARE NEGATIVE
	{
		result.hours--;
		result.minutes += 60;
	}
	if (result.hours < 0) // IMPLEMENT 24h LIMIT, MOVE TO THE PREVIOUS DAY
	{
		result.hours += 24;
	}
	return result;
}

Time::Time(int hours0, int minutes0) // IMPLEMENTATION OF CONSTRUCTOR WITH DEFAULT VALUES DEFINED IN THE HEADER
{
	hours = hours0;
	minutes = minutes0;
}

bool Time::operator < (const Time& time) const
{
	return(hours * 60 + minutes) < time.hours * 60 + time.minutes;
}

bool Time::operator > (const Time& time) const
{
	return(hours * 60 + minutes) > time.hours * 60 + time.minutes;
}

bool Time::operator==(const Time& time) const // OVERRIDE ==
{
	return (hours == time.hours) && (minutes == time.minutes); // SIMPLY RETURN COMPARISON BOOLEAN
}

Time& Time::operator++() // OVERRIDE PRE-INCREMENT
{
	minutes++;
	if (minutes >= 60)	// >60 MINS MEANS NEXT HOUR
	{
		hours++;
		minutes -= 60;
	}
	if (hours >= 24)	// >24 HOURS MEANS NEXT DAY
	{
		hours -= 24;
	}
	return *this;	// RETURN AFTER INCREMENT
}

Time Time::operator++(int) // OVERRIDE POST-INCREMENT
{
	Time old = *this;
	minutes++;
	if (minutes >= 60)	// >60 MINS MEANS NEXT HOUR
	{
		hours++;
		minutes -= 60;
	}
	if (hours >= 24)	// >24 HOURS MEANS NEXT DAY
	{
		hours -= 24;
	}
	return old;
}

void Time::read(const char* prompt) // READ A Time
{
	do
	{
		cout << prompt;
		char c = ':';
		cin >> hours >> c >> minutes;
		if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) // PRINT ERROR IF VALUES ARE NOT SANE
		{
			cout << "PLEASE PUT IN PROPER DIGITAL CLOCK VALUES" << endl
				<< "HOURS 0 TO 23 AND MINUTES 0 TO 59 (FORMAT: HH MM)" << endl;
		}
	} while (hours < 0 || hours >23 || minutes < 0 || minutes > 59); // LOOP IF VALUES ARE NOT SANE
}

void print(const vector<Time>& v)
{
	for (auto& t : v)
	{
		cout << t << endl;
	}
}

int main() {
	Time time1, time2, duration, duration2;

	time1.read("Enter time 1: ");
	time2.read("Enter time 2: ");
	if (time1 < time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
		duration2 = time1 - time2;
	}
	else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
		duration2 = time2 - time1;

	}
	cout << "Duration was " << duration << endl;

	// check that we don't get negative times
	cout << "Duration2 was " << duration2 << endl;


	vector<Time> tv(5);
	for (auto& t : tv) {
		t.read("Enter time: ");
	}

	cout << "Times: " << endl;
	print(tv);

	Time sum;
	for (auto t : tv) {
		sum = sum + t;
	}

	cout << "Sum of times: " << sum << endl;

	cout << "Post-increment: " << endl;
	print(tv);
	for (auto& t : tv) {
		cout << t++ << endl;
	}

	print(tv);

	cout << "Pre-increment: " << endl;
	for (auto& t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}