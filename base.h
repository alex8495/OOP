#ifndef BASE_H
#define BASE_H

#include <string>


class Printable
{
protected:
    std::string info;
public:
    virtual std::string getInfo() = 0;
    ~Printable() { }
};


class Named : public Printable
{
public:
    Named (std::string & name);
    std::string getInfo()
    {
        std::cout << this -> info << "\n";
        return this -> info;
    }
    ~Named() { }
};

Named::Named (std::string & name)
{
    this -> info += "This is a " + name + ".";
}

#endif // BASE_H
