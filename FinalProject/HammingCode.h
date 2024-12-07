#ifndef _HAMMINGCODE_
#define _HAMMINGCODE_
#include <string>
//#include <Eigen/Dense>

using namespace std;
class HammingCode {
    public:

        HammingCode(const string& encoded);

        void decode();
        
        void encode();


        ~HammingCode();


    private:
        string encoded;
        string decoded;
        //bool multipleErrorsInOneBlock;

};
#endif