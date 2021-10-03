#include <algorithm>
#include <map>


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
            return {};
        vector<bool> reachable(s.size() + 1, false);
        reachable[0] = true;
        vector<vector<int>> ending(s.size() + 1);
        size_t maxlen = maxWordLength(wordDict);
        
        for (int i = 0; i < s.size(); i++){
            if (not reachable[i])
                continue;
            for (int j = 1; j <= min(maxlen, s.size() - i); j++){
                auto it = find(wordDict.begin(), wordDict.end(), s.substr(i, j));
                if (it != wordDict.end()){
                    reachable[i + j] = true;
                    ending[i].push_back(i + j);
                }
            }
        }
        if (!reachable.back())
            return {};
        map<int, vector<string>> sentences;
        for (int i = 0; i < ending.size(); i++){
            if (ending[i].empty())
                continue;
            
            auto it = sentences.find(i);
            if (it == sentences.end()){
                for (int j : ending[i])
                    sentences[i + j].push_back(s.substr(i, j - i));
            } else {
                for (const string& sen : it->second){
                    for (int j : ending[i])
                        sentences[j].push_back(sen + " " + s.substr(i, j - i));
                }
            }
        }
        return sentences[s.size()];
    }
    
    size_t maxWordLength(vector<string>& words){
        auto it = max_element(
            words.begin(), words.end(),
            [](const auto& x, const auto& y){ return x.size() < y.size();}
        );
        return it == words.end() ? 0 : it->size();
    }
};

