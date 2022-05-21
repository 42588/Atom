class Solution {
public:
    bool isAnagram(string s, string t) {
      int Current[26]={0};
      for(int i=0;i<s.length;i++){
        Current[s[i]-'a']++;
      }
      for(int i=0;i<t.length;i++){
        Current[t[i]-'a']--;
      }
      for(int i=0;i<26;i++){
        if(Current[i]!=0){
          return false;
        }
      }
      return true;
    }
};
