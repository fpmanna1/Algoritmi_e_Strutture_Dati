#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree tree;
    Nodo* root = new Nodo;

    root->setKey(4);
    tree.insert(root);

    Nodo* temp = new Nodo;
    Nodo* temp2 = new Nodo;
    Nodo* temp3 = new Nodo;
    Nodo* temp4 = new Nodo;

    temp->setKey(2);
    temp2->setKey(4);
    temp3->setKey(6);
    temp4->setKey(7);

    tree.insert(temp);
    tree.insert(temp2);
    tree.insert(temp3);
    tree.insert(temp4);

    tree.print(root);

    return 0;
}
