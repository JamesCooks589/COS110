//The Controller implementation file
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

using namespace std;
template<class T>
Controller<T>::Controller(Plane<T>* p)
{
    plane = p;
}

template<class T>
string Controller<T>::loadOnPlane(T* t)
{
    try
    {
        plane->add(t);
        return "Success";
    }
    catch(AboveWeightEx(weightDifference))
    {
        double temp;
        string sTemp;
        temp = weightDifference.getDifference();
        stringstream sOut;
        sOut << temp;
        sOut >> sTemp;

        
        return "Could not load item, above max weight by " + sTemp;
    }
    
}

template<class T>
double Controller<T>::getTotalValue()
{
   try
   {
       return plane->calculateValue();
   }
   catch(EmptyEx e)
   {
    return 0;
   }
   catch(UnauthorisedEx e)
   {
    return 0;
   }
   catch(UndervaluedEx<T> e)
   {
    return e.getSum();
   }
   
}

template<class T>
string Controller<T>::getPlaneContents()
{
    try
    {   
        return plane->getDescription();
        
    }
    catch(EmptyEx e)
    {
        return "Nothing to report";
    }
    catch(UnauthorisedEx e)
    {
        return "Not permitted";
    }
    
}

#endif