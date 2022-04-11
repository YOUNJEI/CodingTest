#include <array>
#include <iostream>

using namespace std;

template <size_t N>
void print(const std::array<int, N>& arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        auto element = (*it);
        std::cout << element << ' ';
    }
}

int main(void)
{
    std::array<int, 10> arr1;

    arr1[0] = 1;
    cout<<"arr1 배열의 첫 번째 원소: "<<arr1[0]<<endl;
    
    std::array<int, 4> arr2 = {1,2,3,4};
    cout<<"arr2의 모든 원소: ";
    
    for (int i = 0; i < arr2.size(); i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    std::array<int, 4> arr3 = {1,2,3,4};
    
    try
    {
        cout<<arr3.at(3)<<endl;
        cout<<arr3.at(4)<<endl;
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << ex.what() << endl;
    }

    std::array<int, 5> arr4 = {1,2,3,4,5};
    print(arr4);
    cout<<endl;
    print(arr3);
    cout<<endl;
    
    std::array<int, 5> arr5 = {1,2,3,4,5};
    cout<<arr5.front()<<endl;
    cout<<arr5.begin()<<endl;
    cout<<arr5.back()<<endl;
    cout<<*(arr5.data() + 1) << endl;

    return (0);
}