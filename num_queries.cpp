#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

void printVector(vector<int>& vec)
{
    for_each(vec.begin(), vec.end(), [](int &ele){ cout << ele << " ";});
    cout << endl;
}
int myaccumulator2 (int x, int y) {return y - x;}

int myaccumulator (int x, int y) {return x - y;}

int myproduct (int x, int y) {return x+y;}

int myop (int x, int y) {return x * y;}

int main()
{
    vector<int> vec = {10,20,30,30,20,10,10,20};
    printVector(vec);
    cout << "10 repeats:" << std::count(vec.begin(), vec.end(), 10) << endl; //24
    cout << "20 repeats:" << std::count(vec.begin(), vec.end(), 20) << endl;
    cout << "30 repeats:" << std::count(vec.begin(), vec.end(), 30) << endl;

    int sum = 0;
    cout << "Accumulate:" << std::accumulate(vec.begin(), vec.end(), sum) << endl; //25

    vector<int> val = {1,2,3,4,5};
    int res[5];
    std::partial_sum(val.begin(), val.end(), res); //26
    for(auto &ele: res) cout << ele << " "; cout << endl;

    std::partial_sum(val.begin(), val.end(), res, std::multiplies<int>());
    for(auto &ele: res) cout << ele << " "; cout << endl;

    std::partial_sum(val.begin(), val.end(), res, myaccumulator2);
    cout << "My acc2:"; for(auto &ele: res) cout << ele << " "; cout << endl;

    int init = 100;
    int series1[] = {10,20,30};
    int series2[] = {1,2,3};

    std::cout << "using default inner_product: ";
    std::cout << std::inner_product(series1,series1+3,series2,init); //27
    std::cout << '\n';

    std::cout << "using functional operations: ";
    std::cout << std::inner_product(series1,series1+3,series2,init,std::minus<int>(),std::divides<int>());
    std::cout << '\n';

    std::cout << "using custom functions: ";
    std::cout << std::inner_product(series1,series1+3,series2,init,myaccumulator,myproduct);
    std::cout << '\n';

    vector<int> values = {1,2,3,5,9,11,12};
    int result[7];

    std::adjacent_difference(values.begin(), values.end(), result); //28
    for(auto &ele: result) cout << ele << " "; cout << endl;

    std::adjacent_difference(values.begin(), values.end(), result, std::plus<int>());
    for(auto &ele: result) cout << ele << " "; cout << endl;

    std::adjacent_difference(values.begin(), values.end(), result, myop);
    for(auto &ele: result) cout << ele << " "; cout << endl;

    std::vector<int> vec2(10);
    std::iota(vec2.begin(), vec2.end(), 100); //29
    printVector(vec2);
    return 0;
}