class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int j, counter, curruntGas;
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            j = i;
            counter = 0;
            curruntGas = 0;

            while (counter < n)
            {
                curruntGas += gas[j];
                curruntGas -= cost[j];
                if (curruntGas < 0)
                    break;
                counter++;

                j = (j + 1) % n;
            }
            if (counter == n)
                return i;
        }

        return -1;
    }
};