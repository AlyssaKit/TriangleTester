/**
* @brief Assignment 2
* @name Alyssa Kittle
*/
#include <iostream>
#include <cmath>
using namespace std;

#include "Triangle.h"
#include "Point.h"

const double PI = 3.14159265;

Triangle:: Triangle(Point p1,Point p2,Point p3){
   vertexA = p1;
   vertexB = p2;
   vertexC = p3;
}

Point Triangle:: getPoint(const int number){
   if (number == 0){
       return vertexA;
   } else if(number == 1){
       return vertexB;
   } else{
       return vertexC;
   }
}

void Triangle:: setPoint(const int number, const Point p){
   if(number == 0){
       vertexA = p;
   } else if(number == 1){
       vertexB = p;
   } else{
       vertexC = p;
   }
}

double Triangle:: getPerimeter(){
    return vertexA.distanceTo(vertexB) + vertexA.distanceTo(vertexC) + vertexC.distanceTo(vertexB);
}

double Triangle:: getArea(){
    double semPerim = getPerimeter() / 2;
    double area = sqrt(semPerim * (semPerim - vertexA.distanceTo(vertexB)) * (semPerim - vertexC.distanceTo(vertexB)) * (semPerim - vertexA.distanceTo(vertexC)));
    return area;
}
double Triangle:: getAngle(int number){
    double sideA = vertexC.distanceTo(vertexB);
    double sideB = vertexA.distanceTo(vertexC);
    double sideC = vertexA.distanceTo(vertexB);
    //double x;
    if(number == 0){
        return acos((pow(sideC, 2) + pow(sideB, 2) - pow(sideA, 2)) / (2 * sideB * sideC)) * (180 / PI);
    } else if(number == 1){
        return acos((pow(sideC, 2) + pow(sideA, 2) - pow(sideB, 2)) / (2 * sideA * sideC)) * (180 / PI);
    } else{
        return acos((pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2)) / (2 * sideA * sideB)) * (180 / PI);
    }
}

void Triangle:: translate(const double& xShift, const double& yShift){
    vertexA.translate(xShift, yShift);
    vertexB.translate(xShift, yShift);
    vertexC.translate(xShift, yShift);
}

bool Triangle:: contains(const Point& p){
     Triangle main(vertexA, vertexB, vertexC);
     Triangle t1(vertexA, vertexB, p);
     Triangle t2(vertexA, vertexC, p);
     Triangle t3(vertexB, vertexC, p);
     if(abs((t1.getArea()+ t2.getArea() + t3.getArea()) - main.getArea()) < 0.0000001){
         return true;
     } else{
         return false;
     }
}
