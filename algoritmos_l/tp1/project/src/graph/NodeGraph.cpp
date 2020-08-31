#include "NodeGraph.hpp"

using namespace std;

NodeGraph::NodeGraph(int value, int y, int x):_value(value), _x_position(x), _y_position(y){}

vector<NodeGraph*> NodeGraph::getChildren(){
    return this->_children;
}

int NodeGraph::getValue(){
    return this->_value;
}

int NodeGraph::getNumberOfChildren(){
    return this->_children.size();
}

vector<int> NodeGraph::getPosition(){
    std::vector<int> positions;
    positions.push_back(this->_y_position);
    positions.push_back(this->_x_position);
    return positions;
}

/*-----------------------------------------
bool NodeGraph::hasUser(){
    return this->_has_user;
}*/

bool NodeGraph::isFinalPosition(){
    return _is_final_position;
}

void NodeGraph::setAsFinalPosition(){
    this->_is_final_position = true;
}

void NodeGraph::setChildren(NodeGraph *node){
    this->_children.push_back(node);
}

/*------------------------------------------------------------------
void NodeGraph::setHasUser(){
    this->_has_user = true;
}
*/

