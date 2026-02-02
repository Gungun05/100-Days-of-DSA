    int minEatingSpeed(vector<int>& arr, int h) {
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }

        for (int k = 1; k <= maxi; k++) {

            long long totalHours = 0;

            for (int i = 0; i < arr.size(); i++) {
                totalHours += (arr[i] + k - 1) / k;
            }

            if (totalHours <= h) {
                return k;
            }
        }

        return maxi;
    }
