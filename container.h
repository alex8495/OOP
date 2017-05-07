#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include "shapes.h"

template <class T>
struct element
{
    T value;
    element<T> * pnext;
    element<T> * pprev;
};

template <class T>
class Container
{
private:
    element<T> * pb;
    element<T> * pe;
    uint8_t size;
public:
    Container ();
    ~Container ();
    void push_back (T const & el);
    void push_begin (T const & el);
    void pop_back ();
    void pop_begin ();
    T getFirst () const;
    T getLast () const;
    uint8_t getSize() const;
    element<T> * getPB() const;
    bool empty () const;
    void clear ();
    void output () const;
};

template <class T>
std::ostream & operator << (std::ostream & s, Container<T> const & c)
{
    if (c.getSize() != 0)
    {
        element<T> * tmp = c.getPB();
        s << tmp -> value;
        for (uint8_t i = 1; i < c.getSize(); i++)
        {
            tmp = tmp -> pnext;
            s << ", " << tmp -> value;
        }
    }
    s << "\n";
    return s;
}

template <class T>
Container<T>::Container()
{
    this -> pb = NULL;
    this -> pe = NULL;
    this -> size = 0;
}

template <class T>
Container<T>::~Container()
{
    while (size!=0)
        pop_back();
}

template <class T>
void Container<T>::push_back(T const & el)
{
    element<T> * elem = new element<T>;
    elem -> value = el;
    elem -> pnext = NULL;
    elem -> pprev = pe;
    if (pe != NULL)
        this -> pe -> pnext = elem;
    this -> pe = elem;
    if (this -> pb == NULL)
        this -> pb = elem;
    this -> size++;
}

template <class T>
void Container<T>::push_begin(T const & el)
{
    element<T> * elem = new element<T>();
    elem -> value = el;
    elem -> pnext = pb;
    elem -> pprev = NULL;
    if (this -> pb != NULL)
        this -> pb -> pprev = elem;
    this -> pb = elem;
    if (this -> pe == NULL)
        this -> pe = elem;
    this -> size++;
}

template <class T>
void Container<T>::pop_back()
{
    if (this -> size != 0)
    {
        if (this -> size != 1)
        {
            this -> pe = this -> pe -> pprev;
            delete this -> pe -> pnext;
            this -> pe -> pnext = NULL;
        }
        else
            delete this -> pe;
        this -> size--;
    }
}

template <class T>
void Container<T>::pop_begin()
{
    if (this -> size != 0)
    {
        this -> pb = this -> pb -> pnext;
        delete this -> pb -> pprev;
        this -> pb -> pprev = NULL;
        this -> size--;
    }
}

template <class T>
T Container<T>::getFirst() const
{
    if (this -> size != 0)
        return this -> pb -> value;
    else
        return 0;
}

template <class T>
T Container<T>::getLast() const
{
    if (this -> size != 0)
        return this -> pe -> value;
    else
        return 0;
}

template <class T>
uint8_t Container<T>::getSize() const
{
    return this -> size;
}

template <class T>
element<T> * Container<T>::getPB() const
{
    if (this -> size != 0)
        return this -> pb;
    else
        return 0;
}

template <class T>
bool Container<T>::empty() const
{
    if (this -> size == 0)
        return true;
    else
        return false;
}

template <class T>
void Container<T>::clear()
{
    while (this -> size != 0)
        pop_back();
}

template <class T>
void Container<T>::output() const
{
    if (this -> size != 0)
    {
        element<T> * tmp = this -> pb;
        std::cout << tmp -> value;
        for (uint8_t i = 1; i < this -> size; i++)
        {
            tmp = tmp -> pnext;
            std::cout << ", " << tmp -> value;
        }
    }
}


#endif // CONTAINER_H
