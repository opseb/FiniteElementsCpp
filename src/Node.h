/* 
 * File:   Node.h
 * Author: Paul Sebastian Okoth
 *
 * Created on 29 August 2019, 03:07
 */

#ifndef NODE_H
#define NODE_H

#include "Point.h"
#include <vector>

class Node : public Point {
public:
    Node(long int number, double x = 0.0, double y = 0.0, double z = 0.0);
    Node(long int number, const Point &p);

    void generateDofs();
    long int getNumber() const;
    std::vector<long int> getDofs() const;

    void setNumber(long int number);
    void setDofs(std::vector<long int> &dofs);

    virtual ~Node();

private:
    long int number;
    //nodal degrees of freedom
    std::vector<long int> dofs;
};

#endif /* NODE_H */

