/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paul
 *
 * Created on 29 August 2019, 02:55
 */

#include <iostream>
#include <vector>
#include "Point.h"
#include "Node.h"
#include "Frame2D.h"
#include "Element.h"
#include "Matrix.h"
#include "Solver.h"

void print(Point p) {
    std::cout << "x-" << p.getX() << " y-" << p.getY() << " z-" << p.getZ();
}

int main(int argc, char** argv) {

    Node n1 = Node(1, 0, 0, 0);
    n1.generateDofs();
    Node n2 = Node(2, 5, 5, 0);
    n2.generateDofs();

    Node n3 = Node(3, 5, 0, 0);
    n3.generateDofs();

    Frame2D frame1 = Frame2D(n2, n3, 1, Section());
    frame1.setMaterial(Material());

    Frame2D frame2 = Frame2D(n1, n2, 2, Section());
    frame2.setMaterial(Material());

    std::vector<Frame2D> elements = {frame1, frame2};

    Solver s(12);
    s.assemble(elements);

    return 0;
}

