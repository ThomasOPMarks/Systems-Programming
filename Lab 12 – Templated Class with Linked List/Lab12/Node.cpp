//
//  Node.cpp
//  Lab9
//
//  Created by Computer Science on 2/1/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#include "Node.h"
#include <iostream>

Node::Node(int v, Node* n):value(v), nextNode(n){}


void Node::SetValue(int v){value = v;}

 void Node::SetNext(Node* n){nextNode = n;}

int Node::GetValue() const
{
  return value;
}

Node* Node::GetNext() const
{
  return nextNode;
}

void Node::PrintNode()
{
  std::cout <<"("<<value<<")";
}
