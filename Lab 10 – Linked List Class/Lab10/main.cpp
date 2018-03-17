//
//  main.cpp
//  Lab9
//
//  Created by Computer Science on 2/1/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
  LinkedList list;
  
  list.PrintList();
  
  for(int i=0; i < 10; i++)
  {
    list.InsertAtHead(i);
    list.PrintList();
  }
  
  list.PrintList();
  
  list.freeList();
  
  list.PrintList();
  
  return 0;
}
