//
//  Node.h
//  Lab9
//
//  Created by Computer Science on 2/1/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#ifndef __Lab9__Node__
#define __Lab9__Node__

#include <stdio.h>

class Node
{
public:
  Node(int v=0, Node* n=NULL);
  void SetValue(int v);
  void SetNext(Node* n);
  int GetValue() const;
  Node* GetNext() const;
  void PrintNode();
  
private:
  int value;
  Node* nextNode;
};
#endif /* defined(__Lab9__Node__) */
