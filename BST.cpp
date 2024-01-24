#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = nullptr;
};

BSTNode::BSTNode(){
    data = User();
    left = nullptr;
    right = nullptr;
    heapIndex = 0;
}
BSTNode::~BSTNode(){
    
    
}

BST::~BST()
{
   Clear(root);
}

void BST::Clear(BSTNode * node1){
    if(node1 != nullptr){
        if(node1 -> left != nullptr){
            Clear(node1 -> left);
        }
        if(node1 -> right != nullptr){
            Clear(node1 -> right);
        }
        delete node1;
    }
}

void BST::Insert(User key)
{
    if (root == nullptr)
    {
        root = new BSTNode(key);
    }
    else
    {
        BSTNode *cur = root;
        while (cur != nullptr)
        {
            if (key < cur->data)
            {
                if (cur->left == nullptr)
                {
                    cur->left = new BSTNode(key);
                    cur = nullptr;
                    
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                    if (cur->right == nullptr)
                    {
                        cur->right = new BSTNode(key);
                        cur = nullptr;
                    }
                    else
                    {
                        cur = cur->right;
                        
                    }
                }
            }
        }
    }

    BSTNode *BST::Search(User key)
    {
        BSTNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->data == key)
            {
                return cur;
            }
            else if (key < cur->data)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        return nullptr;
    }

    void BST::setVotes(User key, int votes)
    {
       BSTNode * found = Search(key);
       if(found){
           found->data.incrementVotes(votes);
       }
       return;
    }
    bool BST::isEmpty()
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    BSTNode *BST::Min(BSTNode * root2)
    {
        BSTNode *curr = root2;

        /* loop down to find the leftmost leaf */
        while (curr && curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }

    BSTNode * BST::Remove(BSTNode * root1, User key, BSTNode * ptr, maxHeap & heap)
    {
    if (root1 == NULL)
        return root1;
 
    if (root1 -> data > key) {
        root1 -> left = Remove(root1 -> left, key, ptr, heap);
        return root1;
    }
    else if (root1 -> data < key) {
        root1 -> right = Remove(root1 -> right, key, ptr, heap);
        return root1;
        
    }
 
    //if only has one child
    if (root1 -> left == NULL) {
        BSTNode * temp = root1 -> right;
        delete root1;
        return temp;
    }
    else if (root1->right == NULL) {
        BSTNode * temp = root1 -> left;
        delete root1;
        return temp;
    }
 
    // if has 2 children
    else {
        BSTNode * succPar = root1;
        BSTNode * succ = root1->right;
        while (succ->left != NULL) {
            succPar = succ;
            succ = succ->left;
        }
        if (succPar != root1){
            succPar->left = succ->right;
        }
        else{
            succPar->right = succ->right;
            User suc_data = succ->data;
            int index = succ->heapIndex;
            root1->setData(suc_data);
            root1->setIndex(index);
            heap.setPTR(ptr, root1->heapIndex);
            delete succ;
            return root1;
        }
       }
       return root1;
    }

void BST::printBST(BSTNode * node) {
    if(node == nullptr) {
        return;
    }

    printBST(node->left);
    cout << node -> data << endl;
    printBST(node -> right);
}
