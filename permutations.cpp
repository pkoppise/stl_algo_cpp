#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void printVector(vector<int>& vec)
{
    for_each(vec.begin(), vec.end(), [](int &ele){ cout << ele << " ";});
    cout << endl;
}

int main()
{
    vector<int> vec = {9,6,2,4,3,8,7,5,1};
    printVector(vec);

    std::rotate(vec.begin(), vec.begin() + 3, vec.end()); //13
    //std::rotate(vec.begin() + 1, vec.begin() + 3, vec.begin() + 6);
    printVector(vec);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed)); //14
    printVector(vec);

    cout << "===========" << endl;
    std::vector<int> vt = {1, 2, 3};
    do {
        printVector(vt);
    } while ( std::next_permutation(vt.begin(), vt.end()) ); //15
    cout << "===========" << endl;
    printVector(vt);  

    cout << "===========" << endl;
    std::vector<int> vt2 = {3, 2, 1};
    do {
        printVector(vt2);
    } while ( std::prev_permutation(vt2.begin(), vt2.end()) ); //16
    cout << "===========" << endl;
    printVector(vt2);

    std::reverse(vec.begin(), vec.end()); //17
    printVector(vec);

    return 0;
}