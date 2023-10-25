#ifndef FILM_H
#define FILM_H

#include "video.h"


class Film : public Video
{
    int * durChap {}; //se scrivo *durchap accedo al valore se scrivo solo duChamp accedo all address
    int numChap {};

public:
    Film(std::string name, std::string pathname, int dur, int * durChap, int numChap) : Video(name,pathname,dur) {
        //faccio la riservazione della memoria SOLO UNA VOLTA perchè lo chiamo solo una volta il costruttore
        this->numChap = numChap;
        this->durChap = new int [numChap];

        for (  int i = 0; i < numChap; ++i){
            this-> durChap[i] = durChap[i]; //visto ch emetto [i] sto prendendo leemento e non laddress
        }
    }

    Film(const Film& cree) : Video(cree){ //COPY CONSTRUCTOR (chiamato quando lo creo MA sempre a partire da un altro oggetto, non con NEW)
        numChap = cree.numChap;         //crée è l oggetto già creato prima da cui prendo tutto
        durChap = new int [numChap];

        for (   int i = 0; i < numChap; ++i){
            durChap[i] = cree.durChap[i]; //visto ch emetto [i] sto prendendo l elemento e non laddress
        }
    };

    Film& operator=(const Film& cree) {//OP D'AFFECTATION (chiamato quando lo copio, cioè se loggetto esiste già)
        Video::operator=(cree);
        numChap = cree.numChap;

        if(*durChap && *cree.durChap) *durChap = *cree.durChap;
        else {
            delete durChap;

            durChap = new int [numChap];

            for (   int i = 0; i < numChap; ++i){
                durChap[i] = cree.durChap[i]; //visto ch emetto [i] sto prendendo l elemento e non laddress
            }
        }
        return *this;

    };

    Film();


    ~Film(){
        delete[] this->durChap;
    };

    void setDuration(int const *durChap, int numChap){//qui prendo solo laddress

        if(!durChap) return;

        if(this->numChap != numChap){ //se quello vecchio è magglio di quello che passo ora

            delete []this->durChap;

            //faccio la riservazione della memoria
            this->numChap = numChap;
            this->durChap = new int [numChap];
        }

        for (   int i = 0; i < numChap; ++i){
            this-> durChap[i] = durChap[i]; //visto ch emetto [i] sto prendendo leemento e non laddress
        }

    }

    int getNumChap() const {return numChap; }

    const int *getDurChap() const {return durChap; } // mettendo const all'inizio evito che poi dal main mi modifichino le cose
    //infatti se xes scrivessi t = getDurChap() copierei l'adddress e quindi poi potrei modificare i datri che sono la dentro

    void print(std::ostream & s) const override { s << "The duration of the chapter is: " << getDurChap(); }




};

#endif // FILM_H
