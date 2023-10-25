#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "multimedia.h"

#include <string>
#include <memory>
#include <map>

class Management
{
private:
    std::map<std::string, std::shared_ptr<Multimedia>> multimedias;
    std::map<std::string, std::shared_ptr<Group>> groups;

    bool ifMultimediaExist(std::string name);

    bool ifGroupExist(std::string name);

public:
    std::shared_ptr<Photo> createPhoto(std::string name, std::string pathname, float lat, float lon);
    std::shared_ptr<Video> createVideo(std::string name, std::string pathname, int dur);
    std::shared_ptr<Film> createFilm(std::string name, std::string pathname, int dur, int * durChap, int numChap);
    std::shared_ptr<Group> createGroup(std::string name);


    void getMultimedia(std::string name,std::ostream & s);
    void getGroup(std::string name, std::ostream & s);


    void playMultimedia(std::string name,  std::ostream & s);

};


#endif // MANAGEMENT_H
