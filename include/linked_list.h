// Created by Anushka Goswami on 7/26/26

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace goswaa4{

    class Node{
        public:
            int data;
            Node* next;
            Node();
            Node(int x);
    };

    Node* GenLinkedList(int size);
    void BruteForceSort(Node* head);
    Node* SplitLinkedList(Node* head);
    Node* Merge(Node* one, Node* two);
    Node* MergeSort(Node* head);

}

#endif