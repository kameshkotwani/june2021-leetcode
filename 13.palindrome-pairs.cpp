class Solution {
public:
     vector<vector<int>> palindromePairs(vector<string>& words) {  
  unordered_map<string, int> dict;  
     set<vector<int>> result;  
    for(int i =0; i< words.size(); i++) {  
     string word = words[i];  
      reverse(word.begin(), word.end());  
      dict[word] = i;  
     }  
     for(int i =0; i< words.size(); i++) {  
    string word = words[i];  

     for(int j = 0; j<=word.size(); j++) {  
        string left = word.substr(0, j);  
         string right = word.substr(j, word.size() - j);  
         // candi | left | right  
         if(isPalindro(left) && dict.find(right) != dict.end() && dict[right] != i) {  
          result.insert({dict[right], i});  
         }  
         // left | right | candi  
          if(isPalindro(right) && dict.find(left) != dict.end() && dict[left] != i) {  
         result.insert({i, dict[left]});  
          }  
        }   
     }  
     std::vector<vector<int>> output(result.begin(), result.end());   
     return output;  
    }  
   bool isPalindro(string& str) {  
     int left = 0, right = str.size() -1;  
    while(left < right) {  
        if(str[left++] != str[right--]) return false;  
     }  
    return true;  
   } 
};
