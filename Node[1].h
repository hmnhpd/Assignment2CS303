#pragma once
#include <string>
using namespace std;

struct Node{ //node struct from notes in lectures

  string data;
  Node* next;

  Node(const string& data_item, Node* next_ptr = nullptr): 
      data(data_item), next(next_ptr) {};
};