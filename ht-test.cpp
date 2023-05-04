#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    HashTable<
        std::string, 
        int, 
        DoubleHashProber<std::string, MyStringHash >, 
        std::hash<std::string>, 
        std::equal_to<std::string> > ht(0.3, dh);

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
    // for(size_t i = 0; i < 10; i++){
    //     std::stringstream ss;
    //     ss << "hi" << i;
    //     ht.insert({ss.str(), i});
    //     cout << i << endl;
    // }
    for(int i = 0; i < 5; i++) {
        pair<string, int> newItem(to_string(i), i);
        ht.insert(newItem);
    }
    //add another item should resize
    pair<string,int> newItem(to_string(5),5);
    ht.insert(newItem);
    //check that all the items are still there

    if (ht.find("0") != nullptr) {
      cout << "0" << endl;
    }
    if (ht.find("1") != nullptr) {
      cout << "1" << endl;
    }
    if (ht.find("2") != nullptr) {
      cout << "2" << endl;
    }
    if (ht.find("3") != nullptr) {
      cout << "3" << endl;
    }
    if (ht.find("4") != nullptr) {
      cout << "4" << endl;
    }
    if (ht.find("5") != nullptr) {
      cout << "5" << endl;
    }
    

    // if( ht.find("hi1") != nullptr ){
    //     cout << "Found hi1" << endl;
    //     ht["hi1"] += 1;
    //     cout << "Incremented hi1's value to: " << ht["hi1"] << endl;
    // }
    // if( ht.find("doesnotexist") == nullptr ){
    //     cout << "Did not find: doesnotexist" << endl;
    // }
    // cout << "HT size: " << ht.size() << endl;
    // ht.remove("hi7");
    // ht.remove("hi9");
    // cout << "HT size: " << ht.size() << endl;
    // if( ht.find("hi9") != nullptr ){
    //     cout << "Found hi9" << endl;
    // }
    // else {
    //     cout << "Did not find hi9" << endl;
    // }
    // ht.insert({"hi7",17});
    // cout << "size: " << ht.size() << endl;
    return 0;
}
