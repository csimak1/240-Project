#ifndef _BST_h
#define _BST_h

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "User.h"
#include "Heap.h"

class maxHeap;
class HeapNode;
using namespace std;

class BSTNode {
    public:
        User data;
        BSTNode * left;
        BSTNode * right;
        int heapIndex;
        BSTNode();
        ~BSTNode();
        void setData(User data_In){
            data = data_In;
        }
        void setIndex(int i){
            heapIndex = i;
        }
        BSTNode(User data1){
            data = data1;
            heapIndex = 0;
            left = nullptr;
            right = nullptr;
        }
};

class BST {
    public:
        BST();
        ~BST();
        void Insert(User key);
        BSTNode * Search(User key);
        BSTNode * Min(BSTNode * root2);
        void Clear(BSTNode * node);
        void setRoot(BSTNode * rootIN){root = rootIN;}
        BSTNode * getRoot(){return root;}
        BSTNode * Remove(BSTNode * root1, User key,  BSTNode * ptr, maxHeap & heap);
        void printBST(BSTNode * n);
        void setVotes(User key, int votes);
        bool isEmpty();
        /*vector<Node> createNodes(int size);*/

    private:
       BSTNode * root;
};


#endif