#include <iostream>
#include "Node.h"

using namespace std;

void deleteAlternate();
void deleteOdd();
void deleteMax();
void findValue();
void reverseOrder();
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
  addIncreasing(4);
  addIncreasing(2);
  addIncreasing(9);
  printList(head);
  deleteAlternate();
  printList(head);
}

void deleteAlternate(){
  Node* temp;
  Node* follow;
  temp = head;
  head = head->getNext();
  delete temp;
  temp = head;
  follow = head;
  while(temp != NULL && follow->getNext() != NULL){
    temp = temp->getNext();
    follow->setNext(temp->getNext());
    delete temp;
    follow = follow->getNext();
    temp = follow;


  }





}
void deleteOdd(){
  Node* temp;
  Node* follow;
  temp = head;
  follow = head;
  while(temp != NULL){
    if (temp->getValue() % 2 == 1 && temp == head){
      head = head->getNext();
      follow = head;
      delete temp;
      temp = head;
    }
    else if (temp->getValue() % 2 == 1){
      follow->setNext(temp->getNext());
      delete temp;
      temp = follow;
    }
    else {
      follow = temp;
      temp = temp->getNext();
      
    }
  }



}

void deleteMax(){
  Node* max;
  Node* temp;
  temp = head;
  max = temp;
  if (head == NULL){
    return;
  }
  while(temp->getNext() != NULL){
    if (max->getValue() < temp->getValue()){
      max = temp;
    }
    temp = temp->getNext();
  }
  Node* prev;
  prev = head;
  if (prev == max){
    head= head->getNext();
    delete max;
    return;
  }
  while(prev->getNext() != max){
    prev = prev->getNext();
  }
  prev->setNext(max->getNext());
  delete max;


}

void findValue(){
  int max = 0;
  int sum = 0;
  int avg = 0;
  int counter = 0;
  Node* temp;
  temp = head;
  max = temp->getValue();
  while(temp->getNext() != NULL){
    if(temp->getNext()->getValue() > max){
      max = temp->getValue();
    }
    temp = temp->getNext();
  }
  cout << "max: " << max;
  temp = head;
  while(temp != NULL){
    sum = sum + temp->getValue();
    temp = temp->getNext();
    counter++;
  }
  avg = sum/counter;
  cout << "avg: " << avg << endl;
}
void reverseOrder(){
  if (head == NULL){
    return;
  }
  Node* prev;
  prev = NULL;
  Node* current;
  current = head;
  Node* nextNode;
  
  while(current != NULL){
    nextNode = current->getNext();
    current->setNext(prev);
    prev = current;
    current = nextNode;

  }
  head = prev;

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
