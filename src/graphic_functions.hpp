#pragma once

#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_mixer.h>
//#include <SDL2/SDL_ttf.h>

#include "color_functions.hpp"
#include "complex_functions.hpp"

struct SDL {
    SDL(int DIMX, int DIMY);

    ~SDL();

    SDL_Window* window;
    SDL_Renderer* renderer;

    // The width of the window.
    const int WINX;
    // The height ot the window.
    const int WINY;
    // The position of the center of the window.
    const SDL_Point CENTER;
    // The size of the font.
    const int FONTSIZE;

    // False if the window is open.
    bool stop;
    // Handles every events.
    SDL_Event event{};
    // Checks the state of all keyboard keys.
    const Uint8* keyboard{};

    /**
     * \brief Checks if either the 'ESCAPE' key or the window's 'X' is pressed.
     * If it is, changes the value of SDL::stop.
     */
    void quitWindow();

    /**
     * \brief Updates the changes since the last iteration and clears previous ones off the window.
     * @param backgroundColor The color the window will be cleared with.
     */
    void clearAndUpdate(SDL_Color backgroundColor) const;

    /**
     * \brief Updates the state of SDL::keyboard
     */
    void getKeyboardState();

    /**
     * \brief Updates the drawing color
     * @param color The color it will be changed to.
     */
    void setColor(SDL_Color color) const;

    /**
     * \brief Draws a filled circle.
     * @param center The position of the circle's center.
     * @param radius The radius of the circle.
     * @param color The color it will be drawn with.
     */
    void fillCircle(SDL_Point center, int radius, SDL_Color color) const;
};