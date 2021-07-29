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
            cout << "QUEUE PUSH" << endl;
            // if (_rear + 1 == capacity)
            // {
            //     DoubleCapacity();
            // }
            _queue[++_rear] = item;
        };

        // Delete one element from front
        void pop()
        {
            cout << "QUEUE POP" << endl;
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
BaseStack<string> * B = new BaseStack<string>[1];

// TODO: Implement five types of command
void insert(int L)
{
    int lp; // Starting slot
    int e = 0;
    int len = 0;
    int len2 = 0;
    int len3 = 0;
    char c[L];
    cin >> lp >> c;
    bool Ck; // 檢查要不要補@
    bool CkCk; //檢查 檢查要不要補@

    for (int i = 0; i < L; i++)
    {
        if (A[i].empty())
        {
            if (i != L-1)
                continue;
            else
                CkCk = false;
        }
        else
        {
            CkCk = true; // 代表那排有東西
            break;
        }
    }

    if (CkCk)
    {
        for (int i = lp; i < lp + strlen(c); i++)
        {
            for (int j = A[i].rear()-1; j >= 0; j--)
            {
                if (A[i].rear()-1 == 0)
                {
                    Ck = false;
                    len2 = 1;
                    break;
                }
                else
                {
                    if (A[i].top(j) != " ")
                    {
                        // cout << "\nj+1 = " << j+1;
                        len2 = j+1;
                        if (len2-1 == A[i].rear()-1)
                        {
                            Ck = false;
                            break;
                        }
                        if (i == lp)
                            len3 = len2;
                        break;
                    }
                }
            }
            // cout << "\nlen3 = " << len3 << " \nlen2 = " << len2;
            if (i != lp)
            {
                if (len3 - len2 != 0)
                {
                    // cout << "\nlen3 != len2 " << endl;
                    len = 1;
                    break;
                }
                else
                    len = 0;
                    continue;
            }
            else
            {
                continue;
            }

            // cout << "\nlen = " << len << endl;
        }
        if (len == 0)
            Ck = true;
        else
            Ck = false;
    }

    for (int i = 0; i < L; i++)
    {
        if(i >= lp && i < lp + strlen(c))
        {
            if (A[i].rear() == 0)
            {
                string s(1, c[e]);
                A[i].push(s);
                e++;
            }
            else
            {
                if(Ck)
                {
                    string s(1, c[e]);
                    A[i].top(len2) = s;
                    e++;
                }
                else
                {
                    for (int j = 0; j <= A[i].rear()-1; j++)
                    {
                        if (A[i].top(j) == " ")
                            A[i].top(j) = "@";
                    }
                    string s(1, c[e]);
                    A[i].push(s);
                    e++;
                }
            }
        }
        else
        {
            if (Ck)
                continue;
            else
                A[i].push(" ");
        }
    }
};

void Print(int L, int c)
{
    for (int n = 4; n >= 0; n--)
    {
        for (int i = 0; i < L; i++)
        {
            if (A[i].empty())
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
    int l = 0;
    string s;
    for (int i = 0; i <L; i++)
    {
        if (A[i].empty())
        {
            l++;
        }
    }
    if (l == L)
    {
        print == false;
    }
    else
    {
        cout << "BOTTOM_ROW" << endl;
        for (int i = 0; i < L; i++)
        {
            if (A[i].top(0) == " ")
            {
                cout << "~";
                s = s + "~";
                continue;
            }

            cout << A[i].top(0);
            s = s + A[i].top(0);
        }
        cout << endl;
    }
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
        str1 += A[i].top(0);
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
    int N = B[0].size();
    cout << "FLUSH" << endl;
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
    BaseQueue<string> * A = new BaseQueue<string>[100];
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