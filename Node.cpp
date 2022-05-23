#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(){

}

void Node:: setData(int x)
{
    this->data = x;
}

int Node:: getData()
{
    return this->data;
}

void Node:: setNext(Node* x)
{
    this->next = x;
}

Node* Node:: getNext()
{
    return this->next;
}