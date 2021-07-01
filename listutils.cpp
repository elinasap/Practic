#include <iostream>

struct Node {
  int val;
  Node* next;
};

// Инициализации элемента односвязного списка нулями

void init(Node* node) {
node->val = 0;
	node->next = NULL;

}

// Отображения односвязного списка на экран
void show(Node* head) {
Node* p = head;
	while(p->next !=NULL)
	{
		std::cout << p->val << " ";
		p = p->next;
	}
    std::cout << std::endl;
}

// Добавления элемента в односвязный список
void pushNode(Node* head,Node* node) {
Node* p = head;
	while (p->next != NULL) 
	p = p->next;
	p->next = new Node;
	p = p->next;
	p->val = node->val;
	p->next = NULL;
} 


// Написать функцию инициализации size элементов списка заданным значением val.
void initList(Node* head, int size, int val)  {

}

// Написать функцию копирования элементов массива source в новый массив dest
void copyMas(Node* source, Node* dest) {
while (source->next != NULL && dest->next != NULL) 
		{
        	dest->val = source->val;
        	dest = dest->next;
        	source = source->next;
    	}
}
  

// Написать функцию сравнение списков source и dest. Если списки равны 0, если не равны -1
int compareMas(Node* source, Node* dest) {
  return 0;
}


// Написать функцию удаления со сдвигом влево n-го элемента списка.
void deleteList(Node* head,int n) {

}


// Написать функцию сдвига значений вправо на n-элементов с заполнением крайних элементов нулями
void rShiftList(Node* head,int n) {

}



// Написать функцию сдвига значений влево на n-элементов с заполнением крайних элементов нулями.
void lShiftList(Node* head,int n) {

}


//Написать функцию сдвига значений влево на n-элементов с переносом вытесненных элементов в конец
void lRoundShiftMas(Node* head,int n, int size) {

}


// Написать функцию вычисления среднего значения элементов списка.
int averageList(Node* head, int size) {
  return 0;
}



// Написать функцию вычисления средне квадратического отклонения элементов списка.
int skoFromList(Node* head, int size) {
  return 0;
}


int testCopyMas() {
    

    Node* source = new Node;
    Node* dest = new Node;
    Node* sourceNode = source, *destNode = dest;

    for (int i = 0; i <= 5; i++)
	   {
        pushNode(source, new Node);
        pushNode(dest, new Node);
        sourceNode->val =i+1;
        init(destNode);
		destNode = destNode->next;
        sourceNode = sourceNode->next;
    	}

   		 if (compareMas(source, dest) != 0)
        	return -1;
    source->next->next->val = -1;
    	 if (compareMas(source, dest) != -1)
        	return -1;
    return 0;
}


static void runTest(int (*testFunction)(),const std::string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}



int main() {
  runTest(testCopyMas,"testSkoFromList");


}
