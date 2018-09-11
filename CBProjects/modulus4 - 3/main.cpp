#include <iostream>
#include <list>
#include <vector>

using namespace std;

int MaxPower(list<vector<int> > adjacencyStructure){
    int result = 0;
    for(auto it: adjacencyStructure){
        result = max(result, int(it.size()));
    }
    return result;
}

int main()
{
    list<vector<int> > adjacencyStructure;

    vector<int> first;
    vector<int> second;
    vector<int> third;
    vector<int> fourth;

    first.push_back(3);

    second.push_back(3);
    second.push_back(4);

    third.push_back(1);
    third.push_back(2);
    third.push_back(4);

    fourth.push_back(2);
    fourth.push_back(3);

    adjacencyStructure.insert(adjacencyStructure.begin(), fourth);
    adjacencyStructure.insert(adjacencyStructure.begin(), third);
    adjacencyStructure.insert(adjacencyStructure.begin(), second);
    adjacencyStructure.insert(adjacencyStructure.begin(), first);

    cout << MaxPower(adjacencyStructure) << endl;
    return 0;
}
