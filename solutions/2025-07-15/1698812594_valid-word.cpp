class Solution {
public:
    bool isValid(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        int n=word.length();
        bool hasVowel=false;
      bool hasConsonant=false;
      if(n<3) return false;
       for(char c:word)
       {
        if(!isalnum(c)) return false;
        if(isalpha(c))
        {
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            {
                 hasVowel=true;
            }
            else{
                hasConsonant=true;
            }
        }
       }

       return hasVowel&&hasConsonant;
     
      }
    
};