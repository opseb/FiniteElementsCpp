/* 
 * File:   Material.h
 * Author: Paul Sebastian Okoth
 *
 * Created on 29 August 2019, 11:39
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

class Material {
public:
    Material(const std::string &name = "default", double E = 1.0, double v = 1.0);
    
    double getModulus();
    double getPoisson();
    std::string getName();

    void setModulus(double E = 1.0);
    void setPoisson(double v = 1.0);
    void setName(std::string &name);
    
    virtual ~Material();
private:
    std::string name;
    double E;
    double v;
};

#endif /* MATERIAL_H */

