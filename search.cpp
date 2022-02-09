#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class Container>
void printContainer(Container const& container)
{
    typename Container::const_iterator it;
    for(it = container.begin(); it != container.end(); ++it) { cout << *it << " "; }
    cout << endl;
}

int main()
{
    vector<int> v1 = {20,40,60,80,100,80,10,90,80, 100,110};
    printContainer(v1);
    auto it = std::find(v1.begin(), v1.end(), 80); //37
    if(it != v1.end()) {
        cout << "found:" << *it << " at index:" << std::distance(v1.begin(), it) << endl; //38
    }
    else {
        cout << "Not found" << endl;
    }

    std::sort(v1.begin(), v1.end());
    printContainer(v1);
    auto it2 = std::adjacent_find(v1.begin(), v1.end()); //39
    cout << "Duplicate1:" << *it2 << endl;

    v1.erase(std::remove(v1.begin(), v1.end(), *it2), v1.end()); //40
    printContainer(v1);

    /*while(*it2 == 80)
    {
        std::advance(it2, 1); //41
    }*/

    auto it3 = std::adjacent_find(it2, v1.end());
    cout << "Duplicate2:" << *it3 << endl;
    v1.erase(std::remove(v1.begin(), v1.end(), *it3), v1.end());
    printContainer(v1);

    cout << "=================" << endl;
    vector<int> v2 = {20,40,60,80,100,80,10,90,80, 100,110};
    std::sort(v2.begin(), v2.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end()); //42
    printContainer(v2);
    
    return 0;
}