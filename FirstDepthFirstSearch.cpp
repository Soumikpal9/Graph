/*

        Problem Description

        You are given N towns (1 to N). All towns are connected via unique directed path as mentioned in the input.

        Given 2 towns find whether you can reach the first town from the second without repeating any edge.

        B C : query to find whether B is reachable from C.

        Input contains an integer array A of size N and 2 integers B and C ( 1 <= B, C <= N ).

        There exist a directed edge from A[i] to i+1 for every 1 <= i < N. Also, it's guaranteed that A[i] <= i.

        NOTE: Array A is 0-indexed.



        Problem Constraints

        1 <= n <= 100000



        Input Format

        First argument is vector A

        Second argument is integer B

        Third argument is integer C



        Output Format

        Return 1 if reachable, 0 otherwise.



        Example Input

        Input 1:

        A = [1, 1, 2]
        B = 1
        C = 2
        Input 2:

        A = [1, 1, 2]
        B = 2
        C = 1


        Example Output

        Output 1:

        0
        Output 2:

        1


        Example Explanation

        Explanation 1:

        Tree is 1--> 2--> 3 and hence 1 is not reachable from 2.
        Explanation 2:

        Tree is 1--> 2--> 3 and hence 2 is reachable from 1.


*/

int Solution::solve(vector<int> &A, int B, int C){
    vector<vector<int>> graph(A.size()+1);
    for(int i=0;i<A.size();i++){
        graph[A[i]].push_back(i+1);
    }
    queue<int> q;
    vector<bool> vis(A.size()+1, false);
    q.push(C);
    vis[C]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            int v=graph[x][i];
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
            }
        }
    }
    if(vis[B])  return 1;
    else    return 0;
}