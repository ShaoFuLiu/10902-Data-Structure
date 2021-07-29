#include <string.h>
#include <string>
#include <iostream>
using namespace std;

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

int main(void)
{
    BaseQueue<string> * A = new BaseQueue<string>[100];
    if (A[1].top(1) == "")
        cout << "NO" << endl;
    cout << A[1].size();
    char c[10];
    cin >> c;
    for (int i = 0; i < 10; i++)
    {
        string s(1, c[i]);
        cout << s;
    }
    cout << endl;
}
