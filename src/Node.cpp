/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: paul
 * 
 * Created on 29 August 2019, 03:07
 */

#include "Node.h"

Node::Node(long int number, double x, double y, double z)
: Point(x, y, z), number(number) {
    generateDofs();
}

Node::Node(long int number, const Point &p) : Point(p), number(number) {
    generateDofs();
}

void Node::generateDofs() {
    this->dofs = {3 * number - 2, 3 * number - 1, 3 * number};
}

long int Node::getNumber() const {
    return number;
}

void Node::setNumber(long int number) {
    this->number = number;
}

void Node::setDofs(std::vector<long int>& dofs) {
    this->dofs = dofs;
}

std::vector<long int> Node::getDofs() const {
    return dofs;
}

Node::~Node() {
}





