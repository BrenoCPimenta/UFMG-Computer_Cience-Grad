#include "Heap.hpp"
#include <iostream>

using namespace std;


Heap::Heap(Graph graph, std::vector<std::vector<int>> players_position):_graph(graph), _players_position(players_position){}

void Heap::searchBFS(Player *player){
    std::vector<std::vector<int>> visited_position; 

    //Get player graph node
    std::vector<int> initial_position = {player->getPosition()};
    NodeGraph* reference = this->_graph.getNodeByLinearPosition(initial_position[0], initial_position[1]);

    //Create root heap node
    NodeHeap* chain_end = new NodeHeap();
    this->_node_control.push_back(chain_end);//add ao controle de nos para ser deletado no final

    //Create root only child heap node, that points to players position on graph 
    NodeHeap* initial_node = new NodeHeap(chain_end, reference); 

    //Recursive search to find  path
    std::vector<NodeHeap*> result = this->startNextLayer({initial_node}, visited_position);

    if(result[0]->hasPath()){
        player->setFinished();
        //player->setPath(this->getPath(result[0])); 
    }
} 


std::vector<NodeHeap*> Heap::startNextLayer(std::vector<NodeHeap*> last_layer, std::vector<std::vector<int>> visited_positions){

    std::vector<NodeHeap*> next_layer; 

    //Loop pela camada, buscando celula por celula
    for(int i=0; i < last_layer.size(); i++){
        //Busca a posicao das celulas filhas 
        std::vector<std::vector<int>> children_positions = last_layer[i]->getChildrenPosition();    

        //Se tiver celula filha:
        if (!children_positions.empty()){

            //Percorre as celulas filhas
            for(int j=0; j < children_positions.size(); j++){
                bool jump_node = false;

                //Setando em variaveis a posicao do no do momento, para facilitar
                int y = children_positions[j][0];
                int x = children_positions[j][1];

                //Verificando se a celula ja foi visitada
                if(!visited_positions.empty()){
                    for(int k=0; k<visited_positions.size(); k++){
                        if( (y == visited_positions[k][0])
                        && (x == visited_positions[k][1])){
                            jump_node = true;
                            break;
                        }
                    }
                }

                //Verificando se a celula ja possui jogador
                if(!jump_node){
                    for(int k=0; k<this->_players_position.size(); k++){
                        if( (y == visited_positions[k][0])
                        && (x == visited_positions[k][1])){
                            jump_node = true;
                            break;
                        }
                    }
                }

               if(!jump_node){
                    NodeGraph* reference = this->_graph.getNodeByLinearPosition(y,x);
                    //Verificando se a celula é a final
                    if(reference->isFinalPosition()){
                        return {last_layer[i]};
                    }else{
                        //Cria um node no Heap
                        NodeHeap* new_node = new NodeHeap(last_layer[i], reference);
                        //O armazena para ser analisado na proxima camada:
                        next_layer.push_back(new_node);
                        //Armazena na variavel geral para ser deletado no final da execucao:
                        this->_node_control.push_back(new_node);
                        //Marca essa posicao como visitada:
                        visited_positions.push_back({y,x});
                    }//if posicao final
                }//if celula ja visitada
            }//Percorre as celulas filhas
        }//Se possui celulas filhas
    }//Loop da camada atual

    if(next_layer.empty()){
        //Retorna celula afirmando final da execucao sem chegar a ultima posicao
        NodeGraph* reference = this->_graph.getNodeByLinearPosition(0,0);
        NodeHeap* end_node = new NodeHeap(last_layer[0], reference);
        this->_node_control.push_back(end_node);
        end_node->setEmptyPath();
        return {end_node};
    }else{
        //Continua com chamada recursiva a proxima camada
        return this->startNextLayer(next_layer, visited_positions);
    }
}



