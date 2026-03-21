Queue Data Structure DEMO
    • A queue is a linear data structure that follows the FIFO (First In, First Out) principle. 
    • The first element inserted is the first one removed.

    1. Basic Concept
In a queue implemented with a singly linked list, we maintain two pointers:
    • Front → points to the first element (for deletion)
    • Rear → points to the last element (for insertion)
Each node contains:
    • data
    • next pointer (link to next node)

    2. Operations of Queue (Linked List Implementation)
A. Enqueue (Insert at Rear)
Steps:
        ◦ Create a new node.
        ◦ If queue is empty:
            ▪ front = rear = new node
        ◦ Otherwise:
            ▪ rear->next = new node
            ▪ rear = new node
B. Dequeue (Remove from Front)
Steps:
        ◦ If queue is empty → Underflow
        ◦ Store front node temporarily
        ◦ Move front to front->next
        ◦ If front becomes NULL → rear = NULL
        ◦ Free old node


Task: Complete the implementation below:

struct nodes {
	int x;
	struct nodes *next;
};
int main () {
	struct nodes *front = NULL;
	struct nodes *rear = NULL;

	struct nodes *n1 = (struct nodes *) malloc (sizeof(struct nodes));
	//create a function Enqueue (front, rear, 10) to insert the node (value 10) in the queue.  

	struct nodes *n2 = (struct nodes *) malloc (sizeof(struct nodes));
	//call the function Enqueue (front, rear, 15) to insert the node (value 15) in the queue.

struct nodes *n3 = (struct nodes *) malloc (sizeof(struct nodes));
	//call the function Enqueue (front, rear, 25) to insert the node (value 25) in the queue.


	//create a function that display all the nodes from the queue, start from the front to rear.


	//create a function Dequeue (front, rear) to remove the front node in the queue.
	//the Dequeue function will then return the x (value of node) and this display in main function

	//call the function Dequeue (front, rear) to remove the front node in the queue.
	//the Dequeue function will then return the x (value of node) and this display in main function

	//call the function Dequeue (front, rear) to remove the front node in the queue.
	//the Dequeue function will then return the x (value of node) and this display in main function


	//try to call function Dequeue, if the queue is empty, just display “The Queue is empty”.

	return 0;
}
