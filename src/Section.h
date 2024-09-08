/* 
 * File:   Section.h
 * Author: Paul Sebastian Okoth
 *
 * Created on 29 August 2019, 11:24
 */

#ifndef SECTION_H
#define SECTION_H

#include <string>

class Section {
public:
    Section(const std::string &name = "default", double area = 1.0, double Ixx = 1.0, double Iyy = 1.0, double Izz = 1.0);
    double getIxx();
    double getIyy();
    double getIzz();
    std::string getName();

    void setIxx(double Ixx);
    void setIyy(double Iyy);
    void setIzz(double Izz);
    void setArea(double area);

    virtual double getArea();

    virtual ~Section();

protected:
    double Ixx;
    double Iyy;
    double Izz;
    double area;
    std::string name;
};

#endif /* SECTION_H */

