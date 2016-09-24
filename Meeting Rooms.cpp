class Solution {
public:
    bool static cmp(Interval& a,Intervals& b){
        return a.start<b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int len=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<len-1;i++){
            if(intervals[i].end>intervals[i+1].start)
                return 0;
        }

        return 1;
    }
};