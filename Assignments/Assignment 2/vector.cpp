#include "vector.h"
#include <iomanip>
Vector::Vector(unsigned s)
{
    size = s;
    vector = new double[size];
    for (int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
    
}

Vector::Vector(const Vector& rhs)
{
    this->size = rhs.size;
    vector = new double[size];
    for (int i = 0; i < size; i++)
    {
        vector[i] = rhs.vector[i];
    }
}

Vector::~Vector()
{
    delete [] vector;
}

void Vector::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << setprecision(3) << vector[i];
    }
    cout << endl;
    
}

void Vector::readFile(istream &infile)
{
    for (int i = 0; i < size; i++)
    {
        infile >> vector[i];
    }
    
}

const Vector& Vector::operator=(const Vector& rhs)
{
    if (&rhs != this)
    {
        this->size = rhs.size;
        vector = new double[size];
        for (int i = 0; i < size; i++)
        {
            vector[i] = rhs.vector[i];
        }
    }

    return *this;
}

Vector Vector::operator/(const double& rhs)
{
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    Vector temp(*this);
    for (int i = 0; i < size; i++)
    {
        temp.vector[i] = vector[i]/rhs;
    }
    
    return temp;
}

const double& Vector::operator[](const unsigned r) const
{
    return vector[r];
}

double& Vector::operator[](const unsigned r)
{
    return vector[r];
}

Vector Vector::operator-(const Vector& rhs)
{
    Vector temp(*this);
    if (size != rhs.size)
    {
        throw "“Error: subtracting vectors of different dimensionality";
    }
    for (int i = 0; i < size; i++)
    {
        temp.vector[i] = vector[i] - rhs.vector[i];
    }
    
    return temp;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    if (size != rhs.size)
    {
        throw "“Error: subtracting vectors of different dimensionality";
    }
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector[i] - rhs.vector[i];
    }
    
    return *this;
}

Vector Vector::operator~()
{
    Vector temp(*this);
    int a = size - 1;
    for (int i = 0; i < size; i++)
    {   
        temp.vector[i] = vector[a];
        a--;     
    }
    
    return temp;
}

Vector& Vector::operator*=(const double& rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector[i] * rhs;
    }
    
    return *this;
}

Vector Vector::operator*(const double& rhs)
{
    Vector temp(*this);
    for (int i = 0; i < size; i++)
    {
        temp.vector[i] = vector[i] * rhs;
    }
    
    return temp;
}

Vector& Vector::operator^=(int pow)
{
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    double temp = 1;
    for (int i = 0; i < size; i++)
    {
       for (int j = 0; j < pow; ++j)
       {
          temp *= vector[i];
       }
       vector[i] = temp;
       temp = 1;
       
    }
    
    return *this;
}

Vector Vector::operator^(int pow)
{
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    Vector VTemp(*this);
    double temp = 1;
    for (int i = 0; i < size; i++)
    {
       for (int j = 0; j < pow; j++)
       {
          temp *= vector[i];
       }
       VTemp.vector[i] = temp;
       temp = 1;
       
    }
    
    return VTemp;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    if (size != rhs.size)
    {
        throw "“Error: adding vectors of different dimensionality";
    }
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector[i] + rhs.vector[i];
    }
    
    return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
    Vector temp(*this);
    if (size != rhs.size)
    {
        throw "“Error: adding vectors of different dimensionality";
    }
    for (int i = 0; i < size; i++)
    {
        temp.vector[i] = vector[i] + rhs.vector[i];
    }
    
    return temp;
}



unsigned Vector::getSize() const
{
    return size;
}

Vector operator* (const double& mul, const Vector& rhs)
{
    for (int i = 0; i < rhs.size; i++)
    {
        rhs.vector[i] = rhs.vector[i] * mul;
    }
    
    return rhs;
}
