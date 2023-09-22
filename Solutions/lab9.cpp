#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

//definition of class Point (base class)
class Point 
{
public:
    //constructor
    Point(double xcoord = 0.0, double ycoord = 0.0);
    // destructor
    virtual ~Point() = default;
    virtual void input(const char* prompt = "");
    virtual void output() const;
    virtual double area() const;
    void move(double deltax, double deltay);
private:
    double x;
    double y;
};

//derive two classes from base class Point
class Circle :public Point
{
public:
    Circle(double xcoord = 0.0, double ycoord = 0.0, double r = 0.0);
    virtual void input(const char* prompt = "") override;
    virtual void output() const override;
    virtual double area() const override;
private:
    double radius;
};

class Square :public Point
{
public:
    Square(double xcoord = 0.0, double ycoord = 0.0, double h = 0.0, double w = 0.0);
    virtual void input(const char* prompt = "")override;
    virtual void output()const override;
    virtual double area() const override;
private:
    double height;
    double width;
};

//Point constructor 
Point::Point(double xcoord, double ycoord)
{
    x = xcoord;
    y = ycoord;
}

void Point::input(const char* prompt)
{
    if (prompt != "") //skip printing prompt if it is empty
    {
        cout << prompt << endl;
    }
    cout << "Enter coordinate x: ";
    cin >> x;
    cout << "Enter coordinate y: ";
    cin >> y;
}

void Point::output()const
{
    cout << "Coordinates: " << "(" << x << ", " << y << ")";
}

double Point::area() const //this member function will be override in derive class
{
    return 0;
}

void Point::move(double deltax, double deltay)
{
    x = x + deltax;
    y = y + deltay;
}

//class Circle's constructor
Circle::Circle(double xcoord, double ycoord, double r) :Point(xcoord, ycoord)
{
    radius = r;
}

void Circle::input(const char* prompt)
{
    //Call 'input' member function of Point class
    cout << prompt << endl;
    Point::input();
    cout << "Enter radius: ";
    cin >> radius;
}

void Circle::output()const
{
    cout << "Circle's area: " << area() << " ";
    Point::output();
}

double Circle::area()const
{
    return (radius * radius) * 3.1415926;
}

Square::Square(double xcoord, double ycoord, double h, double w) :Point(xcoord, ycoord)
{
    height = h;
    width = w;
}

void Square::input(const char* prompt)
{
    cout << prompt << endl;
    Point::input();
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;
}

void Square::output()const
{
    cout << "Square's area: " << area() << " ";
    Point::output();
}

double Square::area()const
{
    return height * width;
}

bool sortByArea(shared_ptr<Point>a, shared_ptr<Point>b)
{
    return (a->area() < b->area());
}

//main function
int main()
{
    //Vector of shared pointers
    vector<shared_ptr<Point>> arr;

    //Define some values according to assginemnt
    arr.push_back(make_shared<Point>(1.0, 1.0));
    arr.push_back(make_shared<Circle>(2.0, 2.0, 2.0));
    arr.push_back(make_shared<Square>(5.0, 5.0, 2.0, 2.0));

    //Prompt user for input
    Point pt;
    pt.input("[ POINT ]");
    Circle c;
    c.input("[ CIRCLE ]");
    Square sqr;
    sqr.input("[ SQUARE ]");

    //add into vector of shared point arr
    arr.push_back(make_shared<Point>(pt));
    arr.push_back(make_shared<Circle>(c));
    arr.push_back(make_shared<Square>(sqr));
    cout << endl;

    //print the object data
    for (auto& i : arr)
    {
        i->output();
        cout << endl;
    }
    cout << endl;
    //sort vector by area
    cout << "Sorting by area:" << endl;
    sort(arr.begin(), arr.end(),sortByArea);
    cout << endl;
    //print the object data again after sorting
    for (auto& i : arr)
    {
        i->output();
        cout << endl;
    }
    cout << endl;

    //Exercise B : ADDING FIVE RANDOM OBJECTS TO THE SHARE POINT VECTOR

    char input;
    cout << "Would you like to create and add extra 5 objects into vector? Input Y/N" << endl;
    cout << "Answer: ";
    cin >> input;
    if (toupper(input) == 'Y')
    {
        srand((unsigned)time(NULL));
        for (int i = 0; i < 5; i++)
        {
            int randomOption = rand() % 3;
            switch (randomOption)
            {
            case 0:
            {
                Point pnt;
                pnt.input("[ POINT ]");
                arr.push_back(make_shared<Point>(pnt));
                break;
            }
            case 1:
            {
                Circle crl;
                crl.input("[ CIRCLE ]");
                arr.push_back(make_shared<Circle>(crl));
                break;
            }  
            case 2:
            {
                Square sq;
                sq.input("[ SQUARE ]");
                arr.push_back(make_shared<Square>(sq));
                break;
            }
            }        
        }
    }

    //print the object data
    for (auto& i : arr)
    {
        i->output();
        cout << endl;
    }
    cout << endl;
    
    //sort vector by area
    cout << "Sorting by area:" << endl;
    sort(arr.begin(), arr.end(), sortByArea);
    cout << endl;
    
    //print the object data again after sorting
    for (auto& i : arr)
    {
        i->output();
        cout << endl;
    }
    cout << endl;
    return 0;
}