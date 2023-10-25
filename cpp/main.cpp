#define v1
#ifndef v1

#include <iostream>

#include "multimedia.h"
#include "photo.h"
#include "video.h"


using namespace std;


int main(int argc, const char* argv[])
{
    int count = 0;

    Multimedia ** m = new Multimedia *[2];
    m[count++] = new Photo("imm1","pr",2,2) ;
    m[count++] = new Video("video1", "dd", 20);


    for(unsigned int i = 0; i < count; ++i){
        m[i]->print(cout);
    }


    delete []m; //quando chiamo questo delete chiamo il distruttore

}

#endif

//#define v2
#ifndef v2

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "management.h"

const int PORT = 3331;


int main(int argc, char* argv[])
{
    bool correctReq =  false;
    std::stringstream reponseStream{};
    std::stringstream requestStream{};
    std::string type{};
    std::string name{};
    std::string method{};

    Management * mng = new Management();
    mng->createVideo("video1", "desktop/video1", 10);
    mng->createPhoto("photo1","Desktop/photo1", 20.00, 12.00);
    mng->createPhoto("photo2","Desktop/photo2", 2.00, 1.00);

  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client

          requestStream.str(request);
          requestStream >> type;
          requestStream >> method;
          requestStream >> name;

          if(type=="Multimedia"){
            if(method=="get"){
            correctReq = true;
            mng->getMultimedia(name, reponseStream);
            }else if(method=="play"){
            correctReq = true;
            mng->playMultimedia(name,reponseStream);
            }
          }
          if(type=="Group"){
            if(method=="get"){
            correctReq = true;
            mng->getGroup(name, reponseStream);
            }
          }

          if(!correctReq){
          response = "You have mistyped the requested" ;
        }else{
          response=reponseStream.str();
           }


          correctReq=false;
          type="";
          method="";
          name="";
          reponseStream.str("");
          requestStream.str("");

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}

#endif

