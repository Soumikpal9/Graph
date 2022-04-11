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

int find(int x, vector<int> &parent){
    if(parent[x]==x)    return x;
    parent[x]=find(parent[x], parent);
    return parent[x];
}

bool merge(int x, int y, vector<int> &parent){
    int root_x=find(x, parent);
    int root_y=find(y, parent);
    if(root_x!=root_y){
        parent[root_x]=root_y;
        return true;
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int total=0;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> parent(A+1, 0);
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
    for(int i=0;i<B.size();i++){
        edges.push_back(make_pair(B[i][2], make_pair(B[i][0], B[i][1])));
    }
    sort(edges.begin(), edges.end());
    for(auto it:edges){
        int cost=it.first;
        int x=it.second.first;
        int y=it.second.second;
        if(merge(x, y, parent)){
            total+=cost;
        }
    }
    return total;
}
