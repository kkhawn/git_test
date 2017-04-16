#ifndef LIST_H
#define LIST_H
struct Node
{
	Node* prev;
	Node* next;
	void* data;
};

struct List
{
	Node* head;
};

List* CreateList();
void InsertNodeAfter(Node* node, void* data);
void RemoveNode(Node* node, bool deleteData);
void RemoveList(List* list, bool deleteData);

Node* GetTail(List* list);
Node* GetNext(Node* node);
Node* GetPrev(Node* node);
void* GetData(Node* node);
#endif