#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsOdd (int i) { return (i%2)==1; }

void printVector(vector<int>& vec)
{
    for_each(vec.begin(), vec.end(), [](int &ele){ cout << ele << " ";});
    cout << endl;
}

int main()
{
    vector<int> vec = {9,6,2,4,3,8,7,5,1};
    printVector(vec);

    //std::partition(vec.begin(), vec.end(), IsOdd);  //10
    //printVector(vec);

    std::stable_partition(vec.begin(), vec.end(), IsOdd); //11
    printVector(vec);

    std::vector<int> odd;
    auto it = std::partition_point(vec.begin(),vec.end(),IsOdd); //12
    odd.assign (vec.begin(),it);
    printVector(odd);
    return 0;
}