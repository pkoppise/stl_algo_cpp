// C++ program to demonstrate the use of std::find_end
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // Defining first container
    vector<int>v = {3, 10, 1, 3, 3, 1, 3, 10, 10, 7, 8,
                                    1, 3, 10};

    // Defining second container
    vector<int>v1 = {1, 3, 10};

    vector<int>::iterator ip;
    
    // Using std::find_end
    ip = std::find_end(v.begin(), v.end(), v1.begin(),v1.end()); //47

    // Displaying the index where the last common occurrence begins
    //cout << (ip - v.begin()) << "\n";
    cout << std::distance(v.begin(), ip) << endl;

    ip = std::search(v.begin(), v.end(), v1.begin(),v1.end()); //48
    cout << std::distance(v.begin(), ip) << endl;

    cout << *std::max_element(v.begin(), v.end()) << endl;  //49
    cout << *std::min_element(v.begin(), v.end()) << endl;  //50

    //std::minmax_element //51

    return 0;
}
