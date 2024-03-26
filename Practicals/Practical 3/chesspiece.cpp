#include "chesspiece.h"

int Chesspiece::numberOfPieces = 0;

Chesspiece::Chesspiece()
{
    name = "";
    type == true;
    numberOfPieces++;
}

Chesspiece::Chesspiece(Chesspiece &obj)
{
    name = obj.name;
    type = obj.type;
    numberOfPieces++;
}

Chesspiece::Chesspiece(string in_name)
{
    name = in_name;
    numberOfPieces++;
}

Chesspiece::~Chesspiece()
{
    numberOfPieces--;
}

string Chesspiece::getName() const
{
    return name;
}

bool Chesspiece::getType() const
{
    return type;
}

int Chesspiece::getNumberOfPieces() const
{
    return numberOfPieces;
}

Chesspiece::Chesspiece(string in_name, bool in_type)
{
    name = in_name;
    type = in_type;
    numberOfPieces++;
}
