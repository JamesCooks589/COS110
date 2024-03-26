#include "chessboard.h"

Chessboard::Chessboard(Chessboard &obj)
{
    rows = obj.rows;
    columns = obj.columns;
    board = new Chesspiece**[rows];
    for (int row = 0; row < rows; row++)
    {
        board[row] = new Chesspiece*[columns];
        for (int col = 0; col < columns; col++)
        {
            if (obj.board[row][col])
            {
                board[row][col] = new Chesspiece(*obj.board[row][col]);
            }
            else
            {
                board[row][col] = NULL;
            }
            
            
        }  
    }
    

}

Chessboard::Chessboard(int in_rows, int in_columns)
{
    rows = in_rows;
    columns = in_columns;
    board = new Chesspiece**[rows];
    for (int row = 0; row < rows; row++)
    {
        board[row] = new Chesspiece*[columns];
        for (int col = 0; col < columns; col++)
        {
            board[row][col] = NULL;
        }  
    }
}

Chessboard::~Chessboard()
{
   for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            delete board[row][col];
        }
        delete[] board[row];
    }
    delete[] board; 
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column)
{
    if (board[row][column] == NULL)
    {
        board[row][column] = piece;
    }
     
}

void Chessboard::removeChesspiece(int row, int column)
{
    if (board[row][column])
    {
        delete board[row][column];
        board[row][column] = NULL;
    }
    
}

Chesspiece& Chessboard::at(int row, int column) const
{
    return *board[row][column];
}

Chessboard& Chessboard::operator=(const Chessboard &other)
{
    rows = other.rows;
    columns = other.columns;
    board = new Chesspiece**[rows];
    for (int row = 0; row < rows; row++)
    {
        board[row] = new Chesspiece*[columns];
        for (int col = 0; col < columns; col++)
        {
            if (other.board[row][col])
            {
                board[row][col] = new Chesspiece(*other.board[row][col]);
            }
            else
            {
                board[row][col] = NULL;
            }
            
            
        }  
    }
    return *this;
}

Chessboard& Chessboard::operator+=(const Chessboard &rhs)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            if (!board[row][col] && rhs.board[row][col])
            {
               board[row][col] = rhs.board[row][col];
            }
            
        }
        
    }
    return *this;
}
