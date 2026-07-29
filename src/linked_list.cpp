// Created by Anushka Goswami on 7/26/26

#include "linked_list.h"
#include <cstdlib>

namespace goswaa4{

    // I declared a static memory Node Arr since the project did not specify any DMA requirements
    const int MAX_ARR = 100000;
    Node data_arr[MAX_ARR];

    // Node constructors
    Node::Node(){
            data = 0;
            next = nullptr;
        }

    Node::Node(int x){
            data = x;
            next = nullptr;
        }

    // Linked List generator function
    Node* GenLinkedList(int size) {

        Node* head = &data_arr[0];

        for(int i = 0; i < size - 1; i++){
            data_arr[i].data = rand();
            data_arr[i].next = &data_arr[i+1];
        }

        data_arr[size-1].data = rand();
        data_arr[size-1].next = nullptr;
        
        return head;
    }

    // my brute force approach
    void BruteForceSort(Node* head){
        Node* CurrPtr = head;
        Node* IterPtr = CurrPtr->next;

        while(CurrPtr->next != nullptr){
 
            while(IterPtr != nullptr){
                if(IterPtr->data < CurrPtr->data){
                    int temp = IterPtr->data;
                    IterPtr->data = CurrPtr->data;
                    CurrPtr->data = temp;
                }
                IterPtr = IterPtr->next;
            }
            CurrPtr = CurrPtr->next;
            IterPtr = CurrPtr->next;
        }
    }

    // helper function for MergeSort()
    Node* SplitLinkedList(Node* head) {

        Node* FastPtr = head;
        Node* SlowPtr = head;

        while(FastPtr->next != nullptr && FastPtr->next->next != nullptr){
            FastPtr = FastPtr->next->next;
            SlowPtr = SlowPtr->next;
        }

        // cutting the linked list into two distinct linked lists
        Node* temp = SlowPtr->next;
        SlowPtr->next = nullptr;

        return temp;
    }

    // helped function for MergeSort()
    Node* Merge(Node* one, Node* two){
        if(one == nullptr) return two;
        if(two == nullptr) return one;

        if(one->data < two->data){
            one->next = Merge(one->next,two);
            return one;
        }
        else{
            two->next = Merge(two->next,one);
            return two;
        }
    }

    // optimized sort function
    Node* MergeSort(Node* head){

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        Node* front = head;
        Node* half = SplitLinkedList(head);

        front = MergeSort(front);
        half = MergeSort(half);

        return Merge(front, half);
    }
}
