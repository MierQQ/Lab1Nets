//
// Created by MEB on 26.09.2021.
//

#ifndef LAB1SETI_MULTICASTCOPYANALYZER_H
#define LAB1SETI_MULTICASTCOPYANALYZER_H

#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <list>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include "MCAException.h"

#define TIMEOUT 5
#define RESPITE_TIME 2
#define MAX_BUFF_SIZE 50

class MulticastCopyAnalyzer {
    enum IPVersion {
        IPV4, IPV6, NOT_IP
    };
    static IPVersion GetIPType(const string& str);
    static size_t GenerateUID(const string& str);
    int GetSocket();
    void BindSocket(int socket);
    void ConnectToMulticast(int socket);
    void AddToList(size_t uid, sockaddr addr);
    void RemoveOld();
    void printList();
    struct element{
        size_t uid;
        time_t time;
        sockaddr addr;
        bool operator==(const struct element& other) const {
            return (uid == other.uid);
        }
        bool operator<(const struct element& other) const {
            return (uid < other.uid);
        }
    };


    list<element> _list;
    IPVersion _ipVersion;
    size_t _uid;
    int _port;
    string _addr_str;
public:
    MulticastCopyAnalyzer(const std::string& address, int port);
    void run();
};


#endif //LAB1SETI_MULTICASTCOPYANALYZER_H
