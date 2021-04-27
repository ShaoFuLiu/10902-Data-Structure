#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// Structure of a ENode

class ENode
{
	public:
		int X, Y;
		ENode *up;
		ENode *down;
		ENode *left;
		ENode *right;
};

class HNode
{
	public:
		int N;
		HNode *next;
		ENode *up;
		ENode *down;
		ENode *left;
		ENode *right;
};

bool is_element_in_vector(vector<int> v, int element)
{
    vector<int>::iterator it;
    it = find(v.begin(),v.end(),element);
    if (it != v.end())
        return true;
    else
        return false;
}

int Check_XY(vector<int>& XY, int x, int y)
{
	bool X_exist = is_element_in_vector(XY, x);
	bool Y_exist = is_element_in_vector(XY, y);
    cout << "X_exist = " << X_exist << " Y_exist = " << Y_exist << endl;
	if (X_exist != true && Y_exist != true)
	{
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
		cout  << "Allready had HNode X and Y" << endl;
		return -1;
	}
}

void Creat_HNode(HNode** startH, int n)
{
	int N;
	if (n < N)
	{
		HNode* new_node = new HNode;
		new_node->next = (*startH);
		new_node->N = n;
	}
	else
	{
		HNode* s, ptr;
		s = (*startH)->next;
		// if (s == NULL)
		// {
		// 	HNode* new_node = new HNode;
		// 	new_node->next = NULL;
		// 	new_node->N = n;
		// 	new_node->right = new_node->left = new_node->down = new_node->up = NULL; // Initialized HNode
		// 	s->next = new_node;
		// 	break;
		// }
		while(s != NULL)
		{
			if (s == NULL)
			{
				HNode* new_node = new HNode;
				new_node->next = NULL;
				new_node->N = n;
				new_node->right = new_node->left = new_node->down = new_node->up = NULL; // Initialized HNode
				s->next = new_node;
				break;
			}
			else if (s->next->N > n)
			{
				HNode* q = (*startH)->next;
				HNode* new_node = new HNode;
				new_node->next = q;
				new_node->N = n;
				new_node->right = new_node->left = new_node->down = new_node->up = NULL; // Initialized HNode
				s->next = new_node;
				break;
			}
			else
			{
				N = s->next->N;
				s = s->next;
			}
		}
	}
}


// Function to insert at the end
void House(HNode** startH, vector<int> &XY, int x, int y)
{
	int Condition = Check_XY(XY, x, y);
	cout << Condition << endl;
	// switch (Condition)
	// {
	// 	case(1): // Creat Y and Insert XY
	// 		// cout << Condition << endl;
	// 		Creat_Y(&startH, Y)
	// 		Insert_X(&startH, X)
	// 		Insert_Y(&startH, Y)
	// 	case(2): // Creat X and Insert XY
	// 		// cout << Condition << endl;
	// 		Creat_X(&startH, X)
	// 		Insert_X(&startH, X)
	// 		Insert_Y(&startH, Y)
	// 	case(3): // Creat XY and Insert XY
	// 		// cout << Condition << endl;
	// 		Creat_X(&startH, X)
	// 		Creat_Y(&startH, Y)
	// 		Insert_X(&startH, X)
	// 		Insert_Y(&startH, Y)
	// }
	return;
}

void PrintFront(HNode** startH)
{
	HNode* s;
	s = (*startH);
	while(s->next != NULL)
	{
		cout<<s->N<<"->";
        s = s->next;
	}
	cout<<s->N<<endl;
}
void PrintEnd(HNode** startH);
void Boom(HNode** startH, int BX, int BY);

int main()
{
	HNode* startH = new HNode;
	startH->N = 0;
	startH->next = startH->right = startH->left = startH->down = startH->up = NULL; // Initialized HNode

	int N, x, y;
	vector<int> XY;
	XY.push_back(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		if (command  == "House")
		{
			cin >> x >> y;
			House(&startH, XY, x, y);
		}
		// if (command  == "Boom")
		// {
		// 	cin >> x >> y;
		// 	Boom(&start, &startH, x, y);
		// }
		// if (command  == "PrintFront")
		// {
		// 	PrintFront(&start ,&startH);
		// }
		// if (command  == "PrintEnd")
		// {
		// 	PrintEnd(&start ,&startH);
		// }
	}
	return 0;
}
