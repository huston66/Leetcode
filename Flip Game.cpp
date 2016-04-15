class Solution {
public:
    
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> v;
        int slen=s.length();
        if(slen<=1)
            return v;
        
        for(int i=0;i<slen-1;i++)
        {
            if(s[i]=='+'&&s[i+1]=='+')
            {
                string t=s;
                t[i]='-';
                t[i+1]='-';
                v.push_back(t);
            }
        }
        
        return v;
    }