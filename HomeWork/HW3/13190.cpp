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
}*root;


class Tree
{
    public:
		int *arr;
		void Store_matrix(int value, int i, int j, int col);
		void Build_Tree(int y, int x);
        void add_Lnode(int value, int row, int col);
		void add_Rnode(int value, int row, int col);
		void add_Unode(int value, int row, int col);
		void add_Dnode(int value, int row, int col);
		int minPathSum();
        void Print(int row, int col);
        Tree()
        {
            root = NULL;
        }
};

int main(void)
{
	Tree tree;
	int row, col, value, x, y;
	cin >> row >> col;
	cin >> x >> y;
	int mat[row][col];

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> value;
			mat[i][j] = value;
			tree.Store_matrix(value, i, j, col);
		}
	}
	tree.Print(row, col);
	// tree.Build_Tree(y, x);
}

void Tree::Store_matrix(int value, int i, int j, int col)
{
	arr[i*col+j] = value;
}

void Tree::add_Lnode(int value, int row, int col)
{

}
void Tree::add_Rnode(int value, int row, int col)
{

}
void Tree::add_Unode(int value, int row, int col)
{

}
void Tree::add_Dnode(int value, int row, int col)
{

}
int Tree::minPathSum()
{

}
void Tree::Print(int row, int col)
{

}