#include <bits/stdc++.h>

using namespace std;

struct node
{
	int value, col, row;
	bool passed = false;
	struct node *up;
	struct node *down;
	struct node *left;
	struct node *right;
};

void Creat_root(node &root, int value, int x, int y)
{
	root.value = value;
	root.row = y;
	root.col = x;
	root.left  = NULL;
	root.right = NULL;
	root.up    = NULL;
	root.down  = NULL;
}

void add_Lnode(node &root, int value, int row, int col)
{
	root.left->value = value;
	root.left->row = row;
	root.left->col = col;
	root.left->left  = NULL;
	root.left->right = NULL;
	root.left->up    = NULL;
	root.left->down  = NULL;
}
void add_Rnode(node &root, int value, int row, int col)
{

}
void add_Unode(node &root, int value, int row, int col)
{

}
void add_Dnode(node &root, int value, int row, int col)
{

}
int minPathSum(node &root)
{

}
void Print(node &root, int row, int col)
{

}

int main(void)
{
	node root;
	int row, col, value, Rx, Ry;
	cin >> row >> col;
	cin >> Rx >> Ry;
	int mat[row][col];

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> value;
			mat[i][j] = value;
		}
	}

	Creat_root(root, mat[Ry][Rx], Rx, Ry);
	cout << root.value << endl;

	while(Rx-1 > 0 || mat[Ry][Rx-1] != 0)
	{
		cout << "A" << endl;
		Rx = Rx-1;
		cout << Rx-1 << endl;
		add_Lnode(root, mat[Ry][Rx], row, col);
	}
	cout << root.left->value << endl;
}