#include "multimedia.h"
#include <iostream>


Multimedia::Multimedia( std::string _name, std::string _pathname)
{
    name = _name;
    pathname = _pathname;
}

Multimedia:: ~Multimedia(){}

void Multimedia::setName(std::string n){
    name = n;
}

void Multimedia::setPathName(std::string p){
    pathname = p;

}

std::string Multimedia::getName() const{
    return name;
}

std::string Multimedia::getPathName() const{
    return pathname;
}

void Multimedia::print(std::ostream & s) const {
   s << "the name of the multimedia is: " << getName() << "and the path is: " << getPathName() << std::endl;
}
