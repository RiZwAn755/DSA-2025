#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int n =1000;
    int mini = 1e9;
    int tp = -1;
    vector<int>arr;
    Stack()
    {
        
       arr.resize(n);
    }
    Stack(int n)
    {
        
        arr.resize(n);
    }

    void push(int x)
    {
        if(tp != 1000)
        {
           arr[++tp] = x;
           mini = min(mini , x);
        }        
        
    }

    int top()
    {
        if(tp != -1)
        {
            return arr[tp];
        }
        return -1;
    }
    
    void pop()
    {
        if(tp!= -1)
        {
            tp--;

            for(int i=0 ; i < tp; i++)
            {
              mini = min(mini , arr[i]);
            }
        }
    }

    int minii()
    {
        return mini;
    }

    bool isEmpty()
    {
        return (tp == -1);
    }
    

};

int main()
{
    Stack a =  Stack();

    a.push(1);
    a.push(2);
    a.push(3);
    
    cout << a.top() << endl;

    a.pop();

    cout << a.minii() << endl;

     a.push(-1);
    cout << a.minii();

}