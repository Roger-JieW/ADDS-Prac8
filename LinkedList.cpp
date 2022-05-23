#include<iostream>
#include<limits>
#include"LinkedList.h"
#include "Node.h"

using namespace std;

    LinkedList::  LinkedList(){
      head = NULL;
  }
    LinkedList:: LinkedList(int inputs[] ,int n){
        head = NULL;
        for (int i = 0; i < n; i++)
        {
            Node * newNode = new Node();
            newNode->setData(inputs[i]);
            newNode->setNext(NULL);  
            Node * newPointer;
            if( head == NULL)
            {
                head = newNode;
            }else{
                newPointer = head;
                while(newPointer->getNext() != NULL){
                    newPointer = newPointer->getNext();
                }
                newPointer->setNext(newNode);
            }
        }
    }
    LinkedList:: ~LinkedList(){
        if(head == NULL)
        {

        }else if (head->getNext() == NULL){
            free(head);
            head = NULL;
        }else{
            Node * last = head;
            while(last != NULL)
            {
                Node* next = last->getNext();
                free(last);
                last = next;
            }
        }
        head = NULL;
    }
    void LinkedList ::addFront(int newItem){
        Node* newNode = new Node();
        newNode->setData(newItem);
        newNode->setNext(head);
        head = newNode;
    }
    void LinkedList :: addEnd(int newItem){
        Node* newNode = new Node();
        newNode->setData(newItem);
        newNode->setNext(NULL);

        if(head == NULL)
        {
            head = newNode;
            return;
        }else{
            Node * last = head;
            while(last->getNext() != NULL)
            {
               last = last->getNext();
            }
            last->setNext(newNode);
        }
    }
    void LinkedList :: addAtPosition(int position, int newItem) {
        Node * prevNode = new Node();
        Node * lastNode = new Node();
        int count = 0;
        lastNode = head;
        while(lastNode != NULL){
            lastNode = lastNode->getNext();
            count++;
        }

        if(position <= 1)
        {
            addFront(newItem);
            
        }     
        else if(position > count){
             addEnd(newItem);
        }else{
            Node* newNode = new Node();
            newNode->setData(newItem);
            prevNode = head;
            for(int i = 0; i<position - 2; i++)
            {
                prevNode = prevNode->getNext();
            }
            newNode->setNext(prevNode->getNext());
            prevNode->setNext(newNode);

        }

    }
    int LinkedList :: search(int item){
        Node* last = head;
        int position = 0;
        bool foundOrNot = false;
        while(last != NULL){
            position++;
            if(last->getData() == item)
            {
                cout<<position<<" ";
                foundOrNot = true;
            }
            last = last->getNext();
        }
        if(foundOrNot == false)
        {
            position = 0;
            cout<<"0 ";
        }
        return position;
    }
    void LinkedList :: deleteFront(){
        if(head == NULL){

        }else{
            Node * shadow = new Node();
            shadow = head;
            head = head->getNext();
            delete shadow;
        }
    } 
    void LinkedList :: deleteEnd(){
        if(head == NULL){

        }else if(head->getNext() == NULL)
        {
            free(head);
            head = NULL;
        }else{
            Node * temp = head;
            while (temp->getNext()->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            Node * last = temp->getNext();
            free(last);
            temp->setNext(NULL);

        }
    }
    void LinkedList :: deletePosition(int position){
        // Node * prevNode = new Node();
        Node * lastNode = new Node();
        int count = 0;
        lastNode = head;
        while(lastNode != NULL){
            lastNode = lastNode->getNext();
            count++;
        }

        if(position < 1 || position > count)
        {
            cout<<"outside range"<<endl;
            
        }  else if (position == 1)
        {
            deleteFront();
        }   
        else if(position == count){
             deleteEnd();
        }else{
            int prevPosition = 0;
            Node * targetItem = head;
            while(targetItem != NULL){
                prevPosition++;
                if(prevPosition == position - 1)
                {
                    break;
                }
                targetItem = targetItem->getNext();
            }
            Node* temp = new Node();
            temp = targetItem->getNext();
            targetItem->setNext(temp->getNext());
            free(temp);


        }
    }
    int LinkedList :: getItem(int position){
        Node * lastNode = new Node();
        int count = 0;
        lastNode = head;
        while(lastNode != NULL){
            lastNode = lastNode->getNext();
            count++;
        }

        if(position < 1 || position > count)
        {
            cout<< numeric_limits < int >::max()<< " " <<endl;
            return numeric_limits < int >::max();
            
        }  else if (position == 1)
        {
            cout<<head->getData()<<" ";
            return head->getData();
        }   
         else{
                int prevPosition = 0;
                Node * targetItem = head;
            while(targetItem != NULL){
                prevPosition++;
                if(prevPosition == position)
                {
                    break;
                }
                targetItem = targetItem->getNext();
            }
            cout<<targetItem->getData()<< " " ;
            return targetItem->getData();
        }
    } 
    void LinkedList ::printItems() {
        Node * last = head;
        while(last != NULL)
        {
            cout<<last->getData()<<" ";
            last = last->getNext();
        }
    }
