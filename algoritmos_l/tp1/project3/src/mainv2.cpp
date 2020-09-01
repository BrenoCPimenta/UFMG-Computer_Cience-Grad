#include "graph/NodeGraph.hpp"
#include "graph/Graph.hpp"
#include "player/Player.hpp"
#include "heap/Heap.hpp"

#include <iostream>
#include <vector>

using namespace std;


int main(){

    //Lendo parametros iniciais
    std::vector<int> values;
    int table_N;
    int table_M;
    int number_of_players;
    std::vector<Player> players;
    std::vector<std::vector<int>> players_position;
    std::vector<char> names({ 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});

    cin>>table_N>>table_M>>number_of_players;
    
    //Le tabuleiro
    for(int n=0; n < table_N; n++) {
        for(int m=0; m<table_M; m++) {
            int temp;
            cin>>temp;
            values.push_back(temp);
        }
    }

    //Le jogadores
    for(int i=0; i < number_of_players; i++) {
        int m_position;
        int n_position;
        cin>>m_position>>n_position;

        //Create Player
        Player player_temp(n_position, m_position); 
        player_temp.setName(names[i]);
        players.push_back(player_temp);

        //Save Position
        players_position.push_back({n_position, m_position});
    }


    Graph graph(table_N, table_M, values); 
    std::vector<Player> winners;
    int smallest_path = 99999;

    cout<<"MAIN before players loop"<<endl; //-----------------------------------
    for(int i=0; i < number_of_players; i++){
        Heap heap(graph, players_position);
        heap.searchBFS(&players[i]);
        if( players[i].hasFinished() && players[i].getNumberOfTurns() < smallest_path ){
            winners.clear();
            winners.push_back(players[i]);
            smallest_path = players[i].getNumberOfTurns();
        }else if( players[i].hasFinished() && players[i].getNumberOfTurns() == smallest_path){
            winners.push_back(players[i]);
        }
    }

    if(winners.empty()){
        cout<<"SEM VENCEDORES";
    }else if((int)winners.size() == 1){
        cout<<winners[0].getName()<<endl;
        cout<<smallest_path<<endl;
    }else{
        cout<<"MULTPLE"<<endl;

        int winner_number = 0;
        for(int i=0; i<smallest_path; i++){
            for(int j=0; j<(int)winners.size(); j++){

            }
        }
        cout<<winners[winner_number].getName()<<endl;
        cout<<smallest_path<<endl;

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


    graph.printPositionsPossibleMoves();
}

