#ifndef __SOLID_2D_RECTANGLE_INTERFACE_H__
#define __SOLID_2D_RECTANGLE_INTERFACE_H__

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
 * @brief Draw a solid (filled) rectangle on the renderer using the specified color.
 *
 * @param renderer The SDL_Renderer on which to draw the rectangle.
 * @param x The x-coordinate of the top-left corner of the rectangle.
 * @param y The y-coordinate of the top-left corner of the rectangle.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 * @param color The SDL_Color representing the color of the rectangle (RGBA).
 */
void drawSolidRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);

/**
 * @brief Applies a force to a rectangle.
 * @param rectangle Pointer to the Rectangle struct to apply the force to.
 * @param forceX The force along the X-axis.
 * @param forceY The force along the Y-axis.
 * @param deltaTime The time step for the simulation.
 */
void applyForce(Rectangle* rectangle, float forceX, float forceY, float deltaTime);

/**
 * @brief Reset the position and velocity of a rectangle to initial values.
 *
 * This function resets the position (x, y) and velocity (velX, velY) of a given rectangle
 * to their initial values. This is typically used to reset the rectangle's state when a button
 * or event is triggered, for example, to start a new simulation or to reset the object's position.
 *
 * @param rectangle A pointer to the Rectangle structure whose values will be reset.
 */
void resetRectangle(Rectangle* rectangle);

/**
 * @brief Checks for collision between the rectangle and the window boundaries.
 * @param rectangle Pointer to the Rectangle struct.
 * @param windowWidth The width of the window.
 * @param windowHeight The height of the window.
 */
void checkCollisionWithWindow(Rectangle* rectangle, int windowWidth, int windowHeight);

/**
 * @brief Updates the position of a rectangle based on its velocity.
 * @param rectangle Pointer to the Rectangle struct to update its position.
 * @param deltaTime The time step for the simulation.
 */
void updateRectanglePosition(Rectangle* rectangle, float deltaTime);



#endif /**< __SOLID_2D_RECTANGLE_INTERFACE_H__ */