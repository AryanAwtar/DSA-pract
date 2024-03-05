//Bubble Sort
#include<stdio.h>

void bubblesort(int [],int);

int main()
{
    int arr[50];
    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    bubblesort(arr,10);
    
    printf("The sorted array is:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void bubblesort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//Selection sort
#include<stdio.h>

void selectionsort(int [],int);

int main()
{
    int arr[50];
    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    selectionsort(arr,10);
    
    printf("The sorted array is:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void selectionsort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

//Quick sort
#include<stdio.h>

void quicksort(int [],int,int);
int partition(int[],int,int);

int main()
{
    int arr[50];
    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    quicksort(arr,0,9);
    
    printf("The sorted array is:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void quicksort(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=p-1;

    for(int j=p;j<r;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return(i+1);
}

//Heap Sort
#include<stdio.h>

void heapsort(int [],int);
void maxheapify(int [],int,int);

int main()
{
    int arr[50];
    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    heapsort(arr,10);
    
    printf("The sorted array is:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void maxheapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        // swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--) {
        // swap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxheapify(arr, i, 0);
    }
}

//Merge sort
#include<stdio.h>

void mergesort(int [],int,int);
void merge(int[],int,int,int);

int main()
{
    int arr[50];
    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergesort(arr,0,9);
    
    printf("The sorted array is:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

void mergesort(int arr[],int p,int r)
{
    int q;
    if(p>=r)
        return;

    q=(p+r)/2;

    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);
}

void merge(int arr[],int p,int q,int r)
{
    int left,right,k;

    left=q-p+1;
    right=r-q;

    int arrLeft[left],arrRight[right];

    for(int i=0;i<left;i++)
        arrLeft[i]=arr[p+i];

    for(int j=0;j<right;j++)
        arrRight[j]=arr[q+j+1];

    int a=0;
    int b=0;
    k=p;

    while(a<left && b<right)
    {
        if(arrLeft[a]<=arrRight[b])
        {
            arr[k]=arrLeft[a];
            a++;
        }
        else
        {
            arr[k]=arrRight[b];
            b++;
        }

        k++;
    }

    while(a<left)
    {
        arr[k]=arrLeft[a];
        a++;
        k++;
    }

    while(b<right)
    {
        arr[k]=arrRight[b];
        b++;
        k++;
    }
}

//Sequential search
#include<stdio.h>

int sequentialsearch(int [],int,int);

int main()
{
    int arr[50],num,loc;

    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the number to be searched:\n");
    scanf("%d",&num);
    
    loc=sequentialsearch(arr,num,10);

    if(loc==-1)
        printf("Number not found");
    else
        printf("Number found in position %d",loc+1);

    return 0;
}

int sequentialsearch(int arr[],int num,int size)
{
    int loc;
    for(int i=0;i<size;i++)
    {
        if(num==arr[i])
        {
            loc=i;
            break;
        }
        loc=-1;
    }
    return loc;
}

//Binary search
#include<stdio.h>

int binarysearch(int [],int,int,int);

int main()
{
    int arr[50],num,loc;

    printf("Enter the 10 elements of the array:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the number to be searched:\n");
    scanf("%d",&num);
    
    loc=binarysearch(arr,num,0,9);

    if(loc==-1)
        printf("Number not found");
    else
        printf("Number found in position %d",loc+1);

    return 0;
}

int binarysearch(int arr[],int num,int start,int end)
{
    while(start<=end)
    {
        int mid=(start+end)/2;

        if (num==arr[mid])
            return mid; // Element found at index mid

        if (num<arr[mid])
            end=mid-1;

        else
            start=mid+1;
    }

    return -1; // Element not found
}

//Stack using array
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack* createStack();
int isFull(struct Stack*);
int isEmpty(struct Stack*);
void push(struct Stack*,int);
int pop(struct Stack*);

struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

int main()
{
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d removed from stack\n", pop(stack));
    printf("%d removed from stack\n", pop(stack));
    printf("%d removed from stack\n", pop(stack));

    return 0;
}

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = item;
    printf("%d added to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

//Infix to Postfix Expression
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();
int isOperand(char);
int precedence(char);
void infixToPostfix(char [],char []);

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char ch;
    for (i = j = 0; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
            while ((ch = pop()) != '(')
                postfix[j++] = ch;
        else
        {
            while (precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

//Evaluating postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack* newNode(int);
struct stack* push(struct stack*,int);
struct stack* pop(struct stack*);
int evaluatePostfix(char*);

int main()
{
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

struct stack* newNode(int data)
{
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;
    return new;
}

struct stack* push(struct stack* top, int data)
{
    struct stack* new = newNode(data);
    new->next = top;
    return new;
}

struct stack* pop(struct stack* top)
{
    if (top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
    struct stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int evaluatePostfix(char* postfix)
{
    struct stack* stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
            stack = push(stack, ch - '0');
        else
        {
            int operand2 = stack->data;
            stack = pop(stack);
            int operand1 = stack->data;
            stack = pop(stack);

            int result;
            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            stack = push(stack, result);
        }
    }
    return stack->data;
}

//Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int);
int dequeue();
void display();

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = item;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue[front++];
    if (front > rear)
    {
        front = rear = -1;
    }
    return item;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

//Single Linked List
#include <stdio.h>
#include <stdlib.h>

struct node* createNode(int);
struct node* insertAtBeginning(struct node*,int);
void insertAtEnd(struct node*,int);
struct node* deleteNode(struct node*,int);
void traverse(struct node*);

struct node 
{
    int data;
    struct node* next;
};

int main()
{
    struct node* q = NULL;

    q = insertAtBeginning(q, 10);
    insertAtEnd(q, 20);
    insertAtEnd(q, 30);

    printf("Linked list after creation:\n");
    traverse(q);

    q = insertAtBeginning(q, 5);
    printf("Linked list after insertion at beginning:\n");
    traverse(q);

    insertAtEnd(q, 40);
    printf("Linked list after insertion at end:\n");
    traverse(q);

    q = deleteNode(q, 20);
    printf("Linked list after deletion of node with data 20:\n");
    traverse(q);

    return 0;
}

struct node* createNode(int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;
    return new;
}

struct node* insertAtBeginning(struct node* q, int data)
{
    struct node* new = createNode(data);
    new->next = q;
    return new;
}

void insertAtEnd(struct node* q, int data)
{
    struct node* new = createNode(data);
    struct node* temp = q;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

struct node* deleteNode(struct node* q, int data)
{
    struct node* current = q;
    struct node* prev = NULL;

    if (current != NULL && current->data == data)
    {
        q = current->next;
        free(current);
        return q;
    }

    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        prev->next = current->next;
        free(current);
    }
    else
        printf("Node with data %d not found\n", data);
    return q;
}

void traverse(struct node* q)
{
    struct node* temp = q;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Double Linked List
#include <stdio.h>
#include <stdlib.h>

struct node* create(int);
struct node* insertAtBeg(struct node*,int);
void insertAtEnd(struct node*,int);
struct node* deleteNode(struct node*,int);
void display(struct node*);
void displayBackward(struct node*);

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

int main()
{
    struct node* q = NULL;

    q = insertAtBeg(q, 10);
    insertAtEnd(q, 20);
    insertAtEnd(q, 30);

    printf("Linked list after creation:\n");
    display(q);

    q = insertAtBeg(q, 5);
    printf("Linked list after insertion at beginning:\n");
    display(q);

    insertAtEnd(q, 40);
    printf("Linked list after insertion at end:\n");
    display(q);

    q = deleteNode(q, 20);
    printf("Linked list after deletion of node with data 20:\n");
    display(q);

    printf("Linked list in reverse order:\n");
    displayBackward(q);
    return 0;
}

struct node* create(int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

struct node* insertAtBeg(struct node* q, int data)
{
    struct node* new = create(data);
    if (q != NULL) {
        q->prev = new;
    }
    new->next = q;
    return new;
}

void insertAtEnd(struct node* q, int data)
{
    struct node* new = create(data);
    struct node* temp = q;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
}

struct node* deleteNode(struct node* q, int data)
{
    struct node* current = q;
    struct node* prev = NULL;

    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    if (current == q)
    {
        q = q->next;
        if (q != NULL)
        {
            q->prev = NULL;
        }
        free(current);
    }
    else if (current != NULL)
    {
        prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = prev;
        }
        free(current);
    }
    else
    {
        printf("Node with data %d not found\n", data);
    }
    return q;
}

void display(struct node* q)
{
    struct node* temp = q;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(struct node* q)
{
    struct node* temp = q;
    
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

//Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int);
struct node* insert(struct node*, int);
void inorderTraversal(struct node*);

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);

    return 0;
}

struct node* createNode(int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* insert(struct node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorderTraversal(struct node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

//Dijkstra's Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

int minDist(int [],int []);
void printSol(int []);
void dijkstra(int [][V],int);

int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
  
    dijkstra(graph, 0);
  
    return 0;
}

int minDist(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

void printSol(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int sptSet[V];
  
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
  
    dist[src] = 0;
  
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDist(dist, sptSet);
  
        sptSet[u] = 1;
  
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    printSol(dist);
}

//Floydd's Algorithm
#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int [][V]);
void floydWarshall(int [][V]);

int main()
{
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    printf("Floyd's Algorithm:\n");
    floydWarshall(graph);

    return 0;
}

void printSolution(int dist[][V])
{
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("INF\t");
            else 
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V])
{
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}
