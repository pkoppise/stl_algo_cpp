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
    vector<int> v1 = {5,10,15,20,25};
    vector<int> v2 = {50,40,30,20,10};

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    vector<int> v(v1.size() + v2.size());
    auto it = std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin()); //52
    v.resize(it - v.begin());
    cout << "Diff:";printContainer(v);

    vector<int> intersection(v1.size() + v2.size());
    it = std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), intersection.begin()); //53
    intersection.resize(it - intersection.begin());
    cout << "Inter:";printContainer(intersection);

    vector<int> uni(v1.size() + v2.size());
    it = std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), uni.begin()); //54
    uni.resize(it - uni.begin());
    cout << "Union:";printContainer(uni);

    vector<int> sym_diff(v1.size() + v2.size());
    it = std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), sym_diff.begin()); //54
    sym_diff.resize(it - sym_diff.begin());
    cout << "Sym Diff:";printContainer(sym_diff);

    vector<int> container = {5,10,15,20,25,30,35,40,45,50};
    vector<int> continent = {40,30,20,10};

    std::sort(container.begin(), container.end());
    std::sort(continent.begin(), continent.end());
    cout << boolalpha << "Container includes continent:" << std::includes(container.begin(), container.end(), continent.begin(), continent.end()) << endl; //55

    //std::merge  //56

    return 0;
}