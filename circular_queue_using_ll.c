#include <stdio.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

struct Queue* enqueue(int x);
struct Queue* dequeue();
int peek();
void display();

int main() 
{
    Front = enqueue(10);
    Front = enqueue(100);
    Front = enqueue(110);
    Front = enqueue(102);
    
    //Front = dequeue();
    
    display();
    
    int x = peek();
    printf("%d\n", x);
    
    printf("Rear->next->data = %d\n", Rear->next->data);
    printf("Front->data = %d\n", Front->data);
	
}

struct Queue* enqueue(int x)
{
    struct Queue *t = (struct Queue*) malloc (sizeof(struct Queue));
    t->data = x;
    
    if (Front==NULL)
    {
        Front = t;
        Rear = t;
        Rear->next = Front;
        return Front;
    }
    
       Rear->next = t;
       t->next = Front;
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
    
    Rear->next = Front->next;
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
    int flag = 0;
    
    while (po != Front || flag == 0)
    {
        flag = 1;
        printf("%d\t", po->data);
        po = po->next;
    }
    printf("\n");
}

