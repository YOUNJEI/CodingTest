#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string itoa(int n) {
    std::stringstream ssInt;
    ssInt << n;
    return ssInt.str();
}

int zip(string s, int zipLen) {
    int i = 0;
    string temp = "";
    while (i < s.length()) {
        int j = i + zipLen;
        int count = 1;
        while (j < s.length()) {
            int k = 0;
            bool flag = true;
            while (k < zipLen) {
                if (s[i + k] != s[j + k]) {
                    flag = false;
                    break;
                }
                k++;
            }
            if (flag) {
                count++;
                j += zipLen;
            }
            else {
                break;
            }
        }
        if (count > 1) {
            temp += itoa(count);
            int k = 0;
            while (k < zipLen && i + k < s.length()) {
                temp += s[i + k];
                k++;
            }
        }
        else {
            int k = 0;
            while (k < zipLen && i + k < s.length()) {
                temp += s[i + k];
                k++;
            }
        }
        i += (count) * zipLen;
    }
    //cout << temp << "\n";
    return temp.length();
}

int solution(string s) {
    int answer = 1000;
    
    for (int i = 1; i <= s.length(); i++) {
        answer = min(answer, zip(s, i));
    }
    return answer;
}
