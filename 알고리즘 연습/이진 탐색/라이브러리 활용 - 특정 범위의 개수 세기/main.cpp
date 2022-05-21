#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> arr = {1,3,5,5,7,8,8,10,10,11,13};
	// 이진 탐색전 자료가 정렬 되어있어야함.
	sort(arr.begin(), arr.end());

	cout<<"5 이상 11 이하의 갯수: "<<upper_bound(arr.begin(), arr.end(), 11) - lower_bound(arr.begin(), arr.end(), 5);
	// upper_bound & lower_bound 는 메모리주소 혹은 iter를 리턴함으로
	// 최초값을 뺴주어야함.

	cout<<endl;

	cout<<"5의 갯수: "<<upper_bound(arr.begin(), arr.end(), 5) - lower_bound(arr.begin(), arr.end(), 5);

	return (0);
}
