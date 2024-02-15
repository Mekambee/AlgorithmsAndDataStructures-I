#include <iostream>
#include "binarytree.h"

int main(){
    RandomBinaryTree<int> myTree;
    myTree.insert(5);
    myTree.insert(2);
    myTree.insert(0);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(4);
    myTree.insert(9);
    myTree.insert(6);
    myTree.insert(1);
    myTree.insert(8);

    std::cout<<"Drzewo binarne, elementy wstawione metodą insert(), wypisane metoda display() : "<<std::endl;
    myTree.display();

    myTree.show_leafs_number();

}