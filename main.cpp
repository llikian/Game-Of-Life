#include "src/mainLib.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char* argv[]) {
    GameOfLife got(10);

    Uint32 updateTicks{};

    // Main Loop
    while(!got.sdl.stop) {
        got.sdl.getKeyboardState();

        got.draw();
        if(SDL_GetTicks() - updateTicks > 300) {
            got.update();
            updateTicks = SDL_GetTicks();
        }

        got.sdl.clearAndUpdate(BG_COLOR);
        got.sdl.quitWindow();
    }
}