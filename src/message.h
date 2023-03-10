
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <memory>


#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
public:
    virtual ~Message() {};
    virtual int toByte(std::shared_ptr<uint8_t> &buffer) = 0;
};

class BinaryMessage: public Message {
public:
    BinaryMessage(std::shared_ptr<uint8_t> msg_, size_t len):
        Message(), msg(nullptr), length(0)  {

        if (msg_ == nullptr) {
            throw std::invalid_argument("Message pointer is null");
        }

        msg = std::make_shared<uint8_t>(len);
        std::memcpy(msg.get(), msg_.get(), len);
    }

    int toByte(std::shared_ptr<uint8_t> &buffer) final {
        buffer = msg;
        return length;
    }
private:
    std::shared_ptr<uint8_t> msg;
    int length;
};

#endif /* MESSAGE_H */
