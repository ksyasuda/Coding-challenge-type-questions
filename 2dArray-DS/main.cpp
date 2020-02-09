#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const int ROWS = 6;
const int COLS = 6;
vector<vector<int>> vect(ROWS, vector<int>(COLS, 0));

void readInput(char* argv[]);
int countHourglass();

int main(int argc, char* argv[]) {
	if(argc < 2) {cout << "Not enough args\n"; exit(1);}
	readInput(argv);
	int result = 0;
	result = countHourglass();
	cout << result << endl;
	return 0;
}

static int countHelper(int i, int j) {
	int result = 0;
	result += vect[i][j];
	result += vect[i-1][j-1];
	result += vect[i+1][j-1];
	result += vect[i-1][j];
	result += vect[i+1][j];
	result += vect[i+1][j+1];
	result += vect[i-1][j+1];
	return result;
}

int countHourglass() {
	//* start at 1 and go up to 4 because there cannot be an hourslass
	//* starting at index 0 or size-1 (5)
	vector<vector<int>> temp(4, vector<int>(4, 0));
	int last3 = 0, max = -numeric_limits<int>::infinity();
	for(int i = 1; i <= 4; ++i) { 
		for(int j = 1; j <= 4; ++j) {
			// if(j == 1) temp[i-1][j-1] = countHelper(i, j, last3);
			// else temp[i-1][j-1] = countHelper2(i, j, last3);
			temp[i-1][j-1] = countHelper(i, j);
			max = std::max(max, temp[i-1][j-1]);
		}
	}
	return max;
}

void readInput(char* argv[]) {
	string file;
	ifstream is;
	file = argv[1];
	is.open(file);
	if(!is.is_open()) {
		cout << "File not open";
		exit(1);
	}
	int temp = 0;
	for(int i = 0; i < ROWS; ++i) {
		for(int j = 0; j < COLS; ++j) {
			is >> temp;
			vect[i][j] = temp;
		}
	}
	is.close();
}