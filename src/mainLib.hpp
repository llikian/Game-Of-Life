#pragma once

#include "graphic_functions.hpp"

const SDL_Color BG_COLOR = makeColor(20, 20, 20);

class GameOfLife {
public:
    GameOfLife(int radius);

    ~GameOfLife();

    // YOU NEED TO CONFIGURE THE COPY OPERATORS AND CONSTRUCTORS

    SDL sdl;

    const int WIDTH;
    const int HEIGHT;

    const int RADIUS;

    bool** cells;
    bool** previousGen;

    void print() const;
    void draw() const;
    void update() const;

    void countCells(short& alive, int posX, int posY) const;
};
