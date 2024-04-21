#include "mainLib.hpp"

GameOfLife::GameOfLife(int radius) : RADIUS{radius}, sdl{1200, 700}, WIDTH{(sdl.WINX/radius)-1}, HEIGHT{(sdl.WINY/radius)-1} {
    cells = new bool*[WIDTH];
    previousGen = new bool*[WIDTH];

    int x, y, count{};

    for(int i = 0 ; i < WIDTH ; ++i) {
        cells[i] = new bool[HEIGHT]{};
        previousGen[i] = new bool[HEIGHT]{};
    }

    while(count < WIDTH*HEIGHT/2) {
        x = randInt(1, WIDTH-2);
        y = randInt(1, HEIGHT-2);

        if(!cells[x][y]) {
            cells[x][y] = true;
            previousGen[x][y] = true;
            ++count;
        }
    }

    update();
}

GameOfLife::~GameOfLife() {
    for(int i = 0 ; i < WIDTH ; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void GameOfLife::print() const {
    for(int i = 0 ; i < WIDTH ; ++i) {
        for(int j = 0 ; j < HEIGHT ; ++j) {
            std::cout << ((cells[i][j])? 'o' : 'x');
        }
        std::cout << std::endl;
    }
}

void GameOfLife::draw() const {
    for(int i = 0 ; i < WIDTH ; ++i) {
        for(int j = 0 ; j < HEIGHT ; ++j) {
            if(cells[i][j]) {
                sdl.fillCircle(makePoint(RADIUS*(i+1), RADIUS*(j+1)), RADIUS/2, BLUE/2 + PURPLE/2);
            }
        }
    }
}

void GameOfLife::update() const{
    short alive;

    for(int i = 1; i < WIDTH-1 ; ++i) {
        for(int j = 1 ; j < HEIGHT-1 ; ++j) {
            countCells(alive, i, j);

            if(cells[i][j] && (alive < 2 || alive > 3)) {
                cells[i][j] = false;
            } else if(!cells[i][j] && alive == 3) {
                cells[i][j] = true;
            }
        }
    }

    for(int i = 0 ; i < WIDTH ; ++i) {
        for(int j = 0 ; j < HEIGHT ; ++j) {
            previousGen[i][j] = cells[i][j];
        }
    }
}

void GameOfLife::countCells(short& alive, int posX, int posY) const{
    alive = 0;

    for(int i = -1 ; i <= 1 ; ++i) {
        for(int j = -1 ; j <= 1 ; ++j) {
            if((i || j) && previousGen[i+posX][j+posY]) {
                ++alive;
            }
        }
    }
}