#include <iostream>

using namespace std;

class Counter 
{
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

//deive class LimitedCounter
class LimitedCounter :public Counter
{
public:
	LimitedCounter(int number = 0, int upperLimit = 0);
	virtual void inc();
	virtual void dec();
	virtual operator int();
private:
	int value;
	int limit;
};

//derive class OverflowCounter
class OverflowCounter :public Counter
{
public:
	OverflowCounter(int number = 0, int upperLimit = 0);
	virtual void inc();
	virtual void dec();
	virtual operator int();
private:
	int value;
	int limit;
};

void UseCounter(Counter& ctr, int num);

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;// should display 5
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for (int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	//Own testing 
	LimitedCounter liCo(2,10);
	OverflowCounter ovCo(5, 18);

	cout << "Incrementing LimitedCounter of (2,10) 12 times" << endl;
	for (int i = 0; i < 12; i++)
	{
		liCo.inc();
		cout << "Value is: " << liCo << endl;
	}
	cout << "Final value after incrementing 12 times is " << liCo << endl;
	cout << endl;
	cout << "Decrementing LimitedCounter (4,20) 12 times" << endl;
	for (int i = 0; i < 12; i++)
	{
		liCo.dec();
		cout << "Value is: " << liCo << endl;
	}
	cout << "Final value after decrementing 12 times is " << liCo << endl;
	cout << endl;
	cout << "Incementing OverflowCounter (5,18) 20 times" << endl;
	for (int i = 0; i < 20; i++)
	{
		ovCo.inc();
		cout << "Value is: " << ovCo << endl;
	}
	cout << "Final value after incrementing 20 times is " << ovCo << endl;
	cout << endl;
	cout << "Decementing OverflowCounter (5,18) 20 times" << endl;
	for (int i = 0; i < 20; i++)
	{
		ovCo.dec();
		cout << "Value is: " << ovCo << endl;
	}
	cout << "Final value after decrementing 20 times is " << ovCo << endl;
	return 0;
}

LimitedCounter::LimitedCounter(int number, int upperLimit) :value(number), limit(upperLimit)
{

}

void LimitedCounter::inc()
{
	if (value < limit)
	{
		value++;
	}
}

void LimitedCounter::dec()
{
	if (value > 0)
	{
		value--;
	}
}

LimitedCounter::operator int()
{
	return value;
}

OverflowCounter::OverflowCounter(int number, int upperLimit) :value(number), limit(upperLimit)
{

}

void OverflowCounter::inc()
{
	if (value < limit)
	{
		value++;
	}
	else
		value = 0;
}

void OverflowCounter::dec()
{
	if (value > 0)
	{
		value--;
	}
	else
		value = limit;
}

OverflowCounter::operator int()
{
	return value;
}

void UseCounter(Counter& ctr, int num)
{
	if (num >= 0)
	{
		for (int i = 0; i < num; i++)
		{
			ctr.inc();
		}
	}
	else
	{
		for (int i = 0; i > num; i--)
		{
			ctr.dec();
		}
	}
}