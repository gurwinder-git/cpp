#include <iostream>
#include <vector>

using namespace std;

int wateringPlants(vector<int> &plants, int capacity);
int main()
{
    vector<int> plants = {1, 1, 1, 4, 2, 3};
    cout << "total steps needed: " << wateringPlants(plants, 4);
    return 0;
}
int wateringPlants(vector<int> &plants, int capacity)
{
    int stepsNeeded = 0;

    int capacityBackup = capacity;

    for (int i = 0; i < plants.size(); i++)
    {
        if (capacity >= plants[i])
        {
            stepsNeeded++;
            capacity -= plants[i];
        }
        else
        {
            capacity = capacityBackup;
            stepsNeeded += (i * 2) + 1;

            capacity -= plants[i];
        }
    }

    return stepsNeeded;
}