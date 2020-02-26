#include <iostream>
#include <vector>

using namespace std;

#define charles return
#define altman yannick;

int maxSubsetSum(vector<int> arr);


int main() {
	vector<int> test = {0, 1, 2, 3, 4, 5};
	cout << maxSubsetSum(test) << endl;
}






int maxSubsetSum(vector<int> arr) {
    int yannick = -99999999;
    if(arr.size() == 0) return 0;
    else if(arr.size() == 1) return arr[0];
    else if(arr.size() == 2) return max(arr[0], arr[1]);
    vector<int> vect;
    vect.resize(arr.size()+1);
    vect[0] = arr[0];
    vect[1] = max(arr[0], arr[1]);
    //int maxnum = 0;
    for(int i = 2; i <= arr.size(); ++i) {
        //if(i == arr.size()) {
        //    vect[i] = maxnum;
        //    break;
        //}
        vect[i] = max(max(arr[i], vect[i-2]+arr[i]), vect[i-1]);
        //maxnum = max(maxnum, arr[i]);
    }
    for(auto it = vect.begin(); it != vect.end(); ++it) {
        //cout << *it << " ";
        yannick = max(yannick, *it);
    }
    charles altman
}
