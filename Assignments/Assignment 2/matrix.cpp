#include "matrix.h"
#include <iomanip>
Matrix::Matrix(unsigned r, unsigned c)
{
    rows = r;
    cols = c;
    matrix = new double *[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new double[cols];
            for (int col = 0; col < cols; col++)
            {
                matrix[row][col] = 0;
            }
        }
}

Matrix::Matrix(const Matrix& rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;
    matrix = new double *[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new double[cols];
            for (int col = 0; col < cols; col++)
            {
                matrix[row][col] = rhs.matrix[row][col];
            }
        }
}

Matrix::~Matrix()
{
    for (int row = 0; row < rows; row++)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
}

void Matrix::print()
{
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                cout << setw(10) << setprecision(3) << matrix[row][col];
            }
            cout << endl;
        }
}

void Matrix::readFile(istream &infile)
{
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
               infile >> matrix[row][col]; 
            }
        }
}

const Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (&rhs != this)
    {
        rows = rhs.rows;
        cols = rhs.cols;
        matrix = new double *[rows];
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = new double[cols];
            for (int col = 0; col < cols; col++)
            {
                matrix[row][col] = rhs.matrix[row][col];
            }
        }
    }

    return *this;
}

Matrix Matrix::operator/(const double& rhs)
{
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    Matrix temp(*this);
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                temp.matrix[row][col] = matrix[row][col]/rhs;
            }
        }
    
    return temp;
}

Matrix Matrix::operator~()
{
    Matrix temp(cols, rows);
    for (int row = 0; row < cols; row++)
        {
            for (int col = 0; col < rows; col++)
            {
                temp.matrix[row][col] = matrix[col][row];
            }
        }

    return temp;
}

Matrix Matrix::operator*(const double& rhs)
{
    Matrix temp(*this);
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                temp.matrix[row][col] = matrix[row][col] * rhs;
            }
        }
    return temp;
}

Matrix& Matrix::operator^=(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    double dTemp = 1;
    if (pow == 0)
    {
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == col)
                {
                    matrix[row][col] = 1;
                }
                else
                {
                    matrix[row][col] = 0;
                }             
            }
        }
    }
    else
    {
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                for (int i = 0; i < pow; i++)
                {
                    dTemp *= matrix[row][col]; 
                }
               matrix[row][col] = dTemp;
               dTemp = 1; 
            }
        }
    }
    
    
   return *this; 
}

Matrix Matrix::operator^(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    Matrix temp(*this);
    double dTemp = 1;
    if (pow == 0)
    {
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == col)
                {
                    temp.matrix[row][col] = 1;
                }
                else
                {
                    temp.matrix[row][col] = 0;
                }             
            }
        }
    }
    else
    {
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                for (int i = 0; i < pow; i++)
                {
                    dTemp *= temp.matrix[row][col]; 
                }
               temp.matrix[row][col] = dTemp;
               dTemp = 1; 
            }
        }
    }
    
    
   return temp; 
}

Matrix Matrix::operator-(const Matrix& rhs)
{
   if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "“Error: adding matrices of different dimensionality";
    }
    Matrix temp(*this);
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                temp.matrix[row][col] = matrix[row][col] - rhs.matrix[row][col];
            }
        }
   return temp;  
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
   if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "“Error: adding matrices of different dimensionality";
    }
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                matrix[row][col] = matrix[row][col] - rhs.matrix[row][col];
            }
        }
   return *this;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
    if (rows != rhs.cols || cols != rhs.rows)
    {
        throw "Error: invalid matrix multiplication";
    }
    Matrix temp(rows, rhs.cols);
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < rhs.cols; col++)
            {
                for (int i = 0; i < cols; i++)
                {
                    temp.matrix[row][col] += matrix[row][i] * rhs.matrix[i][col];
                }
                
            }
        }
    
    return temp;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
     if (rows != rhs.cols || cols != rhs.rows)
    {
        throw "Error: invalid matrix multiplication";
    }
    Matrix temp(rows, rhs.cols);
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < rhs.cols; col++)
            {
                for (int i = 0; i < cols; i++)
                {
                    temp.matrix[row][col] += matrix[row][i] * rhs.matrix[i][col];
                }
                
            }
        }
    
    
   return temp; 
}

Matrix Matrix::operator+(const Matrix& rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "“Error: adding matrices of different dimensionality";
    }
    Matrix temp(*this);
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                temp.matrix[row][col] = matrix[row][col] + rhs.matrix[row][col];
            }
        }
   return temp;
}

double& Matrix::operator()(const unsigned r, const unsigned c)
{
    if (r >= rows || r < 0)
    {
        throw "Error: invalid row index";
    }

    if (c >= cols || c < 0)
    {
         throw "Error: invalid column index";
    }
    
    
    return matrix[r][c];
}

const double& Matrix::operator()(const unsigned r, const unsigned c) const
{
    if (r >= rows || r < 0)
    {
        throw "Error: invalid row index";
    }

    if (c >= cols || c < 0)
    {
         throw "Error: invalid column index";
    }

    return matrix[r][c];
}

Matrix& Matrix::operator*=(const double& rhs)
{
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                matrix[row][col] = matrix[row][col] * rhs;
            }
        }
   return *this; 
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "“Error: adding matrices of different dimensionality";
    }
    for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                matrix[row][col] = matrix[row][col] + rhs.matrix[row][col];
            }
        } 
   return *this; 
}

Vector Matrix::operator[](const unsigned r) const
{
    if (r > rows || r < 0)
    {
        throw "Error: invalid row index";
    }
    
    Vector temp(rows);
    for (int i = 0; i < rows; i++)
    {
        temp[i] = matrix[r][i];
    }
    return temp;
}

unsigned Matrix::getRows() const
{
    return rows;
}

unsigned Matrix::getCols() const
{
    return cols;
}

Matrix Matrix::operator|(const Matrix& rhs)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }

    if (rhs.rows != rows || rhs.cols != 1)
    {
        throw "Error: incorrect augmentation";
    }

    Matrix t1(rhs);
    Matrix t2(*this);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < r; c++)
        {
            if (t2.matrix[r][c] != 0)
            {
                t2.operator|=(t1);
                break;
            }
            
        }
        
    }

    for (int i = t2.rows - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < t2.rows; j++)
        {
            t1.matrix[i][0] = t1.matrix[i][0] - t2.matrix[i][j] * t1.matrix[j][0];
        }

        if (t2.matrix[i][i] == 0)
            {
                throw "Error: division by zero";
            }
        t1.matrix[i][0] = t1.matrix[i][0] / t2.matrix[i][i];
        
    }
    
    

    return t1;
}

Matrix& Matrix::operator|=(Matrix& rhs)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }

    if (rhs.rows != rows || rhs.cols != 1)
    {
        throw "Error: incorrect augmentation";
    }
    
    
    double mul = 0;
    for (int j = 0; j < rows - 1; j++)
    {
        for (int i = j + 1; i < rows; i++)
        {
            if (matrix[j][j] == 0)
            {
                throw "Error: division by zero";
            }
            
            mul = this->matrix[i][j]/this->matrix[j][j];
            for (int k = 0; k < rhs.rows; k++)
            {
                matrix[i][k] = matrix[i][k] - mul * matrix[j][k];
            }
            *rhs.matrix[i] = *rhs.matrix[i] - mul * *rhs.matrix[j];
        }
        
    }
    return *this;
}

Matrix operator* (const double& mul, const Matrix& rhs)
{
    for (int row = 0; row < rhs.rows; row++)
        {
            for (int col = 0; col < rhs.cols; col++)
            {
                rhs.matrix[row][col] = rhs.matrix[row][col] * mul;
            }
        }
    return rhs;
}
