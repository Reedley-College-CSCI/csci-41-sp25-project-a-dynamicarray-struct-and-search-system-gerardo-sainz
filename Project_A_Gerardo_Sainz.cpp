#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Movie
{
	int year;
	float rating;
	string genre;
	string title;
};

int main()
{
	int size = 100;

	string filename = "movieData.txt";
	ifstream inputFile(filename);
	
	if (!inputFile.is_open()) {
		cout << "Error: Could not open file " << filename << endl;
		return 1;
	}

	string line;
	while (getline(inputFile, line)) {
		cout << line << endl;
	}

	inputFile.close();
	
	return 0;
}