//
//  Programmer_Strings.cpp
//
//  A programmer string contains letters that can be rearranged to form the word
//  'programmer' and is a substring of a longer string. Note that the strings 'programmer',
//  'grammproer', and 'prozmerqgram' are all classified as programmer strings by definition.
//  Given a string, determine the number of indices that lie between the rightmost and leftmost
//  programmer strings that it contains.
//
//  Created by Konstantin Kuchenmeister on 10/30/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// find the last index of the leftmost programmer string
int findLeftMost(string s) {

    // whether we found it
    short p = false;
    short r = false;
    short o = false;
    short g = false;
    short a = false;
    short m = false;
    short e = false;

     vector<int> indices;

    for (unsigned i = 0; i < s.length(); i++) {

        if (s[i] == 'p') {
            if (p < 1) {
                indices.push_back(i);
                ++p;
            }
        }

        if (s[i] == 'r') {
            if (r < 3) {
                indices.push_back(i);
                ++r;
            }
        }

        if (s[i] == 'o') {
            if (o < 1) {
                indices.push_back(i);
                ++o;
            }
        }


        if (s[i] == 'g') {
            if (g < 1) {
                indices.push_back(i);
                ++g;
            }
        }

        if (s[i] == 'a') {
            if (a < 1) {
                indices.push_back(i);
                ++a;
            }
        }

        if (s[i] == 'm') {
            if (m < 2) {
                indices.push_back(i);
                ++m;
            }
        }

        if (s[i] == 'e') {
            if (e < 1) {
                indices.push_back(i);
                ++e;
            }
        }
    }

    return *(max_element(indices.begin(), indices.end()));

}



// find the last index of the leftmost programmer string
int findRightMost(string s) {

    // whether we found it
    short p = false;
    short r = false;
    short o = false;
    short g = false;
    short a = false;
    short m = false;
    short e = false;

    vector<int> indices;

    for (unsigned i = s.length() - 1; i > 0; --i) {
        if (s[i] == 'p') {
            if (p < 1) {
                indices.push_back(i);
                ++p;
            }
        }

        if (s[i] == 'r') {
            if (r < 3) {
                indices.push_back(i);
                ++r;
            }
        }

        if (s[i] == 'o') {
            if (o < 1) {
                indices.push_back(i);
                ++o;
            }
        }


        if (s[i] == 'g') {
            if (g < 1) {
                indices.push_back(i);
                ++g;
            }
        }

        if (s[i] == 'a') {
            if (a < 1) {
                indices.push_back(i);
                ++a;
            }
        }

        if (s[i] == 'm') {
            if (m < 2) {
                indices.push_back(i);
                ++m;
            }
        }

        if (s[i] == 'e') {
            if (e < 1) {
                indices.push_back(i);
                ++e;
            }
        }
    }
    return *(min_element(indices.begin(), indices.end()));

}

int solve(string s) {
    return findRightMost(s) - findLeftMost(s)-1;
}

int main()
{
//    cout << solve("xxxprozmerqgram") << endl;
    cout << solve("oooprogrammerxxxxprozmerqgramiii") << endl;
    cout << findRightMost("programmerxxpddddxrozmerqgram") << endl;
    cout << findLeftMost("programmerxxddddxprozmerqgram") << endl;

}
