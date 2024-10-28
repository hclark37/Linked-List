#include "list.h"
#include <iostream>

using namespace std;

list::list() : first(NULL) {	
	
}

list::~list() {
	if (!empty()) { 
		Node *current = first; //starts at first node 
		
		while (current != NULL) { //while it isnt the end 
			Node *next = current->next; //declare pointer to next 
			delete current; //delete current node 
			current = next; //move to the next one
		}
	}
}

void list::addNode(const int &data) {
	Node *new_node = newNode(data); // create new node 
	new_node->next = first; //make the next node for your new node the first node 
	first = new_node; //make node the new first 
}

bool list::empty() {
	if (first == NULL) {
		return true;
	} else {
		return false;
	}
}

int Node::getData(void) const { //return data because otherwise private or weird to access
	return data;  
}

Node::Node(const int &info) :data(info),next(NULL) {
}

Node *list::newNode(const int &value) {
	return new Node(value);
}

list list::sumList(const list &list2) const {
	list summedList;
	Node *firstList = first;
	Node *secondList = list2.first;
	int carry = 0; //carried over to next node
	while (firstList != NULL || secondList != NULL || carry > 0) {
        int total = carry; //total of the calculation per list node 
        if (firstList != NULL) { //done so that it doesnt try to reference a node that does not exist; one list can be much larger than the other- this avoids segfault
            total += firstList->getData();  //add data from list 
            firstList = firstList->next;  //iterate to next 
        }
		
        if (secondList != NULL) {
            total += secondList->getData(); 
            secondList = secondList->next; 
        }

        summedList.addNode(total % 10); //add what's left if it goes up by 10 and needs to be carried 
        carry = total / 10;  //add the carry since it's an int it cuts truncates the decimal that is left 
    }

	return summedList;
}

void list::printList() {
	Node *current = first; //start at first 
	while (current != NULL) { //until the end 
		cout << current->getData(); 
		current = current->next; //iterate to next node
	}
}