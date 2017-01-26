#include <iostream>
#include "Node.h"

using namespace std;

void removeByValue(int removedValue);
void removeFirst();
void removeLast();
void addIncreasing(int newvalue);
void addAsSecond(int newvalue);
void addToBeginning(int newvalue);
void addToEnd(int newvalue);
void printList(Node* pointer);
Node* head = NULL;

int main(){
  addIncreasing(1);
  addIncreasing(3);
  addIncreasing(7);
  addIncreasing(5);
  addIncreasing(9);
  printList(head);
  removeLast();
  printList(head);
  removeByValue(3);
  printList(head);
}

void removeByValue(int removedValue){
  Node* temp;
  Node* tempPrev;
  if(head == NULL){
    return;
  }
  if(head->getValue() == removedValue){
    temp = head;
    head = head->getNext();
    delete head;
  }
  else{
    temp = head; 
    while (temp != NULL && temp->getValue() != removedValue){
      tempPrev = temp; 
      temp = temp->getNext();
    }
    
    if (temp == NULL)  {
      return;
    }
    else
     {
       tempPrev->setNext(temp->getNext());
       delete temp;
     }
  }
  
}

void removeLast(){
  Node* temp;
  if(head == NULL){
    return;
  }
  if(head->getNext() == NULL){
    delete head;
    head = NULL;
  }
  else{
    while(temp->getNext() != NULL && temp->getNext()->getNext() != NULL){
      temp = temp->getNext();
    }
    delete temp->getNext();
    temp->setNext(NULL);
  }

}
void removeFirst(){
  Node* temp;
  if(head == NULL){
    return;
  }
  else{
    temp = head;
    head = head->getNext();
    delete temp;
  }

}
void addIncreasing(int newvalue){
  Node* current = new Node;
  current->setValue(newvalue);
  Node* temp;
  if (head == NULL){
    head = current;
  }
  else if (current->getValue() < head->getValue()){
    current->setNext(head);
    head = current;
  }
  else if (current->getValue() > head->getValue()){
    temp = head;
    while (temp->getNext() != NULL && current->getValue() > temp->getValue() && current->getValue() > temp->getNext()->getValue()){
      temp = temp->getNext();
    }
    current->setNext(temp->getNext());
    temp->setNext(current);
  }


}
void addToBeginning(int newvalue){
  Node* current = new Node;
  current->setValue(newvalue); //set value of current 
  current->setNext(head); //set current as the first element
  head = current; //move head to beginning  
}
void addToEnd(int newvalue){
  Node* current = new Node;
  current->setValue(newvalue);
  if (head == NULL){
    head = current;
  }
  else if (head != NULL){
    Node* temp;
    temp = head;
    while (temp->getNext() != NULL){ //make temp the last Node
      temp = temp->getNext();
    }
    temp->setNext(current); //set current as the next Node
  }
}

void addAsSecond(int newvalue){
  Node* current = new Node;
  current->setValue(newvalue);
  current->setNext(head->getNext());
  head->setNext(current);
}

void printList(Node* pointer){
  Node* temp;
  temp = pointer;
  if (temp != NULL){
    cout << temp->getValue() << " ";
    printList(temp->getNext());
  }
  else{
    cout << endl;
  }
}
