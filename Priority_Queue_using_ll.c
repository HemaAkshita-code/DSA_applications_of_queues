#include <stdio.h>

struct Queue
{
    int data;
    int priority;
    struct Queue *next;
};

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

struct Queue* enqueue(int x, int priority);
struct Queue* dequeue();
int peek();
void display();

int main() 
{
    Front = enqueue(10, 0);
    Front = enqueue(100, 3);
    Front = enqueue(110, 2);
    Front = enqueue(102, 1);
    
    //Front = dequeue();
    
    display();
    
    int x = peek();
    printf("%d\n", x);
	
}

struct Queue* enqueue(int x, int priority)
{
    struct Queue *t = (struct Queue*) malloc (sizeof(struct Queue));
    t->data = x;
    t->priority = priority;
    
    if (Front==NULL)
    {
        Front = t;
        t->next = NULL;
        Rear = t;
        return Front;
    }
    
    struct Queue *p = Front;
    
    while(p->next != NULL && p->next->priority < t->priority )
    {
        p = p->next;
    }
    
    t->next = p->next;
    p->next = t;
    
    if (t->next == NULL)
    {
        Rear = t;
    }
    
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

