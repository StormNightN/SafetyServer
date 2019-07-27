//
// Created by stormnight on 7/27/19.
//

#ifndef SAFETYSERVER_SERVER_H
#define SAFETYSERVER_SERVER_H


#include <cstdint>

namespace Server {

    class Server {
    private:
        int32_t m_Socket;
    public:
        Server();

        virtual ~Server();
    };

}
#endif //SAFETYSERVER_SERVER_H
