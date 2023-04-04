#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

#define size 10

class stack
{

private:

    int top;
    int array[size];

public:

    stack()
    {
        top = -1;
    }

    int pop();

    void push(int);

    bool isFull();

    bool isEmpty();

    int StackTop();

    void Display();
};


bool stack::isEmpty()
{

    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::isFull()
{
    if (top == (size - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stack::pop()
{

    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        int temp = array[top];
        top--;
        return temp;
    }
}

void stack::push(int item)
{

    if (isFull())
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        array[top] = item;
    }
}

int stack::StackTop()
{

    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        return array[top];
    }
}

void stack::Display()
{
    int i; 
    for(i=(top); i>=0; i--)
        cout<<array[i]<<" ";
    cout<<endl;
}


struct Node {
   int data;
   struct Node *next;
};
struct Node* top = NULL;

void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
int pop() {

   if(top==NULL){
   cout<<"Stack Underflow"<<endl;
   return 0;
   }
   else {
      int temp=top->data;
      top = top->next;
      return temp;
   }
}
void display() {

   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}



int main()
{
    //stack s;
    clock_t begin  = clock();
    
    for(int i=1;i<11;i++){

        push(rand()%100);

    }

    display();
    for(int i=0;i<5;i++){
        int val=pop();
    }
    display();

    for(int i=1;i<5;i++){

    
        push(rand()%100);

    }
    display();
    clock_t end=clock();
    cout<<"Time taken is : "<<(end- begin)<<" milliseconds"<<"\n"<<endl;


    
}