class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    void Union_Size(int u,int v){
        int up_u=findUpar(u);
        int up_v=findUpar(v);
        if (up_u==up_v){
            return;
        }
        if(size[up_u]>size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        else{
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
    }
};
class Solution {
    int dx[4]= {-1,0,1,0};
    int dy[4]= {0,1,0,-1};
public:
    bool check(vector<vector<int>>& grid,int t){
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<=t){
                    for(int k=0;k<4;k++){
                        int nx=dx[k]+i;
                        int ny=dy[k]+j;
                        if(nx<n and ny<n and nx>=0 and ny>=0 and grid[nx][ny]<=t){
                            ds.Union_Size(nx*n+ny,i*n+j);
                        }
                    }
                }
            }
        }
        if(ds.findUpar((n-1)*n + n-1)==ds.findUpar(0)){
            return 1;
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        // Binary search on time and ds union for all elements to check condition (n^2 log(n^2))
        int n=grid.size();
        int high=n*n;
        int low=grid[n-1][n-1];
        int t=0;
        int ans=0;
        while(low<=high){
            t=(high+low)/2;
            bool flag=check(grid,t);
            if(flag){
                ans=t;
                high=t-1;
            }
            else{
                low=t+1;
            }
        }
        return ans;
    }
};