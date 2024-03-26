#include <iostream>

#include "matrix.h"

using namespace std;

// Do not change the displayMatrix() function
void Matrix::displayMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            cout << *matrix[i][j];

            if (j != columns - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

Matrix::Matrix(int in_rows, int in_columns)
{
    if (in_rows < 1 || in_columns < 1)
    {
        rows = 3;
        columns = 3;

        matrix = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                matrix[row][col] = new int(1);
            }
        }
    }
    else
    {
        rows = in_rows;
        columns = in_columns;

        matrix = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                matrix[row][col] = new int(0);
            }
        }
    }
}

Matrix::~Matrix()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            delete matrix[row][col];
        }
        delete[] matrix[row];
    }
    delete[] matrix;
}

void Matrix::resizeRows(int num_rows)
{
    if (num_rows < 1)
    {
        cout << "Error: cannot have less than 1 row" << endl;
    }
    else if (num_rows < rows)
    {
        int ***temp;
        rows = num_rows;
        temp = new int **[num_rows];
        for (int row = 0; row < num_rows; row++)
        {
            temp[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                temp[row][col] = matrix[row][col];
            }
        }

        matrix = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                matrix[row][col] = temp[row][col];
            }
        }

        /*for (int row = 0; row < rows; row++)
             {
                for (int col = 0; col < columns; col++)
                {
                    delete temp[row][col];
                }
                    delete [] temp[row];
                }
             delete [] temp;*/
    }
    else if (num_rows > rows)
    {
        int ***temp;
        temp = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            temp[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                temp[row][col] = matrix[row][col];
            }
        }

        matrix = new int **[num_rows];
        for (int row = 0; row < num_rows; row++)
        {
            matrix[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                if (row < rows)
                {
                    matrix[row][col] = temp[row][col];
                }
                else
                {
                    matrix[row][col] = new int(0);
                }
            }
        }
        rows = num_rows;
    }
}

void Matrix::resizeColumns(int num_cols)
{
    if (num_cols < 1)
    {
        cout << "Error: cannot have less than 1 column" << endl;
    }
    else if (num_cols < columns)
    {
        int ***temp;
        columns = num_cols;
        temp = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            temp[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                temp[row][col] = matrix[row][col];
            }
        }

        matrix = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                matrix[row][col] = temp[row][col];
            }
        }

    }else if (num_cols > columns)
    {
        int ***temp;
        temp = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            temp[row] = new int *[columns];
            for (int col = 0; col < columns; col++)
            {
                temp[row][col] = matrix[row][col];
            }
        }

        matrix = new int **[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new int *[num_cols];
            for (int col = 0; col < num_cols; col++)
            {
                if (col < columns)
                {
                    matrix[row][col] = temp[row][col];
                }
                else
                {
                    matrix[row][col] = new int(0);
                }
            }
        }
        columns = num_cols;
    }
}

void Matrix::setMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> *matrix[i][j];
        }
    }
}
