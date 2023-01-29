
#include <string>
#include <memory>
#include "message.h"
#include <sys/socket.h>

#ifndef MACHINE_H
#define MACHINE_H


class Machine {
public:
    virtual ~Machine() {}
    virtual bool connect() = 0;

private:
    virtual void sendMsg(std::shared_ptr<Message> msg) = 0;
    std::string ident;
};


class GenericMachine: public Machine {
public:
    GenericMachine(std::string addr, int port) {

    }

    bool connect() final {

    }

private:
    void sendMsg(std::shared_ptr<Message> msg) final {

    }

    int socket;
};

#endif /* MACHINE_H */
