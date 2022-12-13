/**
* @brief Assignment 2
* @name Alyssa Kittle
*/
//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;


//Include your .h files
#include "Triangle.h"
#include "Point.h"

//Helper function - feel free to use in your tests
Triangle makeT1() {
    Point p1(0, 0);
    Point p2(6, 0);
    Point p3(3, 5);
    return Triangle(p1, p2, p3);
}

Triangle makeT2() {
    Point p1(0, -1);
    Point p2(6, 5);
    Point p3(-3, 3);
    return Triangle(p1, p2, p3);
}

TEST_CASE( "Triangle/Constructor" ) {
    //Set up a triangle using helper - could just do work here
    Triangle t = makeT1();

    //Check the vertices

    //Vertex A - wordy version
    Point tempA = t.getPoint(0);
    Point tempAGoal(0, 0);
    REQUIRE( tempA.isSameAs(tempAGoal) );

    //Vertex B - check vs anonymous point
    Point tempB = t.getPoint(1);
    REQUIRE( tempB.isSameAs( Point(6, 0) ) );

    //Vertex C - super terse - harder to debug...
    REQUIRE( t.getPoint(2).isSameAs( Point(3, 5) ) );
}

TEST_CASE("setPoint"){
    Triangle t = makeT1();

    Point a(2,2);
    t.setPoint(0, a);
    REQUIRE(t.getPoint(0).isSameAs( a ));

    Point b(5,8);
    t.setPoint(1, b);
    REQUIRE(t.getPoint(1).isSameAs( b ));

    Point c(15,10);
    t.setPoint(2, c);
    REQUIRE(t.getPoint(2).isSameAs( c ));

//    //error checking (purposefully making an error to check if it will show up)
//    Point d(-1,-5);
//    t.setPoint(2, d);
//    REQUIRE(t.getPoint(2).isSameAs( c ));
}

TEST_CASE("getPerimeter"){
    Triangle t = makeT1();
    Triangle tTwo = makeT2();
    CHECK(t.getPerimeter() == Approx(17.662));

    CHECK(tTwo.getPerimeter() == Approx(22.705));

    //checking
    CHECK(t.getPerimeter() != Approx(48));
}

TEST_CASE("getArea"){
    Triangle t = makeT1();
    Triangle tTwo = makeT2();

    CHECK(t.getArea() == Approx(15));

    CHECK(tTwo.getArea() == Approx(21));

    //checking
    CHECK(t.getArea() != Approx(48));
}

TEST_CASE("getAngle"){
    Triangle t = makeT1();

    CHECK(t.getAngle(0) == Approx(59.03624));
    CHECK(t.getAngle(1) == Approx(59.03624));
    CHECK(t.getAngle(2) == Approx(61.92751));
}

TEST_CASE("translate"){
    Triangle t = makeT1();

    double xMove = 3;
    double yMove = -3;

    Point p1(3,-3);
    Point p2(9,-3);
    Point p3(6,2);

    t.translate(xMove, yMove);
    CHECK(t.getPoint(0).isSameAs(p1));
    CHECK(t.getPoint(1).isSameAs(p2));
    CHECK(t.getPoint(2).isSameAs(p3));

//    //error checking (purposefully making an error to check if it will show up)
//    CHECK(t.getPoint(0).isSameAs(p3));
}

TEST_CASE("contains"){
    Triangle t = makeT1();

    Point p1t(3,0);
    Point p2t(0,0);
    Point p3t(3,3);

    //contains a point thats on the perimeter of the triangle
    CHECK(t.contains(p1t) == true);
    //contains a point thats one of the vertexes of the triangle
    CHECK(t.contains(p2t) == true);
    //contains a point thats in the inside of the triangle
    CHECK(t.contains(p3t) == true);
}

TEST_CASE("contains on different triangle"){
    Triangle t2 = makeT2();

    //points that are in the inside of the triangle
    Point p1t2(-2,3);
    Point p2t2(5.9,4.9);
    //contains a point thats one of the vertexes of the triangle
    Point p3t2(0,-1);

    CHECK(t2.contains(p1t2) == true);
    CHECK(t2.contains(p2t2) == true);

    CHECK(t2.contains(p3t2) == true);
}
TEST_CASE("contains"){
    Triangle t = makeT1();
    Triangle t2 = makeT2();

    Point p1t(3,0);
    Point p2t(6,5);

    CHECK(t.contains(p2t) == false);
    CHECK(t2.contains(p1t) == false);
}
