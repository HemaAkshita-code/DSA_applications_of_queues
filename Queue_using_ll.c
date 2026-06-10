#include <stdio.h>

struct Queue
{
    char data;
    struct Queue *next;
};

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

struct Queue* enqueue(char x);
struct Queue* dequeue();
int peek();
int isEmpty();
void display();

int main() 
{
    Front = enqueue(10);
    Front = enqueue(100);
    Front = enqueue(110);
    Front = enqueue(102);
    
    Front = dequeue();
    
    display();
    
    int x = peek();
    printf("%d\n", x);
	
    if (isEmpty())
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }
}

struct Queue* enqueue(char x)
{
     struct Queue *t = (struct Queue*) malloc (sizeof(struct Queue));
    t->data = x;
    
    if (Front==NULL)
    {
        Front = t;
        t->next = NULL;
        Rear = t;
        return Front;
    }
    
    Rear->next = t;
    t->next = NULL;
    Rear = Rear->next;
    
    return Front;

}

struct Queue* dequeue()
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return NULL;
    }
    
    struct Queue *p = Front;
    Front =  Front->next;
    free(p);
    
    return Front;
}

int peek()
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return -1;
    }
    return Front->data;
}

int isEmpty()
{
    if (Front == NULL && Rear == NULL)
    {
        return 1;
    }   
    else
    {
        return 0;
    }
}

void display()
{
    struct Queue *po = Front;
    
   while (po != NULL)
    {
        printf("%d\t", po->data);
        po = po->next;
    }
    printf("\n");
}

