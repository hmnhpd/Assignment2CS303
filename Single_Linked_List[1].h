#pragma once
#include "Node.h"

template <typename Item_Type>
class Single_Linked_List {
private:
  Node* head;
  Node* tail;
  int numitems;
public:
  void push_front(const Item_Type& item);
  void push_back(const Item_Type& item);
  void pop_back();
  void pop_front();
  Item_Type front();
  Item_Type back();
  void empty();
  void insert(size_t index, const Item_Type& item);
  bool remove(size_t index);
  size_t find(const Item_Type& item);
  void print();
  size_t size();
};
