#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;


int main() 
{
    ifstream myFile("data.txt");
        if (!myFile.is_open()){
            cout << "File Failed to open"<< endl;
        }

      string line;
      int numLines = 0;
      
      while (getline(myFile, line))
      {
         ++numLines;

      }

      myFile.close();
      myFile.open("data.txt");

      int arrNumItems[numLines] = {};
      int k = 0;

       while (getline(myFile, line))
      {
         int numItems = 1;
         for (int i = 0; i < line.size(); i++)
         {

             if (line[i] == ',')
             {
               ++numItems;   
             }
 
             
         }
        arrNumItems[k] = numItems;
        k ++;
      }

       string** a = new string*[numLines];
       for (int i = 0; i < arrNumItems[i]; i++)
        {
           a[i] = new string[arrNumItems[i]];
        }


        for (int row = 0; row < numLines; row++)
        {
            for (int col = 0; col < arrNumItems[col]; col++)
            {
               a[row][col] == "0"; 
            }
            
        }

         for (int row = 0; row < numLines; row++)
        {
            for (int col = 0; col < arrNumItems[col]; col++)
            {
              cout << a[row][col]; 
            }
            cout << endl;
        }

        for(int row = 0; row < numLines; row++)
        {
	        delete [] a[row];
        }
            delete [] a;



        
      
      



        
        
	return 0;
}