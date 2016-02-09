class TwoSum {
    unordered_map<int,int> mp;
    public:
    void add(int number) {
        mp[number]++;
    }

    bool find(int value) {
        unordered_map<int,int>::iterator iter;
        for(iter=mp.begin();iter!=mp.end();iter++){
            int a=iter->first;
            int b=value-a;
            if((a==b&&iter->second>1)||(a!=b&&mp.count(b))){
                return 1;
            }
        }

        return 0;
    }
};


    