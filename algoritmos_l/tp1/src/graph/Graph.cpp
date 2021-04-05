#include "Graph.hpp"

using namespace std;

Graph::Graph(int n, int m, std::vector<int> table):_n(n), _m(m) {

    this->_size = _n * _m;

    //Lineariza o tabuleiro em um vetor linear de celulas 
    for(int i=0; i<_n; i++){
        for(int j=0; j<_m; j++){
            int linear_position = (i*_m) + j;
            int value = table[linear_position];
            NodeGraph* node = new NodeGraph(value, i, j);
            this->_node_sequence.push_back(node);        
            if( i==(_n-1) && j==(_m-1)){
                node->setAsFinalPosition();
            }
        }
    }


    //Realiza a ligacao das arestas / movimentos possiveis no tabuleiro
    for(int i=0; i<_n; i++){
        for(int j=0; j<_m; j++){
            int linear_position =  (i*_m) + j;
            NodeGraph* node = this->_node_sequence[linear_position];
            int node_value = node->getValue();

            if(node_value != 0) {
                
                //Movimento Horizontal:
                int x_right = j + node_value;
                int x_left = j - node_value;
                if( x_right < _m ) {
                    int next_node_position = (i * _m) + x_right; 
                    NodeGraph* next_node = this->_node_sequence[next_node_position];
                    node->setChildren(next_node);       
                }
                if( x_left >= 0 ) {
                    int next_node_position = (i * _m) + x_left; 
                    NodeGraph* next_node = this->_node_sequence[next_node_position];
                    node->setChildren(next_node);       
                }

                //Movimento Vertical:
                int y_down = i + node_value;
                int y_up = i - node_value;
                if( y_down < _n ) {
                    int next_node_position = (y_down *_m) + j; 
                    NodeGraph* next_node = this->_node_sequence[next_node_position];
                    node->setChildren(next_node);       
                }
                if( y_up >= 0 ) {
                    int next_node_position = (y_up *_m) + j; 
                    NodeGraph* next_node = this->_node_sequence[next_node_position];
                    node->setChildren(next_node);
                }
            }
        }
    }

}


void Graph::clean(){
    int addresses = (int)_node_sequence.size() - 1;
    for(int i = addresses; i>=0; i--){
        delete _node_sequence[i];
    }
}


NodeGraph* Graph::getNodeByLinearPosition(int y_position, int x_position){
    int position = (y_position * _m) + x_position;
    return this->_node_sequence[position];
}


