#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class Container>
void printContainer(Container const& container)
{
    typename Container::const_iterator it;
    for(it = container.begin(); it != container.end(); ++it) { cout << *it << " "; }
    cout << endl;
}

bool mypredicate (int i, int j) {
  return (i==j);
}

int main()
{
    vector<int> v1 = {20,40,60,80,100};
    //vector<int> v2(v1);
    vector<int> v2  = {40,80,60,100,20};
    printContainer(v1);
    printContainer(v2);
    cout << std::equal(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl; //33

    //v1[3] = 85;
    //cout << std::equal(v1.begin(), v1.end(), v2.begin(), v2.end(), mypredicate) << endl;
    cout << std::is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl; //34

    char foo[]="abcdefgh";
    char bar[]="abcdyz";

    std::cout << std::boolalpha;

    std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
    std::cout << "Using default comparison (operator<): ";
    std::cout << std::lexicographical_compare(foo,foo+8,bar,bar+6); //35
    std::cout << '\n';

    std::vector<int> myvector;
    for (int i=1; i<6; i++) myvector.push_back (i*10); // myvector: 10 20 30 40 50
    int myints[] = {10,20,80,320,1024};                //   myints: 10 20 80 320 1024

    std::pair<std::vector<int>::iterator,int*> mypair;

    // using default comparison:
    mypair = std::mismatch (myvector.begin(), myvector.end(), myints); //36
    std::cout << "First mismatching elements: " << *mypair.first;
    std::cout << " and " << *mypair.second << '\n';
    return 0;
}
