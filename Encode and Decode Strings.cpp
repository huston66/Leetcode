class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int siz=strs.size();
        string s="";
        for (int i = 0; i < siz; ++i)
        {
            int len=strs[i].length();
            s+=to_string(len)+"@"+strs[i];
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int head=0;
        int len=s.length();
        vector<string> res;

        while(head<len){
            int pos=s.find_first_of("@",head);
            int nxtsiz=stoi(s.substr(head,pos-head));
            head=pos+1;
            res.push_back(s.substr(head,nxtsiz));
            head+=nxtsiz;
        }

        return ret;
    }
};