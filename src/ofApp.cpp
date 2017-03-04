#include "ofApp.h"



Protocol com;
int Blob_id1 = 1234;
int Blob_id2 = 1222;
int Blob_id3 = 1233;

//--------------------------------------------------------------
void ofApp::setup(){

    //  Usage:
    //  Protocol::Start("127.0.0.1",12345,true); //can also be called without parameters : default values are these.
    //  Protocol::Prepare(Blob_id, "Blob_id"); //called everytime a variable needs to be sent
    //  Protocol::Clear(); //To clear the prepared variables (clears everything thats been prepared until now)
    //  Protocol::Send(); //called after all the variables are prepared to be sent
    //  Protocol::Recv(2000); // set the buffer size : default is 10000
    //  Protocol::Stop(); //stop the connection
using namespace std;

    
    com.Start("127.0.0.1",12345,true);
    
    com.Prepare(Blob_id1, "Blob_id1");
    
    com.Prepare(Blob_id2, "Blob_id2");
    com.Prepare(Blob_id3, "Blob_id3");

    com.Send();
    com.Recv(1000);
    com.Stop();
}

//--------------------------------------------------------------
void ofApp::update(){
    

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

}

