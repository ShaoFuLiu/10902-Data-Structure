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
        BaseStack():_top(-1),capacity(20) // initial state: top=-1, capacity=20
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
        BaseQueue():capacity(20),_front(-1),_rear(-1)
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
            // if (_rear + 1 == capacity)
            // {
            //     DoubleCapacity();
            // }
            _queue[++_rear] = item;
        };

        // Delete one element from front
        void pop()
        {
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

BaseQueue<string> * A = new BaseQueue<string>[100];
BaseStack<string> * B = new BaseStack<string>[100];

bool Check(BaseQueue<string> * A, char c, int L, int lp);

// TODO: Implement five types of command
void insert(int L)
{
    int lp; // Starting slot
    int e = 0;
    int len1 = 0;
    int len = 0;
    char c[L];
    cin >> lp >> c;
    bool Ck;
    bool CkCk;

    for (int i = 0; i < L; i++)
        if (A[i].empty())
            if (i != L-1)
                continue;
            else
                 CkCk = false;
        else
             CkCk = true;
//// A[i].rear()-1 = ith col top element position number
    if (CkCk)
    {
        for (int i = lp; i < lp + strlen(c); i++)
        {
            for (int j = A[i].rear()-1; j >= 0; j--)
            {
                if (A[i].top(j) != "*")
                {
                    len = j+1; // Should put position
                }
            }
            if (i == 0)
                len1 = len;
            if (len != len1)
            {
                Ck == false;
                break;
            }
            else
            {
                Ck == false;
                continue;
            }
        }
    }

    for (int i = 0; i < L; i++)
    {
        if(i >= lp && i < lp + strlen(c))
        {
            if (A[i].rear() == 0)
            {
                cout << "2";
                string s(1, c[e]);
                A[i].push(s);
                e++;
            }
            else
            {
                for (int j = 0; j <= A[i].rear()-1; j++)
                {
                    if (A[i].top(j) == "*")
                        A[i].top(j) = "@";
                }
                string s(1, c[e]);
                A[i].push(s);
                e++;

                if(Ck)
                {
                    cout << "3";
                    cout << "\nlen = " << len << endl;
                    string s(1, c[e]);
                    A[i].top(len) = s;
                    e++;
                }
            }
        }
        else
        {
            if (Ck)
            {
                cout << "4";
                A[i].push("*");
            }
            else
            {
                continue;
            }
        }
    }
    cout << endl;
};

void Print(int L, int c)
{
    for (int n = c; n >= 0; n--)
    {
        for (int i = 0; i < L; i++)
        {
            cout << A[i].top(n);
        }
        cout << endl;
    }
}

string first_row(int L, bool print = false) // It will return BOTTOM_ROW
{
    if (print == true)
    {

        cout << "BOTTOM_ROW" << endl;
        for (int i = 0; i < L; i++)
        {
            cout << A[i].top(0);
            B[i].push(A[i].top(0));
        }
    }
    return B[0].top();
};

void query(int L)
{
    string s;
    cin >> s;
    if (A[0].top(0) == s)
    {
        B[0].push(A[0].top(0));
        A[0].pop();
    }
};

void flush()
{
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

// // TODO:
//     // Constructor
//     BaseQueue();

//     // Destructor
//     ~BaseQueue();

//     // Check if the stack is empty
//     bool empty();

//     // Return the size of the queue
//     int size();

//     // Return the front element
//     T& front();

//     // Insert a new element at rear
//     void push(const T& item);

//     // Delete one element from front
//     void pop();

// private:
//     T* _queue;
//     int _front, _rear;
//     int capacity;
// };