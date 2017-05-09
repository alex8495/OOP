#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <istream>
#include <string>
#include <cstdint>
#include "base.h"
#include "container.h"

# define M_PI           3.14159265358979323846


class Shape : public Printable
{
private:
    static uint8_t number;
public:
    static uint8_t GetCount();
    Shape();
    std::string getInfo() const
    {
        std::cout << this -> info << "\n";
        return this -> info;
    }
    ~Shape();
};

uint8_t Shape::number = 0;

std::ostream & operator << (std::ostream & s, Shape const & sh)
{
    return s << sh.getInfo() << "\n";
}

Shape::Shape()
{
    std::cout<<"++";
    ++number;
    this -> info += "This is a geometric shape.";
}

uint8_t Shape::GetCount()
{
    return number;
}

Shape::~Shape()
{
    std::cout<<"--";
    --number;
}


class Point : public Shape, public Named
{
private:
    float x;
    float y;
    std::string info;
public:
    Point ();
    Point (float const pt_x, float const pt_y);
    float getX() const {return this -> x;}
    float getY() const {return this -> y;}
    Point & operator = (Point const & pt);
    std::string getInfo()
    {
        std::cout << this -> info << "\n";
        return this -> info;
    }
    static Point & getRand();
    ~Point() { }
};

std::ostream & operator << (std::ostream & s, Point const & p)
{
    return s << "Point: (" << p.getX() << ", " << p.getY() << ")\n";
}

Point::Point() : Named(std::string ("point"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> x = 0;
    this -> y = 0;
    this -> info += "It's coordinates are: (" + std::to_string(this -> x) + ", "
            + std::to_string (this -> y) + ").";
}

Point::Point(float const pt_x, float const pt_y) : Named(std::string ("point"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> x = pt_x;
    this -> y = pt_y;
    this -> info += "It's coordinates are: (" + std::to_string(this -> x) + ", "
            + std::to_string (this -> y) + ").";
}

Point & Point::operator = (Point const & pt)
{
    this -> x = pt.x;
    this -> y = pt.y;
    return * this;
}

Point & Point::getRand()
{
    std::srand ((unsigned int)time(0));
    Point * p = new Point ((const float)(std::rand() % 100), (const float)(std::rand() % 100));
    return * p;
}


class Circle : public Shape, public Named
{
private:
    Point center;
    float rad;
    std::string info;
public:
    Circle ();
    Circle(Point const & cir_centr, float const cir_rad);
    Circle(float const ct_x, float const ct_y, float const cir_rad);
    Point getCenter() const {return this -> center;}
    float getRad() const {return this -> rad;}
    std::string getInfo()
    {
        std::cout << this -> info << "\n";
        return this -> info;
    }
    static Circle & getRand();
    ~Circle() { }
};

std::ostream & operator << (std::ostream & s, Circle const & c)
{
    return s << "Circle: \n\tCenter: " << c.getCenter() << "\tRadius: " << c.getRad() << "\n";
}

Circle::Circle () : Named(std::string ("circle"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> rad = 1;
    this -> center = Point (1, 1);
}

Circle::Circle(Point const & cir_center, float const cir_rad) : Named(std::string ("circle"))
{
    this -> info = Shape::info + " " + Named::info;
    try
    {
        if (cir_rad <= 0)
            throw std::string ("Radius is less than 0.");
        this -> rad = cir_rad;
    }
    catch (std::string err)
    {
        std::cout << "Error! " << err << "\n" << "Radius set to 5.\n";
        this -> rad =5;
    }

    this -> center = cir_center;
    this -> info += "It's radius is: " + std::to_string(this -> rad) + ", coordinates of center are: ("
            + std::to_string(this -> center.getX()) + ", " + std::to_string(this -> center.getY())
            + "), area is: " + std::to_string(M_PI * (this -> rad) * (this -> rad)) + ", length is: "
            + std::to_string(2 * M_PI * this -> rad) + ".";
}

Circle::Circle(float const ct_x, float const ct_y, float const cir_rad) : Named(std::string ("circle"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> center = Point(ct_x, ct_y);
    try
    {
        if (cir_rad <= 0)
            throw std::string ("Radius is less than 0.");
        this -> rad = cir_rad;
    }
    catch (std::string err)
    {
        std::cout << "Error! " << err << "\n" << "Radius set to 5.\n";
	this -> rad = 5;
    }
    this -> info += "It's radius is: " + std::to_string(this -> rad) + ", coordinates of center are: ("
            + std::to_string(this -> center.getX()) + ", " + std::to_string(this -> center.getY())
            + "), area is: " + std::to_string(M_PI * (this -> rad) * (this -> rad)) + ", length is: "
            + std::to_string(2 * M_PI * this -> rad) + ".";
}

Circle & Circle::getRand()
{
    std::srand ((unsigned int)time(0));
    Point p = Point::getRand();
    Circle * c = new Circle (p, (const float)(std::rand() % 100));
    return * c;
}


class Rect : public Shape, public Named
{
private:
    float width;
    float height;
    Point left_up;
    std::string info;
public:
    Rect ();
    Rect(Point const & p1, Point const & p2);
    Rect(Point const & _left_up, float const _width, float const _height);
    float getWidth() const {return this -> width;}
    float getHeight() const {return this -> height;}
    Point getLeftUp() const {return this -> left_up;}
    std::string getInfo()
    {
        std::cout << this -> info << "\n";
        return this -> info;
    }
    static Rect & getRand();
    ~Rect() { }
};

std::ostream & operator << (std::ostream & s, Rect const & r)
{
    return s << "Rectangular: \n\tLeft up: " << r.getLeftUp() << "\tWidth: " << r.getWidth()
             << "\n\tHeight: " << r.getHeight() << "\n";
}

Rect::Rect () : Named(std::string ("rectangular"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> left_up = Point (1, 1);
    this -> width = 1;
    this -> height = 1;
}

Rect::Rect(Point const & p1, Point const & p2) : Named(std::string ("rectangular"))
{
    this -> info = Shape::info + " " + Named::info;
    if (p1.getX() >= p2.getX())
    {
        if (p1.getY() >= p2.getY())
        {
            this -> left_up = Point(p2.getX(),p2.getY());
        }
        else
        {
            this -> left_up = Point(p2.getX(),p1.getY());
        }
    }
    else
    {
        if (p1.getY() >= p2.getY())
        {
            this -> left_up = Point(p1.getX(),p2.getY());
        }
        else
        {
            this -> left_up = Point(p1.getX(),p1.getY());
        }
    }
    this -> width = abs(p1.getX()-p2.getX());
    this -> height = abs(p1.getY()-p2.getY());
    this -> info += "It's width is: " + std::to_string(this -> width) + ", height is: "
            + std::to_string(this -> height) + ", coordinates of left up corner are: ("
            + std::to_string(this -> left_up.getX()) + ", "
            + std::to_string(this -> left_up.getY()) + "), area is: "
            + std::to_string((this -> width) * (this -> height)) + ", perimeter is: "
            + std::to_string(2*((this -> width) + (this -> height))) + ".";
}

Rect::Rect(Point const & _left_up, float const _width, float const _height) : Named(std::string ("rectangular"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> left_up = _left_up;
    this -> width = _width;
    this -> height = _height;
    this -> info += "It's width is: " + std::to_string(this -> width) + ", height is: "
            + std::to_string(this -> height) + ", coordinates of left up corner are: ("
            + std::to_string(this -> left_up.getX()) + ", "
            + std::to_string(this -> left_up.getY()) + "), area is: "
            + std::to_string((this -> width) * (this -> height)) + ", perimeter is: "
            + std::to_string(2 * ((this -> width) + (this -> height))) + ".";
}

Rect & Rect::getRand()
{
        std::srand ((unsigned int)time(0));
	Rect * r = new Rect (Point::getRand(), (const float)(std::rand() % 100), (const float)(std::rand() % 100));
	return * r;
}


class Square : public Shape, public Named
{
private:
    Point left_up;
    float side;
    std::string info;
public:
    Square();
    Square(const Point & _left_up, const float _side);
    Square(const Point & p1, const Point & p2);
    Point getLeftUp() const {return this -> left_up;}
    float getSide() const {return this -> side;}
    std::string getInfo()
    {
        std::cout << this -> info << "\n";
        return this -> info;
    }
    static Square & getRand();
    ~Square() { }
};

std::ostream & operator << (std::ostream & s, Square const & sq)
{
    return s << "Square: \n\tLeft up: " << sq.getLeftUp() << "\tSide: " << sq.getSide() << "\n";
}

Square::Square() : Named(std::string ("square"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> left_up = Point (1, 1);
    this -> side = 1;
}

Square::Square(const Point & _left_up, const float _side) : Named(std::string ("square"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> left_up = _left_up;
    this -> side = _side;
    this -> info += "It's length is: " + std::to_string(this -> side) + ", coordinates of left up corner are: ("
            + std::to_string(this -> left_up.getX()) + ", "
            + std::to_string(this -> left_up.getY()) + "), area is: "
            + std::to_string((this -> side) * (this -> side)) + ", perimeter is: "
            + std::to_string(4 * (this -> side)) + ".";
}

Square::Square(const Point & p1, const Point & p2) : Named(std::string ("square"))
{
    this -> info = Shape::info + " " + Named::info;
    Rect r(p1,p2);
    this -> left_up = r.getLeftUp();
    try
    {
        if (r.getWidth() != r.getHeight())
        {
            throw std::string ("Width is not equal to height.");
        }
    }
    catch (std::string err)
    {
        std::cout << "Error! " << err << "Width = " << r.getWidth() << ". Height = "
                  << r.getHeight() << ".\n" << "Side of square set to " << r.getWidth() << "\n";
    }
    this -> side = r.getWidth();
    this -> info += "It's length is: " + std::to_string(this -> side) + ", coordinates of left up corner are: ("
            + std::to_string(this -> left_up.getX()) + ", "
            + std::to_string(this -> left_up.getY()) + "), area is: "
            + std::to_string((this -> side) * (this -> side)) + ", perimeter is: "
            + std::to_string(4 * (this -> side)) + ".";
}

Square & Square::getRand()
{
        std::srand ((unsigned int)time(0));
	Square * s = new Square (Point::getRand(), (const float)(std::rand() % 100));
	return * s;
}

class Polyline : public Shape, public Named
{
private:
    Container<Point> pts;
    std::string info;
public:
    Polyline ();
    Polyline(Point const & p1, Point const & p2);
    Container<Point> getPoints() const
    {
	return this -> pts;
    }
    void AddPoint( Point const & point );
    std::string getInfo()
    {
	std::cout << this -> info << "\n";
	return this -> info;
    }
    static Polyline & getRand();
    ~Polyline ();
};

std::ostream & operator << (std::ostream & s, Polyline const & pl)
{
    return s << "Polyline: \n" << pl.getPoints();
}

Polyline::Polyline() : Named(std::string ("polyline"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> pts = Container<Point> ();
}

Polyline::Polyline(Point const & p1, Point const & p2) : Named(std::string ("polyline"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> pts = Container<Point> ();
    this -> pts.push_back(p1);
    this -> pts.push_back(p2);
}

void Polyline::AddPoint( Point const & point )
{
    this -> pts.push_back(point);
}

Polyline & Polyline::getRand()
{
    std::srand ((unsigned int)time(0));
    Polyline * p = new Polyline (Point::getRand(), Point::getRand());
    for (uint8_t i = 0; i < std::rand() % 50; i++)
	p -> AddPoint(Point::getRand());
    return * p;
}

Polyline::~Polyline()
{

}


class Polygon : public Shape, public Named
{
private:
    Container<Point> pts;
    std::string info;
public:
    Polygon();
    Polygon(Point const & p1, Point const & p2, Point const & p3);
    Container<Point> getPoints() const {return this -> pts;}
    void AddPoint(Point const & point );
    std::string getInfo()
    {
	std::cout << this -> info << "\n";
	return this -> info;
    }
    static Polygon & getRand();
    ~Polygon ();
};

std::ostream & operator << (std::ostream & s, Polygon const & pl)
{
    return s << "Polyline: \n" << pl.getPoints();
}

Polygon::Polygon() : Named(std::string ("polygon"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> pts = Container<Point>();
}

Polygon::Polygon(Point const & p1, Point const & p2, Point const & p3) : Named(std::string ("polygon"))
{
    this -> info = Shape::info + " " + Named::info;
    this -> pts = Container<Point>();
    this -> pts.push_back(p1);
    this -> pts.push_back(p2);
    this -> pts.push_back(p3);
}

void Polygon::AddPoint( Point const & point )
{
   this -> pts.push_back(point);
}

Polygon & Polygon::getRand()
{
    std::srand ((unsigned int)time(0));
    Polygon * p = new Polygon (Point::getRand(), Point::getRand(), Point::getRand());
    for (uint8_t i = 0; i < std::rand() % 50; i++)
	p -> AddPoint(Point::getRand());
    return * p;
}

Polygon::~Polygon()
{

}



#endif // SHAPE_H
