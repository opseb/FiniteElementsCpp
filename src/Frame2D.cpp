/* 
 * File:   Frame2D.cpp
 * Author: Paul Sebastian Okoth
 * 
 * Created on 29 August 2019, 10:57
 */

#include "Frame2D.h"
#include "Matrix.h"
#include <iostream>
#include <exception>

Frame2D::Frame2D(const Node &nn, const Node &nf, int number, const Section &section)
: Element(number), n1(nn), n2(nf), section(section) {
    generateDofs();
}

void Frame2D::generateDofs() {
    this->dofs = {n1.getDofs()[0], n1.getDofs()[1], n1.getDofs()[2],
        n2.getDofs()[0], n2.getDofs()[1], n2.getDofs()[2]};
}

void Frame2D::computeStiffness() {
    double E, A, I, L;

    L = n1.distance(n2);
    double lsq = L*L;
    double lcb = L * L*L;

    E = material.getModulus();
    I = section.getIzz();
    A = section.getArea();

    double c = (n2.getX() - n1.getX()) / L;
    double s = (n2.getY() - n1.getY()) / L;

    T = {
        {c, s, 0, 0, 0, 0},
        {-s, c, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, c, s, 0},
        {0, 0, 0, -s, c, 0},
        {0, 0, 0, 0, 0, 1}
    };

    double K11 = E * A / L;
    double K22 = 12 * E * I / lcb;
    double K33 = 4 * E * I / L;
    double K66 = 6 * E * I / lsq;

    k = std::vector<std::vector<double> >{
        {K11, 0.0, 0.0, -K11, 0.0, 0.0},
        {0.0, K22, K66, 0.0, -K22, K66},
        {0.0, K66, K33, 0.0, -K66, K33 / 2},
        {-K11, 0.0, 0.0, K11, 0.0, 0.0},
        {0.0, -K22, -K66, 0.0, K22, -K66},
        {0.0, K66, K33 / 2, 0.0, -K66, K33}
    };

    try {
        
        Matrix mT(T);
        Matrix mk(k);
        mk = mT.transpose().times(mk).times(mT);
        
        k = mk.getData();

    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

Frame2D::~Frame2D() {
}

