/* 
 * File:   Element.h
 * Author: Paul Sebastian Okoth
 *
 * Created on 29 August 2019, 10:14
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "Material.h"

class Element {
public:
    Element(int number);
    //the user will not change any of these values
    std::vector<std::vector<double> > getStiffness();
    std::vector<long int> getDofs();
    Material getMaterial();

    void setMaterial(const Material &material);
    virtual ~Element();
    virtual void computeStiffness() = 0;
private:
    int number;

protected:
    std::vector<long int> dofs;
    std::vector<std::vector<double> > k;
    std::vector<std::vector<double> > T;
    Material material;
};

#endif /* ELEMENT_H */

