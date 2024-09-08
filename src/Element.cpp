/* 
 * File:   Element.cpp
 * Author: Paul Sebastian Okoth
 * 
 * Created on 29 August 2019, 10:14
 */

#include "Element.h"

Element::Element(int number) : number(number) {
    
}

std::vector<std::vector<double> > Element::getStiffness() {
    return k;
}


Material Element::getMaterial() {
    return material;
}

std::vector<long int> Element::getDofs() {
    return dofs;
}

void Element::setMaterial(const Material& material) {
    this->material = material;
}

Element::~Element() {
}

