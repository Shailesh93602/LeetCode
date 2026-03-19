class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 12
        // 10, 8, 0, 5, 3
        // 2, 4, 1, 1, 3

        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i=0; i<n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({ position[i], time });
        }

        sort(cars.begin(), cars.end(), greater<>());

        int ans = 0;
        double maxTime = 0;

        for(auto &car: cars) {
            if(car.second > maxTime) {
                maxTime = car.second;
                ans++;
            }
        }

        return ans;
    }
};