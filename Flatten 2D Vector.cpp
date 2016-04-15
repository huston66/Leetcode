class Vector2D{
    int row;
    int col;
    vector<vector<int>> data;
public:
    Vector2D(vector<vector<int>>& vec2D){
        data=vec2D;
        row=0;
        col=0;
    }
    
    int next(){
        return data[row][col++];
    }
    
    bool hasNext(){
        while(row<data.size()&&col==data[row].size()){
            row++;
            col=0;
        }
        return row<data.size();
    }
};