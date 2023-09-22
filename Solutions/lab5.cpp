#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
int readNumber(const char* prompt, int limit);

class Time
{
	friend ostream& operator<<(ostream& out, const Time& time);
	friend Time operator+(const Time& p1, const Time& p2);
	friend Time operator-(const Time& p1, const Time& p2);
private:
	int hour;
	int mins;
public:
	void read(const char* prompt);
	bool operator < (const Time& biggerTime) const;
	Time& operator++();
	Time operator++(int);
	Time(int hour = 0, int mins = 0);
};
//read function to prompt user for hour and minutes input
void Time::read(const char* prompt)
{
	cout << prompt << endl;
	hour = readNumber("Enter hours: ", 24);
	mins = readNumber("Enter minutes: ", 60);
}
//pre-increment operator
Time& Time::operator++()
{
	++mins;
	if (mins >= 60)
	{
		mins = mins - 60;
		hour++;
	}
	if (hour >= 24)
	{
		hour = hour - 24;
	}
	return *this;
}
//post-increment operator
Time Time::operator++(int)
{
	Time old = *this;
	++mins;
	if (mins >= 60)
	{
		mins = mins - 60;
		hour++;
	}
	if (hour >= 24)
	{
		hour = hour - 24;
	}
	return old;
}
// check if user input correct format
int readNumber(const char* prompt, int limit)
{
	int number;
	do
	{
		cout << prompt;
		cin >> number;
		if (cin.fail())
		{
			cout << "Invalid input. Try again!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			if (number >= 0 && number < limit)
			{
				return number;
				break;
			}
			else
			{
				cout << "Input should be in range from 0 to " << limit << ". Try again!" << endl;
			}
		}
	} while (1);
}

bool Time::operator < (const Time& biggerTime) const
{
	return(hour * 60 + mins) < biggerTime.hour * 60 + biggerTime.mins;
}

Time::Time(int hour, int minute) :hour(hour), mins(minute)
{
	
}

ostream& operator<<(ostream& out, const Time& time)
{
	out << setiosflags(ios::right);
	out << setfill('0') << setw(2) << time.hour;
	out << ":" << setfill('0') << setw(2) << time.mins;
	return out;
}

Time operator+(const Time& p1, const Time& p2)
{
	Time result;
	result.hour = ((p1.hour * 60 + p1.mins) + (p2.hour * 60 + p2.mins)) / 60;
	result.mins = ((p1.hour * 60 + p1.mins) + (p2.hour * 60 + p2.mins)) % 60;
	if (result.hour >= 24)
	{
		result.hour = result.hour - 24;
	}
	if (result.mins >= 60)
	{
		result.mins = result.mins - 60;
		result.hour = result.hour + 1;
	}
	return result;
}

Time operator-(const Time& p1, const Time& p2)
{
	Time result;
	int different = (p1.hour * 60 + p1.mins) - (p2.hour * 60 + p2.mins);
	if (different < 0)
	{
		int p = 24 * 60 + different;
		result.mins = p % 60;
		result.hour = p / 60;
	}
	else
	{
		result.mins = different % 60;
		result.hour = different / 60;
	}
	return result;
}

void print(const vector<Time>& v)
{
	for (auto& t : v) {
		cout << t << endl;
	}
}

int main() {
	Time time1, time2, duration, duration2;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
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
		t.read("Enter time:");
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
