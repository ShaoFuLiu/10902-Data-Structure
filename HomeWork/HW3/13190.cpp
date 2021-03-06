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
		vector<vector<int> > mat;
		vector<int> Sums;
		vector<string> Derc;
		void Build(int Rx, int Ry);
        void add_L(int x, int y);
		void add_R(int x, int y);
		void add_U(int x, int y);
		void add_D(int x, int y);
		void minPathSum(int Rx, int Ry); 												// return min path value

        Tree()
        {
			root = NULL;
        }
};

int main(void)
{
	int row, col, value, Rx, Ry;
	cin >> row >> col;
	cin >> Rx >> Ry;
	vector<vector<int> > mat(row, vector<int>(col));
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> value;
			(mat.at(i)).at(j) = value;
		}
	}

	Tree tree;
	tree.mat = mat;
	tree.col = col-1; // minus 1 because index start from 0
	tree.row = row-1; // minus 1 because index start from 0
	tree.Build(Rx, Ry);
	tree.minPathSum(Rx, Ry);
}

void Tree::Build(int Rx, int Ry)
{
	if (Rx-1 >= 0 && mat[Ry][Rx-1] != 0)					// left
	{
		Derc.push_back("@");
		add_L( Rx-1, Ry);
		Derc.push_back("/");
	}
	if (Rx+1 <= col && mat[Ry][Rx+1] != 0)					// right
	{
		Derc.push_back("@");
		add_R(Rx+1, Ry);
		Derc.push_back("/");
	}
	if (Ry-1 >= 0 && mat[Ry-1][Rx] != 0)					// up
	{
		Derc.push_back("@");
		add_U(Rx, Ry-1);
		Derc.push_back("/");
	}
	if (Ry+1 <= row && mat[Ry+1][Rx] != 0)					// down
	{
		Derc.push_back("@");
		add_D(Rx, Ry+1);
		Derc.push_back("/");
	}
}

void Tree::add_L(int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));

	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(x-1, y);
	}
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(x, y-1);
	}
	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(x, y+1);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::add_R(int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));

	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(x+1, y);
	}
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(x, y-1);
	}
	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(x, y+1);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::add_U(int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));

	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(x, y-1);
	}
	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(x-1, y);
	}
	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(x+1, y);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::add_D(int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));

	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(x, y+1);
	}
	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(x-1, y);
	}
	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(x+1, y);
	}
	else
	{
		Derc.push_back("/");
	}
}

void Tree::minPathSum(int Rx, int Ry)
{
	int k = 0;
	int counter = 0;
	int sum = 0;

	while (true)
	{
		if (Derc[k]  == "@") // "@"
		{
			sum = mat[Ry][Rx];
			counter = 0;
			k += 1;
			continue;
		}

		if (Derc[k] != "@" && Derc[k] != "/") // "R"
		{
			if (Derc[k] == "-1")
			{
				Derc[k] = "100000";
			}
			sum += stoi(Derc[k]);
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
			vector<string>().swap(Derc);
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
			Sums.push_back(sum);
			k = 0;
			continue;
		}
	}

	int minValue = *min_element(Sums.begin(), Sums.end());
	cout << minValue << "\n";
}