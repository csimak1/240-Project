#ifndef _HEAP_h
#define _HEAP_h

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include "BST.h"


using namespace std;
class BST;
class BSTNode;
class HeapNode{
    public:
        HeapNode();
        HeapNode(BSTNode * b);
        HeapNode(BSTNode * b, int v);
        ~HeapNode(){
            ptr = nullptr;
        }
        BSTNode * ptr;
        int num_votes;
        bool operator<=(HeapNode other) {
            return this->num_votes <= other.num_votes;
        }
};

class maxHeap {
    public:
        maxHeap();
        void percolateUp(int index);
        void swapNodes(int n1, int n2);
        HeapNode getMax();
        HeapNode extractMax();
        void Heapify(int i);
        int votesAtIndex(int i);
        void percolateDown(int i);
        void printData();
        void Remove();
        void setPTR(BSTNode * p, int index);
        HeapNode getNode(int i);
        vector<HeapNode> getVotes(){return votes;}
        void Insert(HeapNode node);
        void addVotes(int index, int votes);
        int left(int i){ return 2*i + 1 ;}
        int right(int i){ return 2*i +2;}
        int getVotesSize(){ return votes.size();}
        int cap;
        int size;
        
    private:
        vector<HeapNode> votes;
        
        

  
        
};

#endif