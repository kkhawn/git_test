#include "list.h"
List* CreateList()
{
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List;
		list->head = head;

	return list;
}

void InsertNodeAfter(Node* node, void* data)
{
	// before 와 after 사이에 새로운 노드가 들어감
	Node* before = node;
	Node* after = node->next;

	// 새 노드 생성 및 초기화
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	// after의 prev가 newNode 가리킴
	after->prev = newNode;

	// before의 next가 newNode 가리킴
	before->next = newNode;
}

void RemoveNode(Node* node, bool deleteData)
{
	// node를 삭제하므로 node의 before와 after를 이어줌
	Node* before = node->prev;
	Node* after = node->next;

	before->next=after;
	after->prev=before;

	if(deleteData)
		delete node->data;
	delete node;
}

void RemoveList(List* list, bool deleteData)
{
	Node* current = list->head;

	do{
		Node* next = current->next;
		
		if(deleteData)
			delete current->data;
		delete current;

		current = next;

	}while(current != list->head);
	
	delete list;
}

Node* GetTail(List* list)
{
	return list->head->prev;
}
Node* GetNext(Node* node)
{
	return node->next;
}
Node* GetPrev(Node* node)
{
	return node->prev;
}
void* GetData(Node* node)
{
	return node->data;
}