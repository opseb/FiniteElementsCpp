/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Solver.h
 * Author: paul
 *
 * Created on 29 August 2019, 15:43
 */

#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "Frame2D.h"
#include "Matrix.h"

class Solver {
public:

    Solver(long int numDofs) : numDofs(numDofs) {
        initVectors();
    }

    void assemble(std::vector<Frame2D> &elements) {

        try {
            for (Frame2D e : elements) {
                e.generateDofs();
                std::vector<long int> dofs = e.getDofs();
                //make sure stiffnesses are up to date
                e.computeStiffness();
                std::vector<std::vector<double> > k = e.getStiffness();
                for (int r = 0; r < dofs.size(); r++) {
                    for (int c = 0; c < dofs.size(); c++) {
                        K[dofs[r] - 1][dofs[c] - 1] += k[r][c];
                    }

                }
            }

            Matrix m(K);
            m.print();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }



    }

    virtual ~Solver() {

    }
private:


    //Initialise vectors and make all values zero

    void initVectors() {

        K.resize(numDofs);
        F.resize(numDofs);
        U.resize(numDofs);
        for (long int r = 0; r < numDofs; r++) {

            K[r].resize(numDofs);
            F[r].resize(1);
            U[r].resize(1);

            zeroVector(K[r]);
            zeroVector(F[r]);
            zeroVector(U[r]);
        }
    }

    void zeroVector(std::vector<double> &vec) {
        for (int r = 0; r < vec.size(); r++)
            vec[r] = 0.0;
    }
    //Global stiffness matrix 
    std::vector<std::vector<double> > K;

    //Global force vector
    std::vector<std::vector<double> > F;

    //Global displacement vector
    std::vector<std::vector<double> > U;

    //Store the number of degrees of freedom in the Element
    long int numDofs;
};

#endif /* SOLVER_H */

