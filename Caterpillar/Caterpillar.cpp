#include <iostream>
#include <stdio.h>

using namespace std;

struct List
{
	char sign;
	List *next;
	List *prev;
};

List *first, *last;
int counter;

bool isEmpty()
{
	if (counter == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push_front(char sign)
{
	if (isEmpty())
	{
		List *n = new List;
		n->sign = sign;
		n->next = NULL;
		n->prev = NULL;
		first = n;
		last = n;
		counter++;
	}
	else
	{
		List *n = new List;
		n->sign = sign;
		n->next = first;
		n->prev = NULL;
		first->prev = n;
		first = n;
		counter++;
	}
}

void push_back(char sign)
{
	if (isEmpty())
	{
		List *n = new List;
		n->sign = sign;
		n->next = NULL;
		n->prev = NULL;
		first = n;
		last = n;
		counter++;
	}
	else
	{
		List *n = new List;
		n->sign = sign;
		n->next = NULL;
		n->prev = last;
		last->next = n;
		last = n;
		counter++;
	}
}

void pop_back()
{
	if (isEmpty())
	{
		return;
	}
	else if (counter == 1)
	{
		delete last;
		last = NULL;
		first = NULL;
		counter--;
	}
	else
	{
		last = last->prev;
		delete last->next;
		last->next = NULL;
		counter--;
	}
}

void pop_front()
{
	if (isEmpty())
	{
		return;
	}
	else if (counter == 1)
	{
		delete first;
		first = NULL;
		last = NULL;
		counter--;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = NULL;
		counter--;
	}
}

void drawCaterpillar()
{
	List * n = first;
	while (n != NULL)
	{
		cout << n->sign ;
		n = n->next;
	}
	cout << "\n";
}

int main()
{
	
	int n, m, c, x, y, d;
	cin >> n >> m >> c;
	if (n > 4000 || m > 1000 || c > 10000000)
	{
		return 0;
	}
	cin >> x >> y >> d;
	x = x - 1;
	y = y - 1;
	if (x > n || y > m || d > 1000)
	{
		return 0;
	}
	char **board = new char*[m];
	for (int i = 0; i < m; i++)
	{
		board[i] = new char[n];
	}
	char *string = new char[d];
	for (int i = 0; i < d; i++)
	{
		cin >> string[i];
		push_back(string[i]);
	}
	delete[] string;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int move = 4;
	while (true)
	{
		if (board[y][x] >= 'a' && board[y][x] <= 'z')
		{
			push_front(board[y][x]);
			if (board[y][x] == 'a')
			{
				board[y][x] = '$';
			}
			else
			{
				board[y][x]--;
			}
		}
		else if (board[y][x] >= 'A' && board[y][x] <= 'Z')
		{
			push_back(board[y][x] + 32);
			if (board[y][x] == 'A')
			{
				board[y][x] = '^';
			}
			else
			{
				board[y][x]--;
			}
		}
		else if (board[y][x] == '$')
		{
			pop_front();
		}
		else if (board[y][x] == '^')
		{
			pop_back();
		}
		else if (board[y][x] == '1')
		{
			move = 1;
		}
		else if (board[y][x] == '2')
		{
			move = 2;
		}
		else if (board[y][x] == '3')
		{
			move = 3;
		}
		else if (board[y][x] == '4')
		{
			move = 4;
		}
		
		c--;
		if (counter <= 0 || c <= 0)
		{
			break;
		}
		if (move == 1)
		{
			if (y == 0)
			{
				y = m - 1;
			}
			else
			{
				y--;
			}
		}
		else if (move == 2)
		{
			if (y == m-1)
			{
				y = 0;
			}
			else
			{
				y++;
			}
		}
		else if (move == 3)
		{
			if (x == 0)
			{
				x = n - 1;
			}
			else
			{
				x--;
			}
		}
		else if (move == 4)
		{
			if (x == n-1)
			{
				x = 0;
			}
			else
			{
				x++;
			}
		}
	}

	cout << x+1 << " " << y+1 << " ";
	if (isEmpty())
	{
		cout << "#\n";
	}
	else
	{
		drawCaterpillar();
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '$' || board[i][j] == '^')
			{
				cout << "@";
			}
			else
			{
				cout << board[i][j];
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < m; i++)
	{
		delete[] board[i];
	}
	delete[] board;
	
	return 0;
}