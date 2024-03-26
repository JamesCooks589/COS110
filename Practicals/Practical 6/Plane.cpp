//The Plane implementation file'
#ifndef PLANE_CPP
#define PLANE_CPP
using namespace std;
template<class T>
Plane<T>::Plane(double max)
{
    maxWeight = max;
}

template<class T>
Plane<T>::~Plane()
{
   for (int i = 0; i < cargo.size(); i++)
   {
     delete cargo[i];
   }
   
    
}

template<class T>
void Plane<T>::add(T* item)
{
    double temp = 0;
    for (int i = 0; i < cargo.size(); i++)
    {
        
        temp += cargo[i]->getWeight();
    }
    
    if (temp + item->getWeight() > maxWeight)
    {
        double weightDifference = temp + item->getWeight() - maxWeight;
        throw AboveWeightEx(weightDifference);
    }
    else
    {
        cargo.push_back(item);
    }  
    
    
}

template<class T>
void Plane<T>::remove(T* item)
{
   if (cargo.size() == 0)
   {
    throw EmptyEx();
   }

   
   for (int i = 0; i < cargo.size(); i++)
   {
        if (item == cargo[i])
        {
            cargo.erase(cargo.begin() + i);
            return;
        }
        
   }
   throw NotFoundEx<T>(item);
}

template<class T>
string Plane<T>::getDescription()
{
    if (cargo.size() == 0)
   {
    throw EmptyEx();
   }

   string desc = "";
   for (int i = 0; i < cargo.size(); i++)
   {
        if (i == cargo.size()-1)
        {
            desc += cargo[i]->describe();
        }
        else
        {
            desc += cargo[i]->describe() + "\n";
        }
        
        
   }
   return desc;
   
}

template<>
string Plane<SecretCargo>::getDescription()
{
    if (cargo.size() == 0)
   {
    throw EmptyEx();
   }
    else
    {
        throw UnauthorisedEx();
    }
    
   
}

template<class T>
double Plane<T>::calculateValue()
{
   if (cargo.size() == 0)
   {
    throw EmptyEx();
   }
    double s1 = cargo[0]->getValue();
    double s2 = cargo[0]->getValue();
    int index = 0;
    double sum = 0;
    for (int i = 0; i < cargo.size(); i++)
    {
        if (cargo[i]->getValue() > s1)
        {
            if (cargo[i]->getValue() < s2 || s1 == s2)
            {
                s2 = cargo[i]->getValue();
            }
            
        }
        else
        {
            if (s2 > s1 && cargo[i]->getValue() != s1)
            {
                s2 = s1;
            }
            s1 = cargo[i]->getValue();
            index = i;
        }
        
       sum += cargo[i]->getValue(); 
    }
    
    if (s1 < s2/2)
    {
        sum -= s1;
        throw UndervaluedEx<T>(cargo[index], sum);
    }
    
    return sum;

}

template<>
double Plane<SecretCargo>::calculateValue()
{
    if (cargo.size() == 0)
   {
    throw EmptyEx();
   }
    else
    {
        throw UnauthorisedEx();
    }
    
   
}

#endif