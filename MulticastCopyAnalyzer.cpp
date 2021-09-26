#include "MulticastCopyAnalyzer.h"

MulticastCopyAnalyzer::IPVersion MulticastCopyAnalyzer::GetIPType(const string &str) {
    char buffer[sizeof(in6_addr)];
    if ((inet_pton(AF_INET, str.data(), buffer) == 1)) {
        return IPV4;
    }
    if ((inet_pton(AF_INET6, str.data(), buffer) == 1)) {
        return IPV6;
    }
    return NOT_IP;
}

size_t MulticastCopyAnalyzer::GenerateUID(const string& str) {
    hash<string> hash;
    return hash(str + to_string(getpid()));
}

int MulticastCopyAnalyzer::GetSocket() {
    int sockfd;
    if (_ipVersion == IPV4) {
        sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    } else {
        sockfd = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
    }
    return sockfd;
}

void MulticastCopyAnalyzer::BindSocket(int socket) {
    if (_ipVersion == IPV4) {
        sockaddr_in ipv4{};
        ipv4.sin_family = AF_INET;
        ipv4.sin_port = htons(_port);
        ipv4.sin_addr.s_addr = htonl(INADDR_ANY);
        //ipv4.sin_addr.s_addr = inet_addr(_addr_str.data());
        //inet_pton(AF_INET, _addr_str.data(), &ipv4.sin_addr);
        if (bind(socket, (sockaddr*)&ipv4, sizeof(sockaddr_in)) == -1){
            throw SocketInitializationException("Error while binding address");
        }
    } else {
        sockaddr_in6 ipv6{};
        ipv6.sin6_family = AF_INET6;
        ipv6.sin6_port = htons(_port);
        ipv6.sin6_addr = in6addr_any;
        if (bind(socket, (sockaddr*)&ipv6, sizeof(sockaddr_in6)) == -1){
            throw SocketInitializationException("Error while binding address");
        }
    }
}

void MulticastCopyAnalyzer::ConnectToMulticast(int socket) {
    if (_ipVersion == IPV4) {
        struct ip_mreq mreq{};
        inet_pton(AF_INET,_addr_str.data(), &(mreq.imr_multiaddr));
        mreq.imr_interface.s_addr = htonl(INADDR_ANY);
        if (setsockopt(socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(struct ip_mreq)) != 0) {
            throw SocketInitializationException("Connection to multicast group failed");
        }
    } else {
        struct ipv6_mreq mreq{};
        mreq.ipv6mr_interface = 0;
        inet_pton(AF_INET6, _addr_str.data(), &mreq.ipv6mr_multiaddr);
        if (setsockopt(socket, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, &mreq, sizeof(struct ipv6_mreq)) != 0) {
            throw SocketInitializationException("Connection to multicast group failed");
        }
    }
}

void MulticastCopyAnalyzer::AddToList(size_t uid, sockaddr addr) {
    for (auto & it : _list) {
        if (it.uid == uid) {
            it.time = time(nullptr);
            return;
        }
    }
    element newElement{};
    newElement.time = time(nullptr);
    newElement.uid = uid;
    newElement.addr = addr;
    _list.push_back(newElement);
    printList();
}

void MulticastCopyAnalyzer::RemoveOld() {
    for (auto it = _list.begin(); it != _list.end(); ++it) {
        clock_t newTime = time(nullptr);
        //cout << it->uid << " " << (newTime - it->time) << endl;
        if ((newTime - it->time) > TIMEOUT) {
            it = _list.erase(it);
            printList();
        }
    }
}

void MulticastCopyAnalyzer::printList() {
    std::system ("clear");
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "My uid: " << _uid << endl;
    _list.sort();
    for (auto it : _list) {
        char buffer[MAX_BUFF_SIZE];
        inet_ntop(it.addr.sa_family, &it.addr, buffer, MAX_BUFF_SIZE);
        cout << buffer << " uid:" << it.uid << endl;
    }
}

MulticastCopyAnalyzer::MulticastCopyAnalyzer(const string& address, int port) {
    _ipVersion = GetIPType(address);
    if (_ipVersion == NOT_IP) {
        throw NotIpException("Argument is not ip address");
    }
    _uid = GenerateUID(address);
    _port = port;
    _addr_str = address;
}

void MulticastCopyAnalyzer::run() {
    int inputSocket = GetSocket();
    if (inputSocket == -1 ) {
        throw SocketInitializationException("Cannot create input socket");
    }
    int outputSocket = GetSocket();
    if (outputSocket == -1) {
        throw SocketInitializationException("Cannot create output socket");
    }
    const int optval = 1;
    if (setsockopt(inputSocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) != 0) {
        throw SocketInitializationException("Error while setsockopt");
    }
    BindSocket(inputSocket);
    ConnectToMulticast(inputSocket);

    sockaddr* mAddr;
    sockaddr* newAddr;
    socklen_t size;
    sockaddr_in ipv4{};
    sockaddr_in6 ipv6{};
    sockaddr_in recvIPv4{};
    sockaddr_in6 recvIPv6{};
    if (_ipVersion == IPV4) {
        ipv4.sin_family = AF_INET;
        ipv4.sin_port = htons(_port);
        //ipv4.sin_addr.s_addr = inet_addr(_addr_str.data());
        inet_pton(AF_INET, _addr_str.data(), &ipv4.sin_addr);
        mAddr = (sockaddr*)&ipv4;
        newAddr = (sockaddr*)&recvIPv4;
        size = sizeof(sockaddr_in);
    } else {
        ipv6.sin6_family = AF_INET6;
        ipv6.sin6_port = htons(_port);
        inet_pton(AF_INET6, _addr_str.data(), &ipv6.sin6_addr);
        mAddr = (sockaddr*)&ipv6;
        newAddr = (sockaddr*)&recvIPv6;
        size = sizeof(sockaddr_in6);
    }

    pollfd fd{};
    fd.fd = inputSocket;
    fd.events = POLLIN;
    time_t lastTime = time(nullptr);
    while (true) {
        time_t newTime = time(nullptr);
        if (newTime - lastTime > RESPITE_TIME) {
            if (sendto(outputSocket, &_uid, sizeof(size_t), 0, mAddr, size) < 0) {
                throw SendRecvException("Failed to send message");
            }
            lastTime = newTime;
        }
        int result = poll(&fd, 1, 500);
        if (result < 0) {
            throw SendRecvException("Poll returned with error");
        }
        if (result != 0) {
            size_t buffer;
            int readBytes;
            if ((readBytes = recvfrom(inputSocket, &buffer, sizeof(size_t), MSG_WAITALL, newAddr, &size)) < 0) {
                throw SendRecvException("Failed to recv message");
            }
            if (readBytes != sizeof(size_t)) {
                continue;
            }
            RemoveOld();
            AddToList(buffer, *newAddr);
        }
    }
}
