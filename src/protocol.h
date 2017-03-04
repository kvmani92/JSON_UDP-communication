//
//  protocol.h
//  mtproject
//
//  Created by Manikandan on 2/20/17.
//
//

#ifndef protocol_h
#define protocol_h

#include "ofxJSON.h"
#include "ofxNetwork.h"
#include <string>

#endif /* protocol_h */

class Protocol {
public:
    void Start(const char *ipaddr, int port, bool status_flag);
    void Prepare(int P_val, std::string P_name);
    void Send();
    std::string Recv(const int buffer);
    //void Clear();
    void Stop();
    
    
    
private:
    
    
};
