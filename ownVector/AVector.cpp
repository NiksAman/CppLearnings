#include "AVector.hpp"

int main()
{
    aVector<int>a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(6);
    a.push_back(4);

    a.erase(2);

    for(int i = 0; i < 4; i++)
    {
        a.pop();
    }
}