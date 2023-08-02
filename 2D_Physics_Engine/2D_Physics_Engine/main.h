#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>


/**
 * @struct Circle
 * @brief Represents a circle with position, velocity, radius, and mass.
 */
typedef struct
{
    float x, y;         /**< The x and y coordinates of the circle's center. */
    float velX, velY;   /**< The velocity components of the circle. */
    float radius;       /**< The radius of the circle. */
    float mass;         /**< The mass of the circle. */
} Circle;

/**
 * @struct Rectangle
 * @brief Represents a rectangle in 2D space with position, velocity, width, height, and mass.
 *
 * This struct is used to represent a rectangle in a 2D physics simulation. It contains information
 * about the rectangle's position, velocity, dimensions (width and height), and mass. The rectangle
 * can be affected by forces and will move and interact with other objects accordingly.
 */
typedef struct
{
    float x;            /**< The x-coordinate of the rectangle's center. */
    float y;            /**< The y-coordinate of the rectangle's center. */
    float velX;         /**< The velocity component along the X-axis. */
    float velY;         /**< The velocity component along the Y-axis. */
    float width;        /**< The width of the rectangle. */
    float height;       /**< The height of the rectangle. */
    float mass;         /**< The mass of the rectangle. */
} Rectangle;

/**
 * @brief Applies gravity to a circle.
 * @param circle Pointer to the Circle struct to apply gravity to.
 * @param deltaTime The time step for the simulation.
 */
void applyGravity(Circle* circle, float deltaTime)
{
    // Apply gravity (in this case, downward acceleration)
    float gravity = 9.81f; // Adjust the value as needed
    circle->velY += gravity * deltaTime; // Vf = Vi + a * dt
}

/**
 * @brief Updates the position of a circle based on its velocity.
 * @param circle Pointer to the Circle struct to update its position.
 * @param deltaTime The time step for the simulation.
 */
void updatePosition(Circle* circle, float deltaTime)
{
    circle->x += circle->velX * deltaTime;
    circle->y += circle->velY * deltaTime;
}

/**
 * @brief Checks for collision between two circles.
 * @param c1 Pointer to the first Circle struct.
 * @param c2 Pointer to the second Circle struct.
 * @return 1 if the circles collide, 0 otherwise.
 */
int checkCollision(Circle* c1, Circle* c2)
{
    float dx = c2->x - c1->x;
    float dy = c2->y - c1->y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance <= (c1->radius + c2->radius);
}

/**
 * @brief Resolves the collision between two circles.
 *
 * When two circles overlap (collide), this function calculates the necessary adjustments to their positions and velocities
 * to separate them and ensure they no longer intersect. It also updates the velocities of the circles after the collision
 * to simulate a realistic reaction to the impact.
 *
 * @param c1 Pointer to the first Circle struct representing one of the colliding circles.
 * @param c2 Pointer to the second Circle struct representing the other colliding circle.
 */
void resolveCollision(Circle* c1, Circle* c2)
{
    // Calculate the distance between the centers of the two circles
    float dx = c2->x - c1->x;
    float dy = c2->y - c1->y;
    float distance = sqrt(dx * dx + dy * dy);

    // Calculate the normalized collision normal (direction of collision)
    float nx = dx / distance;
    float ny = dy / distance;

    // Calculate the amount of overlap between the circles
    float overlap = (c1->radius + c2->radius) - distance;

    // Separate the circles by adjusting their positions along the collision normal
    c1->x -= overlap * nx;
    c1->y -= overlap * ny;

    // Calculate the relative velocity of the circles along the collision normal
    float relativeVelocity = c1->velX * nx + c1->velY * ny - c2->velX * nx - c2->velY * ny;

    // Calculate the impulse (change in momentum) for the collision resolution
    float impulse = 2 * relativeVelocity / (c1->mass + c2->mass);

    // Update the velocities of the circles after the collision
    c1->velX -= impulse * c2->mass * nx;
    c1->velY -= impulse * c2->mass * ny;
}

/**
 * @brief Implementation of Bresenham's Circle Drawing Algorithm.
 * @param renderer SDL_Renderer pointer to draw the circle.
 * @param x The x coordinate of the circle's center.
 * @param y The y coordinate of the circle's center.
 * @param radius The radius of the circle to be drawn.
 */
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

/**
 * @brief Applies a force to a rectangle.
 * @param rectangle Pointer to the Rectangle struct to apply the force to.
 * @param forceX The force along the X-axis.
 * @param forceY The force along the Y-axis.
 * @param deltaTime The time step for the simulation.
 */
void applyForce(Rectangle* rectangle, float forceX, float forceY, float deltaTime)
{
    // Apply the force to the rectangle using Newton's second law: F = ma
    float accelerationX = forceX / rectangle->mass;
    float accelerationY = forceY / rectangle->mass;

    rectangle->velX += accelerationX * deltaTime;
    rectangle->velY += accelerationY * deltaTime;
}

/**
 * @brief Checks for collision between the rectangle and the window boundaries.
 * @param rectangle Pointer to the Rectangle struct.
 * @param windowWidth The width of the window.
 * @param windowHeight The height of the window.
 */
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

/**
 * @brief Updates the position of a rectangle based on its velocity.
 * @param rectangle Pointer to the Rectangle struct to update its position.
 * @param deltaTime The time step for the simulation.
 */
void updatePosition(Rectangle* rectangle, float deltaTime)
{
    rectangle->x += rectangle->velX * deltaTime;
    rectangle->y += rectangle->velY * deltaTime;
}



#endif /**< __MAIN_H__ */
