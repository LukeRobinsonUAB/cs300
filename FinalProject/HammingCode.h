#ifndef _HAMMINGCODE_
#define _HAMMINGCODE_
#include <string>
//#include <Eigen/Dense> didn't need it for decoding

using namespace std;
class HammingCode {
    public:

        HammingCode(const string& encoded);

        void decode();
        
        //void encode();

        void display();

        ~HammingCode();

    private:
        string encoded;
        string decoded;

};
#endif