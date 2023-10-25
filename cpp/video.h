#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

class Video : public Multimedia
{
    int duration {};

public:
    Video(std::string name, std::string pathname, int dur) : Multimedia(name, pathname) {duration = dur; }

    Video();

    int getDuration() const {return duration; }

    void setDuration(int dur){duration = dur; }

    void print(std::ostream & s) const override { s << "The duration of the video is: " << getDuration(); }

    void play() const override {

        std::string s = "mpv " + getPathName() + " &" ;
        system(s.data());

    };
};

#endif // VIDEO_H
