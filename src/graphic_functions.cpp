#include "graphic_functions.hpp"

SDL::SDL(int DIMX, int DIMY) : WINX(DIMX), WINY(DIMY), CENTER{WINX / 2, WINY / 2}, FONTSIZE(25) {
    stop = false;

    window = nullptr;
    renderer = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL was not initialized, SDL Error: " << SDL_GetError() << std::endl;
        stop = true;
    }

    window = SDL_CreateWindow("SDL Tutos", 0x2FFF0000u, 0x2FFF0000u, DIMX, DIMY, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        std::cout << "Window not created, SDL Error: " << SDL_GetError() << std::endl;
        stop = true;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        std::cout << "Renderer not created, SDL Error: " << SDL_GetError() << std::endl;
        stop = true;
    }

    SDL_ShowCursor(SDL_DISABLE);
}

SDL::~SDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void SDL::quitWindow() {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT || keyboard[SDL_SCANCODE_ESCAPE]) {
            stop = true;
        }
    }
}

void SDL::clearAndUpdate(SDL_Color backgroundColor) const {
    SDL_RenderPresent(renderer);
    setColor(backgroundColor);
    SDL_RenderClear(renderer);
}

void SDL::getKeyboardState() {
    keyboard = SDL_GetKeyboardState(nullptr);
}

void SDL::setColor(SDL_Color color) const {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void SDL::fillCircle(SDL_Point center, int radius, SDL_Color color) const {
    int x = 0, y = radius, a, b, c, d;

    setColor(color);

    while(x <= radius) {
        a = center.x + x;
        b = center.y + y;
        c = center.x - x;
        d = center.y - y;

        SDL_RenderDrawLine(renderer, a, b, a, d);
        SDL_RenderDrawLine(renderer, c, b, c, d);

        ++x;
        y = (int) sqrt(radius * radius - x * x);
    }
}