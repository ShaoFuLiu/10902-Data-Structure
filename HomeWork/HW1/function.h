#ifndef FUNCTION_H_
#define FUNCTION_H_

// #include <string>
#include <iostream>
using namespace std;

// TODO: Implement all member functions in BaseStack
template <class T>
class BaseStack
{
    public:
        // Constructor
        BaseStack();

        // Destructor
        ~BaseStack();

        // Check if the stack is empty
        bool empty()
        {
            if(capacity == 0)
                return true;
            else
                return false;
        };

        // Return the size of the _stack
        int size()
        {
            return ++_top;
        };

        // Return the top element
        T& top()
        {
            return _stack[_top];
        };

        // Insert a new element at top
        void push(const T& item)
        {
            // if(_top == capacity – 1) // Create more capacity of _stack
            // {
            //     ChangeSize1D(_stack, capacity, 2*capacity);
            //     capacity *= 2;
            // }
            _stack [ ++_top ] = item;
            ++capacity;
        };

        // Delete one element from top
        void pop()
        {
            if(empty())
            {
                cout << "Stack is empty. Cannot delete." << endl;
            }
            else
            _stack [ _top-- ].~T(); // Delete the element
            capacity--;
        };

    private:
        T* _stack;
        int _top = -1;
        int capacity = 0;
};

// TODO: Implement five types of command
void insert(int L)
{
    int lp; // Starting slot
    string s;
    cin >> lp >> s;
    // cout << lp << s << endl;
    BaseStack<int> Stack;
    Stack.pop();
};

string first_row(int L, bool print = false)
{

}; // It will return BOTTOM_ROW

void query(int L)
{

};

void flush()
{

};

void reset(int L)
{

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

// // TODO: Implement all member functions in BaseQueue
// template < class T >
// class BaseQueue
// {
// public:
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