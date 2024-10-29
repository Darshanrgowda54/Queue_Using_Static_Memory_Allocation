#include <stdio.h>
#define Max 20

int queue[Max];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == Max - 1)
    {
        printf("Queue overflow.\n", value);
    }
    else
    {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d Dequeued from the queue\n", queue[front++]);
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1)
    {
        printf("\nChoose an operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

