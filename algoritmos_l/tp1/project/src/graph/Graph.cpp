#include "Graph.hpp"

Graph::Graph(int n, int m, int** table):_n(n), _m(m) {

    //Lineariza o tabuleiro em um vetor linear de celulas 
    for(int i=0; i<_n; i++){
        for(int j=0; j<_m; i++){
            int value = table[i][j];
            NodeGraph node(value);
            this->_node_control.push_back(&node);        
        }
    }

    //Realiza a ligacao das arestas / movimentos possiveis no tabuleiro
    for(int i=0; i<_n; i++){
        for(int j=0; j<_m; i++){
            int linear_position = _n*_m + _m;
            NodeGraph* node = this->_node_control[linear_position];
            int node_value = node->getValue();

            //Movimento Horizontal:
            int x_right = j + node_value;
            int x_left = j - node_value;
            if( x_right < _m ) {
                int next_node_position = (i * _m) + x_right; 
                NodeGraph* next_node = this->_node_control[next_node_position];
                node->setChildren(next_node);       
            }
            if( x_left >= 0 ) {
                int next_node_position = (i * _m) + x_left; 
                NodeGraph* next_node = this->_node_control[next_node_position];
                node->setChildren(next_node);       
            }

            //Movimento Vertical:
            int y_up = n + node_value;
            int y_down = n - node_value;
            if( y_up < _n ) {
                int next_node_position = (y_up *_m) + j; 
                NodeGraph* next_node = this->_node_control[next_node_position];
                node->setChildren(next_node);       
            }
            if( y_down >= 0 ) {
                int next_node_position = (y_down *_m) + j; 
                NodeGraph* next_node = this->_node_control[next_node_position];
                node->setChildren(next_node);
            }
        }
    }
}
