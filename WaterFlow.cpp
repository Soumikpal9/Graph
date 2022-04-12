/*

Problem Description

Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.



Problem Constraints
1 <= M, N <= 1000

1 <= A[i][j] <= 109



Input Format
First and only argument is a 2D matrix A.



Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.



Example Input
Input 1:

 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]
Input 2:

 A = [
       [2, 2]
       [2, 2]
     ]


Example Output
Output 1:

 7
Output 2:

 4


Example Explanation
Explanation 1:

 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

Explanation 2:

 Water can flow from all cells.

*/

void dfs(int i, int j, vector<vector<int>> &A, vector<vector<int>> &vis){
    if(i<0 || j<0 || i>=A.size() || j>=A[0].size()){
        return;
    }
    vis[i][j]=1;
    if(i+1<A.size() && A[i][j]<=A[i+1][j] && vis[i+1][j]==0){
        dfs(i+1, j, A, vis);
    }
    if(i-1>=0 && A[i][j]<=A[i-1][j] && vis[i-1][j]==0){
        dfs(i-1, j, A, vis);
    }
    if(j+1<A[0].size() && A[i][j]<=A[i][j+1] && vis[i][j+1]==0){
        dfs(i, j+1, A, vis);
    }
    if(j-1>=0 && A[i][j]<=A[i][j-1] && vis[i][j-1]==0){
        dfs(i, j-1, A, vis);
    }
}

int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> blue(A.size(), vector<int> (A[0].size(), 0));
    vector<vector<int>> red(A.size(), vector<int> (A[0].size(), 0));
    int ans=0;

    //blue side  dfs
    for(int i=0;i<A.size();i++){
        dfs(i, 0, A, blue);
    }
    for(int i=0;i<A[0].size();i++){
        dfs(0, i, A, blue);
    }

    //red side dfs
    for(int i=0;i<A.size();i++){
        dfs(i, A[0].size()-1, A, red);
    }
    for(int i=0;i<A[0].size();i++){
        dfs(A.size()-1, i, A, red);
    }

    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(blue[i][j] && red[i][j]){
                ans++;
            }
        }
    }
    return ans;
}
