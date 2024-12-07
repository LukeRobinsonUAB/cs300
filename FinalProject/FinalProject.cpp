#include <iostream>
#include <string>
#include <fstream>
#define FILE_NOT_FOUND 404

using namespace std;

static void fileOpen() {
     string fileName;
    cout << "Enter Filename: " << endl;
    std::cin >> fileName;
    ifstream file(fileName);
    if (!file.is_open()) {
        string line;
        while (file) {
            getline(file, line);
            //now we have the line in the string do something with it now
            cout << "Hamming Codeword: " << line << " ";
        }
    }
    else
        exit(FILE_NOT_FOUND);

    
}

int main() {

    fileOpen();
    


    return 0;
}
