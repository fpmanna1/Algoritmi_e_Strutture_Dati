#include "BinaryTree.h"
#include <iostream>

using std::cout;
using std::endl;

void BinaryTree::insert(Nodo* nodo) {
    Nodo* parent; //trailing pointer as father of current node;
    Nodo* curr;

    parent = new Nodo;
    curr = root;
    while(curr != nullptr){ //Not NIL
        parent = curr; //keep track of current node

        if(nodo->key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;

        nodo->parent = parent;

        if (parent->key == '\0') //NIL; tree was empty
            root = nodo;
        else if(curr == nullptr){
            /*
            * Aggiorna riferimenti del nodo -parent- solo se arrivati alla fine dell'albero,
            * ovvero quando -curr- punta a nullptr, altrimenti si rischia di aggiornare i riferimenti del
            * nodo a cui -parent- punta senza che ve ne sia bisogno, perdendo i riferimenti.
            * In questo modo viene modificato il riferimento del figlio sinistro o destro --del solo-- nodo padre dell'attuale nodo da inserire.
            */
            if(nodo->key < parent->key)
                parent->left = nodo;
            else
                parent->right = nodo;
        }
    }
    ++nodes;
}

ostream& BinaryTree::print(ostream& out, Nodo* node) const
{
    if(node != nullptr){
        //print(out, node->left);

        out << node->key << " ";

        //print(out, node->right);
    }

    return out;
}

void BinaryTree::print(Nodo* nodo)const{
    if(nodo != nullptr){
        print( nodo->left);

        cout << nodo->key << " ";

        print(nodo->right);
    }
}


