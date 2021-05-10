#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
	int val;
	struct node *left;
	struct node *right;
	struct node *up;
	struct node *down;
}*root;

class Tree
{
    public:
		int col, row;
		vector<int> Vals, Sums;
		vector<string> Derc;
		void Build(vector<vector<int>> mat, int Rx, int Ry);
        void add_L(vector<vector<int>> mat, node *temp, int x, int y);
		void add_R(vector<vector<int>> mat, node *temp, int x, int y);
		void add_U(vector<vector<int>> mat, node *temp, int x, int y);
		void add_D(vector<vector<int>> mat, node *temp, int x, int y);
		void minPathSum(); 												// return min path value

        Tree(int value)
        {
			struct node *tempH = new(struct node);
    		tempH->val = value;
			tempH->left  = NULL;
			tempH->right = NULL;
			tempH->up 	 = NULL;
			tempH->down  = NULL;
			root = tempH;
        }
};

int main(void)
{
	int row, col, value, Rx, Ry;
	cin >> row >> col;
	cin >> Rx >> Ry;
	vector<int> test(row),test2;
	for(int i = 0; i < row; i++)
	{
		test[i] = i;
	}

	test.erase(test.begin());
	cout << "vec capacity = " << test.capacity() << endl ;
	// test.reserve(test.size() + 10);
	// cout << "vec capacity = " << test.capacity() << endl ;
	test.clear();
	vector<int>().swap(test[);
	cout << "vec capacity = " << test.capacity() << endl ;
	for(int i = 0; i < test.size(); i++)
	{
		cout << test[i];
	}
 	cout << endl;
}

void Tree::Build(vector<vector<int>> mat, int Rx, int Ry)
{

	if (Rx-1 >= 0 && mat[Ry][Rx-1] != 0)					// left
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_L(mat, root->left, Rx-1, Ry);
		Derc.push_back("/");
	}
	if (Rx+1 <= col && mat[Ry][Rx+1] != 0)					// right
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_R(mat, root->right, Rx+1, Ry);
		Derc.push_back("/");
	}
	if (Ry-1 >= 0 && mat[Ry-1][Rx] != 0)					// up
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_U(mat, root->up, Rx, Ry-1);
		Derc.push_back("/");
	}
	if (Ry+1 <= row && mat[Ry+1][Rx] != 0)					// down
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_D(mat, root->down, Rx, Ry+1);
		Derc.push_back("/");
	}
}

void Tree::add_L(vector<vector<int>> mat, node *temp, int x, int y)
{
	Derc.push_back("L");
	Vals.push_back(mat[y][x]);
	struct node *tempN = new (struct node);
	tempN->val = mat[y][x];
	tempN->left = NULL;
	tempN->up = NULL;
	tempN->down = NULL;
	temp = tempN;
	bool Trav = false;

	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(mat, temp->left, 	x-1, y);
	}
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(mat, temp->up, x, y-1);
	}
	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(mat, temp->down, 	x, y+1);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::add_R(vector<vector<int>> mat, node *temp, int x, int y)
{
	Derc.push_back("R");
	Vals.push_back(mat[y][x]);
	struct node *tempN = new (struct node);
	tempN->val = mat[y][x];
	tempN->right = NULL;
	tempN->up = NULL;
	tempN->down = NULL;
	temp = tempN;
	bool Trav = false;

	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(mat, temp->right, x+1, y);
	}
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(mat, temp->up, x, y-1);
	}
	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(mat, temp->down, 	x, y+1);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::add_U(vector<vector<int>> mat, node *temp, int x, int y)
{
	Derc.push_back("U");
	Vals.push_back(mat[y][x]);
	struct node *tempN = new (struct node);
	tempN->val = mat[y][x];
	tempN->left = NULL;
	tempN->right = NULL;
	tempN->up = NULL;
	temp = tempN;
	bool Trav = false;
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(mat, temp->up, x, y-1);
	}
	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(mat, temp->left, 	x-1, y);
	}
	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(mat, temp->right, x+1, y);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::add_D(vector<vector<int>> mat, node *temp, int x, int y)
{
	Derc.push_back("D");
	Vals.push_back(mat[y][x]);
	struct node *tempN = new (struct node);
	tempN->val = mat[y][x];
	tempN->left = NULL;
	tempN->right = NULL;
	tempN->down = NULL;
	temp = tempN;
	bool Trav = false;

	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(mat, temp->down, 	x, y+1);
	}
	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(mat, temp->left, 	x-1, y);
	}
	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(mat, temp->right, x+1, y);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::minPathSum()
{
	vector<string> tempS;
	int k = 0;
	int counter = 0;
	int sum = 0;

	while (true)
	{
		if (Derc[k]  == "@") // "@"
		{
			sum = Vals[0];
			counter = 0;
			k += 1;
			continue;
		}

		if (Derc[k] != "@" && Derc[k] != "/") // "R"
		{
			if (Vals[k] == -1)
			{
				Vals[k] = 1000000;
			}
			sum += Vals[k];
			k += 1;
			continue;
		}

		if (Derc[k] == "/" && Derc[k+1] == "/") // "//"
		{
			counter += 1;
			k += 1;
			continue;
		}

		if (Derc[k] == "/" && Derc[k+1] == *(Derc.end())) // End
		{
			Sums.push_back(sum);
			break;
		}

		if (Derc[k] == "/" && Derc[k+1] != "/" && Derc[k+1] != "@") // Initialize "/R"
		{
			counter = counter + 1;
			k = k+1;
			for (int j = 0; j < 2*counter; j++)
			{
				Derc.erase(Derc.begin()+k-2*counter);
			}
			for (int j = 0; j < counter; j++)
			{
				Vals.erase(Vals.begin()+k-2*counter);
			}
			Sums.push_back(sum);
			counter = 0;
			sum = 0;
			k = 0;
			continue;
		}

		if (Derc[k] == "/" && Derc[k+1] == "@")  // Initialize /@
		{
			counter = counter + 1;
			k = k + 1;
			for (int j = 0; j < k; j++)
			{
				Derc.erase(Derc.begin());
			}
			for (int j = 0; j < k - counter; j++)
			{
				Vals.erase(Vals.begin());
			}
			Sums.push_back(sum);
			k = 0;
			continue;
		}
	}

	int minValue = *min_element(Sums.begin(), Sums.end());
	cout << minValue << "\n";
}