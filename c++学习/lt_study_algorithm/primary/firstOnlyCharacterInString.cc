#include <iostream>
#include <string>

class Solution{
  public:
    int firstUniqChar(string s) {
      if (s.size() == 1) return 0;
      int hashmap[256] = {0};
      for (int i = 0; i < s.size(); i++) {
        hashmap[s[i] += 1;
      }  
      for (int i = 0; i < s.size(); i++) {
 	if(hashmap[s[i]] == 1;
	return i;
	}
	return 0;
    }
};
