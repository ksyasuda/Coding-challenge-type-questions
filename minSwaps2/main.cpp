#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <fstream>
#include <limits>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
	if(arr.empty() || arr.size() == 1) return 0;
	int min = arr[0], count = 0, num_swaps = 0;
	auto ind = arr.begin();
	// for(int i = count; i < (int) arr.size()-1; ++i) {
	for(auto it = arr.begin() + count; it != arr.end()-1; ++it) {
		// * find min number in array
		if(*it > 0 && *it == *(it-1)+1) {
			//* if the current value, after the first, is one more than the previous then it is
			//* in the correct order and don't need a swap this iteration
			++count;
			continue;
		}
		else if(*it == 0 && *it == 1) {
			++count;
			continue;
		}
		min = *it;
		// for(int j = i; j < (int) arr.size(); ++j) {
			for(auto iter = it; iter != arr.end(); ++iter) {
			if(*iter < min) {
				min = *iter;
				ind = iter;
			}
		}
		// * swap into location
		std::swap(*it, *ind);
		++num_swaps;
		// ++count;
	}
	return num_swaps;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    // fout << res << "\n";

    // fout.close();
	cout << res << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
