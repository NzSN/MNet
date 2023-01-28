
#include <string>
#include <memory>
#include "message.h"

#ifndef MACHINE_H
#define MACHINE_H


class Machine {
public:

private:
    void sendMsg(std::shared_ptr<Message> msg);
};


#endif /* MACHINE_H */
