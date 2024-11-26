#include <stdio.h>
#include <stdlib.h>

//one part of the LL
typedef struct Node{
	int data;
	struct Node *next;
}Node;

//a struct that contains pointers to all the functions and the start of the list
typedef struct LinkedList{
	struct Node *Head;
	void (*addAtStart)(Node **CStart, int Val);
	void (*addAtEnd)(Node *Start, int Val);
	void (*pointList)(Node *start);
	void (*free)(struct LinkedList *L);
	void (*init)(struct LinkedList *L);
	void (*addAtPos)(Node **Start, int Val, int Pos);
	void (*RemoveAtPos)(struct LinkedList *Start, int Pos);
	Node *(*getPointAtPos)(struct LinkedList *List, int Pos);
	int (*length)(Node* start);
	void (*rotateListBy)(struct LinkedList *List, int amount);
	void (*changeVal)(struct LinkedList *List, int Data, int Pos);
	void (*changeNodePose)(struct LinkedList *List, int OldPlace, int NewPlace);
}LinkedList;

//adds a new node at the start(Doesn't replace)
void AddAtStart(Node **CStart, int Val){
	Node *Start = (Node*)(malloc(sizeof(Node)));
	Start->data = Val;
	Start->next = *CStart;
	*CStart = Start;
}

//adds a new node at the end(Doesn't replace)
void AddAtEnd(Node *Start, int Val){
	Node *end = (Node*)(malloc(sizeof(Node)));

	end->data = Val;
	end->next = NULL;

	if (Start->next == NULL){
		Start = end;
		return;
	}
	while (Start->next != NULL)Start = Start->next;
	Start->next = end;
}

//adds a new node at the specified place(Doesn't replace)
void AddAtPos(Node **Start, int Val, int Pos){
	Node *NewNode = (Node*)(malloc(sizeof(Node)));
	NewNode->data = Val;
	Node *CurrentNode = *Start;
	for (int i = 0; i < Pos; i++) CurrentNode = CurrentNode->next;
	NewNode->next = CurrentNode->next;
	CurrentNode->next = NewNode;
}


//rotates the nodes from the start to the end by specified number
void RotateListBy(LinkedList *List, int amount){
	Node* OneBeforeEndOfList = List->getPointAtPos(List, List->length(List->Head)-2);
	Node* EndOfList = OneBeforeEndOfList->next;
	for (int i = 0; i < amount; i++){
		EndOfList->next = List->Head;
		List->Head = EndOfList;
		OneBeforeEndOfList->next = NULL;
		EndOfList = OneBeforeEndOfList;
		OneBeforeEndOfList = List->getPointAtPos(List, List->length(List->Head)-2);
	}
}

//chnge the value of the node in specified place
void changeVal(LinkedList *List, int Data, int Pos){
	if (!Pos){
		List->Head->data = Data;
		return;
	}
	List->getPointAtPos(List, Pos)->data = Data;
}

//remove Node in specified place
void RemoveAtPos(LinkedList *Start, int Pos){
	Node *CurrentNode = Start->Head;
	Node *ptr= CurrentNode;
	if (!Pos){
		Start->Head = CurrentNode->next;
		free(ptr);
		return;
	}
	
	for (int i = 0; i < Pos - 1; i++) CurrentNode = CurrentNode->next;
	ptr = CurrentNode->next;
	CurrentNode->next = CurrentNode->next->next;
	free(ptr);
}

//this function takes a strting node and prints the full linked list
void PointList(Node *start){
	Node *CurrentNode = start;
	while (CurrentNode->next != NULL){
		printf(" %d ->", CurrentNode->data);
		CurrentNode = CurrentNode->next;
	}

	printf(" %d\n", CurrentNode->data);
}

//return the node in place Pos in the list
Node *GetPointAtPos(LinkedList *List, int Pos){
	Node* CurrentNode = List->Head;
	for (int i = 0; i< Pos; i++){
		CurrentNode = CurrentNode->next;
	}
	return CurrentNode;
}

//free all the nodes in the list
void Free(LinkedList *L){
	while (L->Head->next != NULL){
		PointList(L->Head);
		RemoveAtPos(L,0);
	}
	PointList(L->Head);
	free(L->Head);
}

//returnes the length of the list that start with this node(could be used to find the length of a partial list that starts in this node)
int Length(Node *node){
	int counter = 1;
	while (node->next != NULL){
		counter++;
		node = node->next;
	}
	return counter;
	
}

void moveNode(LinkedList* list, int old_index, int new_index) {
    if (old_index == new_index) return;
    if (old_index < 0 || new_index < 0) return;
    
    Node* prev_old = NULL;
    Node* node_to_move = list->Head;

    // Find the node to move and its previous node
    for (int i = 0; i < old_index && node_to_move != NULL; i++) {
        prev_old = node_to_move;
        node_to_move = node_to_move->next;
    }

    if (node_to_move == NULL) return; // Invalid old_index

    // Remove node_to_move from its current position
    if (prev_old != NULL) {
        prev_old->next = node_to_move->next;
    } else {
        list->Head = node_to_move->next;
    }

    // If new_index is 0, move the node to the head
    if (new_index == 0) {
        node_to_move->next = list->Head;
        list->Head = node_to_move;
        return;
    }

    Node* prev_new = NULL;
    Node* node_after_move = list->Head;

    // Find the new position and its previous node
    for (int i = 0; i < new_index && node_after_move != NULL; i++) {
        prev_new = node_after_move;
        node_after_move = node_after_move->next;
    }

    // Insert node_to_move at new_index
    if (prev_new != NULL) {
        prev_new->next = node_to_move;
    }
    node_to_move->next = node_after_move;


}

//initializes the List(must call before any use!!!!)
void init(LinkedList *L){
	L->Head = NULL;
	L->length = Length;
	L->addAtEnd = AddAtEnd;
	L->addAtStart = AddAtStart;
	L->pointList = PointList;
	L->free = Free;
	L->addAtPos = AddAtPos;
	L->RemoveAtPos = RemoveAtPos;
	L->rotateListBy = RotateListBy;
	L->getPointAtPos = GetPointAtPos;
	L->changeVal = changeVal;
	L->changeNodePose = moveNode;
}
