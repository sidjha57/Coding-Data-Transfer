#include <iostream>
#include <stdio.h>
using namespace std;

class stack
{
    public:

    int size;
    int Top;
    int *s;
};

void empty_stack(stack S)
{
    if(S.Top == -1)
    {
        cout<<"Is empty\n";
        return ;
    }

    else if(S.Top == S.size - 1)
    {
        cout<<"Is full\n";
        return ;
    }

    return ;
    
}

stack push_in_stack(stack st, int x)
{
    if(st.Top < st.size - 1)
    {
        st.s[st.Top + 1] = x;
        st.Top = st.Top + 1;
        cout<<"element is pushed\n";
    }

    else if(st.Top == st.size - 1)
    {
        cout<<"Stack Overflow\n";
    }

    return st;
}

int pop_stack(stack& st)
{
    int x = -1;

    if(st.Top == -1)
    {
        cout<<"stack Underflow\n";
        
    }

    else
    {
        x = st.s[st.Top];
        st.Top--;
    }

    return x;
}

void display_stack(stack st)
{
    while(st.Top != -1)
    {
        cout<<st.s[st.Top]<<" ";
        st.Top--;
    }
}

int main()
{
    stack sta;
    int sz = 5;
    sta.size = sz;
    sta.s = new int[sz];
    sta.Top = -1;

    sta = push_in_stack(sta, 1);
    sta = push_in_stack(sta, 2);
    sta = push_in_stack(sta,3);
    
    display_stack(sta);
    cout<<"\n";
    cout<<sta.Top<<" ";
    cout<<pop_stack(sta)<<"\n";
    cout<<sta.Top<<" ";
    cout<<pop_stack(sta)<<"\n";
    
    return 0;

}