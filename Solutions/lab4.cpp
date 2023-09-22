#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int readNumber(const char* prompt, int limit);

class Time
{
public:
	void read(const char* prompt);
	bool lessThan(Time biggerTime);
	Time subtract(Time smallerTime);
	void display();
private:
	int hours;
	int mins;
};

int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	}
	else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
	}
	cout << endl;
	cout << "Duration was ";
	duration.display();

	return 0;
}

void Time::read(const char* prompt)
{
	cout << prompt << endl;
	hours = readNumber("Enter hours: ", 24);
	mins = readNumber("Enter minutes: ", 60);
}

void Time::display()
{
	cout << setiosflags(ios::right);
	cout << setfill('0') << setw(2) << hours;
	cout << ":" << setfill('0') << setw(2) << mins;
}

bool Time::lessThan(Time biggerTime)
{
	int biggerTimeMins, smallerTimeMins;
	smallerTimeMins = hours * 60 + mins;
	biggerTimeMins = biggerTime.hours * 60 + biggerTime.mins;
	if (smallerTimeMins < biggerTimeMins)
	{
		return true;
	}
	else
		return false;
}

Time Time::subtract(Time smallerTime)
{
	Time aux;
	int subMins, biggerTimeMins, smallerTimeMins;

	biggerTimeMins = hours * 60 + mins;
	smallerTimeMins = smallerTime.hours * 60 + smallerTime.mins;
	subMins = biggerTimeMins - smallerTimeMins;
	aux.hours = subMins / 60;
	aux.mins = subMins % 60;
	return aux;
}

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
			if (number > 0 && number < limit)
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