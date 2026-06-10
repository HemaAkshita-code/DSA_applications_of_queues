#include <stdio.h>

int *enqueue(int element) ;
int *dequeue() ;
int peek() ;
int isEmpty() ;

int front = -1, rear = -1, Queue[20];

int main() 
{
    int i, element;

    int count;
    int *queuePtr = Queue;

    queuePtr = enqueue(10);
    queuePtr = enqueue(20);
    queuePtr = enqueue(30);
    element = peek();
    printf("Front element: %d\n", element);

    queuePtr = dequeue();
    element = peek();
    printf("Front element after dequeue: %d\n", element);

    if (isEmpty()) 
    {
        printf("Queue is empty\n");
    } 
    else
    {
        printf("Queue is not empty\n");
    }

    if(!isEmpty()) 
    {
        count = rear - front + 1;
        printf("Number of elements in queue: %d\n", count);
    } 
    else 
    {
        printf("Queue is empty\n");
    }

}

int *enqueue(int element) 
{
    int *ptr = Queue;
    if (rear == 19) 
    {
        printf("Queue is full\n");
        return ptr;
    } 
    else 
    {
        if (front == -1) 
        {
            front = 0;
        }
        rear++;
        Queue[rear] = element;
        return ptr;
    }
}

int *dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
        return Queue;
    } 
    else 
    {
        printf("Dequeued element: %d\n", Queue[front]);
        front++;
        return Queue;
    }
}

int peek() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
        return -1;
    } 
    else 
    {
        return Queue[front];
    }
}

int isEmpty() 
{
    return (front == -1 || front > rear);
}