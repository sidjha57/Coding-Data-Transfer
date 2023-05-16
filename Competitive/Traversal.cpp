#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *lc;
    Node *rc;

    /*Node(int val)
    {
        data = val;
        lc = NULL;
        rc = NULL;
    }*/

   
};

class Queue
{
    public:
    int size;
    int front;
    int last;
    Node *a[10];

    public:

    Queue(){size = 10; front = -1, last = -1;};

};

void Display_queue(Queue q)
{
    for(int i = 0; i <= q.last; i++)
    {
        cout<<q.a[i]<<" ";
    }
}

int is_emp(Queue q)
{
    if(q.front == -1 && q.last == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }

    return 0;
}

int is_full(Queue q)
{
    if(q.last == q.size - 1 && q.front == 0)
    {
        return 1;
    }

    return 0;
}

void enqueue(Queue &q, Node* x)
{
    if(is_emp(q))
    {
        q.front = 0;
        q.last = 0;
        q.a[0] = x;
         
    }

    else if(is_full(q))
    {
        cout<<"Queue Overflow\n";
    }

    else
    {
        q.a[q.last + 1] = x;
        q.last++;
    }
}

Node* dequeue(Queue &q)
{
    Node* p = q.a[q.last] ;
    q.last = q.last - 1;

    return p; 
}

void Preorder(Node*s)
{
    if(!s) return;
    cout << s->data << " ";                                     
    Preorder(s->lc);
    Preorder(s->rc);
    
}

void Inorder(Node*s)
{
    if(!s) return;
    
    Inorder(s->lc);
    cout<<s->data<<" ";
    Inorder(s->rc);
    
}


int main()
{
    //int A[7] = {1,2,3,4,5,6,7};
    Node *root = new Node[1];
    int a;
    cout<<"Enter root of the tree: ";
    cin>>a;
    root->data = a;
    root->lc = NULL;
    root->rc = NULL;
    Queue Q;
    enqueue(Q, root);
    int i = 1;
    while(!(is_emp(Q)))
    {
        int l;
        cout<<"enter left child: "<<Q.a[Q.last]<<" ";
        cin>>l;
        if(l != -1)
        {
            Node*p = dequeue(Q);
            Node *temp = new Node;
            temp->data = l;
            temp->lc = NULL;
            temp->rc = NULL;
            p->lc = temp;
            enqueue(Q, p->lc);
        }

        // for right child 

        int r;
        cout<<"Enter right child: "<<Q.a[Q.last]<<" ";
        cin>>r;
        
        
        

        if(r != -1) {
            Node *p = dequeue(Q);
            Node *temp = new Node;
            temp->data = r;
            temp->lc = NULL;
            temp->rc = NULL;
            p->rc = temp;
            enqueue(Q, p->rc);
        }

        else if(r == -1 && l == -1)
        {
            break;
        }
 
    }
    cout<<"Printing Preorder Form: ";
    Preorder(root);
    cout<<"\nPrinting Inorder Form: ";
    Inorder(root);

    return 0;

}