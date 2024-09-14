#include<bits/stdc++.h>
using namespace std;


void flood(vector<vector<int>>& image, int sr, int sc,int oriColor, int newColor){
        
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        
        if(image[sr][sc] == newColor || image[sr][sc] != oriColor)
            return;
        
        image[sr][sc] = newColor;
        
        // for upper
        flood(image, sr-1, sc, oriColor, newColor);
        
        // for down
        flood(image, sr+1, sc, oriColor, newColor);
        
        // for left
        flood(image, sr, sc-1, oriColor, newColor);
        
        // for right
        flood(image, sr, sc+1, oriColor, newColor);
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
        int oriColor = image[sr][sc];
        
        flood(image, sr,sc,oriColor, newColor);
        
        return image;
        
    }