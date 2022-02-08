#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

template<class Container>
void printContainer(Container const& container)
{
    typename Container::const_iterator it;
    for(it = container.begin(); it != container.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main()
{
    // Initializing array
    int ar[6] = {1, 2, 3, 4, 5, -6};
    vector<int> vec(ar, ar+6);

    // Checking if all elements are positive
    all_of(vec.begin(), vec.end(), [](int x)
            {
                return x>0;
            }
    )?
    cout << "All are positive elements" << endl:
    cout << "All are not positive elements" << endl;   //30

    any_of(vec.begin(), vec.end(), [](int x)
            {
                return x<0;
            }
    )?
    cout << "There exists a negative element" << endl:
    cout << "All are positive elements" << endl;  //31

    int arr[6] = {1, 2, 3, 4, 5, 6};
    vector<int> vec2(arr, arr+6);
    none_of(vec2.begin(), vec2.end(), [](int x) { return x<0; })?
            cout << "There are no negative elements" << endl :
            cout << "There are negative elements" << endl;  //32

    return 0;
}