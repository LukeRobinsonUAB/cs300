#include <iostream>
//#include <string>
#include "HammingCode.h"

HammingCode::HammingCode(const string& cEncoded) {
    this->encoded = cEncoded;
}

void HammingCode::decode() {
    string encoded = this->encoded;
    //xor outputs 1 if diff bits and 0 if same bit

    int p1 = encoded.at(0) - '0';
    int p2 = encoded.at(1) - '0';
    int x3 = encoded.at(2) - '0';
    int p4 = encoded.at(3) - '0';
    int x2 = encoded.at(4) - '0';
    int x1 = encoded.at(5) - '0';
    int x0 = encoded.at(6) - '0';

    int c1 = p1 ^ x3 ^ x2 ^ x0;
    int c2 = p2 ^ x3 ^ x1 ^ x0;
    int c4 = p4 ^ x2 ^ x1 ^ x0;


    if (c1 && c2 && c4 == 1)
        encoded.at(6) = (encoded.at(6) == '0') ? '1' : '0'; 
    else if (c1 && c2)
        encoded.at(2) = (encoded.at(2) == '0') ? '1' : '0';
    else if (c1 && c4)
        encoded.at(4) = (encoded.at(4) == '0') ? '1' : '0';
    else if (c2 && c4)
        encoded.at(5) = (encoded.at(5) == '0') ? '1' : '0';
    else if (c1)
        encoded.at(0) = (encoded.at(0) == '0') ? '1' : '0';
    else if (c2)
        encoded.at(1) = (encoded.at(1) == '0') ? '1' : '0';
    else if (c4)
        encoded.at(3) = (encoded.at(3) == '0') ? '1' : '0';
    

    this->encoded = encoded; //update any fixes we made to bits to object

    string decoded = "";
    for (int i = 0; i < encoded.length(); i++) {
        if (!((i+1) > 0 && ((i+1) & i) == 0)) // if pos in encoded not pow^2 add char to decoded msg because it's a data bit
            decoded += encoded.at(i);
    }
    this->decoded = decoded;
    return;
}


void HammingCode::display() {
    string test = this->encoded;
    string test2 = this->decoded;
    string test3 = "Encoded: " + test;
    string test4 = "Decoded: " + test2;
    cout << test3 << endl;
    cout << test4 << endl;
    return;
    //this code looks horrible for some reason stdout is not working right on my machine when nicer looking code works on online compiliers?
    //i think because im in a VM in WSL(a VM) my stdout is not working right but like this it prints ok.
}

HammingCode::~HammingCode() {
    //nothing to free with delete
}