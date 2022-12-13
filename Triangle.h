/**
* @brief Assignment 2
* @name Alyssa Kittle
*/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle {
    private:
       Point vertexA;
       Point vertexB;
       Point vertexC;
    public:
       /**
         * @brief Triangle- Construct triangle using the three Points as the verticies
         * @param p1- a vertex of a triangle
         * @param p2- a vertex of a triangle
         * @param p3- a vertex of a triangle
         */
        Triangle(Point p1,Point p2,Point p3);

        /**
         * @brief getPoint- Takes value expected to be 0, 1, 2 and returns corresponding vertex from triangle.
         * @param number- takes a value to determine which vertex will be returned
         * @return
         */
        Point getPoint(int number);

        /**
         * @brief setPoint- Takes value expected to be 0, 1, 2 and a Point. Stores that point as the indicated vertex.
         * @param number- takes a value and determines which vertex of the triangle will be changed
         * @param p- the new coordinates of the vertex
         */
        void setPoint(int number, Point p);

        /**
         * @brief getPerimeter- Calculate and return value.
         * @return returns the calculated perimeter of the triangle
         */
        double getPerimeter();

        /**
         * @brief getArea- Calculate and return value.
         * @return returns the calculated area of the triangle
         */
        double getArea();

        /**
         * @brief getAngle- Return the measure of the given angle in degrees.
         * @param number- determines what vertex your angle will be calculated from
         * @return the angle of the vertex
         */
        double getAngle(int number);

        /**
         * @brief translate- Translate is the fancy word for “move”. Move the triangle by the given amount in x and y dimensions. Do so by moving all three vertices.
         * @param xShift- shifts a point left or right
         * @param yShift- shifts a point up or down
         */
        void translate(const double& xShift, const double& yShift);

        /**
         * @brief contains- Return true if indicated Point is within the triangle
         * @param p- a point on a graph that may or may not be located in the triangle
         * @return true if the point is in the triangle, if not it will return false
         */
        bool contains(const Point& p);

};

#endif // TRIANGLE_H
