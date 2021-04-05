#include "graph/NodeGraph.hpp"
#include "graph/Graph.hpp"
#include "player/Player.hpp"
#include "heap/Heap.hpp"
#include "heap/NodeHeap.hpp"

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
        cin>>n_position>>m_position;

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

    //Realiza uma busca BFS os jogadores
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

    //Verifica os ganhadores
    if(winners.empty()){
        cout<<"SEM VENCEDORES";
    }else if((int)winners.size() == 1){
        cout<<winners[0].getName()<<endl;
        cout<<smallest_path<<endl;
    }else{
        //Desempate por rodada quando ha mais de um jogador com o mesmo numero de 'menor caminho'
        //
        //Alocando todos os jogadores empatados
        std::vector<int> players_with_smallest_values;
        for(int i=0; i < (int)winners.size(); i++)
            players_with_smallest_values.push_back(i);

        //Percorrendo os valores dos turnos, do ultimo ao primeiro 
        for(int turn=0; turn < smallest_path; turn++){
            int turn_smallest_value = 9999;
            int number_players_remaining = (int)players_with_smallest_values.size();
            std::vector<int> temp_winners;           

            //Comparando os valores de cada jogador naquele turno
            for(int j=0; j<number_players_remaining; j++){
                int player_number = players_with_smallest_values[j];
                int turn_value = winners[player_number].getPath()[turn];
                if(turn_value < turn_smallest_value){
                    temp_winners.clear();
                    temp_winners.push_back(player_number);
                }else if(turn_value == turn_smallest_value){
                    temp_winners.push_back(player_number);
                }
            }

            players_with_smallest_values = temp_winners;

            if((int)players_with_smallest_values.size() == 1)
                break;
        }
        
        cout<<winners[players_with_smallest_values[0]].getName()<<endl;
        cout<<smallest_path<<endl;
    }

    //Deletando ponteiros do grafo
    graph.clean();
}

