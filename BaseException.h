#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

#include <iostream>
#include <string>

class BaseException {
protected:
    std::string message;
public:
    explicit BaseException(std::string msg) : message(std::move(msg)) {}
    virtual ~BaseException() {}
    virtual void printMessage() const {
        std::cerr << "Ошибка: " << message << std::endl;
    }
};

#endif