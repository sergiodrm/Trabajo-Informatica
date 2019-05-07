#include "game.h"

Game::Game()
{
    game_over = false;

}


GameWindow Game::getGameWindow() { return this->gamewindow; }
MenuWindow Game::getMenuWindow() { return this->menuwindow; }

bool Game::getGameOver() { return this->game_over; }
void Game::setGameOver(bool game_over) { this->game_over = game_over; }

void Game::initGame(){
    this->menuwindow.show();
}

void Game::actualizarGame(){
    this->gamewindow.repaint();
}
