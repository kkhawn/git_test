#include <string> // strcmp()
#include <iostream>
#include <cstdlib> // qsort()
#include <fstream>

#include "list.h"
using namespace std;

int compare(const void *a, const void *b);
void show();
struct key
{
	string keylocation;
	string value[5];
};
List* list = CreateList();

int main(int argc, char** argv)
{
	fstream reg;
	string temp;
	reg.open(argv[1]);
	if(!reg.is_open())
	{
		cout<<"����"<<endl;
	}
	else
		cout<<"����"<<endl;
	

	while(!reg.eof())
	{
		getline(reg,temp);
		if(!temp.empty() && ('[' == temp.at(0)))
		{
			key* one = new key;
			one->keylocation = temp;
			int i=0;
			do{
				if(i==5)
				getline(reg,temp);
				if(!temp.empty() && ('\"' == temp.at(0)))
				{
					one->value[i] = temp;
					i++;
				}
			}while(false);

			InsertNodeAfter(GetTail(list),one);
		}	
	}

	reg.close();
	
	


	//const int ELEMENTS = 8; // ��� ����

	//char array[ELEMENTS][6 + 1] = {
	//                               "�ͱ�",
	//                             "�����",
	//                             "��ĥ��",
	//                             "�嵿��",
	//                             "������",
	//                             "��â��",
	//                             "Ȳ����",
	//                             "������" };
	//qsort((void *)array, ELEMENTS, sizeof(array[0]), compare);

	/*List* list=NULL;
	list = CreateList();*/
	
	show();


  return 0;
}




int compare(const void *a, const void *b) {
  return( strcmp( (char *)a, (char *)b) );
}

void show(){
	Node* current = list->head->next;
	while(current != list->head)
	{
		const key* std = (key*)GetData(current);
		
		// �ش� �л��� ������ ����Ѵ�.
		cout <<std->keylocation<<endl;
		cout << std->value[0]<<endl;

		current = GetNext(current);

	}
}