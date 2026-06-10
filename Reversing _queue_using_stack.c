#include <stdio.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Stack
{
    int data;
    struct Stack *next;
};


struct Stack *Head = NULL;

struct Stack * push(int x);
struct Stack* pop();
char peek();
struct Queue* enqueue(char x);
struct Queue* dequeue();
void display();

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

int main() 
{
    char input[30];
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        Front = enqueue(input[i]);
    }

    while(Front != NULL)
    {
        Head = push(Front->data);
        Front = dequeue();
    }

    while(Head != NULL)
    {
        Front = enqueue(peek());
        Head = pop();
    }

    display();
    
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


struct Stack* pop()
{
    if (Head==NULL)
    {
        printf("Your stack is empty!\n");
    }
    
    struct Stack *p = Head;
    Head = Head->next;
    free(p);
    
    return Head;
}

char peek()
{
    if (Head == NULL)
    {
        printf("Your stack is empty!\n");
        return -1;
    }
    return Head->data;
}

struct Stack * push(int x)
{
     struct Stack *t = (struct Stack*) malloc (sizeof(struct Stack));
    t->data = x;
    
    if (Head==NULL)
    {
        Head = t;
        t->next = NULL;
        return Head;
    }
    
    t->next = Head;
    Head = t;
   
    return Head;

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

