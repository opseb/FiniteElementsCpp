/* 
 * File:   Frame2D.h
 * Author: Paul Sebastian Okoth
 *
 * Created on 29 August 2019, 10:57
 */

#ifndef FRAME2D_H
#define FRAME2D_H

#include <vector>
#include "Node.h"
#include "Element.h"
#include "Section.h"

class Frame2D : public Element {
public:
    Frame2D(const Node &nn, const Node &nf, int number, const Section &section);
    void computeStiffness();

    void generateDofs();
    virtual ~Frame2D();
private:
    Node n1;
    Node n2;
    Section section;

};

#endif /* FRAME2D_H */

