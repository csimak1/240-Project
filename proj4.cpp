#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include "lib.h"

using namespace std;


void printHeap(BSTNode * node, maxHeap heap){
    for(int i = 0; i < heap.size; i++){
        cout << heap.getNode(i).ptr->data.getUserID() << " " << heap.votesAtIndex(i) << endl;
    }
}
int main(int argc, char *argv[])
{
    string flightCost = argv[1];
    User u;
    string line;
    int profit = 0;
    int run = 1;
    BST b;
    int total_votes = 0;
    maxHeap heap;
    while (run)
    {
        cout << "Enter a command: register|vote|scoreboard|profit" << endl;
        while (getline(cin, line))
        {
            if(!line.empty()){
            
            vector<string> inputs;
            istringstream inpt(line);
            string temp;
            while (getline(inpt, temp, ' '))
            {
                inputs.push_back(temp);
            }
            if (inputs[0] == "register")
            {               
                string id;
                for (int i = 1; i < inputs.size(); i++)
                {
                    if (i != inputs.size() - 1)
                    {
                        id += inputs[i] + " ";
                    }
                    else
                    {
                        id += inputs[i];
                    }
                }
                u.setUserID(id);
                if (b.isEmpty())
                {
                    b.Insert(u);
                    BSTNode *current = b.Search(u);
                    HeapNode Hnode(current);
                    heap.Insert(Hnode);
                    // create HeapNode
                    // add heap node to the heap
                }
                else if (b.Search(u))
                {
                    cout << "User " << "\"" << id << "\"" << " already exists" << endl;
                }
                else
                {
                    b.Insert(u);
                    BSTNode *current = b.Search(u);
                    HeapNode Hnode(current);
                    heap.Insert(Hnode);
                    
                }
            }

            else if (inputs[0] == "vote")
            {
                string num_votes = inputs[1];
                string id;
                for (int i = 2; i < inputs.size(); i++)
                {
                    if (i != inputs.size() - 1)
                    {
                        id += inputs[i] + " ";
                    }
                    else
                    {
                        id += inputs[i];
                    }
                }
                u.setUserID(id);
                BSTNode *leaf = b.Search(u);
                if (leaf)
                {
                    // get heap index gets the votes
                    heap.addVotes(leaf->heapIndex, stoi(num_votes) / 2);
                    if(stoi(num_votes) % 2 == 1){
                        profit += (stoi(num_votes) / 2) + 1;
                    }
                    else{
                        profit += stoi(num_votes) / 2;
                    }
                    
                    total_votes += stoi(num_votes)/2;
                    if (total_votes > stoi(flightCost))
                    {
                        while (total_votes >= stoi(flightCost))
                        {
                            if(heap.cap < 1){
                                break;
                            }
                            //total amount of votes among all users, launch MAX user
                            HeapNode h = heap.extractMax();
                            cout << "LAUNCHED" << " " << h.ptr->data.getUserID() << endl;
                            total_votes -= stoi(flightCost);
                            BSTNode * nroot = b.Remove(b.getRoot(),h.ptr->data, h.ptr, heap);
                            b.setRoot(nroot);
                            

                        }
                    }
                }
            else
            {
                cout << "User " << "\"" << id << "\"" << " doesn't exists" << endl;
            }
        }

        else if (inputs[0] == "scoreboard")
        {
             int num_users = stoi(inputs[1]);
             if(num_users > heap.cap){
                 break;
             }
             else{
                vector<HeapNode> nodes;
                if(heap.getVotes().size() == 0){
                    break;
                }
                for(int i = 0; i < num_users; i++){
                    HeapNode extracted = heap.extractMax();
                    cout << extracted.ptr->data << " " << extracted.num_votes << endl;
                    nodes.push_back(extracted);
                }
                for(int j = 0; j < nodes.size(); j++){
                    heap.Insert(nodes[j]);
                }
            } 
        }
        else if (inputs[0] == "profit")
        {
            cout << "$" << profit << endl;
        }
     }
     else{
         exit(0);
     }
    }
    run = 0;
}

return 0;
}
