#include <iostream>
#include <string>
#include "MulticastCopyAnalyzer.h"
#define PORT 9999

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " [ipv4 or ipv6]";
        return 1;
    }
    string address(argv[1]);
    MulticastCopyAnalyzer multicastCopyAnalyzer(address,  PORT);
    try {
        multicastCopyAnalyzer.run();
    } catch (exception& exception) {
        cerr << exception.what() << endl;
        perror("error");
    }
    return 0;
}
