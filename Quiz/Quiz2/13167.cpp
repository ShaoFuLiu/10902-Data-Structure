#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

struct Enode
{
    long x;
	// struct Enode *left;
	struct Enode *right;
}*head;

class circular_llist
{
    public:
        void House(long x);;
        void Bomb(long a, long d);
        void PrintFront();
        void PrintEnd();
        circular_llist()
        {
            head = NULL;
        }
};

int main()
{
    long position, x, a, d;
    int N;
    // long b = pow(10,10);
    circular_llist cl;
    cin >> N;
    while(N != 0)
    {
        string command;
        cin >> command;
        if (command == "House")
        {
            cin >> x ;
            // x = x+b;
            cl.House(x);
        }
        else if (command == "Bomb")
        {

            cin >> a >> d;
            // a = a+b;
            // d = d+b;
            cl.Bomb(a, d);
        }
        else if (command == "PrintFront")
        {
            cl.PrintFront();
        }
        else if (command == "PrintEnd")
        {
            cl.PrintEnd();
        }
        N--;
    }
    return 0;
}

void circular_llist::PrintFront()
{
    cout << "PrintFront" << endl;

    // long a = pow(10,10);
    long X;
    Enode* tempE = head;

    while (tempE != NULL)
    {
        X = tempE->x;
        cout << X << endl;
        tempE = tempE->right;
    }
    // cout << X << endl;
}

void circular_llist::PrintEnd()
{
    cout << "PrintEnd" << endl;

    // long a = pow(10,10);
    long X;
    vector<long> Xs;

    Enode* tempE = head;
    while (tempE != NULL)
    {
        X = tempE->x;
        Xs.push_back(X);
        tempE = tempE->right;
    }
    // Xs.push_back(X);

    while (!Xs.empty())
    {
        cout << Xs.back()<< endl;
        Xs.pop_back();
    }
}

void circular_llist::House(long x)
{
    struct Enode *tempE, *new_node;
    new_node = new(struct Enode);
    new_node->x = x;
    new_node->right = NULL;

    tempE = head; // headE

    if (head != NULL) // Iserted after
    {
        while (tempE->right != NULL)
        {
            // cout<<"A"<<endl;
            if (tempE->x < x)
            {
                if (tempE->right->x > x)
                {
                    // cout<<"B"<<endl;
                    new_node->right = tempE->right;
                    tempE->right = new_node;
                    break;
                }
                else
                {
                    // cout<<"C"<<endl;
                    tempE = tempE->right;
                    continue;
                }
            }
            else
            {
                // cout<<"D"<<endl;
                new_node->right = tempE;
                head = new_node;
                break;
            }
        }
        if (tempE->right == NULL)
        {
            if (tempE->x > x)
            {
                if(tempE == head)
                {
                    // cout<<"D"<<endl;
                    new_node->right = tempE;
                    head = new_node;
                }
            }
            else  // If insert at end
            {
                // cout<<"E"<<endl;
                new_node->right = NULL;
                tempE->right = new_node;
            }
        }
    }
    else// Create HeadNode
    {
        // cout<<"F"<<endl;
        struct Enode *temp;
        temp = new(struct Enode);
        temp->x = x;
        temp->right = NULL;
        head = temp;
    }
}

void circular_llist::Bomb(long a, long d)
{
    long less = a-d; // less is safe
    long bigger = a+d; // bigger is safe
    struct Enode *tempE;
    struct Enode *prev;
    bool yes = true;

    while(yes)
    {
        prev = NULL;
        tempE = head;

        // cout<<"HeadE != NULL/ Search Bomb along x\n";
        while(tempE != NULL)
        {
            cout<<"A"<<endl;
            if(tempE->x < less)
            {
                cout<<"B"<<endl;
                prev = tempE;
                tempE = tempE->right;
                if (tempE->right == NULL)
                {
                    yes = false;
                    break;
                }
            }
            else if (tempE->x > less && tempE->right->x < bigger)
            {
                cout<<bigger<<less<<"C"<<endl;

                prev->right = tempE->right;
                delete tempE;
                tempE = 0;
                yes = true;
                break;
            }
            else
            {
                cout<<"D"<<endl;
                yes = false;
                break;
            }
        }
    }
}