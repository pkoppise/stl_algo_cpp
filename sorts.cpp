#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>& vec)
{
    for_each(vec.begin(), vec.end(), [](int &ele){ cout << ele << " ";});
    cout << endl;
}

void printVector(vector<double>& vec)
{
    for_each(vec.begin(), vec.end(), [](double &ele){ cout << ele << " ";});
    cout << endl;
}

bool compare_as_ints (double i,double j)
{
  return (int(i)<int(j));
}

int main()
{
    //vector<int> vec = {9,6,2,4,3,8,0,7,5,1};
    //printVector(vec);

    //std::sort(vec.begin(), vec.end());  //5
    //printVector(vec);

    //std::partial_sort(vec.begin(), vec.begin()+ 4, vec.end()); //6
    //printVector(vec);
    
    //std::nth_element(vec.begin(), vec.begin() + 2, vec.end()); //7
    //printVector(vec);

    int first[] = {5,10,15,20,25};
    int second[] = {50,40,30,20,10};
    std::vector<int> v(10);
    std::vector<int>::iterator it;

    std::sort (first,first+5);
    std::sort (second,second+5);

    it=std::copy (first, first+5, v.begin()); //8
    std::copy (second,second+5,it);
    printVector(v);

    std::inplace_merge (v.begin(),v.begin()+5,v.end()); //9
    printVector(v);

    vector<double> doubles = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};
    printVector(doubles);

    std::stable_sort (doubles.begin(), doubles.end());
    printVector(doubles);

    vector<double> doubles2 = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};
    printVector(doubles2);

    std::stable_sort (doubles2.begin(), doubles2.end(), compare_as_ints); //18
    printVector(doubles2);

    return 0;
}