/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Material.cpp
 * Author: paul
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

