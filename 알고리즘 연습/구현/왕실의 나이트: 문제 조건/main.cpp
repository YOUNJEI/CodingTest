#include <iostream>
using namespace std;
#define BUFFER_SIZE 8


int main(void)
{
	int r, c;
	string temp;
	int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
	int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};
	int count = 0;

	cin>>temp;
	r = temp[1] - '1';
	c = temp[0] - 'a';
	for (int dir = 0; dir < 8; dir++)
	{
		int nr = r + dx[dir];
		int nc = c + dy[dir];

		if (nr >= 0 && nr < BUFFER_SIZE && nc >= 0 && nc < BUFFER_SIZE)
			count++;
	}
	cout<<count<<'\n';
	return (0);
}
