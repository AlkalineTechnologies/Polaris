//
// Created by Lysander Mealy on 10/24/21.
//

#ifndef POLARIS_EXCEPTION_H
#define POLARIS_EXCEPTION_H

#include <exception>
#include <string>

class Exception: public std::exception {
public:
    explicit Exception(std::string &message) {
        _message = message;
        _messageToReturn = "Exception: " + _exceptionType + "\nMessage:" + _message;
    }

    std::string getType() {
        return _exceptionType;
    }

    [[nodiscard]] const char * what() const noexcept override
    {
        return _messageToReturn.c_str();
    }
private:
    const std::string _exceptionType = "Exception";
    std::string _message;
    std::string _messageToReturn;
};

#endif //POLARIS_EXCEPTION_H
