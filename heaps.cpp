#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>& vec)
{
    for_each(vec.begin(), vec.end(), [](int &ele){ cout << ele << " ";});
    cout << endl;
}

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    printVector(vec);
    cout << "Is heap:" << std::is_heap(vec.begin(), vec.end()) << endl;  //21
    auto it = std::is_heap_until(vec.begin(), vec.end());
    if(it != vec.end())
         cout << "Value:" << *it << endl;
         cout << "Index:" <<  std::distance(vec.begin(), it) << endl;


    std::make_heap(vec.begin(), vec.end());  //1
    printVector(vec);
    cout << "Is heap:" << std::is_heap(vec.begin(), vec.end()) << endl;
    auto it2 = std::is_heap_until(vec.begin(), vec.end()); //23
    if(it2 == vec.end())
        cout << "Entire vector is heap" << endl;

    vec.push_back(10);
    printVector(vec);
    
    std::push_heap(vec.begin(), vec.end()); //2
    printVector(vec);

    std::pop_heap(vec.begin(), vec.end()); //3
    printVector(vec);

    vec.pop_back();
    printVector(vec);

    std::sort_heap(vec.begin(), vec.end()); //4
    printVector(vec);

    return 0;
}