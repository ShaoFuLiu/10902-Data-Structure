#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string.h>
#include <string>
#include <iostream>
using namespace std;

// TODO: Implement all member functions in BaseStack
template <class T>
class BaseStack
{
    public:
        // Constructor
        BaseStack():_top(-1),capacity(50) // initial state: top=-1, capacity=20
        {
            _stack = new T[capacity];
        };

        // Destructor
        ~BaseStack() {};

        // Check if the stack is empty
        bool empty()
        {
            return (_top + 1 == 0?true:false);
        };

        // Return the size of the _stack
        int size()
        {
            return _top + 1;
        };

        // Return the top element
        T& top()
        {
            return _stack[_top];
        };

        void DoubleCapacity()
        {
            capacity *= 2;                            // double capacity
            T *newStack = new T[capacity];            // create newStack

            for (int i = 0; i < capacity/2; i++)      // copy element to newStack
            {
                newStack[i] = _stack[i];
            }

            delete [] _stack;                         // release the memory of stack
            _stack = newStack;                        // redirect stack to newStack
        };

        // Insert a new element at top
        void push(const T& item)
        {
            if(_top == capacity-1) // if stack is full, double the capacity
            {
                DoubleCapacity();
            }
            _stack[++_top] = item;
        };

        // Delete one element from top
        void pop()
        {
            if(empty())
            {
                cout << "Stack is empty. Cannot delete." << endl;
            }
            else
            {
                _stack[_top--].~T(); // Delete the element
                capacity--;
            }
        };

    private:
        T* _stack;
        int _top;
        int capacity;
};

// TODO: Implement all member functions in BaseQueue
template <class T>
class BaseQueue
{
    public:
        // Constructor
        BaseQueue():capacity(100),_front(-1),_rear(-1)
        {
            _queue = new T[capacity];
        };

        // Destructor
        ~BaseQueue() {};

        // Check if the stack is empty
        bool empty()
        {
            return (_front  == _rear);
        };

        // Return the top element
        T& top(int i)
        {
            return _queue[_front + 1 + i];
        };

        // Return the size of the queue
        int size()
        {
            return (_rear - _front);
        };

        // Return the front element
        T& front()
        {
            if (empty())
            {
                cout << "Queue is empty.\n";
            }

            return _queue[_front+1];
        };

        // Return the latest element position
        int rear()
        {
            return _rear+1;
        };

        // Insert a new element at rear
        void push(const T& item)
        {
            // cout << "QUEUE PUSH" << endl;
            // if (_rear + 1 == capacity)
            // {
            //     DoubleCapacity();
            // }
            _queue[++_rear] = item;
        };

        // Delete one element from front
        void pop()
        {
            // cout << "QUEUE POP" << endl;
            if (empty())
            {
                cout << "Queue is empty.\n";
                return;
            }
            _front++;
        };

    private:
        T* _queue;
        int _front, _rear;
        int capacity;
};

BaseQueue<string> * A = new BaseQueue<string>[10];
BaseStack<string> * B = new BaseStack<string>[1];

// TODO: Implement five types of command
void insert(int L)
{
    int lp; // Starting slot
    char c[L];
    cin >> lp >> c;
    int pos = 0;
    for (int i = lp; i < lp+strlen(c); i++)
    {
        if (A[i].size() > pos)
            pos = A[i].size();
        else
            continue;
    }

    int lc = 0;
    for (int i = lp; i < lp+strlen(c); i++)
    {
        for (int j = A[i].rear(); j < pos; j++)
        {
            if (A[i].top(j) != "")
                continue;
            if (A[i].top(j) == "")
                A[i].push("@");
        }
        string s(1, c[lc]);
        // cout << s;
        A[i].push(s);
        lc += 1;
    }
};

void Print(int L, int c)
{
    for (int n = 4; n >= 0; n--)
    {
        for (int i = 0; i < L; i++)
        {
            if (A[i].top(n) == "")
                cout << " ";
            else
                cout << A[i].top(n);
        }
        cout << endl;
    }
    cout << "Each size:" << endl;
    for (int i = 0; i < L; i++)
    {
        cout << A[i].size();
    }
    cout << endl;
};

string first_row(int L, bool print = false) // It will return BOTTOM_ROW
{
    cout << "BOTTOM_ROW" << endl;
    int l = 0;
    string s;
    for (int i = 0; i <L; i++)
    {
        if (A[i].empty())
        {
            l++;
        }
    }

    for (int i = 0; i < L; i++)
    {
        if (A[i].top(0) == "")
        {
            cout << "~";
            s = s + "~";
            continue;
        }

        cout << A[i].top(0);
        s = s + A[i].top(0);
    }
    cout << endl;

    return s;
};

void query(int L)
{
    char c[L];
    cin >> c;
    string str1;
    string str2(c);

    for (int i = 0; i < L; i++)
    {
        if (A[i].top(0) != "")
            str1 += A[i].top(0);
        else
            str1 += " ";
    }
    int a = str1.find(str2);
    if (a != -1)
    {
        B[0].push(str2);
        for (int i = a; i < a + str2.length(); i++)
        {
            // A[i].push(" ");
            A[i].pop();
        }
    }
};

void flush()
{
    cout << "FLUSH" << endl;
    int N = B[0].size();
    for (int i = 0; i < N; i++)
    {
        cout << B[0].top() << endl;
        B[0].pop();
    }
};

void reset(int L)
{
    delete [] A;
    delete [] B;
    BaseQueue<string> * A = new BaseQueue<string>[10];
    BaseStack<string> * B = new BaseStack<string>[1];
};

// The codes bellow prevent you from importing C++ containers.
// Nothing needed to be implemented below.
// Do not modify the codes below.
#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif