#include "Game.h"

using namespace std;


Game::Game(int w, int h, string chars)
{
    
}

Game::~Game()
{
   map->~Map();
   player->~Player(); 
}

string Game::display()
{
    return map->print();
}

void Game::update(char input)
{
    if (player)
    {
            switch (input)
        {
            case '1':
            player->move(-1, 1);
            break;
            case '2':
            player->move(0, 1);
            break;
            case '3':
            player->move(1, 1);
            break;
            case '4':
            player->move(-1, 0);
            break;
            case '6':
            player->move(1, 0);
            break;
            case '7':
            player->move(-1, -1);
            break;
            case '8':
            player->move(0, -1);
            break;
            case '9':
            player->move(1, -1);
            break;
        } 
    }
     
    
}
