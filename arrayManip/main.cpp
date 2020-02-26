#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;


vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
	//* +1 because 1 based indexing, ignore vect[0]
	vector<int> vect;
	vect.resize(n+1);
	int a, b, k, max = 0;
	// bool checkMax = true;
	for(int i = 0; i < (int) queries.size(); ++i) {
		a = queries[i][0];
		b = queries[i][1];
		k = queries[i][2];
		for(int j = a; j <= b; ++j) {
			vect[j] += k;
		}
	}
	for(auto it = vect.begin(); it != vect.end(); ++it) {
		max = std::max(max, *it);
	}
	return max;
}


int main() {
    long int N,K,p,q,sum,i,max=0,x=0;

    cin>>N>>K;
    // long int *a=new long int[N+1]();
	vector<long int> a;
	a.resize(N+1);

    for(i=0;i<K;i++)
    {
        cin>>p>>q>>sum;
        a[p]+=sum;
        if((q+1)<=N) a[q+1]-=sum;
    }

    for(i=1;i<=N;i++)
    {
       x=x+a[i];
       if(max<x) max=x;

    }

    cout<<max;
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