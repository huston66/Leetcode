class Solution {
private:
	vector<string> ret;
public:
	void dfs(string s,unordered_map<char,char>mp,int pos,int tot){
	int len=s.length();
	if(len==tot/2){
	    if(len*2==tot)
	    {
	        for(int i=len-1;i>=0;i--){
	            s+=mp[s[i]];
	        }
	        ret.push_back(s);
	    }
	    else
	    {
	        for(int i=len-1;i>=0;i--){
	            s+=mp[s[i]];
	        }

	        for(int i=0;i<3;i++){
	            string nxt=s;
	            if(i==0){
	                nxt.insert(tot/2,1,'0');
	            }
	            else if(i==1){
	                nxt.insert(tot/2,1,'1');
	            }
	            else
	            {
	                nxt.insert(tot/2,1,'8');
	            }
	            ret.push_back(nxt);
	        }
	    }

	    return;
	}

	for(int i=0;i<5;i++){
	    string nxt=s;
	    if(i==0)
	    {
	        if(pos!=0)
	            dfs(s+"0",mp,pos+1,tot);
	    }
	    else if(i==1)
	        dfs(s+"1",mp,pos+1,tot);
	    else if(i==2)
	        dfs(s+"6",mp,pos+1,tot);
	    else if(i==3)
	        dfs(s+"9",mp,pos+1,tot);
	    else
	        dfs(s+"8",mp,pos+1,tot);
	}
	}

	vector<string> findStrobogrammatic(int n) {
	if(n == 0)
	    return ret;
	if(n==1)
	{
		ret.push_back('0');
		ret.push_back('1');
		ret.push_back('8');
		retun ret;
	}
	unordered_map<char,char>mp{{'0','0'},{'1','1'},{'6','9'},{'9','6'},{'8','8'}};
	string s="";
	int pos=0;
	dfs(s,mp,pos,n);
	return ret;
	}
};