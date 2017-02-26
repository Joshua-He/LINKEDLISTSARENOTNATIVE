#include <iostream>
#include <string.h>
#include <stack>
#include "Node.h"
#include <cstring>

using namespace std;


/*

Joshua He 

Period 7 

This program converts an Infix expression to postfix using a linked lsit stack and the shunting yard algorithm.


 */
void push(Node* &head, char C);
void pop(Node* &head, char C);
void processToken(Node* &stack, char* token);
int isOperator(char C);
bool isOperand(char C);
bool isSpace(char C);
void popParentheses(Node* &head, char op);

int main(){
  
  char array[100];
  char output[100] = "";
  char token[100]= "";
  int length;
  Node* stack = NULL;
  
  cout << "Enter an Infix expression. Please enter with a space separating each operator and operand" << endl;
  cout << "For example: 3 + ( 2 * 5 ) + 3" << endl;
  cin.getline(array, 101);
  length = strlen(array);
  cout << "The postfix is: " << endl;

  //Scan the entered string and process each individual token separated by space
  for(int i = 0; i < length; i++){
    if (array[i] == ' '){
      //cout << token << endl;
      processToken(stack, token);
      token[0] = '\0';      
    }
    else {
      strncat(token, &(array[i]), 1);
    }
    
  }
  //cout << token << endl;
  processToken(stack, token);
  pop(stack, ' ');
}

//Function to process the different token types 
void processToken(Node* &stack, char* token){
  if (isOperator(token[0]) >0){

    // When the token is not a ^
    if (token[0] != '^') {
       pop(stack, token[0]);
    }
    // Push the operator 
    push(stack, token[0]);
  }
  if (isOperand(token[0]) == true){
    cout << token << " ";
  }
  if (token[0] == '('){
    push(stack, token[0]);
  }
  if (token[0] == ')'){
    popParentheses(stack, token[0]);
  }
}
//Evaluate if the character is an operator
int isOperator(char C){

  if (C == '+' || C == '-'){
    return 1;
  }
  if (C == '*' || C == '/'){
    return 2;
  }
  if (C == '^'){
    return 3;
  }
  else return 0;
}

//Evaluate if the character is a letter or number 
bool isOperand(char C){
  if ((int)C >= (int)'0' && (int)C <= (int)'9'){
    return true;
  }
  if ((int)C >= (int)'a' && (int)C <= (int)'z'){
    return true;
  }
  if ((int)C >= (int)'A' && (int)C <= (int)'Z'){
    return true;
  }
  else {
    return false;
  }
}

//evaluate if the character is a space
bool isSpace(char C){
  if (C == ' '){
    return true;
  }
  else {
    return false;
  }
}


// pushes an operator into the stack
void push(Node* &head, char C){
  Node* temp = new Node;
  temp->setValue(C);
  if (head == NULL){
    temp->setNext(NULL);
    head = temp;
  }
  else {
    temp->setNext(head);
    head = temp;
  }
}

// function to pop the head value of the stack
void pop(Node* &head, char op){
  Node* temp;
  temp = head;
  
  while (temp != NULL && isOperator(temp->getValue()) >= isOperator(op)){
    cout << temp->getValue() << " ";
    head = temp->getNext();
    delete temp;
    temp = head;
    }
}

//Special pop case for when there are parentheses
void popParentheses(Node* &head, char op){
  Node* temp;
  temp = head;

  while (temp != NULL && temp->getValue() != '('){
    cout << temp->getValue() << " ";
    head = temp->getNext();
    delete temp;
    temp = head;
    }
  if (temp != NULL && temp->getValue() == '('){
    head = temp->getNext();
    delete temp;
    temp = head;
  }
}

