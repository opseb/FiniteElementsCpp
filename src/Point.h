/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: paul
 *
 * Created on 29 August 2019, 02:56
 */

#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0, double y = 0, double z = 0);
    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    
    double distance(const Point &p) const;
    
    virtual ~Point();

private:
    double x;
    double y;
    double z;

};

#endif /* POINT_H */

