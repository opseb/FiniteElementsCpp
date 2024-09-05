/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Section.cpp
 * Author: paul
 * 
 * Created on 29 August 2019, 11:24
 */

#include "Section.h"

Section::Section(const std::string &name, double area, double Ixx, double Iyy, double Izz)
: name(name), area(area), Ixx(Ixx), Iyy(Iyy), Izz(Izz) {
}

double Section::getIxx() {
    return Ixx;
}

double Section::getIyy() {
    return Iyy;
}

double Section::getIzz() {
    return Izz;
}

std::string Section::getName() {
    return name;
}

double Section::getArea() {
    return area;
}

void Section::setIxx(double Ixx) {
    this->Ixx = Ixx;
}

void Section::setIyy(double Iyy) {
    this->Iyy = Iyy;
}

void Section::setIzz(double Izz) {
    this->Izz = Izz;
}

void Section::setArea(double area) {
    this->area = area;
}

Section::~Section() {
}

