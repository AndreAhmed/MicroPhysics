#ifndef __CIRCLE_INTERFACE_H__
#define __CIRCLE_INTERFACE_H__

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
 * @brief Applies gravity to a circle.
 * @param circle Pointer to the Circle struct to apply gravity to.
 * @param deltaTime The time step for the simulation.
 */
void applyGravity(Circle* circle, float deltaTime);

/**
 * @brief Updates the position of a circle based on its velocity.
 * @param circle Pointer to the Circle struct to update its position.
 * @param deltaTime The time step for the simulation.
 */
void updateCirclePosition(Circle* circle, float deltaTime);

/**
 * @brief Checks for collision between two circles.
 * @param c1 Pointer to the first Circle struct.
 * @param c2 Pointer to the second Circle struct.
 * @return 1 if the circles collide, 0 otherwise.
 */
int checkCollision(Circle* c1, Circle* c2);

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
void resolveCollision(Circle* c1, Circle* c2);

/**
 * @brief Implementation of Bresenham's Circle Drawing Algorithm.
 * @param renderer SDL_Renderer pointer to draw the circle.
 * @param x The x coordinate of the circle's center.
 * @param y The y coordinate of the circle's center.
 * @param radius The radius of the circle to be drawn.
 */
void drawCircle(SDL_Renderer* renderer, int x, int y, int radius);


#endif /**< __CIRCLE_INTERFACE_H__ */
