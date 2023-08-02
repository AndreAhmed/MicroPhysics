#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>

#include "SOLID2DRectangle_interface.h"



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
    rectangle.velX = 0.0f;
    rectangle.velY = 0.0f;

    float deltaTime = 0.016f; // Time step for simulation (adjust as needed)

    int quit = 0;
    int isDragging = 0; // Set to 0 initially to indicate the rectangle is not moving

    while (!quit)
    {
        // Handle SDL events, such as window close and mouse events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1; // Set quit flag to exit the game loop
                break;
            case SDL_MOUSEBUTTONDOWN:
                // Check if the mouse is clicked within the rectangle
                if (event.button.button == SDL_BUTTON_LEFT &&
                    event.button.x >= (int)(rectangle.x - rectangle.width / 2) &&
                    event.button.x <= (int)(rectangle.x + rectangle.width / 2) &&
                    event.button.y >= (int)(rectangle.y - rectangle.height / 2) &&
                    event.button.y <= (int)(rectangle.y + rectangle.height / 2))
                {
                    isDragging = 1; // Start moving the rectangle when the mouse button is clicked
                }
                break;
            case SDL_MOUSEBUTTONUP:
                // Release the rectangle when the mouse button is released
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    isDragging = 0;
                }
                break;
            case SDL_MOUSEMOTION:
                // If dragging the rectangle, update its position to the mouse position
                if (isDragging)
                {
                    rectangle.x = (float)event.motion.x;
                    rectangle.y = (float)event.motion.y;
                }
                break;
            case SDL_KEYDOWN:
                // Check for key press to apply force
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    isDragging = 0; // Stop dragging the rectangle when the button is pressed
                    resetRectangle(&rectangle); // Reset the rectangle's position and velocity
                    rectangle.velX = 500.0f; // Set initial X velocity
                    rectangle.velY = -800.0f; // Set initial Y velocity (negative for upward force)
                }
                break;
            }
        }

        // Calculate the force applied to the rectangle based on Newton's second law (F = m * a)

        // Gravity force (pointing downwards)
        float gravityX = 0.0f;
        float gravityY = -9.8f * rectangle.mass; // Adjust gravity strength as needed (negative for downward force)

        // Dragging force (if not dragging, these forces will be zero)
        float forceX = 0.0f;
        float forceY = 0.0f;
        if (!isDragging)
        {
            // Adjust the force values as needed
            forceX = 500.0f;
            forceY = 800.0f; // Negative value for upward force
        }

        // Frictional force (opposite to the direction of motion)
        float frictionForceX = -rectangle.velX * 5.0f; // Adjust the friction coefficient (5.0f in this case)
        float frictionForceY = -rectangle.velY * 5.0f; // Adjust the friction coefficient (5.0f in this case)

        // Calculate the total force components
        float totalForceX = forceX + gravityX + frictionForceX;
        float totalForceY = forceY + gravityY + frictionForceY;

        // Calculate the acceleration based on the total force and mass
        float accelerationX = totalForceX / rectangle.mass;
        float accelerationY = totalForceY / rectangle.mass;

        // Update the velocity of the rectangle based on the acceleration
        rectangle.velX += accelerationX * deltaTime;
        rectangle.velY += accelerationY * deltaTime;

        // If the rectangle's velocity becomes very small, stop its movement
        if (fabs(rectangle.velX) < 0.5f && fabs(rectangle.velY) < 0.5f)
        {
            rectangle.velX = 0.0f;
            rectangle.velY = 0.0f;
        }

        // Update the position of the rectangle based on its velocity
        updateRectanglePosition(&rectangle, deltaTime);

        // Check for collision with window boundaries and simulate reality
        checkCollisionWithWindow(&rectangle, 800, 600);

        // Clear the renderer with a black color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the rectangle with a green color
        SDL_Color greenColor = { 0, 255, 0, 255 };
        drawSolidRectangle(renderer, (int)(rectangle.x - rectangle.width / 2), (int)(rectangle.y - rectangle.height / 2), (int)rectangle.width, (int)rectangle.height, greenColor);

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
