/* 
 * File:   Matrix.h
 * Author: Paul Sebastian Okoth
 *
 * Created on 29 August 2019, 12:45
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <cmath>

class Matrix {
public:

    Matrix(int M, int N) {
        this->M = M;
        this->N = N;
        data.resize(M);
        for (int i = 0; i < M; i++)
            data[i].resize(N);
        

    }

    Matrix(std::vector<std::vector<double> > &data) {
        this->data = data;
        this->M = data.size();
        this->N = data[0].size();
    }
    // create and return the transpose of the invoking matrix

    Matrix transpose() {
        Matrix A = Matrix(N, M);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                A.data[j][i] = this->data[i][j];
        return A;
    }

    // return C = A * B

    Matrix times(Matrix B) {
        Matrix A(*this);
        if (A.N != B.M) throw "Illegal matrix dimensions.";
        Matrix C = Matrix(A.M, B.N);
        for (int i = 0; i < C.M; i++)
            for (int j = 0; j < C.N; j++)
                for (int k = 0; k < A.N; k++)
                    C.data[i][j] += (A.data[i][k] * B.data[k][j]);
        return C;
    }

    //Use default copy constructor
    // return x = A^-1 b, assuming A is square and has full rank

    Matrix solve(Matrix &rhs) {
        if (M != N || rhs.M != N || rhs.N != 1)
            throw "Illegal matrix dimensions.";

        // create copies of the data
        Matrix A(data);
        Matrix b = Matrix(rhs.data);

        // Gaussian elimination with partial pivoting
        for (int i = 0; i < N; i++) {

            // find pivot row and swap
            int max = i;
            for (int j = i + 1; j < N; j++)
                if (std::abs(A.data[j][i]) > std::abs(A.data[max][i]))
                    max = j;
            A.swap(i, max);
            b.swap(i, max);

            // singular
            if (A.data[i][i] == 0.0) {
                std::cout << "The value of A is " << A.data[i][i] << std::endl;
                throw "Matrix is singular.";
            }

            // pivot within b
            for (int j = i + 1; j < N; j++)
                b.data[j][0] -= b.data[i][0] * A.data[j][i] / A.data[i][i];

            // pivot within A
            for (int j = i + 1; j < N; j++) {
                double m = A.data[j][i] / A.data[i][i];
                for (int k = i + 1; k < N; k++) {
                    A.data[j][k] -= A.data[i][k] * m;
                }
                A.data[j][i] = 0.0;
            }
        }

        // back substitution
        Matrix x = Matrix(N, 1);
        for (int j = N - 1; j >= 0; j--) {
            double t = 0.0;
            for (int k = j + 1; k < N; k++)
                t += A.data[j][k] * x.data[k][0];
            x.data[j][0] = (b.data[j][0] - t) / A.data[j][j];
        }
        return x;

    }

    void print() {
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                std::cout << data[r][c] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<double> > getData() {
        return data;
    }

    virtual ~Matrix() {

    }
private:
    //M by N matrix
    int M;
    int N;
    std::vector<std::vector<double> > data; //M by N array


    // swap rows i and j

    void swap(int i, int j) {
        std::vector<double> temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
};

#endif /* MATRIX_H */

