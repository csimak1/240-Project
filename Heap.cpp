#include "Heap.h"

using namespace std;

HeapNode::HeapNode() {
    ptr = nullptr;
    num_votes = 0;
}

HeapNode::HeapNode(BSTNode * b){
    ptr = b;
    num_votes = 0;
}

HeapNode::HeapNode(BSTNode * b, int v){
    ptr = b;
    num_votes = v;
}

maxHeap::maxHeap() {
    cap = 0;
    size = 0;
    
}

void maxHeap::printData(){
    for(int i = 0; i < votes.size(); i++){
        cout << votes[i].ptr->data << " " << votes[i].num_votes << endl;
    }
}

void maxHeap::percolateDown(int nodeIndex){
    int childIndex = (2 * nodeIndex) + 1;
    int value = votes[nodeIndex].num_votes;
    while(childIndex < size){
        int max = value;
        int maxIndex = -1;
        for(int i = 0; i < 2 && (i + childIndex < size) ; i++){
            if(votes[i + childIndex].num_votes > max){
                max = votes[i + childIndex].num_votes;
                maxIndex = i + childIndex;
            }
        }
        if(max == value){
            return;
        }
        else{
            int temp = maxIndex;
            swapNodes(nodeIndex , maxIndex );
            maxIndex = nodeIndex;
            nodeIndex = temp;
            childIndex = (2 * nodeIndex) + 1;
        }
    }


}

void maxHeap::setPTR(BSTNode * p, int index){
    votes[index].ptr = p;
}

void maxHeap::percolateUp(int i){
    if(i > cap){
        return;
    }
    if (i > 0) {
        int parentIndex = (i - 1) / 2;
        if (votes[i].num_votes <= votes[parentIndex].num_votes) {
            return;
        }
        else {
            swapNodes(i, parentIndex);
            percolateUp(parentIndex);
        } 
    }
    return;
}
void maxHeap::Remove(){
    votes.erase(votes.begin());
    size -= 1;

}

void maxHeap::swapNodes(int n1, int n2){
    if(n1 < 0 || n2 < 0){
        return;
    }
    votes[n1].ptr->heapIndex = n2;
    votes[n2].ptr->heapIndex = n1;
    swap(votes[n1], votes[n2]);
}

HeapNode maxHeap::getMax(){
     return votes[0];
}

void maxHeap::Insert(HeapNode node){
    if(votes.empty()){
        node.ptr->heapIndex = 0;
        cap += 1;
    }
    else{
        size += 1;
        node.ptr->heapIndex = size;
        cap += 1;
        
    }
    votes.push_back(node);
    percolateUp(node.ptr->heapIndex);
 }

void maxHeap::addVotes (int index, int vote){
     votes[index].num_votes += vote;
     int parentIndex = (index - 1) / 2;
     percolateUp(index);
 }
int maxHeap::votesAtIndex(int i){
    return votes[i].num_votes;
}
HeapNode maxHeap::getNode(int i){
    return votes[i];
}



HeapNode maxHeap::extractMax(){
    swapNodes(0, size);
    percolateDown(0);
    HeapNode temp(votes[size].ptr, votes[size].num_votes);
    votes.pop_back();
    if(size != 0){
        size -= 1;
    }
    cap -= 1;
    return temp;

 }

// parent index = (i - 1 )/ 2
//left = 2i +1
//right = 2i +2

 
