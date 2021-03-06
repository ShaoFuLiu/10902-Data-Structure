#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct Enode
{
    long x, y;
	struct Enode *up;
	struct Enode *down;
	struct Enode *left;
	struct Enode *right;
};
struct Hnode
{
    long N;
    struct Hnode *next;
	struct Enode *up;
	struct Enode *right;
    // struct Enode *down;
	// struct Enode *left;
}*last;
class circular_llist
{
    public:
        void create_Hnode(long N);
        void add_node(long N);
        void add_UR(long x, long y);
        void add_RU(long x, long y);
        void House(vector<long>& v, long x, long y);
        void Bomb_LR(long x, long y);
        void Bomb_DOWN(long x, long y);
        void Bomb_UP(long x, long y);
        void Bomb(long x, long y);
        void PrintFront();
        void PrintEnd();


        bool is_element_in_vector(vector<long> v, long element);
        long Check_XY(vector<long>& XY, long x, long y);
        circular_llist()
        {
            last = NULL;
        }
};

int main()
{
    long choice, element, position, x, y;
    long a = pow(10,10);
    int N;
    circular_llist cl;
    vector<long> XY;
	XY.push_back(0);
    cl.create_Hnode(0);
    cin >> N;
    while(N != 0)
    {
        string command;
        cin >> command;
        if (command == "House")
        {
            cin >> x >> y;
            x = x+a;
            y = y+a;
            cl.House(XY ,x, y);
        }
        else if (command == "Bomb")
        {
            cin >> x >> y;
            x = x+a;
            y = y+a;
            cl.Bomb(x, y);
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

void circular_llist::House(vector<long>& XY, long x ,long y)
{
    long Condition = Check_XY(XY, x, y);
    // cout << Condition << "\n\n";
    switch (Condition)
	{
        case 10: // Dont do anyting
            break;
        case 1: // Creat Y and Insert XY
			add_node(y);
            break;
		case 2: // Creat X and Insert XY
            add_node(x);
            break;
		case 3: // Creat XY and Insert XY
            add_node(x);
            add_node(y);
            break;
        case 4: // Creat X and Insert XY
            add_node(x);
            break;
	}
    add_UR(x, y);
}

void circular_llist::add_UR(long x, long y) // Insert element up then right
{
    // cout << "\n****Start add_UR****" << endl;

    struct Hnode *tempH;
    struct Enode *tempE;
    struct Enode *new_node;
    new_node = new(struct Enode);
    new_node->x = x;
    new_node->y = y;
    new_node->right = new_node->left = NULL;

    tempH = last->next;
    while (tempH->N != y) // Go to y number's Hnode
    {
        tempH = tempH->next;
    }

    // cout << "Add Hnode: " << tempH->N <<endl;
    if (tempH->right == NULL) // Creat HeadE
    {
        // cout<<"HeadE == NULL/ Creat HeadE"<<endl;
        tempH->right = new_node; // dont need left
    }
    else
    {
        // cout<<"HeadE != NULL/ ";
        tempE = tempH->right; // HeaderElement
        if (tempE->x > x) // Insert begin
        {
            // cout<<"Insert begin"<< endl;
            tempH->right = new_node;
            new_node->right = tempE; // Dont need to add left to tempH
            tempE->left = new_node;
        }

        else
        {
            // cout<<"\nHeadE->Enode";
            while (tempE->right != NULL) // not circular linked list, so we need to check boundary
            {
                cout << "A" << endl;
                if (tempE->x == x || tempE->right->x == x)
                {
                    // cout << "Error, can't insert same place twice.\n";
                    break;
                }
                if (tempE->x < x)
                {
                    if (tempE->right->x < x)
                    {
                        // cout<<"->Enode";
                        tempE = tempE->right;
                    }
                    else // Insert between
                    {

                        // cout << endl;
                        // cout << "Insert betweem : ";
                        // cout << tempE->x << " and " << tempE->right->x <<endl;
                        new_node->right = tempE->right;
                        tempE->right->left = new_node;
                        tempE->right = new_node;
                        new_node->left = tempE;
                        break;
                    }
                }
            }
            if (tempE->right == NULL) // Isert end
            {
                if (tempE->x == x)
                {
                    // cout << "Error, can't insert same place twice.\n";
                }
                else
                {
                    // cout<<endl;
                    // cout<<"Insert at end after Enode:"<<tempE->x<<endl;
                    tempE->right = new_node; // no left
                    new_node->left = tempE;
                }
            }
        }
    }
}

void circular_llist::Bomb(long x, long y)
{
    Bomb_LR(x, y);
    Bomb_DOWN(x, y);
    Bomb_UP(x, y);
}

void circular_llist::Bomb_LR(long x, long y)
{
    struct Hnode *tempH;
    struct Enode *tempE;
    struct Enode *prev;
    prev = NULL;

    tempH = last->next;
    // cout << "Bomb Hnode: " << tempH->N <<endl;
    ///////////// search bomb at row y along x
    while (tempH->N != y) // Go to y number's Hnode
    {
        tempH = tempH->next;
        if (tempH == last->next) // search for all Hnode once
            break;
    }
    if (tempH->N != y)
    {
        // cout<<"Bomb do noting/ Quit"<<endl;
    }
    else
    {
        // cout << "Bomb Hnode: " << tempH->N <<endl;
        if (tempH->right == NULL) // row y is not exist (Bomb = nothing)
        {
            // cout<<"HeadE == NULL/ Quit"<<endl;
        }
        else
        {
            // cout<<"HeadE != NULL/ Search Bomb along x\n";
            tempE = tempH->right; // HeaderElement
            while(tempE != NULL)
            {
                if(tempE->x == x-1) // bomb left has house and not sure right has too?
                {
                    if(tempE->right != NULL)
                    {
                        if (tempE->right->x != x+1) // Only to bomb left house
                        {
                            if (prev == NULL) // headE gone, replace headE to right
                            {
                                tempH->right = tempE->right;
                                delete tempE;
                                tempE = 0;
                                break;
                            }
                            else // bomb mid, replace it
                            {
                                tempE->right->left = prev;
                                prev->right = tempE->right;
                                delete tempE;
                                tempE = 0;
                                break;
                            }
                        }
                        else // bomb left and right house
                        {
                            if (prev == NULL) // headE and right gone, replace headE to right->right
                            {
                                if(tempE->right->right == NULL)
                                {
                                    tempH->right = NULL;
                                    delete tempE->right;
                                    delete tempE;
                                    tempE->right = 0;
                                    tempE = 0;
                                    break;
                                }
                                else
                                {
                                    tempH->right = tempE->right->right;
                                    delete tempE->right;
                                    delete tempE;
                                    tempE->right = 0;
                                    tempE = 0;
                                    break;
                                }
                            }
                            else // bomb mid, replace it
                            {
                                if(tempE->right->right == NULL)
                                {
                                    prev->right = NULL;
                                    delete tempE->right;
                                    delete tempE;
                                    tempE->right = 0;
                                    tempE = 0;
                                    break;
                                }
                                else
                                {
                                    tempE->right->right->left = prev;
                                    prev->right = tempE->right->right;
                                    delete tempE->right;
                                    delete tempE;
                                    tempE->right = 0;
                                    tempE = 0;
                                    break;
                                }
                            }
                        }
                    }
                    else // Only bomb left
                    {
                        if (prev == NULL) // headE gone, no house exist at row y
                        {
                            tempH->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else // end gone, replace prev->right to NULL
                        {
                            prev->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                }

                else if (tempE->x == x+1) // Only bomb right house
                {
                    if (prev == NULL)
                    {
                        if (tempE->right == NULL)// headE gone, nothing at row y
                        {
                            tempH->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            tempH->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                    else
                    {
                        if (tempE->right == NULL)// end gone, replace prev->right to NULL
                        {
                            prev->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            tempE->right->left = prev;
                            prev->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                }

                else if (tempE->x == x)
                {
                    if (prev == NULL)
                    {
                        if (tempE->right == NULL) // Only bomb x, and row y not exist
                        {
                            tempH->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            if (tempE->right->x == x+1)
                            {
                                if (tempE->right->right == NULL)
                                {
                                    tempH->right = NULL;
                                    delete tempE;
                                    tempE = 0;
                                    break;
                                }
                                else
                                {
                                    tempH->right = tempE->right->right;
                                    delete tempE->right;
                                    delete tempE;
                                    tempE->right = 0;
                                    tempE = 0;
                                    break;
                                }
                            }
                            else
                            {
                                tempH->right = tempE->right;
                                delete tempE;
                                tempE = 0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if (tempE->right->x != x+1)
                        {
                            tempE->right->left = prev;
                            prev->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            if (tempE->right->right != NULL)
                            {
                                tempE->right->right->left = prev;
                                prev->right = tempE->right->right;
                                delete tempE->right;
                                delete tempE;
                                tempE->right = 0;
                                tempE = 0;
                                break;
                            }
                            else
                            {
                                prev->right = NULL;
                                delete tempE;
                                tempE = 0;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    prev = tempE;
                    tempE = tempE->right;
                }
            }
        }
    }
}

void circular_llist::Bomb_DOWN(long x, long y)
{
    struct Hnode *tempH;
    struct Enode *tempE;
    struct Enode *prev;

    prev = NULL;

    tempH = last->next;
    ///////////// search bomb at row y-1 along x
    while (tempH->N != y-1) // Go to y number's Hnode
    {
        tempH = tempH->next;
        if (tempH == last->next) // search for all Hnode once
            break;
    }
    if (tempH->N != y-1)
    {
        // cout<<"Bomb do noting at down/ Quit"<<endl;
    }
    else
    {
        // cout << "Bomb Hnode: " << tempH->N <<endl;
        if (tempH->right == NULL) // row y is not exist (Bomb = nothing)
        {
            // cout<<"Bomb do noting at down/ Quit"<<endl;
        }
        else
        {
            // cout<<"HeadE != NULL/ Search Bomb y-1 along x\n";
            tempE = tempH->right; // HeaderElement
            while(tempE != NULL)
            {
                if(tempE->x == x)
                {
                    if(prev == NULL)
                    {
                        if(tempE->right == NULL)
                        {
                            tempH->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            tempH->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                    else
                    {
                        if(tempE->right != NULL)
                        {
                            tempE->right->left = prev;
                            prev = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            prev->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                }
                else
                {
                    prev = tempE;
                    tempE = tempE->right;
                }
            }
        }
    }
}

void circular_llist::Bomb_UP(long x, long y)
{
    struct Hnode *tempH;
    struct Enode *tempE;
    struct Enode *prev;

    prev = NULL;

    tempH = last->next;
    ///////////// search bomb at row y-1 along x
    while (tempH->N != y+1) // Go to y number's Hnode
    {
        tempH = tempH->next;
        if (tempH == last->next) // search for all Hnode once
            break;
    }
    if (tempH->N != y+1)
    {
        // cout<<"Bomb do noting at up/ Quit"<<endl;
    }
    else
    {
        // cout << "Bomb Hnode: " << tempH->N <<endl;
        if (tempH->right == NULL) // row y is not exist (Bomb = nothing)
        {
            // cout<<"Bomb do noting at up/ Quit"<<endl;
        }
        else
        {
            // cout<<"HeadE != NULL/ Search Bomb y+1 along x\n";
            tempE = tempH->right; // HeaderElement
            while(tempE != NULL)
            {
                if(tempE->x == x)
                {
                    // cout << "A" << endl;
                    if(prev == NULL)
                    {
                        // cout << "B" << endl;
                        if(tempE->right == NULL)
                        {
                            tempH->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            // cout << "D" << endl;
                            tempH->right = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                    else
                    {
                        // cout << "E" << endl;
                        if(tempE->right != NULL)
                        {
                            // cout << "F" << endl;
                            tempE->right->left = prev;
                            prev = tempE->right;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                        else
                        {
                            // cout << "G" << endl;
                            prev->right = NULL;
                            delete tempE;
                            tempE = 0;
                            break;
                        }
                    }
                }
                else
                {
                    // cout << "H" << endl;
                    prev = tempE;
                    tempE = tempE->right;
                }
            }
        }
    }
}

void circular_llist::PrintFront()
{
    cout << "PrintFront" << endl;

    long a = pow(10,10);
    long X, Y;
    Hnode* tempH = last->next;
    Enode *tempE;

    while (tempH != last)
    {
        tempE = tempH->right; // headE
        while(tempE != NULL)
        {
            X = tempE->x - a;
            Y = tempE->y - a;
            cout << "(" << X << "," << Y << ")" << endl;
            tempE = tempE->right;
        }
        tempH = tempH->next;
    }
    /// Print last
    tempE = tempH->right; // headE
    while(tempE != NULL)
    {
        X = tempE->x - a;
        Y = tempE->y - a;
        cout << "(" << X << "," << Y << ")" << endl;
        tempE = tempE->right;
    }
}

void circular_llist::PrintEnd()
{
    cout << "PrintEnd" << endl;

    long a = pow(10,10);
    long X, Y;
    vector<long> Xs, Ys;

    Hnode* tempH = last->next;
    Enode *tempE;

    /// Store
    while (tempH != last)
    {
        tempE = tempH->right; // headE
        while(tempE != NULL)
        {
            X = tempE->x - a;
            Y = tempE->y - a;
            Xs.push_back(X);
            Ys.push_back(Y);
            // cout << "(" << X << "," << Y << ")" << endl;
            tempE = tempE->right;
        }
        tempH = tempH->next;
    }
    /// Store last
    tempE = tempH->right; // headE
    while(tempE != NULL)
    {
        X = tempE->x - a;
        Y = tempE->y - a;
        Xs.push_back(X);
        Ys.push_back(Y);
        // cout << "(" << X << "," << Y << ")" << endl;
        tempE = tempE->right;
    }
    /// Print last
    while (!Xs.empty())
    {
       cout << "(" << Xs.back() << "," << Ys.back() << ")" << endl;
       Xs.pop_back();
       Ys.pop_back();
    }
}

void circular_llist::add_node(long N)
{
    // cout<<"\nGG"<<endl;
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct Hnode *tempH;
    tempH = last->next; // head

    struct Hnode *new_node;
    new_node = new(struct Hnode); // Iserted after Hnode
    new_node->N = N;
    new_node->right = new_node->up = NULL;

    while (tempH != last)
    {
        // cout<<"A"<<endl;
        if (tempH->N < N)
        {

            if (tempH->next->N > N)
            {
                // cout<<"B"<<endl;
                new_node->next = tempH->next;
                tempH->next = new_node;
                break;
            }
            else
            {
                // cout<<"C"<<endl;
                tempH = tempH->next;
                continue;
            }
        }
        // Insert back;
    }
    if (tempH == last) // If insert at end
    {
        // cout<<"GGII"<<endl;
        new_node->next = last->next;
        tempH->next = new_node;
        last = new_node;
    }
}

void circular_llist::create_Hnode(long N)
{
    struct Hnode *temp;
    temp = new(struct Hnode);
    temp->N = N;
    temp->right = temp->up = NULL;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        cout << "wrong!!!!!" << endl;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

bool circular_llist::is_element_in_vector(vector<long> v, long element)
{
    vector<long>::iterator it;
    it = find(v.begin(),v.end(),element);
    if (it != v.end())
        return true;
    else
        return false;
}

long circular_llist::Check_XY(vector<long>& XY, long x, long y)
{
	bool X_exist = is_element_in_vector(XY, x);
	bool Y_exist = is_element_in_vector(XY, y);
    // cout << "X_exist = " << X_exist << " Y_exist = " << Y_exist << endl;
	if (X_exist != true && Y_exist != true)
	{
        if(x == y)
        {
            XY.push_back(x);
            return 4;
        }
        XY.push_back(x);
		XY.push_back(y);
		return 3;
	}
	else if (X_exist != true && Y_exist == true)
	{
		XY.push_back(x);
		return 2;
	}
	else if (X_exist == true && Y_exist != true)
	{
		XY.push_back(y);
		return 1;
	}
	else
	{
		// cout  << "Allready had HNode X and Y" << endl;
		return 10;
	}
}
