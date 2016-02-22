class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
	    map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
	    int count = 0;
	    int lowlen=low.length();
	    int highlen=high.length();

	    for(int i=lowlen;i<=highlen;i++){
	    	string temp(i,'0');
	    	dfs(0,i-1,count,temp,mp,low,high);
	    }

	    return count;
	}

	void dfs(int left,int right,int &count,string str, map<char, char> mp, string low, string high){
		if(left > right){
			if((str.length()==low.length()&&str<low)||(str.length()==high.length()&&str>high)) return;

			count++;
			return;
		}

		for(auto curr : mp){
			char a = mp->first;
			char b = mp->second;

			str[left]=a;
			str[right]=b;
			if(str.size() != 1 && str[0] == '0') continue;
			if(left<right || (left==right && a == b))
				dfs(left+1,right-1,count,str,mp,low,high);
		}
	}
};