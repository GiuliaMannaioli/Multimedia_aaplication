#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>
#include <list>


class Multimedia
{
private:
    std::string name {};
    std::string pathname {};


public:
    Multimedia(std::string name, std::string pathname);

    Multimedia();

    virtual ~Multimedia();

    std::string getName() const;

    std::string getPathName() const;

    void setName(std::string name);

    void setPathName(std::string pathname);

    virtual void print(std::ostream & s) const;

    virtual void play() const = 0;



};



#endif // MULTIMEDIA_H

