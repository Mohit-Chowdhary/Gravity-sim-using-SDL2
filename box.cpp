#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BOX_SIZE = 50;
const float GRAVITY = 0.5f;
const float FLOOR_Y = SCREEN_HEIGHT - BOX_SIZE;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Falling Box",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    float boxY = 0;
    float velocity = 0;
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                boxY = 0;
                velocity = 0;
            }
        }

        velocity += GRAVITY;
        boxY += velocity;

        if (boxY >= FLOOR_Y) {
            boxY = FLOOR_Y;
            velocity = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect box = {SCREEN_WIDTH / 2 - BOX_SIZE / 2, (int)boxY, BOX_SIZE, BOX_SIZE};
        SDL_RenderFillRect(renderer, &box);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
