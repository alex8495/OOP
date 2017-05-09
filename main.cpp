#include <iostream>
#include <cstdlib>
#include <ctime>

#include "container.h"
#include "shapes.h"


void main()
{
    srand ((unsigned int)time(0));
    uint8_t r = rand() % 4;
    switch (r)
    {
        case 0:
        {
            Container<Point> c;
	    uint8_t i;
	    uint8_t num;
	    for (i = 0, num = rand() % 20 + 20; i < num; i++)
            {
                c.push_back(Point::getRand());
		std::cout<<"Number of shapes: "<<std::to_string(Shape::GetCount())<<".\n";
            }
	    std::cout<<"Number of shapes: "<<std::to_string(Shape::GetCount())<<".\n";
            c.output();
            c.clear();
	    std::cout<<"Number of shapes after deletion: "<<std::to_string(Shape::GetCount())<<".\n";
            break;
        }
        case 1:
        {
            Container<Circle> c;
	    uint8_t i;
	    uint8_t num;
	    for (i = 0, num = rand() % 20 + 20; i < num; i++)
	    {
                c.push_back(Circle::getRand());
            }
	    std::cout<<"Number of shapes: "<<std::to_string(Shape::GetCount())<<".\n";
            c.output();
            c.clear();
	    std::cout<<"Number of shapes after deletion: "<<std::to_string(Shape::GetCount())<<".\n";
            break;
        }
        case 2:
        {
            Container<Rect> c;
	    uint8_t i;
	    uint8_t num;
	    for (i = 0, num = rand() % 20 + 20; i < num; i++)
            {
                c.push_back(Rect::getRand());
            }
	    std::cout<<"Number of shapes: "<<std::to_string(Shape::GetCount())<<".\n";
            c.output();
            c.clear();
	    std::cout<<"Number of shapes after deletion: "<<std::to_string(Shape::GetCount())<<".\n";
            break;
        }
        case 3:
        {
            Container<Square> c;
	    uint8_t i;
	    uint8_t num;
	    for (i = 0, num = rand() % 20 + 20; i < num; i++)
            {
                c.push_back(Square::getRand());
	    }
	    std::cout<<"Number of shapes: "<<std::to_string(Shape::GetCount())<<".\n";
            c.output();
            c.clear();
	    std::cout<<"Number of shapes after deletion: "<<std::to_string(Shape::GetCount())<<".\n";
            break;
        }
        case 4:
        {
	    Container<Polyline> c;
	    for (uint8_t i = 0; i < rand() % 20 + 20; i++)
	    {
		c.push_back(Polyline::getRand());
	    }
	    std::cout<<"Number of shapes: "<<Shape::GetCount()<<".\n";
	    c.output();
	    c.clear();
	    std::cout<<"Number of shapes after deletion: "<<Shape::GetCount()<<".\n";
	    break;
        }
        case 5:
        {
	    Container<Polygon> c;
	    for (uint8_t i = 0; i < rand() % 20 + 20; i++)
	    {
		c.push_back(Polygon::getRand());
	    }
	    std::cout<<"Number of shapes: "<<Shape::GetCount()<<".\n";
	    c.output();
	    c.clear();
	    std::cout<<"Number of shapes after deletion: "<<Shape::GetCount()<<".\n";
	    break;
        }




    }
    return;
}
