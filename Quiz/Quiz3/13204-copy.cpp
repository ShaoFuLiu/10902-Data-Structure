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
		vector<vector<int> > mat;
		bool check_end(int x, int y);
		void Build(vector<vector<int> > mat, int Rx, int Ry);
        void add_L(vector<vector<int> > mat, int x, int y);
		void add_R(vector<vector<int> > mat, int x, int y);
		void add_U(vector<vector<int> > mat, int x, int y);
		void add_D(vector<vector<int> > mat, int x, int y);
		void minPathSum(); 												// return min path value
		// void Traverse();
        Tree(int value)
        {
			root = NULL;
        }
};

int main(void)
{
	int row, col, value, Rx, Ry;
	cin >> row >> col;
	// cin >> Rx >> Ry;
	Rx = 0;
	Ry = 0;
	vector<vector<int> > mat(row, vector<int>(col));
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> value;
			(mat.at(i)).at(j) = value;
		}
	}

	if (mat[row-1][col-1] == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		Tree tree(mat[Ry][Rx]);
		tree.mat = mat;
		tree.col = col-1; // minus 1 because index start from 0
		tree.row = row-1; // minus 1 because index start from 0
		tree.Build(mat, Rx, Ry);
		tree.minPathSum();
		// tree.Traverse();
	}
}

bool Tree::check_end(int x, int y)
{
	if (x != col || y != row)
	{
		return false;
	}
	return true;
}

void Tree::Build(vector<vector<int> > mat, int Rx, int Ry)
{
	// Vals.reserve(1000000);
	// Sums.reserve(1000000);

	if (Rx-1 >= 0 && mat[Ry][Rx-1] != 0)					// left
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_L(mat, Rx-1, Ry);
		Derc.push_back("/");
	}
	if (Rx+1 <= col && mat[Ry][Rx+1] != 0)					// right
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);

		add_R(mat, Rx+1, Ry);
		Derc.push_back("/");
	}
	if (Ry-1 >= 0 && mat[Ry-1][Rx] != 0)					// up
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_U(mat, Rx, Ry-1);
		Derc.push_back("/");
	}
	if (Ry+1 <= row && mat[Ry+1][Rx] != 0)					// down
	{
		Derc.push_back("@");
		Vals.push_back(mat[Ry][Rx]);
		add_D(mat, Rx, Ry+1);
		Derc.push_back("/");
	}
}

void Tree::add_L(vector<vector<int> > mat, int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));
	// Vals.push_back(mat[y][x]);

	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(mat, x-1, y);
	}
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(mat, x, y-1);
	}
	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(mat, 	x, y+1);
	}
	else
	{
		if (check_end(x, y))
		{
			Derc.push_back("*");
		}
		Derc.push_back("/");
	}
}

void Tree::add_R(vector<vector<int> > mat, int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));
	// Vals.push_back(mat[y][x]);

	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(mat, x+1, y);
	}
	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(mat, x, y-1);
	}
	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(mat, x, y+1);
	}
	else
	{
		if (check_end(x, y))
		{
			Derc.push_back("*");
		}
		Derc.push_back("/");
	}
}

void Tree::add_U(vector<vector<int> > mat, int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));
	// Vals.push_back(mat[y][x]);

	if (y-1 >= 0 && mat[y-1][x] != 0)					// up
	{
		add_U(mat, x, y-1);
	}
	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(mat, x-1, y);
	}
	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(mat, x+1, y);
	}
	else
	{
		if (check_end(x, y))
		{
			Derc.push_back("*");
		}
		Derc.push_back("/");
	}
}

void Tree::add_D(vector<vector<int> > mat, int x, int y)
{
	Derc.push_back(to_string(mat[y][x]));
	// Vals.push_back(mat[y][x]);

	if (y+1 <= row && mat[y+1][x] != 0)					// down
	{
		add_D(mat, x, y+1);
	}
	if (x-1 >= 0 && mat[y][x-1] != 0)					// left
	{
		add_L(mat, x-1, y);
	}
	if (x+1 <= col && mat[y][x+1] != 0)					// right
	{
		add_R(mat, x+1, y);
	}
	else
	{
		if (check_end(x, y))
		{
			Derc.push_back("*");
		}
		Derc.push_back("/");
	}
}

/* void Tree::Traverse()
{
//
	for (int i = 0; i < Derc.size(); i++)
	{
		cout << Derc[i];
	}
	cout << endl;
	for (int i = 0; i < Vals.size(); i++)
	{
		cout << Vals[i];
	}
	cout << endl;

	for (int j = 0; j < 2*6; j++)
	{
		Derc.erase(Derc.begin()+15-6*2);
	}
	for (int i = 0; i < Derc.size(); i++)
	{
		cout << Derc[i];
	}
	cout << endl;
	for (int j = 0; j < 6; j++)
	{
		Vals.erase(Vals.begin()+15-6*2);
	}
	for (int i = 0; i < Vals.size(); i++)
	{
		cout << Vals[i];
	}
	cout << endl;
//

	for (int j = 0; j < 2*2; j++)
	{
		Derc.erase(Derc.begin()+9-2*2);
	}
	for (int i = 0; i < Derc.size(); i++)
	{
		cout << Derc[i];
	}
	cout << endl;
	for (int j = 0; j < 2; j++)
	{
		Vals.erase(Vals.begin()+9-2*2);
	}
	for (int i = 0; i < Vals.size(); i++)
	{
		cout << Vals[i];
	}
	cout << endl;
//
	for (int j = 0; j < 14; j++)
	{
		Derc.erase(Derc.begin());
	}
	for (int i = 0; i < Derc.size(); i++)
	{
		cout << Derc[i];
	}
	cout << endl;
	for (int j = 0; j < 14-6; j++)
	{
		Vals.erase(Vals.begin());
	}
	for (int i = 0; i < Vals.size(); i++)
	{
		cout << Vals[i];
	}
	cout << endl;
}*/

void Tree::minPathSum()
{
	int k = 0;
	int counter = 0;
	int sum = 0;
	bool path = false;
	while (true)
	{
		if (Derc[k]  == "@") // "@"
		{
			sum = Vals[0];
			counter = 0;
			k += 1;
			continue;
		}

		if (Derc[k] == "*") // "*"
		{
			Derc.erase(Derc.begin()+k);
			path = true;
			continue;
		}

		if (Derc[k] != "@" && Derc[k] != "/") // "R"
		{
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
			vector<int>().swap(Vals);
			vector<string>().swap(Derc);
			if (path == true)
			{
				Sums.push_back(sum);
				break;
			}
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
			if (path == true)
			{
				Sums.push_back(sum);
				break;
			}
			counter = 0;
			sum = 0;
			k = 0;
			continue;
		}

		if (Derc[k] == "/" && Derc[k+1] == "@")  // Initialize "/@"
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
			if (path == true)
			{
				Sums.push_back(sum);
				break;
			}
			k = 0;
			continue;
		}
	}

	int minValue = *min_element(Sums.begin(), Sums.end());
	cout << minValue << "\n";
}