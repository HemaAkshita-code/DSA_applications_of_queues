#include <stdio.h>

struct Queue
{
    char data;
    struct Queue *next;
};

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

struct Queue* reverseQueue(struct Queue *p);

struct Queue* enqueue(struct Queue *Front, char x);
struct Queue* dequeue(struct Queue *Front);
char peek();
int isEmpty();
void display();

int main() 
{
    
    char input[30];
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        Front = enqueue(Front, input[i]);
    }
    
    struct Queue *p = Front;
    
    Front = reverseQueue(p);
    
    display();
    
}

struct Queue* reverseQueue(struct Queue *p)
{
    if(Front == NULL)
    {
        return Front;
    }
    
    char val = peek();
    Front = dequeue(Front);
    
    reverseQueue(p);
    
    Front = enqueue(Front, val);
    
    return Front;
}

struct Queue* enqueue(struct Queue *Front, char x)
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

struct Queue* dequeue(struct Queue *Front)
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

char peek()
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
        printf("%c\t", po->data);
        po = po->next;
    }
    printf("\n");
}
