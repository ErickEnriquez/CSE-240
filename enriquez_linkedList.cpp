#include "enriquez_linkedList"
/*implementation of Node here*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class type>
Node<type>::Node() {//this is the default constructor

	next = NULL;
	//dont initialize the nodeData since we don't know what kind of data it will be
}

template <class type>
Node<type>::Node(type data) {// this is the node constructor of type node
	this->nodeData = data;
	this->next = NULL;
}

template<class type>
Node<type>::~Node() {// this is where the desturctor will be
					 // destruct stuff here :)
}

template <class type>
type Node<type>::getNodeData() {//get the nodes contents
	return nodeData;
}

template <class type>
Node<type>* Node<type>::getNext() {//get a pointer to the node
	return next;
}

template<class type>
void Node<type>::setNodeData(type data) {
	this->nodeData = data; //rewites the nodes data
}

template<class type>
void Node<type>::setNext(Node<type>* pointer) {
	this->next = pointer; //changes what the next in Node points to 
}

template<class type>//overload the insertion operator to print the node pointers data
std::ostream& operator<<(std::ostream& out, const Node<type>* ptr) {
	return out << ptr->nodeData << "\n\n";
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Start implementation of linkedList Class*/

template<class type>//constructor that intializes the head pointer and tail pointer and current to NULL
linkedList<type>::linkedList() {
	head = NULL;
	tail = NULL;
	current = NULL;
	size = 0;
}

template<class type>//destructor
linkedList<type>::~linkedList() {//delete the list
	Empty();
}

template<class type>//add a node to the front of the linked list
void linkedList<type>::addToFront(type data) {//this function adds a node to the front of the list
	Node<type>* temp = new Node<type>(data);//
	if (head == NULL) {//check if the list is empty. and if it is make the new node the head
		head = temp;
	}
	else {
		temp->setNext(head);//make newNode point to the head
		head = temp;//make the newNode the head
	}
	size++;//increase the size
}

template<class type>/*this will add nodes to the end of the linked list*/
void linkedList<type>::addToEnd(type data) {
	Node<type>* newNode = new Node<type>(data);
	Node<type>* temp = head;
	if (head == NULL) {//check if the list is null and if it is make the the node the new head
		head = newNode;
	}
	else {
		while (temp->getNext() != NULL) {//while we havent walked off the list
			temp = temp->getNext();//move the temp pointer
		}
		temp->setNext(newNode);//set temp next to be newNode
		tail = newNode; // the tail becomes the newNode
		newNode->setNext(NULL);//set newNodes next to be NULL
	}
	size++;
}

template<class type>//return the length of the linked list
int linkedList<type>::length() {
	return size;
}

template<class type>//prints the contents of the list for debugging
void linkedList<type>::printList() {
	Node<type>* temp = head;
	while (temp != NULL) {//while we havent walked off the end of the list
		std::cout << temp; //output the current node pointers data
		temp = temp->getNext();// move the node up 1 node
	}
}

template<class type>/*this function removes the first component of a linked list*/
type linkedList<type>::removeFromFront()
{
	type data; //create a variable of type type
	if (head == NULL) {//if the list is empty return null
		return NULL;
	}
	else {//else create a node temp that equals head
		Node<type>* temp = head;
		head = head->getNext();//move the head 
		temp->setNext(NULL);//cut the link of the head
		data = temp->getNodeData();
		size--; //decrement the size by one
		return data;
	}


}

template<class type>// this methof removes the last node of the list
type linkedList<type>::removeFromEnd(){
	type data;
	Node<type>* prev; // make a previous node pointer and a temp that points to head
	Node<type>* temp = head;
	if (head == NULL) {//if the list is empty return null
		return NULL;
	}
	while (temp->getNext() != NULL) {//while temps next isnt NULL
		prev = temp;//move the previous to the temp
		temp = temp->getNext();//move the temp 1 forward
	}
	prev->setNext(NULL);//cut the node from the chain
	size--;//decrease size by 1
	data = temp->getNodeData();
	return data;
}

template<class type>//this method goes through the list and empties it out
void linkedList<type>::Empty() {
	Node<type>* temp = head;//set a temporary node to point to the head
	while (temp != NULL) { //while we havent reached the end
		temp = temp->getNext(); //move the current temp to the following node
		delete head;//delete the head
		head = temp;//make the new head be at temp
		size--;//decrease size 
	}
}

template<class type>//this gets the data from the front of the list but it does not remove it 
type linkedList<type>::RetrieveFront() {
	if (head == NULL) {//if the list is empty return null
		return NULL;
	}
	else {// else get the data the head is pointing to and return it
		type data = head->getNodeData();
		return data;
	}

}

template<class type>//this method retrieves the data from the last node of the list
type linkedList<type>::RetrieveEnd() {
	Node<type>* temp = head;// have a pointer temp that starts at the head
	while (temp->getNext() != NULL) {//while the next node isn't null walk the temp pointer 1 node at a time
		temp = temp->getNext();
	}
	type data = temp->getNodeData();//get the temps data and return it
	return data;
}

template<class type>//this method goes through and checks to see if the element exists in the list and returns true or false
bool linkedList<type>::ElementExists(type data) {
	Node<type>* temp = head;//temp pointer starting at head
	while (temp != NULL) {//while we havent walked off the list
		if (temp->getNodeData() == data) {//if the thing we are pointing at currently has the data we are looking for return true
			return true;
		}
		temp = temp->getNext();//walk the temp pointer down the list
	}
	return false;//if we reach the end and there is not match return false
}

template<class type>//this method searches the list and looks too see if data matches parameter. returns a pointer to node if true
Node<type>* linkedList<type>::Find(type data) {
	Node<type>* temp = head;//make a temp that starts at head
	while (temp != NULL) {//while we havent walked off the list
		if (temp->getNodeData() == data) {//if what we are pointing at has data that matches the parameter return the node pointer
			return temp;
		}
		temp = temp->getNext();//walk the list
	}
	return NULL;//if we reach the end and have no match return null
}

template<class type>//this method goes through and removes the first instance of the the data in the list
void linkedList<type>::RemoveFirst(type data) {
	Node<type>* temp = head;//have a node that starts at heads next
	Node<type>* prev = head;//have a node that starts at head
	if (head == NULL) {//if the list is empty retrun back from method
		return;
	}
	if (head->getNodeData() == data) {//if the head contains the data we are looking for 
		head = head->getNext();//move the head pointer 1 node 
		delete temp;//delete what head used to point to;
		size--;
	}
	else {
		while (temp->getNext() != NULL) {//while temp next isnt null
			if (temp->getNodeData() == data) {//if temps node  = parameter break from the while loop
				break;
			}
			else {
				prev = temp; //move the previous node to the temp
				temp = temp->getNext();//move temp up one node
			}
		}
		if (temp->getNodeData() == data) {//if what temp is currently pointing to is equal to parameter = remove the node
			prev->setNext(temp->getNext());
			size--;
			delete temp;
		}
	}
}

template<class type>//removes the node at index n and returns the contents (0 based)
type linkedList<type>::RemoveAtIndex(int n) {
	Node<type>* temp = head;
	Node<type>* prev = head;
	type data;
	if (n<0 || n>size || head == NULL) {//if user enters an index thats not in bounds or the list is empty return from function
		return NULL;
	}
	if (n == 0) {//if index is head 
		head = head->getNext();//move head 1 node over
		data = temp->getNodeData();//get what head used to have
		delete temp;//delete the old head
		size--;
		return data;//return contents of old head
	}
	else {
		int i = 0;
		while (i != n) {//loop through until we get to desired index move the prev and temp pointers accordingly
			prev = temp;
			temp = temp->getNext();
			i++;
		}
		prev->setNext(temp->getNext());//link the prev next to temps next , 
		data = temp->getNodeData();//get contents of temp
		delete temp;//delete temp
		size--;
		return data;//return contents temp

	}
}

template<class type>//adds a node at index n , returns T/F for success, (0 based)
bool linkedList<type>::AddAtIndex(int n, type data) {
	Node<type>* temp = new Node<type>(data); // make  a new node 
	Node<type>* temp2 = head;//make a temp to that points to head
	Node<type>* following = head;
	if (n > size || n < 0) {// if the index is out of bounds return false
		return false;
	}

	if (head == NULL) {//if the list is empty make temp be head
		head = temp;
		size++;
		return true;
	}
	if (n == 0) {//if we want to add at the head make temp be heads next then make head =  temp
		temp->setNext(head->getNext());
		head = temp;
		size++;
		return true;
	}
	else {
		int i = 0;
		while (i < n - 1 ) {//loop through until we are 1 from the the index we want
			temp2 = temp2->getNext();//walk the temp2 down the list
			i++;
		}

		temp->setNext(temp2->getNext());//set temp to be temp2's next
		temp2->setNext(temp);//make temp2 next be temp
		size++;
		return true;
	}
}

template<class type>// goes through the list and removes all of the nodes that equal parameter
void linkedList<type>::RemoveAll(type data) {
	Node<type>* prev = head;
	Node<type>* temp = head;

	while (temp != NULL) {//if we havent walked off list
		if (temp->getNodeData() == data) {//if currentNodes data = data
			if (temp == head) {//if the currentNode is at the head move the head over and delete old node
				head = head->getNext();//move head to head->next
				size--;
				delete temp;//delete old head
				prev = head;//prev = new head
				temp = head;//temp  = new head
			}
			else {
				prev->setNext(temp->getNext());//have prev link to temps next 
				delete temp;//delete temp
				size--;
				temp = prev->getNext();// make temp be prev next
			}
		}
		else {
			prev = temp;
			temp = temp->getNext();// walk the nodes through the list
		}
	}


}

template<class type>//this method uses the current pointer and moves it to the next node, and wraps around at the end
void linkedList<type>::nextNode() {

	if (current->getNext() == NULL && head != NULL) {//if currents next is null and the head isn't null return the current to the head
		current = head;
	}
	else {
		current = current->getNext();//else walk the current 1 place from where it was 
	}

}

template<class type>//this method initalizes the current pointer to start at the head 
void linkedList<type>::InitializeCurrent() {
	current = head;
}

template<class type>//this returns the current pointer of the list
Node<type>* linkedList<type>::getCurrent() {
	return current;
}

template<class type>//this method removes whatever the current pointer is pointing to 
type linkedList<type>::RemoveCurrent() {
	Node<type>* prev = head;// make a temp that equals head

	if ( current == head) {//if the current is at the head or current's next is going to walk off list
		prev = head->getNext();//set pre to be heads next
		type data = head->getNodeData(); //get the contents of the head
		delete head;//delete the head
		head = prev; //set the head to be previous 
		current = head; //have current = head
		size--;//decrement the size
		return data;//return the data
	}
	else if(current->getNext()== NULL){
	    type data = current->getNodeData();
	    delete current;
	    current = head;
	    return data;
	}
	else{
	while (prev->getNext() != current) {//walk through the list until we are 1 before the current node
		prev = prev->getNext();
	}
	prev->setNext(current->getNext());//set prev next to point to currents next
	type data = current->getNodeData();//get the contents of current
	delete current;
	current = prev->getNext();//set current to be the node following what it used to be 
	size--;
	return data;//return the data
}
}

template<class type>//this method inserts a node after whatever current is pointing to 
void linkedList<type>::InsertAfterCurrent(type data){
	Node<type>* temp = new Node<type>(data);
	if (head == NULL) {//if the list is empty set head to be the new node
		head = temp;
		size++;
	}
	if (current->getNext() != NULL) {//while we havent walked off the list
		temp->setNext(current->getNext());//make temps next be currents next
		current->setNext(temp);//make currents next be temp
		size++;
	}
	else {
		current->setNext(temp);//if we are the the end of the list just make currents next be the temp
		size++;
	}
}

template<class type>//this method retrieves that data at the nth node of the list(0 based)
type linkedList<type>::Retrieve(int n) {
	Node<type>* temp = head;
	type data;
	if (n < 0 || n > size || head == NULL) {//if the index is out of bounds or the list is empty return null
		return NULL;
	}
	else {
		int i = 0;
		while (i != n) {//loop until we are at the index desired
			temp = temp->getNext();
			i++;
		}
		data = temp->getNodeData();//get the data from temp
		return data;//return the data
	}
}

template <class type>
int linkedList<type>::IndexOf(type data) {
	Node<type>* temp = head;
	int i = 0;
	while (temp != NULL) {
		if (temp->getNodeData() == data) {
			return i;
		}
		else {
			temp = temp->getNext();
			i++;
		}
	}
	return NULL;
}

template<class type>//this function converts the linked list into a dynamically allocated array and returns a pointer to the begining of it
Node<type>* linkedList<type>::ToArray() {
	Node<type>* temp = head;
	Node<type>* array = new Node<type>[size];//create a dynamically allocated array of nodes
	int i = 0;
	while (temp != NULL) {//while we havent walked off of the list
		array[i] = temp->getNodeData();//copy the contents of temp into array at index i 
		temp = temp->getNext();//move the temp pointer 1 location over
		i++;
	}
	return array;
	
}


/*End implementation of linked list class*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

