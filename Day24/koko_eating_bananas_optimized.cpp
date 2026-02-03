
    int minEatingSpeed(vector<int>& arr, int h) {

        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }

        int start = 1;
        int end = maxi;
        int ans = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;
            long long totalHours = 0;

            for (int i = 0; i < arr.size(); i++) {
                totalHours += (arr[i] + mid - 1) / mid;
            }

            if (totalHours <= h) {
                ans = mid;
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
