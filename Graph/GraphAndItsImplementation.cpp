#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


//This is using adjacency matrix
// class graph{
//     public:

//     vector<vector<int>> adj;

//     void addEdges(int u, int v){
//         for(int i=0; i<u; i++){
//             for(int j=0; j<v; j++){
//                 cin >> adj[i][j];
//             }
//         }
//     }

//     void printEdges(){
//         for(int i=0; i<u; i++){
//             for(int j=0; j<v; j++){
//                 cout << adj[i][j] <<endl;
//             }
//         }
//     }

// };


// Using Adjacency List using unorderedmap
template <typename T>;

class graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdges(T u, T v, bool direction){

        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout << i.first <<"->";
            for(auto j:i.second){
                cout<< j<<", ";
            }
            cout <<endl;
        }
    }

};

int main(){

    graph<int> g;

    int n, m;
    cout<<"Enter no. of nodes:"<<endl;
    cin >> n;

    cout<<"enter no. of edges:"<<endl;
    cin >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >>u >> v;
        g.addEdges(u,v,0);
    }
    

    g.printAdjList();
    return 0;
}