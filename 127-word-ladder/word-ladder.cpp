class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        s.erase(beginWord);

        while(!q.empty()){
            auto temp = q.front();
            string word = temp.first;
            int len = temp.second;

            q.pop();

            if(word == endWord) return len;

            for(int i=0;i<word.length();++i){
                for(int j=0;j<26;++j){
                    string temp = word;
                    temp[i] = 'a'+j;
                    if(s.find(temp)!=s.end()){
                        q.push({temp,len+1});
                        s.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};