#include <iostream>
#include <string>
#include <fstream>
#include "HammingCode.h"
#define FILE_NOT_FOUND 404

using namespace std;

static void fileOpen() {
    string fileName;
    cout << "Enter Filename: " << endl;
    std::cin >> fileName;
    //cout << "Decoding Hamming Codewords line by line now." << endl;
    std::ifstream file;
    file.open(fileName);
    string line;
    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            //now we have the line in the string do something with it now
            //cout << "linetest: " << line << endl;
            HammingCode* hc = new HammingCode(line);
            hc->decode();
            hc->display();
        }
    }
    else {
        cout << "File not found" << endl;
        exit(FILE_NOT_FOUND);
    }

    
}

int main() {

    fileOpen();
    


    return 0;
}
