#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

struct node
{
	int N;
    struct node *next;
	struct node *up;
	struct node *down;
	struct node *left;
	struct node *right;
}*Header;

class HNode
{
	public:
		// int N;
		// HNode *next;
		// ENode *up;
		// ENode *down;
		// ENode *left;
		// ENode *right;
		void Creat_HNode(int n);
		void PrintFront();
		HNode()
		{
			Header->next = NULL;
			// Header->N = 0;
			Header->right = Header->left = Header->down = Header->up = NULL;
		}
};

// class ENode
// {
// 	public:
// 		int X, Y;
// 		ENode *up;
// 		ENode *down;
// 		ENode *left;
// 		ENode *right;
// };
void HNode::Creat_HNode(int n)
{
	struct node *temp, *s;
	temp = new(struct node);
	s = new(struct node);
	int N = Header->N;
	if (n < N)
	{
		cout << "ADD BEGIN" << endl;
		HNode* new_node = new HNode;
		new_node->next = startH;
		new_node->N = n;
		startH = new_node;
	}
	else
	{
		cout << "ADD AFTER" << endl;
		HNode *current;
		current = startH;
		while(current->next != NULL)
		{
			if (current->next->N > n && current->N < n)
			{
				cout << "add between" << endl;
				HNode* q = current->next;
				HNode* new_node = new HNode;
				new_node->N = n;
				new_node->next = q;
				new_node->right = new_node->left = new_node->down = new_node->up = NULL; // Initialized HNode
				current = new_node;
				break;
			}
			else
				current = current->next;
			if (current->next == NULL)
			{
				cout << "add end" << endl;
				HNode* new_node = new HNode;
				new_node->next = NULL;
				new_node->N = n;
				new_node->right = new_node->left = new_node->down = new_node->up = NULL; // Initialized HNode
				current->next = new_node;
				break;
			}
		}
	}
}
// void HNode::PrintFront()
// {
// 	cout << "PrintFront" << endl;
// 	HNode* current;
// 	current = startH;
// 	while(current->next != NULL)
// 	{
// 		cout << current->N << "->";
//         current = current->next;
// 	}
// 	cout<< current-> N <<endl;
// }

int main()
{
	HNode* startH;
	// bool a = startH->next==NULL;
	// startH->next = NULL;
	// startH->N = 0;
	// startH->right = startH->left = startH->down = startH->up = NULL;
	// int N;
	// cin >> N;
	// while(0 < N)
	// {
	// 	int x;
	cin >> x;
	startH.Creat_HNode(x);
	// 	// cout << startH->next->N << endl;
	// 	// startH = startH->next;
	// 	N--;
	// }
	// startH.PrintFront();
}