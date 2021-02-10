#pragma once
#include<iostream>//to overload the << operator
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class type> class Node; //forward declare the Node class to overload << operator later
template<class type> std::ostream& operator<<(std::ostream& out, const Node<type>* node);//forward declare the overload << operator

/*create the definition of a node class that will contain the data as well as a pointer to the next node  and other functions*/
template <class type>
class Node {
private:
	type nodeData;
	Node<type>* next;

public:
	Node();//default constructor
	Node(type data);//Constructor that takes in data of type "type"

	~Node();//destructor

			//getters
	type getNodeData();
	Node<type>* getNext();

	//setters
	void setNodeData(type data);
	void setNext(Node<type>* nextPtr);

	friend std::ostream& operator<< <type> (std::ostream&, const Node<type>*);//overload insertion operator
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Start Definition of Linked list class*/

/*
* Destructor
* ToArray – Create an array from the contents of the list and return it*
*/


template<class type>
class linkedList {

private:
	Node<type>* head;//pointer to the first node of the list
	Node<type>* tail;//pointer to the last node in the list
	Node<type>* current;// pointer to the current node in the list
	int size; //size of the linked list
public:
	Node<type>* getCurrent();// gets the current node pointer of the list
	void InitializeCurrent();//intializes the current node pointer to be the head
	linkedList();//constructor
	~linkedList();// destructor
	void addToFront(type data);//adds a node to the front of the list
	void addToEnd(type data);//add a node to the end of the list
	int length();//returns the length of the list
	type removeFromFront();//removes the first element of the list and returns its contents
	type removeFromEnd();//removes the last element of the list and returns its contents
	void nextNode();//this function moves the pointer to the nextNode
	void Empty();//clears out the list
	type RetrieveFront();// method that returns the first item in a linked list, does not delete it
	type RetrieveEnd();//this method retrives the last item in the linked list
	bool ElementExists(type); //method checks if the element exists in the list and returns either true or false
	Node<type>* Find(type); //looks though the list for an element and returns a pointer to it if found
	void RemoveFirst(type);//this function removes the first instance of the node
	type RemoveAtIndex(int);//removes a Node at the nth position
	bool AddAtIndex(int, type);//adds an Node at the nth position
	void RemoveAll(type); //removes all instances of the data in the list
	type RemoveCurrent();//removes whatever the current is pointing to 
	void InsertAfterCurrent(type);//inserts a node after whatever node current is pointing to 
	void printList();//prints the list for debugging
	type Retrieve(int);//retreives that data located at the nth node (0 based)
	int IndexOf(type);//returns the index of where the data is located nothing if false (0 based)
	Node<type>* ToArray();//convert the linked list to an array

};
