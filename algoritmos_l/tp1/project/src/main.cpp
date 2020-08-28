#include "graph/NodeGraph.hpp"
#include "graph/Graph.hpp"

#include <iostream>
#include <vector>

using namespace std;


int main(){

    //Lendo parametros iniciais
    std::vector<int> values;
    std::vector<std::vector<int>> players_position;
    int table_N;
    int table_M;
    int players;

    cin>>table_N>>table_M>>players;
    

    for(int n=0; n<table_N; n++) {
        for(int m=0; m<table_M; m++) {
            int temp;
            cin>>temp;
            values.push_back(temp);
        }
    }

    for(int i=0; i<players; i++) {
        int m_position;
        int n_position;
        cin>>m_position>>n_position;
        players_position.push_back({m_position, n_position});
    }
   /*--------------------------------------------------------------------------------------------------
     *
    //Process Criando inicial
    NodeGraph node0(0);
    NodeGraph node1(1);
    node0.setChildren(&node1);
    NodeGraph copia = node0;
    NodeGraph* reference = copia.getChildren()[0];
    cout << "Node value reference: " << reference->getValue()<< endl;
    */


    Graph graph(table_N, table_M, values); 
    graph.printPositionsPossibleMoves();
}

