/*
*************************************
*  Simple Linked List               *
*   v.1.3                           *
*  Alan Hummel - alanh@terra.com.br *
*************************************
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class dataType> class LinkedList  {

// ========================================
// Internal classes from Simple Linked List:
// ========================================
protected:

    // Container class for a simple node.
//  template <class dataType>

    class nodeList  {
    public:
        dataType data;  // data stored at node
        nodeList* next;   // Next node from linked list
    };

    // define a shortcut to access a node from the same type from
    // the list, since we'll obviously use nodes as a list parameter.
    typedef nodeList node;

// ========================================
// Data Member for the simple list:
// ========================================
protected:

    node* head;   // pointer for the first node.
    node* tail;   // pointer for the last node.
    node* current; 	// internal node iteractor
	           	// for easy use.

// ========================================
// Public interface for the simple list:
// ========================================
public:

// ----------------------------------------------------------------
//  Name:           LinkedList::LinkedList
//  Description:    Constructor, creates an empty linked list.
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
    LinkedList()  {
        head = 0;
        tail = 0;
	current = 0;
    }


// ----------------------------------------------------------------
//  Name:           LinkedList::~LinkedList
//  Description:    Destructor, deletes each node from the list.
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
    ~LinkedList()  {
        clean();
    }

// ----------------------------------------------------------------
//  Nome:           LinkedList::isEmpty
//  Description:    checks if the list is empty or not.
//  Arguments:      None
//  Return Value:   True if the list is empty, False, otherwise.
// ----------------------------------------------------------------
    bool isEmpty()  {
        if( head == 0 )
            return true;
        return false;
    }

// ----------------------------------------------------------------
//  Name:           LinkedList::isValid
//  Description:    Determines if current iterator is valid
//                  (pointing to existing node).
//  Arguments:      None
//  Return Value:   True if the iteractor is valid, False, otherwise.
// ----------------------------------------------------------------
    bool isValid()  {
        if( current != 0 )
            return true;
        return false;
    }

// ----------------------------------------------------------------
//  Name:           LinkedList::moveToHead
//  Descrição:    Moves the iterator to the beginning of the list.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveToHead()  {
        current = head;
    }

// ----------------------------------------------------------------
//  Nome:           LinkedList::moveToEnd
//  Description:    Move the iterator to the end of the list.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveToTail()  {
        current = tail;   
    }

// ----------------------------------------------------------------
//  Name:           LinkedList::moveForward
//  Description:    Moves the iterator to the next node, or invalidates
//                  the iterator if it is the last one.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void moveForward()  {
        if( current != 0 )
            current = current->next;
    }

// ----------------------------------------------------------------
//  Name:           LinkedList::addBeforeCurrent
//  Description:    adds a data item before the current position of
//                  the list
//  Arguments:      data: data to insert on list.
//  Return Value:   None.
// ----------------------------------------------------------------
    void addBeforeCurrent( dataType& data )  {
        node* newNode = new node;
		node* temp = new node;
        newNode->data = data;
		if ( current != head )  {
			node* dad = head;
		    while( dad->next != current )    
				dad = dad->next;
			dad->next = newNode;
			newNode->next = current;
	        current = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
        if( head == 0 )  {
		head = newNode;
		tail = newNode;
	}
    }


// ----------------------------------------------------------------
//  Name:           ListaLigada::addAfterCurrent
//  Description:    adds the data item after the current list
//                  position.
//  Arguments:      data: data to insert on list.
//  Return Value:   None.
// ----------------------------------------------------------------
    void addAfterCurrent( dataType& data )  {
        node* newNode = new node;
		node* temp = new node;
        newNode->data = data;
		if ( current != tail )  {
			temp = current->next;
			current->next = newNode;
	        newNode->next = temp;
		}
		else {
			current->next = newNode;
			newNode->next = 0;
			tail = newNode;
		}
        if( head == 0 )  {
            head = newNode;
	    tail = newNode;
	}
    }

// ----------------------------------------------------------------
//  Name:           LinkedList::addAtTail
//  Description:    adds a data item at the last position.
//  Arguments:      data: data to insert on list.
//  Return Value:   None.
// ----------------------------------------------------------------
    void addAtTail( dataType& data )  {
        node* newNode = new node;
        newNode->data = data;
		newNode->next = 0;
        if( head == 0 )  
            head = newNode;
		if ( tail !=0 ) 
			tail->next = newNode;
		tail = newNode;
    }


// ----------------------------------------------------------------
//  Name:           LinkedList::remove
//  Description:    Removes a data item from current node, otherwise
//                  do nothing if current node is invalid. Current is
//                  always invalidated after this method calling.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void remove()  {
        if( current != 0 )  {
			node* dad = head;
		    while( dad->next != current )    
				dad = dad->next;
            if( current == head )
                head = current->next;
			if( current == tail )
				tail = dad;
			dad->next = current->next;
            delete current;
            current = 0;
        }
    }

// ----------------------------------------------------------------
//  Name:           LinkedList::clean
//  Description:    Deletes each list node.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
    void clean()  {
        node* temp = head;
        while( temp != 0 )   {
            current = temp->next;
            delete temp;
            temp = current;
        }
        current = 0;
	tail = 0;
        head = 0;
   }

// ----------------------------------------------------------------
//  Name:           LinkedList::getItem
//  Description:    Get the data item from current iterator. It is
//               recommended a isValid() check before its execution
//  Arguments:      None.
//  Return Value:   The Data item from current node iterator.
// ----------------------------------------------------------------
    dataType& getItem()   {
        return current->data;
    }


}; // End of class

#endif
