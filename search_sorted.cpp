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
  int myints[] = {10,20,30,20,10,10,20};
  std::vector<int> v(myints,myints+7);
  printContainer(v);

  std::sort(v.begin(), v.end());
  printContainer(v);
  auto it = std::adjacent_find(v.begin(), v.end());
  while( it != v.end()) {
      auto bounds = std::equal_range(it, v.end(), *it);  //43
      //cout << *bounds.first << " " << *bounds.second << endl;
      v.erase(bounds.first, bounds.second);
      it = std::adjacent_find(v.begin(), v.end());
  }
  printContainer(v);

  /*std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //44
  up= std::upper_bound (v.begin(), v.end(), 20); //45

  cout << *low << endl;
  cout << *up << endl;

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';*/

  vector<int> vec = {9,6,2,4,3,8,0,7,5,1};
  printContainer(vec);
  std::sort(vec.begin(), vec.end());
  cout << std::binary_search(vec.begin(), vec.end(), 7) << endl; //46
  return 0;
}