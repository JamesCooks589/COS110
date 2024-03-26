#include "Map.h"


using namespace std;



Map::Map(int w, int h)
{
    width = w;
    height = h;
    rows = new ObjectList*[width];
    columns = new ObjectList*[height];
    for (int row = 0; row < width; row++)
    {
        rows[row] = new ObjectList(false);
    }
    for (int col = 0; col < height; col++)
    {
        columns[col] = new ObjectList(true);
    }

}

Map::~Map()
{
    //DEALOCATE ROWS
    for (int row = 0; row < width; row++)
    {
        Object* itr = rows[row]->getHead();
        while (itr)
        {
            Object* temp = itr;
            itr = itr->getNext(false);
            delete temp;
        }
        delete rows[row];
    }
    delete[] rows;
    //DEALOCATE COLUMNS
    for (int col = 0; col < height; col++)
    {
        Object* itr = columns[col]->getHead();
        while (itr)
        {
            Object* temp = itr;
            itr = itr->getNext(true);
            delete temp;
        }
        delete columns[col];
    }
    delete[] columns;

}

void Map::add(Object* obj)
{
    
}

string Map::print()
{
    //Use print function to print all rows
    string output = "";
    for (int row = 0; row < width; row++)
    {
        output += rows[row]->print() + "\n";
    }
    return output;

}
