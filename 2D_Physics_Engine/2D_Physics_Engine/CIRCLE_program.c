#include <SDL.h>
#include "CIRCLE_interface.h"

void applyGravity(Circle* circle, float deltaTime)
{
    // Apply gravity (in this case, downward acceleration)
    float gravity = 9.81f; // Adjust the value as needed
    circle->velY += gravity * deltaTime; // Vf = Vi + a * dt
}

void updateCirclePosition(Circle* circle, float deltaTime)
{
    circle->x += circle->velX * deltaTime;
    circle->y += circle->velY * deltaTime;
}

int checkCollision(Circle* c1, Circle* c2)
{
    double dx = c2->x - c1->x;
    double dy = c2->y - c1->y;
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= (c1->radius + c2->radius);
}

void resolveCollision(Circle* c1, Circle* c2)
{
    // Calculate the distance between the centers of the two circles
    double dx = c2->x - c1->x;
    double dy = c2->y - c1->y;
    double distance = sqrt(dx * dx + dy * dy);

    // Calculate the normalized collision normal (direction of collision)
    double nx = dx / distance;
    double ny = dy / distance;

    // Calculate the amount of overlap between the circles
    double overlap = (c1->radius + c2->radius) - distance;

    // Separate the circles by adjusting their positions along the collision normal
    c1->x -= overlap * nx;
    c1->y -= overlap * ny;

    // Calculate the relative velocity of the circles along the collision normal
    double relativeVelocity = c1->velX * nx + c1->velY * ny - c2->velX * nx - c2->velY * ny;

    // Calculate the impulse (change in momentum) for the collision resolution
    double impulse = 2 * relativeVelocity / (c1->mass + c2->mass);

    // Update the velocities of the circles after the collision
    c1->velX -= impulse * c2->mass * nx;
    c1->velY -= impulse * c2->mass * ny;
}

void drawCircle(SDL_Renderer* renderer, int x, int y, int radius)
{
    int centerX = radius;
    int centerY = 0;
    int errorVal = 0;

    while (centerX >= centerY)
    {
        SDL_RenderDrawPoint(renderer, x + centerX, y + centerY);
        SDL_RenderDrawPoint(renderer, x + centerY, y + centerX);
        SDL_RenderDrawPoint(renderer, x - centerY, y + centerX);
        SDL_RenderDrawPoint(renderer, x - centerX, y + centerY);
        SDL_RenderDrawPoint(renderer, x - centerX, y - centerY);
        SDL_RenderDrawPoint(renderer, x - centerY, y - centerX);
        SDL_RenderDrawPoint(renderer, x + centerY, y - centerX);
        SDL_RenderDrawPoint(renderer, x + centerX, y - centerY);

        if (errorVal <= 0)
        {
            centerY += 1;
            errorVal += 2 * centerY + 1;
        }

        if (errorVal > 0)
        {
            centerX -= 1;
            errorVal -= 2 * centerX + 1;
        }
    }
}
