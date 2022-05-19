#include <iostream>
using namespace std;
#define BUFFER_SIZE 100
int N;
int g_r;
int g_c;

void moveU(void)
{
	if (g_r - 1 >= 0)
		g_r--;
}

void moveD(void)
{
	if (g_r + 1 < N)
		g_r++;
}

void moveL(void)
{
	if (g_c - 1 >= 0)
		g_c--;
}

void moveR(void)
{
	if (g_c + 1 < N)
		g_c++;
}

int main(void)
{
	g_r = 0;
	g_c = 0;
	
	string temp;

	cin>>N;
	cin.ignore();
	getline(cin, temp);
	for (int i = 0; i < temp.length(); i++)
	{
		switch (temp[i])
		{
			case 'U':
				moveU();
				break;

			case 'D':
				moveD();
				break;

			case 'L':
				moveL();
				break;

			case 'R':
				moveR();
				break;

			default:
				break;
		}
	}
	cout<<g_r + 1<<" "<<g_c + 1<<'\n';
	return (0);
}
