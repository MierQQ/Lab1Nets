//
// Created by MEB on 26.09.2021.
//
#ifndef LAB1SETI_MCAEXCEPTION_H
#define LAB1SETI_MCAEXCEPTION_H

#include <exception>
#include <string>
#include <cerrno>

using namespace std;

class MCAException : public exception {
    const char* _message;
public:
    MCAException() {
        _message = "Something gone wrong";
    }

    explicit MCAException(const char* message) {
        _message = message;
    }

    const char * what() const noexcept override {
        return _message;
    }
};

class NotIpException : public MCAException {
public:
    explicit NotIpException(const char* message) : MCAException(message) {};

};

class SocketInitializationException : public MCAException {
public:
    explicit SocketInitializationException(const char* message) : MCAException(message) {};
};

class SendRecvException : public MCAException {
public:
    explicit SendRecvException(const char* message) : MCAException(message) {};
};

#endif //LAB1SETI_MCAEXCEPTION_H
