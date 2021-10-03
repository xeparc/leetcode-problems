#include <algorithm>
#include <vector>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> wordbreaks(s.size() + 1, false);
        for (int i = 1; i <= s.size(); i++){
            for (int j = 0; j < i; j++){
                if (j == 0 or wordbreaks[j]){
                    auto it = std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j));
                    if (it != wordDict.end()){
                        wordbreaks[i] = true;
                        break;
                    }
                }
            }
        }
        return wordbreaks.back();
    }
};

