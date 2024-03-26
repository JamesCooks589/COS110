#include "Calendar.h"

using namespace std;


Calendar::Calendar()
{
    head = NULL;
}

Calendar::Calendar(vector<event_data> input)
{
    head = NULL;
    for (int i = 0; i < input.size(); i++)
    {
        createEvent(input[i]);
    }
        
}

Calendar::~Calendar()
{
    this->clearCalendar();
}

Event* Calendar::getUpcomingEvent(long int now)
{
    Event* ptr = head;
    if (!head)
    {
        return NULL;
    }
    while (ptr && ptr->start <= now)
    {
        ptr = ptr->next;
    }
    return ptr;
    
    
}

vector<Event> Calendar::filterEvents(int* id, long int* start,long int* end, string* type)
{
    Event* ptr = head;
    vector<Event> list;
    if (!id && !start && !end && !type)
    {
        if (head)
        {
            while (ptr)
            {
                list.push_back(*ptr);
                ptr = ptr->next;
            }
            return list;
        }
        
    }

       if (head)
    {
        while (ptr)
        {

            if (id)
            {
                if (ptr->id != *id)
                {
                    ptr = ptr->next;
                    continue;
                }
                
            }

            if (start)
            {
                if (ptr->start <= *start)
                {
                    ptr = ptr->next;
                    continue;
                }
            }

            if (end)
            {
                if (ptr->end >= *end)
                {
                    ptr = ptr->next;
                    continue;
                }
            }

            if (type)
            {
                if (ptr->type != *type)
                {
                    ptr = ptr->next;
                    continue;
                }
            }
            
        list.push_back(*ptr);  
        ptr = ptr->next;    
            
        }
        return list;
    } 
    
    
    
}

void Calendar::alterEvent(int id, long int* end, string* type)
{
    Event* ptr = head;
    if (head)
    {
        while (ptr && ptr->id != id)
        {
            ptr = ptr->next;
        }
        if (end)
        {
            ptr->end = *end;
        }
        if (type)
        {
            ptr->type = *type;
        }
        
    }
    
}

void Calendar::removeEvent(int id)
{
   Event* ptr; 
   Event* prev = NULL;
   ptr = head;
   if (head)
   {
     while (ptr && ptr->id != id)
     {
        prev = ptr;
        ptr = ptr->next;
     }
     if (ptr)
     {
        if (ptr == head)
        {
            head = head->next;
            delete ptr;
        }
        else
        {
            prev->next = ptr->next;
            delete ptr;
        }    
     }    
   }
    
}

void Calendar::createEvent(event_data data)
{
   Event* newNode = new Event(data.start, data.end, data.id, data.type);
   Event* ptr;
   Event* prev;
   newNode->next = NULL;
   if (head == NULL)
   {
    head = newNode;
   }
   else
   {
    ptr = head;
    prev = NULL;
    while (ptr != NULL && ptr->start <= newNode->start)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL)
    {
        head = newNode;
        newNode->next = ptr;
    }
    else
    {
        prev->next = newNode;
        newNode->next = ptr;
    }  
    
   }

}

void Calendar::clearCalendar()
{
    Event* ptr = head;
    while (ptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
    
}

Event* Calendar::getFirstEvent()
{    
    return head;
}

ostream& operator<<(ostream& out,Calendar& calendar)
{

    int J = 0;
    Event* ptr = calendar.head;
        while (ptr)
        {

            out << J++ << ": " << *ptr << endl;
            ptr = ptr->next;
        }
        return out;
    
}
