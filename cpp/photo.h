#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"


class Photo : public Multimedia
{
    float latitude = 0.0;
    float longitude = 0.0;

public:
    Photo(std::string name, std::string pathname, float lat, float lon) : Multimedia(name, pathname) {latitude = lat; longitude = lon;}

    Photo();

    float getLatitude() const {return latitude; }

    float getLongitude() const {return longitude; }

    void setLatitude(float lat) {latitude = lat; }

    void setLongitude(float lon) {longitude = lon; }

    void print(std::ostream & s) const override { s << "Latitude is: " << getLatitude() << "and longitude is: " << getLongitude(); }

    void play() const override {

        std::string s = "imagej " + getPathName() + " &" ;
        system(s.data());

    }


};

#endif // PHOTO_H
