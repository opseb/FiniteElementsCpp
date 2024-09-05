/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.cpp
 * Author: paul
 * 
 * Created on 29 August 2019, 02:56
 */

#include <cmath>
#include "Point.h"

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setZ(double z) {
    this->z = z;
}

double Point::distance(const Point &p) const {
    return std::sqrt(std::pow(x - p.x, 2) + std::pow(y - p.y, 2) + std::pow(z - p.z, 2));
}

Point::~Point() {
}




