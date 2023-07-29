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
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED);

    // Set up two circles with initial positions, velocities, radius, and mass
    Circle circle1 = { .x = 100.0f, .y = 100.0f, .velX = 0.0f, .velY = 0.0f, .radius = 20.0f, .mass =  1.0f };
    Circle circle2 = { .x = 150.0f, .y = 200.0f, .velX = 0.0f, .velY = 0.0f, .radius = 25.0f, .mass = 2.0f };

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

        // Apply gravity to both circles
        applyGravity(&circle1, deltaTime);
        applyGravity(&circle2, deltaTime);

        // Update the positions of both circles based on their velocities
        updatePosition(&circle1, deltaTime);
        updatePosition(&circle2, deltaTime);

        // Check if the two circles collide and resolve the collision if necessary
        if (checkCollision(&circle1, &circle2)) 
        {
            resolveCollision(&circle1, &circle2);
        }

        // Clear the renderer with a black color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw a line between the centers of the two circles
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, (int)circle1.x, (int)circle1.y, (int)circle2.x, (int)circle2.y);

        // Draw the first circle with a red color
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawCircle(renderer, (int)circle1.x, (int)circle1.y, (int)circle1.radius);

        // Draw the second circle with a blue color
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        drawCircle(renderer, (int)circle2.x, (int)circle2.y, (int)circle2.radius);

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
