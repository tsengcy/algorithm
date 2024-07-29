#ifndef TREE_HPP_
#define TREE_HPP_

#include <iostream>
#include <vector>
#include <memory>



class node;
class tree;

using pwNode = std::weak_ptr<node> ; 
using pNode = std::shared_ptr<node> ;


class node
{
public:
    node(int id, pNode pParent);
protected:
    std::vector<pNode> mvpChild;
    
    pwNode mpParent;

    int mnid;
};

class tree
{
public:
    tree();

    void insert();

protected:
    pNode pNodeRoot;
};


#endif // TREE_H_