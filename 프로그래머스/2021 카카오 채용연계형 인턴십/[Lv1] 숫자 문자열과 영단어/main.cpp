#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int myFunc(string s){
    vector<int> num;
    int a = 0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num.push_back(s[i]-48);
        }
        
        else{
            switch(s[i]){
                case 'z':
                    num.push_back(0);
                    i += 3;
                    break;
                    
                case 'o':
                    num.push_back(1);
                    i += 2;
                    break;
                    
                case 'e':
                    num.push_back(8);
                    i += 4;
                    break;
                    
                case 'n':
                    num.push_back(9);
                    i += 3;
                    break;
                    
                case 't':
                    switch(s[i+1]){
                        case 'w':
                            num.push_back(2);
                            i += 2;
                            break;
                            
                        case 'h':
                            num.push_back(3);
                            i += 4;
                            break;
                    }
                    break;
                    
                case 'f':
                    switch(s[i+1]){
                        case 'o':
                            num.push_back(4);
                            i += 3;
                            break;
                            
                        case 'i':
                            num.push_back(5);
                            i += 3;
                            break;
                    }
                    break;
                    
                case 's':
                    switch(s[i+1]){
                        case 'i':
                            num.push_back(6);
                            i += 2;
                            break;
                            
                        case 'e':
                            num.push_back(7);
                            i += 4;
                            break;
                    }
                    break;
            }
        }
    }
    
    for(int i=0; i<num.size(); i++){
        cout<<num[i]<<endl;
        a += num[num.size()-1-i]*pow(10,i);
    }
    
    return a;
}

int solution(string s) {
    int answer = 0;
    
    answer = myFunc(s);
    
    return answer;
}
