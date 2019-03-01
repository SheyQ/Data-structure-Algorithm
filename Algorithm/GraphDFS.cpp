#include<iostream>
#include<stack>
using namespace std;

const static int INF = __INT_MAX__;

/*
            A        B
           / \     /
          /   \  /
         /     C------D
        E            /
         \         /
           \     /
              F
 */

int matrix[6][6] = {{INF, INF, 1, INF, 1, INF},
		   {INF, INF, 1, INF, INF, INF},
		   {1, 1, INF, 1, INF, INF},
		   {INF, INF, 1, INF, INF, 1},
	           {1, INF, INF, INF, INF, 1},
		   {INF, INF, INF, 1, 1, INF}
				};

int visited[6] = {0};

void DFS(stack<char>& s, char ch)
{
	if (s.empty())
		return;
	cout << ch;
	for (int i = 0; i < 6; i++)
	{
		if (matrix[ch - 'A'][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			s.push('A' + i);
			DFS(s, s.top());
		}
	}
	s.pop();
}

int main(int argc, char const *argv[])
{
	stack<char> s;
	char begin = 'A';
	cout << "DFS begin from A:\n";
	s.push(begin);
	visited[0] = 1;
	DFS(s, s.top());
	cout << endl;
	return 0;
}
