#include <SDL.h>
#include "solid2DRectangle_interface.h"

void drawSolidRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw individual points for each pixel in the rectangle
    for (int row = y; row < y + height; row++)
    {
        for (int col = x; col < x + width; col++)
        {
            SDL_RenderDrawPoint(renderer, col, row);
        }
    }
}

void applyForce(Rectangle* rectangle, float forceX, float forceY, float deltaTime)
{
    // Apply the force to the rectangle using Newton's second law: F = ma
    float accelerationX = forceX / rectangle->mass;
    float accelerationY = forceY / rectangle->mass;

    rectangle->velX += accelerationX * deltaTime;
    rectangle->velY += accelerationY * deltaTime;
}

void resetRectangle(Rectangle* rectangle)
{
    rectangle->x = 400.0f; // Set the x-coordinate to 400.0f
    rectangle->y = 300.0f; // Set the y-coordinate to 300.0f
    rectangle->velX = 0.0f; // Set the velocity along the x-axis to 0.0f
    rectangle->velY = 0.0f; // Set the velocity along the y-axis to 0.0f
}

void checkCollisionWithWindow(Rectangle* rectangle, int windowWidth, int windowHeight)
{
    // Check for collision with the left and right boundaries
    if (rectangle->x - rectangle->width / 2 < 0)
    {
        rectangle->x = rectangle->width / 2;
        rectangle->velX = -rectangle->velX; // Reverse the X-velocity to simulate a bounce.
    }
    else if (rectangle->x + rectangle->width / 2 > windowWidth)
    {
        rectangle->x = windowWidth - rectangle->width / 2;
        rectangle->velX = -rectangle->velX; // Reverse the X-velocity to simulate a bounce.
    }

    // Check for collision with the top and bottom boundaries
    if (rectangle->y - rectangle->height / 2 < 0)
    {
        rectangle->y = rectangle->height / 2;
        rectangle->velY = -rectangle->velY; // Reverse the Y-velocity to simulate a bounce.
    }
    else if (rectangle->y + rectangle->height / 2 > windowHeight)
    {
        rectangle->y = windowHeight - rectangle->height / 2;
        rectangle->velY = -rectangle->velY; // Reverse the Y-velocity to simulate a bounce.
    }
}

void updateRectanglePosition(Rectangle* rectangle, float deltaTime)
{
    rectangle->x += rectangle->velX * deltaTime;
    rectangle->y += rectangle->velY * deltaTime;
}
