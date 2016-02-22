class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto word : dictionary){
            int len=word.length();
            string s=word[0]+to_string(len)+word[len-1];
            mp[s].insert(word);
        }
    }

    bool isUnique(string word) {
        int len=word.length();
        string s=word[0]+to_string(len)+word[len-1];
        return mp[s].count(word) == mp[s].size();
    }
private:
    unordered_map<string, unordered_set<string>>mp;
};