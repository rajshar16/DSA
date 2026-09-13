class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi=0;
        int n=img1.size();
        // possible transition rowwise
        for(int r=-(n-1); r<n; r++){
            // possible transition columnwise
            for(int c=-(n-1);c<n;c++){
                int count=0;
                // compare the element in the matrix
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                       // calculate shifted coordinates for img2
                        int shifted_i = i + r;
                        int shifted_j = j + c;
                        
                        // only compare if the shifted coordinates are valid in img2
                        if(shifted_i >= 0 && shifted_i < n && shifted_j >= 0 && shifted_j < n) {
                            if(img1[i][j] == 1 && img2[shifted_i][shifted_j] == 1) {
                        count++;
                        }
                        }
                    }
                }
                maxi=max( count,maxi);
            }
        }
        return maxi;
    }
};