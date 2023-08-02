#include "main.h"

 /**
  * @brief The main function to run the 2D physics engine.
  *
  * This function initializes SDL, creates a window and a renderer, and sets up two circles for simulation.
  * It runs the game loop, where gravity is applied to the circles, their positions are updated based on velocity,
  * and collisions between the circles are checked and resolved. The circles are drawn on the window using SDL_RenderDrawPoint
  * and SDL_RenderDrawLine to visualize their movement and collision.
  *
  * @param argc Number of command-line arguments (not used in this program).
  * @param args Array of command-line argument strings (not used in this program).
  * @return 0 on successful execution.
  */
int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL with video subsystem

    // Create a window for the 2D Physics Engine with the specified dimensions
    SDL_Window* window = SDL_CreateWindow("2D Physics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);

    // Create a renderer to draw graphics on the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    // Set up a rectangle with initial position, velocities, width, height, and mass
    Rectangle rectangle = { .x = 400.0f, .y = 300.0f, .velX = 0.0f, .velY = 0.0f, .width = 40.0f, .height = 30.0f, .mass = 2.0f };

    // Seed the random number generator
    srand(SDL_GetTicks());

    // Generate random initial velocities for the rectangle
    rectangle.velX = (float)(rand() % 200 - 100); // Random value between -100 and 100
    rectangle.velY = (float)(rand() % 200 - 100); // Random value between -100 and 100

    float deltaTime = 0.016f; // Time step for simulation (adjust as needed)

    int quit = 0;
    while (!quit)
    {
        // Handle SDL events, such as window close
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1; // Set quit flag to exit the game loop
            }
        }

        // Apply gravity to the rectangle
        float gravity = 200.0f; // Adjust the value as needed
        rectangle.velY += gravity * deltaTime; // Vf = Vi + a * dt

        // Update the position of the rectangle based on its velocity
        updateRectanglePosition(&rectangle, deltaTime);

        // Check for collision with window boundaries and simulate reality
        checkCollisionWithWindow(&rectangle, 800, 600);

        // Clear the renderer with a black color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the rectangle with a green color
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect rect = { (int)(rectangle.x - rectangle.width / 2), (int)(rectangle.y - rectangle.height / 2), (int)rectangle.width, (int)rectangle.height };
        SDL_RenderFillRect(renderer, &rect);

        // Render the graphics on the window
        SDL_RenderPresent(renderer);

        // Add a delay to control the frame rate (approximately 60 fps in this case)
        SDL_Delay(16);
    }

    // Clean up resources and quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}