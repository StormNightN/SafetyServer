//
// Created by stormnight on 7/27/19.
//

#include "Server.h"
#include <Networking.h>


namespace Server
{
    Server::Server()
    {

    }

    Server::~Server()
    {
        Networking::CloseSocket(m_Socket);
    }
}