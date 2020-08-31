#ifndef NODEGRAPH_H
#define NODEGRAPH_H

#include <vector>

class NodeGraph {
    protected:
        std::vector <NodeGraph*> _children;
        //bool _has_user = false;
        bool _is_final_position = false;
        int _value;
        int _x_position;
        int _y_position;
        
    public:
        NodeGraph(int, int, int);
        int getNumberOfChildren();
        std::vector<int> getPosition();
        int getValue();
        std::vector<NodeGraph*> getChildren();
        //bool hasUser();
        bool isFinalPosition();
        void setAsFinalPosition();
        void setChildren(NodeGraph*);
        //void setHasUser();
};

#endif
