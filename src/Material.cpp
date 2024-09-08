/* 
 * File:   Material.cpp
 * Author: Paul Sebastian Okoth
 * 
 * Created on 29 August 2019, 11:39
 */

#include "Material.h"

Material::Material(const std::string &name, double E, double v) : name(name), E(E), v(v) {

}

double Material::getModulus() {
    return E;
}

double Material::getPoisson() {
    return v;
}

std::string Material::getName() {
    return name;
}

void Material::setModulus(double E) {
    this->E = E;
}

void Material::setPoisson(double v) {
    this->v = v;
}

void Material::setName(std::string &name) {
    this->name = name;
}

Material::~Material() {
}

