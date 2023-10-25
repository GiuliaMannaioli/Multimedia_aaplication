#include "management.h"
#include <iostream>

bool Management::ifMultimediaExist(std::string name){
    if (multimedias.count(name)){
        return true;
    }else return false;
};
bool Management::ifGroupExist(std::string name){
    if (groups.count(name)){
        return true;
    }else return false;
};


 std::shared_ptr<Photo> Management::createPhoto(std::string name, std::string pathname, float lat, float lon){
     if (ifMultimediaExist(name)) {
         return NULL;
     }else{
         std::shared_ptr<Photo> p(new Photo(name,pathname,lat,lon));
         multimedias[name]=p;
         return p;
     }
 };

 std::shared_ptr<Video> Management::createVideo(std::string name, std::string pathname, int dur){
     if (ifMultimediaExist(name)) {
         return NULL;
     }else{
         std::shared_ptr<Video> v(new Video(name,pathname,dur));
         multimedias[name]=v;
         return v;
     }
 };
 std::shared_ptr<Film> Management::createFilm(std::string name, std::string pathname, int dur, int * durChap, int numChap){
     if (ifMultimediaExist(name)) {
         return NULL;
     }else{
         std::shared_ptr<Film> f(new Film(name,pathname,dur, durChap, numChap));
         multimedias[name]=f;
         return f;
     }
 };
 std::shared_ptr<Group> Management::createGroup(std::string name){
     if (ifGroupExist(name)) {
         return NULL;
     }else{
         std::shared_ptr<Group> g(new Group(name));
         groups[name]=g;
         return g;
     }

 };

 void Management::getMultimedia(std::string name, std::ostream & s){
     if(ifMultimediaExist(name)){
         multimedias.find(name)->second->print(s);
     }else{
         s<< "The multimedia doesn't exist.";
    }
 };

 void Management::getGroup(std::string name, std::ostream & s){
     if(groups.count(name)){
     groups.find(name)->second->printGroup(s);
     }else{
        s << "The object doesn't exist";
     }
 };

 void Management::playMultimedia(std::string name, std::ostream & s){
     if(ifMultimediaExist(name)){
         multimedias.find(name)->second->play();
     }else{
         s << "The object doesn't exist";
    }
 };
