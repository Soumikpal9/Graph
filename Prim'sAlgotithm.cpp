/*

Problem Description

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.



Problem Constraints

1 <= A, M <= 6*104

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 103



Input Format

The first argument contains an integer, A, representing the number of islands.

The second argument contains an 2-d integer matrix, B, of size M x 3 where Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].



Output Format

Return an integer representing the minimal cost required.



Example Input

Input 1:

 A = 4
 B = [  [1, 2, 1]
        [2, 3, 4]
        [1, 4, 3]
        [4, 3, 2]
        [1, 3, 10]  ]
Input 2:

 A = 4
 B = [  [1, 2, 1]
        [2, 3, 2]
        [3, 4, 4]
        [1, 4, 3]   ]


Example Output

Output 1:

 6
Output 2:

 6


Example Explanation

Explanation 1:

 We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
Explanation 2:

 We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.

*/

int Solution::solve(int A, vector<vector<int>> &B){
    vector<vector<pair<int, int>>> graph(A+1);
    vector<bool> vis(A+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int total=0;
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
        graph[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
    }
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int cost=pq.top().first;
        int parent=pq.top().second;
        pq.pop();
        if(!vis[parent]){
            total+=cost;
            vis[parent]=true;
        }
        for(auto it:graph[parent]){
            int child=it.first;
            int childCost=it.second;
            if(!vis[child]){
                pq.push(make_pair(childCost, child));
            }
        }
    }
    return total;
}