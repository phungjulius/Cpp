#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>

class Car {
	friend std::ostream &operator<<(std::ostream &out, const Car &car);
public:
	Car(const char* m="Ford", const char *l=nullptr, int ml=0) : model(m), license(l?l:(rand()%2?"FOO-":"BAR-") + std::to_string(rand()%999+1)), mileage(ml?ml:rand()%10000) {}
	~Car() { std::cout << model << " " << license << " deleted" << std::endl; };
	void Read();
	std::string GetLicense() const { return license; }
private:
	std::string model;
	std::string license;
	int mileage;
};

void Car::Read()
{
	//std::cout << "Enter car information" << std::endl;
	// replace the following with your own code
	model = "Seat";
	license = (rand() % 2 ? "ZAP-" : "ZIP-") + std::to_string(rand() % 999 + 1);
	mileage = 10000 + rand() % 10000;
}

std::ostream & operator<<(std::ostream & out, const Car & car)
{
	std::cout << "Model: " << car.model << std::endl << "License: " << car.license << std::endl << "Mileage: " << car.mileage << std::endl;

	return out;
}

/* ---------------------- */

class Website {
public:
	Website(const char *n = nullptr) : name(n ? n : "www.cars" + std::to_string(rand() % 99 + 1) + ".com") {}
	~Website() { std::cout << name << " deleted" << std::endl; };
	void advertise(Car *car) { listing.push_back(car); }
	void print(std::ostream &out = std::cout) { out << name << std::endl; for(auto car : listing) out << *car; out << name << " end of list" << std::endl;
	}
	void remove(Car *car) { listing.erase(std::remove(listing.begin(), listing.end(), car),listing.end()); } 
private:
	std::vector<Car *> listing;
	std::string name;
};

class Dealer {
	friend std::ostream &operator<<(std::ostream &out, const Dealer &dealer);
public:
	Dealer(const char *name_ = "John Doe") : name(name_) {};
	~Dealer() { std::cout << name << " deleted" << std::endl; };
	void buy();
	void sell();
	void add(Car *car) { cars.push_back(car); for (auto site : sites) site->advertise(car); }
	void add_site(Website *w) { sites.push_back(w); }
private:
	std::string name;
	std::vector<Car *> cars;
	std::vector<Website *> sites;
};

void Dealer::buy()
{
	Car *car = new Car;
	car->Read();
	add(car);
}

void Dealer::sell()
{
	std::cout << *this; // print my list of cars
	std::cout << "Enter license of car you want to buy" << std::endl;

	std::string license;
	std::cin >> license;
	auto ci = std::find_if(cars.begin(), cars.end(), [&license](Car *c) {return license == c->GetLicense(); });
	if (ci != cars.end()) {
		for (auto site : sites) site->remove(*ci); // modify code wso that this is not needed
		cars.erase(ci);
	}
}


std::ostream & operator<<(std::ostream & out, const Dealer & dealer)
{
	std::cout << dealer.name << "'s cars for sale" << std::endl;
	for (auto car : dealer.cars) std::cout << *car;
	std::cout << "End of " << dealer.name << "'s cars listing" << std::endl;

	return out;
}

/* ---------------------- */



void car_sales()
{
	std::cout << "Car sales started" << std::endl;
	Website *wa = new Website("www.autos.com");
	Website *wb = new Website("www.bilar.com");
	Website *wc = new Website("www.cars.com");
	Dealer *a = new Dealer("Alan Aldis");
	Dealer *b = new Dealer("Bill Munny");
	{
		Dealer *c = new Dealer("Casey Ball");
		Car *ca = new Car;
		Car *cb = new Car;

		a->add_site(wa);
		a->add_site(wb);
		b->add_site(wb);
		b->add_site(wc);
		c->add_site(wa);
		c->add_site(wb);
		c->add_site(wc);

		a->buy();
		a->buy();
		a->buy();
		a->buy();

		b->buy();
		b->buy();
		b->buy();

		c->buy();
		c->buy();
		c->add(ca);
		c->add(cb);

		wa->print();
		wb->print();
		wc->print();

		std::cout << *a << *b << *c << std::endl;

		a->sell();

		std::cout << *a << *b << *c << std::endl;

		wa->print();
		wb->print();
		wc->print();
	}

	wa->print();
	wb->print();
	wc->print();


	std::cout << "Car sales ended" << std::endl;

}

int main(int argc, char **argv) {
	_CrtMemState s1;
	_CrtMemCheckpoint(&s1);

	srand(time(NULL));

	car_sales();

	_CrtMemState s2,s3;
	_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s1, &s2)) {
		_CrtDumpMemoryLeaks();
		_CrtMemDumpStatistics(&s3);
	}

	return 0;
}


