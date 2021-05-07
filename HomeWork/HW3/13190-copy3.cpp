#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
	struct Node* down;
    struct Node* right;
	struct Node* up;
    // val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        down = NULL;
		right = NULL;
		up = NULL;
    }
};

void Print(Node *root, int X, int Y)
{
	struct Node* current;
	current = root;
	cout << mat[Y][X];
	while (current->right != NULL)
	{
		cout << "->" << mat[Y][X+1];
		current = current->right;
		X = X+1;
	}
	cout << endl;
}

void add_L(Node *root, int value)
{
	struct Node* new_node = new Node(value);
	root->left = new_node;
}

void add_R(Node *root, int value)
{
	struct Node* new_node = new Node(value);
	root->right = new_node;
}

int main(void)
{
	int row, col, value, Rx, Ry;
	cin >> row >> col;
	cin >> Rx >> Ry;
	int mat[row][col];

	for(int i = 0; i < row; i++)    							// Store input matrix
	{
		for(int j = 0; j < col; j++)
		{
			cin >> value;
			mat[i][j] = value;
		}
	}

	struct Node* root = new Node(mat[Ry][Rx]);  				// Create root node
	struct Node* currentL, *currentD, *currentR, *currentU, *current;
	current = root;
	currentL = root;
	currentD = root;
	currentR = root;
	currentU = root;
	int currentX = Rx;
	int currentY = Ry;

	while (mat[currentY][currentX+1] != 0)
	{
		struct Node* new_nodeR = new Node(mat[currentY][currentX+1]);
		if (mat[currentY-1][currentX+1] != 0)
		{
			while()
			{
				struct Node* new_nodeU = new Node(mat[currentY-1][currentX+1]);
				current->right->up = new_nodeU;
			}

		}
		if (mat[currentY+1][currentX+1] != 0)
		{
			while()
			{
				struct Node* new_nodeU = new Node(mat[currentY+1][currentX+1]);
				current->right->down = new_nodeD;
			}

		}
		currentR->right = new_nodeR;
		currentX = currentX+1;
	}

	// if (mat[Ry+1][Rx] != 0)
	// {
	// 	add_D();
	// }

	// if (mat[Ry-1][Rx] != 0)
	// {
	// 	add_U();
	// }
}