class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalGas = 0, totalCost = 0, start = 0, remGas = 0;

        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalCost > totalGas) return -1;

        for(int i=0; i<n; i++) {
            remGas += gas[i];

            if(cost[i] <= remGas) {
                remGas -= cost[i];
            } else {
                start = i + 1;
                remGas = 0;
            }
        }

        return start;
    }
};