#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include "multimedia.h"


class Group : public std::list <std::shared_ptr<Multimedia> >
{
    std::string name {};

public:
    Group();
    Group(std::string name) {this->name = name;};
    std::string getGroupName() const {return name;}
    void printGroup(std::ostream & s) const {
        for(auto & iter:*this){
            iter -> print(s);
        }
    }

};
#endif // GROUP_H
