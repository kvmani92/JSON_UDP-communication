//
//  protocol.cpp
//  mtproject
//
//  Created by Manikandan on 2/20/17.
//
//
//  Usage:
//  Protocol::Start(127.0.0.1,12345,true); //can also be called without parameters : default values are these.
//  Protocol::Prepare(Blob_id, "Blob_id"); //called everytime a variable needs to be sent
//  Protocol::Clear(); //To clear the prepared variables (clears everything thats been prepared until now)
//  Protocol::Send(); //called after all the variables are prepared to be sent
//  Protocol::Recv(2000); // set the buffer size : default is 10000
//  Protocol::Stop(); //stop the connection





#include "protocol.h"


ofxUDPManager udpConnection = ofxUDPManager::ofxUDPManager();
Json::Value JsonParam;

void Protocol::Start(const char *ipaddr = "127.0.0.1", int port=12345, bool status_flag=true)
{
    
    udpConnection.Create();
    udpConnection.Connect(ipaddr,port);
    udpConnection.Bind(port);
    udpConnection.SetNonBlocking(status_flag);
}

void Protocol::Prepare(int P_val, std::string P_name)
{
    
    //code to prepare parameters to be sent via udp channel
    
    
    JsonParam[P_name] = P_val;
    
}


void Protocol::Send()
{
    //code to send the json string across the network
    //The static Json::array that was created using the prepare fn will now be converted to a const char* and sent across the udp network
    
    Json::StyledWriter styledWriter;

    
    udpConnection.Send(styledWriter.write(JsonParam).c_str(), styledWriter.write(JsonParam).length());
    
    ofLog(OF_LOG_NOTICE, "Message Sent: " + styledWriter.write(JsonParam));
    
    
}

void Protocol::Stop()
{
    // Stop the service
    
    udpConnection.Close();
    ofLog(OF_LOG_NOTICE, "Connection Stopped !");
    
}



//void Protocol::Clear()
//{
//    // Clears the static Json::arraylist
//    
//
//}



std::string Protocol::Recv(const int buffer = 100000)
{
    //Recieve and return the code as a string
    
    std::string message;
    
    Json::Reader reader;
    Json::StyledWriter styledWriter;
    
    Json::Value parsedFromString;
    
    char udpMessage[buffer];
    udpConnection.Receive(udpMessage,buffer);
    
    bool parsingSuccessful = reader.parse(udpMessage, parsedFromString);
    if (parsingSuccessful)
    {
        ofLog(OF_LOG_NOTICE, "Recived Json Msg");
        ofLog(OF_LOG_NOTICE, styledWriter.write(parsedFromString));
        message = styledWriter.write(parsedFromString);
    }
    else
    {
        ofLog(OF_LOG_NOTICE, "Recieve Failed");
        message = "";
    }
    
    return message;
    
}
