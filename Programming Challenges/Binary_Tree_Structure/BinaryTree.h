#ifndef BINARY_TREE_STRUCTURE_BINARYTREE_H
#define BINARY_TREE_STRUCTURE_BINARYTREE_H

#include <iostream>

using std::ostream;

typedef int T;

struct Nodo{
    T key;
    Nodo* left = nullptr;
    Nodo* right = nullptr;
    Nodo* parent = nullptr;

    void setKey(T key){
        this->key = key;
    }
};

class BinaryTree {
    inline friend ostream& operator<<(ostream& out, const BinaryTree& T) { return T.print(out, T.root); }

private:
     Nodo* root;
     int nodes;

    public:
        BinaryTree() : root(new Nodo), nodes(0) {}
        explicit BinaryTree(T key) : root(new Nodo), nodes(1){
            root->setKey(key);
            insert(root);
        }

        void insert(Nodo*);
        ostream& print(ostream& out, Nodo* node) const;

        void print(Nodo* nodo)const;
};

#endif
