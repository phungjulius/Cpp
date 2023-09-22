#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <time.h>

#define LOTTO_MIN 20
#define LOTTO_MAX 40
#define VIKING_MIN 1
#define VIKING_MAX 48
#define JACKPOT_MIN 1
#define JACKPOT_MAX 50

#define LOTTO_AMOUNT 7
#define VIKING_AMOUNT 6
#define JACKPOT_AMOUNT 5

using namespace std;

class printNumber
{
public:
	printNumber(int index = 1)
	{
		this->index = index;
	}
	void operator()(int number)
	{
		cout << "#" << index << ": " << number << endl;
		index++;
	}
private:
	int index;
};

class RandGen
{
public:
	//constructor takes 2 parameters indicate the range of random numbers
	RandGen(int min0, int max0) : numberArray() { srand((unsigned int)time(NULL)); min = min0; max = max0; }
	int operator()()
	{
		int number;
		do
		{
			number = rand() % (max - min + 1) + min;
		} while (find(numberArray.begin(), numberArray.end(), number) != numberArray.end()); // only accept new generated random number that is not exit in the vector number
		numberArray.push_back(number);
		return number;
	}
private:
	int min;
	int max;
	vector<int>numberArray;
};

int main()
{
	char option;

	do
	{
		//vectors for random numbers 
		vector<int>lotto(LOTTO_AMOUNT);
		vector<int>vikingLotto(VIKING_AMOUNT);
		vector<int>euroJackpot(JACKPOT_AMOUNT);

		//vectors for matched numbers 
		vector<int>lottoVikingMatch(LOTTO_AMOUNT);
		vector<int>allThreeMatch(LOTTO_AMOUNT);
		vector<int>::iterator searchNumber;

		//call fuction object to generate random number according to range parameters
		RandGen genLotto(LOTTO_MIN, LOTTO_MAX);
		RandGen genViking(VIKING_MIN, VIKING_MAX);
		RandGen genJackpot(JACKPOT_MIN, JACKPOT_MAX);

		//generate lottery numbers
		generate(lotto.begin(), lotto.end(), genLotto);
		generate(vikingLotto.begin(), vikingLotto.end(), genViking);
		generate(euroJackpot.begin(), euroJackpot.end(), genJackpot);

		//print each set of number using algorithm and output stream iterator
		cout << "Lotto: ";
		copy(lotto.begin(), lotto.end(), ostream_iterator<int>(cout, " "));
		cout << endl << "Viking lotto: ";
		copy(vikingLotto.begin(), vikingLotto.end(), ostream_iterator<int>(cout, " "));

		//sort() Lotto and Viking Lotto before applying set_intersection
		sort(lotto.begin(), lotto.end());
		sort(vikingLotto.begin(), vikingLotto.end());

		//find matched numbers from Lotto and Viking vectors and put them into lottoVikingMatch vector
		searchNumber = set_intersection(lotto.begin(), lotto.end(), vikingLotto.begin(), vikingLotto.end(), lottoVikingMatch.begin());
		lottoVikingMatch.resize(searchNumber - lottoVikingMatch.begin());

		cout << endl << "Matching numbers from Lotto & Viking Lotto: " << endl;
		if (!lottoVikingMatch.empty())
		{
			for_each(lottoVikingMatch.begin(), lottoVikingMatch.end(), printNumber());
		}
		else
		{
			cout << "There is no matching number! " << endl;
		}

		cout << "EuroJackpot: ";
		//print Euro Jackpot random numbers
		copy(euroJackpot.begin(), euroJackpot.end(), ostream_iterator<int>(cout, " "));

		//sort the numbers for set_intersection
		sort(euroJackpot.begin(), euroJackpot.end());

		//find the matched numbers of three lottories
		searchNumber = set_intersection(lottoVikingMatch.begin(), lottoVikingMatch.end(), euroJackpot.begin(), euroJackpot.end(), allThreeMatch.begin());
		allThreeMatch.resize(searchNumber - allThreeMatch.begin());
		cout << endl << "Matching numbers in three sets: " << endl;
		if (!allThreeMatch.empty())
		{
			for_each(allThreeMatch.begin(), allThreeMatch.end(), printNumber());
		}
		else
		{
			cout << "There is no matching number! " << endl << endl;
		}

		cout << "Would you like to get another try? Enter 'Y' for YES / 'N' for NO: ";
		cin >> option;
		if (toupper(option) == 'N')
		{
			break;
		}
		cout << endl;
	} while (1);
	return 0;
}