//
// Created by Lysander Mealy on 10/24/21.
//

#ifndef POLARIS_EXCEPTION_H
#define POLARIS_EXCEPTION_H

#include <exception>
#include <string>

class Exception: public std::exception {
public:
    ~Exception() {
        delete _whatToReturn;
    }

    explicit Exception(std::string &message) {
        _message = message;
    }

    std::string getType() {
        return _exceptionType;
    }

    [[nodiscard]] const char *what() noexcept
    {
        std::string message = "Exception: " + _exceptionType + "\nMessage:" + _message;
        _whatToReturn = new const char[message.length()] {};
        memcpy((void *) _whatToReturn, message.c_str(), message.length());
        return _whatToReturn;
    }
private:
    const std::string _exceptionType = "Exception";
    std::string _message;
    const char *_whatToReturn;
};

#endif //POLARIS_EXCEPTION_H
