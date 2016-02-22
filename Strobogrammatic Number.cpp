class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char>mp{{'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'}};
        int len=num.length();
        for(int l=0,r=len-1;l<=r;l++,r--){
            if(mp.count(num[l])==0 || mp[num[l]]!=num[r])
                return 0;
        }

        return 1;
    }
};