class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        int siz=intervals.size();
        if(siz==0)
            return 0;
        vector<int>sta(siz,0);
        vector<int>ter(siz,0);

        for(int i=0;i<siz;i++){
            sta[i]=intervals[i].start;
            ter[i]=intervals[i].end;
        }

        sort(sta.begin(),sta.end());
        sort(ter.begin(),ter.end());

        int rooms=0;
        int endItr=0;

        for(int i=0;i<siz;i++){
            if(sta[i]<ter[endItr])
                rooms++;
            else
                endItr++;
        }

        return rooms;
    }
};