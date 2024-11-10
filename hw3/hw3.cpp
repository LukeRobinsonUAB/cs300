#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
//#include <map>
//#include <unordered_set>
//#include <set>
//#include <stack>
#include <algorithm>
//#include <bitset>
//#include <fstream>

using namespace std;

//g++ hw3.cpp -o hw3 -std=c++23

string commonPermutations(string a, string b) {
    unordered_map<char, int> aFreq;
    unordered_map<char, int> bFreq;
    //here we get the frequencies for each letter in our strings
    for (char c : a)
        aFreq[c]++;
    for (char c : b)
        bFreq[c]++;
    /*
    for (const auto& pair : aFreq)
        std::cout << pair.first << " : " << pair.second << std::endl;
    cout << "- - -" << endl;
    for (const auto& pair : bFreq)
        std::cout << pair.first << " : " << pair.second << std::endl;
    */
    string commPerm = "";
    //loop over smaller map to save time
    if (aFreq.size() < bFreq.size()) {
        for (auto const& [ch, freq] : aFreq)
            commPerm.append(min(freq, bFreq[ch]), ch); //inserts 0 for bFreq[key] if no key exists currently
    }
    else {
        for (auto const& [ch, freq] : bFreq)
            commPerm.append(min(freq, aFreq[ch]), ch); //inserts 0 for aFreq[key] if no key exists currently
    }

    sort(commPerm.begin(), commPerm.end());
    cout << commPerm << endl; //print as per instructions, but also returs, ignore warnings for returning
    return commPerm;
}

//this function doesn't take in the number of relatives 
//as you can get that by vector.size()
//or with arrays sizeof(arr)/sizeof(int)
int vitosFamily(vector<int> street) {
    int minDistanceSum = 0; //init zero
    sort(street.begin(), street.end());
    int optimalStreet = street[street.size()/2];
    for (int i = 0; i < street.size(); i++)
        minDistanceSum += abs(optimalStreet - street[i]);
    cout << minDistanceSum << endl;
    return minDistanceSum;
}


int main () {

    commonPermutations("pretty", "women");
    commonPermutations("walking", "down");
    commonPermutations("abcd", "abc");

    vitosFamily(vector<int>{2, 4, 6});
    vitosFamily(vector<int>{5, 9, 13});


    return 0;
}