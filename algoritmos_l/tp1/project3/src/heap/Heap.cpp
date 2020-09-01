#include "Heap.hpp"

using namespace std;


Heap::Heap(Graph graph, std::vector<std::vector<int>> players_position):_graph(graph), _players_position(players_position){
    //Cria noh referencia que tera raiz apontado para ele
    this->_chain_end = new NodeHeap();
    this->_node_control.push_back(_chain_end);//add ao controle de nos para ser deletado no final
}

Heap::~Heap(){
    int addresses = (int)this->_node_control.size() - 1;
    for(int i = addresses; i>=0; i--){
        delete this->_node_control[i];
    }
}

void Heap::searchBFS(Player *player){
    std::vector<std::vector<int>> visited_position; 

    //Get player graph node
    std::vector<int> initial_position = player->getPosition();
    NodeGraph* reference = this->_graph.getNodeByLinearPosition(initial_position[0], initial_position[1]);

    //Noh da raiz da arvore eh criado como posicao do jogador
    //eh passado como noh pai um noh vazio como referencia de ponto final
    NodeHeap* initial_node = new NodeHeap(_chain_end, reference); 
    this->_node_control.push_back(initial_node); //salvando no controle para deletar a posteriori

    //Busca recursiva usando BFS e criando camadas para cada iteracao
    std::vector<NodeHeap*> result = this->startNextLayer({initial_node}, visited_position);

    //Caso esse jogador consiga chegar no final sera salvo o caminho em sua instancia
    if(result[0]->hasPath()){
        player->setFinished();
        player->setPath(this->getPath(result[0])); 
        player->setFinished();
    }
} 


//Contabiliza o caminho do jogador voltando pelos nohs
std::vector<int> Heap::getPath(NodeHeap *last_path_node){
    vector<int> path;
    std::vector<NodeHeap*> control;
    control.push_back(last_path_node);
    for(int i = 0; i<10; i++){
        if(control[i]->isChainEnd()){ 
            break;
        }
        path.push_back(control[i]->getValue());
        control.push_back(control[i]->getFather());
    }
    return path;
}


//Busca BFS recursiva em ArvoreHeap
std::vector<NodeHeap*> Heap::startNextLayer(std::vector<NodeHeap*> last_layer, std::vector<std::vector<int>> visited_positions){

    std::vector<NodeHeap*> next_layer; 

    //Loop pela camada, buscando celula por celula
    for(int i=0; i < (int)last_layer.size(); i++){
        //Busca a posicao das celulas filhas 
        std::vector<std::vector<int>> children_positions = last_layer[i]->getReference()->getChildrenPosition();

        //Se tiver celula filha:
        if (!children_positions.empty()){

            //Loop pelas celulas filhas
            for(int j=0; j < (int)children_positions.size(); j++){
                bool jump_node = false;

                //Setando em variaveis a posicao do noh analisado, para facilitar comparacoes
                int y = children_positions[j][0];
                int x = children_positions[j][1];

                //Verificando se a celula ja foi visitada
                if(!visited_positions.empty()){
                    for(int k=0; k< (int)visited_positions.size(); k++){
                        if( (y == visited_positions[k][0])
                        && (x == visited_positions[k][1])){
                            jump_node = true;
                            break;
                        }
                    }
                }

                //Verificando se algum jogador iniciou nesta celula 
                if(!jump_node){
                    for(int k=0; k< (int)this->_players_position.size(); k++){
                        if( (y == this->_players_position[k][0])
                        && (x == this->_players_position[k][1])){
                            jump_node = true;
                            break;
                        }
                    }
                }

               //Caso a celula não tenha outro jogador ou nao tenha sido visitada ainda
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
        //Caso nao tenha mais camadas
        //Retorna celula afirmando final da execucao sem chegar a ultima posicao
        NodeGraph* reference = this->_graph.getNodeByLinearPosition(0,0);
        NodeHeap* end_node = new NodeHeap(last_layer[0], reference);
        this->_node_control.push_back(end_node);
        end_node->setEmptyPath();
        return {end_node};
    }else{
        //Continua com chamada recursiva para a proxima camada
        return this->startNextLayer(next_layer, visited_positions);
    }
}



