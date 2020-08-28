#include "graph/NodeGraph.hpp"
#include "graph/Graph.hpp"

#include <iostream>
#include <vector>

using namespace std;


int main(){

    //Lendo parametros iniciais
    int table_N;
    int table_M;
    //int players;

    cin>>table_N>>table_M;//>>players;

    //int table[table_N][table_M];
    //bool visited_positions[table_N][table_M];
    //int players_initial_position[players][players];
    std::vector<int> table;
    

    for(int n=0; n<table_N; n++) {
        for(int m=0; m<table_M; m++) {
            int temp;
            cin>>temp;
            table.push_back(temp);
            //cin>>table[n][m];
            //visited_positions[n][m] = false;
        }
    }
    cout<<endl<<"TABLE VALUES:";
    for(int i=0; i<table.size(); i++) {
        cout<<table[i]<<' ';
    }
    cout<<endl;

    /*
    for(int i=0; i<players; i++) {
        cin>>players_initial_position[i][0];
        cin>>players_initial_position[i][1];
        visited_positions[players_initial_position[i][0]][players_initial_position[i][1]] = true;
    }*/

    //cout<<table_N<<endl;
    //cout<<table_M<<endl;
    //cout<<players<<endl;

    /*--------------------------------------------------------------------------------------------------
     *
    //Process Criando inicial
    NodeGraph node0(0);
    NodeGraph node1(1);

    //SetChildren
    node0.setChildren(&node1);

    //copia
    NodeGraph copia = node0;

    
    //busca copia
    NodeGraph* reference = copia.getChildren()[0];
    
    //get value from children
    cout << "Node value reference: " << reference->getValue()<< endl;
    */

    /*
     Verify type
    #include <typeinfo>
    cout << typeid(variable).name() << endl;
    */

    //-------------------------------------------------------------------------------------------------
    Graph graph(table_N, table_M, table); 
    /* print Grafo
    for(int i=0; i<table_N; i++){
        for(int j=0; j<table_M; j++){
            NodeGraph* reference = graph.getNodeByLinearPosition(i,j);
            cout << "Node[" << i << "]["<<j<<"]: " << reference->getValue()<< endl;
        }
    }
    */
}
