#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    // Store values in a map
    std::map<char,int> charRepetitions;
    
    for(int i = 0; i < s.size(); i++){ // O(n) 
        charRepetitions[s[i]]++;
    }
    
    // Iterate again to check the first char that charRepetitions[s[i]] == 1
    for(int i = 0; i < s.size(); i++){ // O(n) 
        if(charRepetitions[s[i]] == 1) return i;
    }
    
    return -1;
}