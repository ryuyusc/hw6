#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <ctime>
#include <cstdlib>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        unsigned long long w[5];
        //initializes all values to be 0
        for (int i = 0; i < 5; i++) {
          w[i] = 0;
        }

        int wIndex = 4;
        for (int i = (int)k.length() - 1; i >= 0; i -= 6) {
          //generates substring
          std::string subString("");

          for (int j = 5; j >= 0; j--) {
            if (i - j >= 0) {
              subString.push_back(k[i-j]);
            }
          }

          //calculates the value to go into w
          unsigned long long value = letterDigitToNumber(subString[0]);
          for (size_t a = 1; a < subString.size(); a++) {
            value = value * 36 + letterDigitToNumber(subString[a]);
          }

          w[wIndex] = value;
          wIndex--;
        }

        HASH_INDEX_T ans = 0;

        for (int i = 0; i < 5; i++) {
          ans += rValues[i] * w[i];
        }
        return ans;
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        HASH_INDEX_T ans = 0;
        //deals with uppercase letters
        size_t l = size_t(letter);
        if (l >= size_t('A') && l <= size_t('Z')) {
          ans = l - 65;
        }
        //deals with digits
        else if (l >= size_t('0') && l <= size_t('9')) {
          ans = l - 22;
        }
        //deals with lowercase letters
        else {
          ans = l - 97;
        }
        return ans;
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
