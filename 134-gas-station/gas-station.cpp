class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalGas = 0, totalCost = 0, start = 0;

        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalCost > totalGas) return -1;

        for(int i=0; i<n; ) {
            int remGas = 0;
            for(int j=i; j<n; j++) {
                remGas += gas[i];

                if(cost[i] <= remGas) {
                    remGas -= cost[i];
                    i++;
                }
                else {
                    i = j + 1;
                    start = j + 1;
                    break;
                }
            }
        }

        return start;
    }
};