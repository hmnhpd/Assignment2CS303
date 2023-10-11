#include <string>
#include <iostream>
#include "Node.h"
#include "Single_Linked_List.h"
#include <stdexcept>
using namespace std;


//PRE: contents to be added to the back of the linked list need to be passed into the function
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item){
  Node *newnode = new Node(item, NULL); //making a new node with contents passed into function, node points to null since it will be at the end of the list
  if (head == NULL){ //if the list is empty, call push_front()
    push_front(item);
  }else{ //list not empty
    tail->next = newnode; //the current tail will point to the newnode
    tail = newnode; //the new node will become the tail
    
  }
  numitems++;
}
//POST: contents passed into function are now at the end of the linked list

//PRE: nothing passed into function to be deleted 
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back(){
  if (head == NULL){ //if the list is empty
    throw runtime_error("List is empty.");
  }
  while(head->next != NULL){ //iterating until the second to last node
    head = head->next; //head is now the next node
    numitems--; //decrease numitems
    delete head->next; //delete the last node
    head->next = NULL; //reassign next to NULL
    tail = head; //the tail is now the current node, head
  }
}
//POST: function deleted the tail item and updated which node is the tail

//PRE: nothing passed into function, but the list cannot be empty
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front(){
  if (head == NULL){ //the list is empty
    throw runtime_error("List is empty.");
  }
  Node *temp = head; //setting space to put the current head
  head = head->next; //setting head to be the following node
  delete temp; //deleting the contents of temp
  numitems--;
}
//POST: the list is shorter and the first node has been deleted

//PRE: nothing passed into function, function is used to get contents at front of list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front(){
  if (head == NULL){ //checking if list is empty
    throw runtime_error("List is empty.");
  }else{
    return head->data; //returning the contents of the head node
  }
}
//POST: the contents of the head node are returned

//PRE: nothing oassed into function, function is used to get contents of the back of the list
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back(){
  if (head == NULL){
    throw runtime_error("List is empty.");
  }else{
    return tail->data; //returns contents of tail node
  }
}
//POST: the last node of the list is returned

//PRE: nothing passed into function, function is used to completely empty the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::empty(){
  if (head == NULL){ //the list is empty
    throw runtime_error("List is already empty.");
  }else{
    while (head != NULL){ //going until the end of the list is reached
      Node *temp = head; //node to store data to be deleted
      head = head->next; //pointing to the next node, similar to pop front
      delete temp; //deleting the data in the temp node
    }
  }
  head = NULL;
  tail = NULL;
  numitems = 0;
}
//POST: the list after calling this function should have no contents

//PRE:index and the items to be inserted are passed into the function
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item){
  if (index >= numitems){ //if index is outside of range, push to back of list
    push_back(item);
  }else {
    if (index == 0){ //if index is the beginning of the list
      push_front(item);
    }else{ //inserting anywhere else in the list
      Node *newnode = new Node(item, NULL); //creating the new node
      int counter = 0;
      while(counter <= index - 1){
        head = head->next; //iterate until reaching the node before the index
        counter++; //increment counter since position in list has gone up
        if (counter == index - 1){
          newnode->next = head->next;
          head->next = newnode;
          numitems++;
        }
      }
    }
  }
}
//POST: the item passed into the function is now inserted at the user given index

//PRE: an index is passed in, this node will be removed from the linked list
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index){
  if (index >= numitems){ //index is out of range
    return false;
  }else{
    if (index == 0){ //if the index is the beginning of the list
      pop_front();
    }else{
      int counter = 0;
      Node *temp = head; //setting a node to store data of currrent node
      Node *prev = NULL; //node to store data of previous node
      while(counter <= index - 1){ //this will stop the loop just before the index to be deleted
        prev = temp; //the previous node will now be the current node
        temp = temp->next; //temp is going to be the next node
        counter++;
        if (counter == index - 1){
          prev->next = temp->next; //linking the list to exclude the node to be deleted
          delete temp; //deleting the data at the user given index
          numitems--; //decreasing num items
          return true;
          
        }
      }
    }
  }
}
//POST: the node has been removed, and num items has been updated 

//PRE: contents are passed into the function to be searched for in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item){
  int index = 0; //keeping track of where in the list 
  while (index < numitems){
    if (item == head->data){ //if the data is the same as the current node
      return index;
    }else{
      head = head->next; //continues onto the next node
      index++;
    }
  }
  return numitems; //return if not found in list
}
//POST: the index of the item passed into the function is returned, if not found, numitems is returned.

//PRE: contents to be added to the front of the linked list need to be passed into function
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item){
  Node *newnode = new Node(item, head); //setting the new node with the contents passed into the function and the node pointing to the head node
  if (head == nullptr){ //checking if the list is empty
    head = newnode; //if list is empty, the new node being added becomes the head and tail, and points to null
    tail = newnode;
    newnode->next = nullptr;
  }
  head = newnode;
  numitems++;
}
//POST: the contents passed into the function have been added to the front of the list

//PRE: nothing passed into function
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print(){
  cout << "LINKED LIST:" << endl;
  while (head != NULL){
    cout << head->data << "->";
    head = head->next;
  }
  cout << "NULL"<< endl;
}
//POST: outputting the linked list onto the screen for the user

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size(){
  return numitems;
}