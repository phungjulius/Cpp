#include <iostream>

using namespace std;

class Person
{
public:
	Person(const char* name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
private:
	string name;
};

//derivated class Spy from base class Person
class Spy :public Person
{
public:
	Spy(const char* name = "nobody", const char* alias = "nobody", int resistNum = 0);
	void identity() const override;
	void interrogate() override;
	void set_identity(const char* alias);
private:
	string aliasName;
	int resistNumber;
};

Person::Person(const char* name)
{
	this->name = name;
}

void Person::identity() const
{
	cout << "My name is: " << name << endl;
}

void Person::interrogate()
{

}

Spy::Spy(const char* name, const char* alias, int resistNum) :Person(name)
{
	aliasName = alias;
	this->resistNumber = resistNum;
}

void Spy::set_identity(const char* alias)
{
	aliasName = alias;
}

void Spy::identity() const
{
	//print alias when resistancy is greater than 0, else print real name
	if (resistNumber > 0)
	{
		cout << "My name is: " << aliasName << endl;
	}
	else
	{
		Person::identity(); //print real name if the resistancy number is under 0 
		cout << "My alias is: " << aliasName << endl;
	}
}

void Spy::interrogate()
{
	if (resistNumber > 0)
	{
		resistNumber--;
	}
}

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}
	return 0;
}