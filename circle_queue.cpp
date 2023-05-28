/*循环队列的实现,初始化，创建，出队，入队，删除，插入，销毁*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX 10              

typedef struct queue{
	int data[MAX];              /*数组长度为10，但实际上只能存储9个数字*/
	int front, rear;
}queue;

void init(queue* &q)
{
	q = (queue*)malloc(sizeof(queue));
	q -> front = q -> rear = 0;
}


void insert(queue* & q, int e)
{
	if((q -> rear + 1) % MAX == q -> front)                  //队尾追上了队首，上溢出
	{
		printf("full!\n");
		return;
	}
	q -> rear = (q -> rear + 1) % MAX;
	q -> data[q -> rear] = e;
}

bool get(queue* &q, int &e)
{
	if(q -> front == q -> rear)                           //如果队列为空，打印提示并返回false
	{
		printf("empty!\n");
		return false;
	}
	int i = ( q -> front + 1) % MAX;
	e = q -> data[i];
	return true;
}

void dele(queue* &q)
{
	if(q -> rear == q -> front)
	{
		printf("empty!\n");
		return;
	}
	 q -> front = (q -> front + 1) % MAX;
}

void deQueue(queue*&q, int &e)
{
	if(q -> rear == q -> front)
	{
		printf("empty!\n");
		return;
	}
	else
	{
		q -> front = (q -> front + 1) % MAX;
		e = q -> data[q -> front];
	}
}
void destroy(queue* &q)
{
	free(q);
}

int main()
{
	queue* q;
	init(q);
	for(int i = 0; i < MAX; i ++)            //初始化队列：0,1,2,3,4,5,6,7,8共9个数字，队列满
	insert(q, i);
	printf("dele * 2\n");             //执行两次出队操作
	int e1, e2;
	deQueue(q, e1);
	deQueue(q, e2);
	printf("%d %d", e1, e2);
	printf("\nenter* 3\n");
	insert(q, 1);
	insert(q, 2);
	insert(q, 3);        //插入三个数1， 2， 3
	if(get(q, e1))
	printf("the front:%d\n", e1);         //获得当前队首值
	for(int i = 0; i < MAX; i ++)
	{
		dele(q);                                //删除所有值并打印队首值
		if(get(q, e1))
		printf("the front:%d\n", e1);         //获得当前队首值
	}
	dele(q);
	destroy(q);
	return 0;
}
