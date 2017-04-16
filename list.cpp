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
	// before �� after ���̿� ���ο� ��尡 ��
	Node* before = node;
	Node* after = node->next;

	// �� ��� ���� �� �ʱ�ȭ
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	// after�� prev�� newNode ����Ŵ
	after->prev = newNode;

	// before�� next�� newNode ����Ŵ
	before->next = newNode;
}

void RemoveNode(Node* node, bool deleteData)
{
	// node�� �����ϹǷ� node�� before�� after�� �̾���
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