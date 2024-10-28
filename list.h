#ifndef LIST_H
#define LIST_H

class Node {

	friend class list;

	public:
		Node(const int &);     //constructor 
		int getData() const;   	
	private:
		int data;           //data contained in node 
		Node *next;   		 // next object
};

class list {
 public:
	list();    // constructor
	~list();   // deconstructor
	void addNode(const int &);   	// add node to the start 
	bool empty();                 // gives if list is empty
	list sumList(const list &) const;	//sums 2 lists
	void printList();				//prints out list. usually would be backwards but summed list is reversed 
	
 private:
	Node *newNode(const int &);   //new node, look at class Node
	Node *first;                	// first node 
};


#endif