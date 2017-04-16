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
		cout<<"실패"<<endl;
	}
	else
		cout<<"성공"<<endl;
	

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
	
	


	//const int ELEMENTS = 8; // 요소 개수

	//char array[ELEMENTS][6 + 1] = {
	//                               "맹구",
	//                             "배용준",
	//                             "땡칠이",
	//                             "장동건",
	//                             "강수정",
	//                             "송창식",
	//                             "황당해",
	//                             "고은아" };
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
		
		// 해당 학생의 정보를 출력한다.
		cout <<std->keylocation<<endl;
		cout << std->value[0]<<endl;

		current = GetNext(current);

	}
}