#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

struct node
{
	int v, col, row;
	bool passed;
	struct node *up;
	struct node *down;
	struct node *left;
	struct node *right;
}*root;

//use doubled non circular linked list representation to store matirx