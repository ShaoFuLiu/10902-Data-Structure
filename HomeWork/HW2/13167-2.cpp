#include<iostream>

using namespace std;

// Structure of a Node
class Node
{
	public:
		int col, row;
		Node *up;
		Node *down;
		Node *left;
		Node *right;
};

class HNode
{
	public:
		int N;
		HNode *next;
		HNode *up;
		HNode *down;
		HNode *left;
		HNode *right;
};

void InsertRow(Node** start, HNode** startH, int row)
{
	Node* new_node = new Node;
	new_node->row = row;
	new_node-> = row;
	(*startH)->next = new_node;
}

void InsertCol(Node** start, HNode** startH, int col)
{

}
// Function to insert at the end
void House(HNode** startH, int col, int row)
{
	Node* new_node = new Node;
	new_node->row = row;
	new_node->col = col;
	new_node->right = new_node->left = new_node;
	new_node->up = new_node->down = new_node;

	for (int i = 0; i < col; i++)
	{
		// Doing insert allong col
		// InsertCol(startH, (*start)->col);
		(*startH)->next = (*startH);
	}
	for (int j = 0; j < row; j++)
	{
		// Doing insert allong row
		// InsertRow(startH, (*start)->row);
		(*startH)->down = (*start);
	}
	return;


}

void PrintFront(Node** start, HNode** startH);
void PrintEnd(Node** start, HNode** startH);
void Boom(Node** start, HNode** startH, int col, int row);

int main()
{
	HNode* startH = new HNode;
	startH->row = 0;
	startH->col = 0;
	startH->right = startH->left = startH->up = startH->down = NULL;

	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		if (command  == "House")
		{

			cin >> x >> y;
			House(&startH, x, y);
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
