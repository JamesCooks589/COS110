#include <iostream>
#include "Calendar.h"
#include "Event.h"
#include "Utils.h"

using namespace std;

int main(){
    string s = "David's cex time";
    long int p = 1680325836;
    cout<<"test1"<<endl;
    Calendar Test(get_api_results(34,10));
    cout<<"test2"<<endl;
    cout<< unix_to_string( Test.getFirstEvent()->start)<<endl;
    cout<< unix_to_string( Test.getFirstEvent()->next->start) <<endl;
    cout<<Test.filterEvents(NULL,&Test.getFirstEvent()->start,NULL,NULL).size()<<endl;
    cout<<Test;
    cout<<*Test.getUpcomingEvent(1663999325)<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    Test.alterEvent(8206, &p, &s);
    cout<<Test;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    Test.removeEvent(8206);
    cout<<Test;
    return 0;
}