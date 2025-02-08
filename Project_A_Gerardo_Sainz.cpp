#include <iostream>
#include <fstream>
#include <string>
using namespace std;



struct Movie
{
	string title;
	string genre;
	int year;
	float rating;
};

class MovieDatabase {
private:
	Movie* movies;
	int capacity;
	int size;

	void resize(int newCapacity) {
		Movie* newMovies = new Movie[newCapacity];
		for (int i = 0; i < size; ++i) {
			newMovies[i] = movies[i];
		}
		delete[] movies;
		movies = newMovies;
		capacity = newCapacity;
}


public:
	MovieDatabase() : movies(new Movie[1]), capacity(1), size(0) {}

	~MovieDatabase() {
		delete[] movies;
	}

void addMovie(const string& title, const string& genre, const int& year, const float& rating) {
	if (size == capacity) {
		resize(2 * capacity);
	}
	movies[size].title = title;
	movies[size].genre = genre;
	movies[size].year = year;
	movies[size].rating = rating;
	size++;

	ofstream file("movieData.txt", ios::app);
	if (file) {
		file << title << "\n" << genre << "\n" << year << "\n" << rating << "\n";
		file.close();
		cout << "Movie added and saved successfully!" << endl;
	}
	else {
		cout << "Error saving movie to file!" << endl;
	}
}

void removeMovie(const string& title) {
	int index = -1;
	for (int i = 0; i < size; ++i) {
		if (movies[i].title == title) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int j = index; j < size - 1; ++j) {
			movies[j] = movies[j + 1];
		}
		size--;
		cout << "Movie " << title << " removed successfully." << endl;

		ofstream file("movieData.txt");
		if (file) {
			for (int i = 0; i < size; ++i) {
				file << movies[i].title << "\n"
					<< movies[i].genre << "\n"
					<< movies[i].year << "\n"
					<< movies[i].rating << "\n";
			}
			file.close();
			cout << "File updated successfully." << endl;
		}
		else {
			cout << "Error updating file after removal!" << endl;
		}
	}
	else {
		cout << "Movie " << title << " not found." << endl;
	}
}

void loadData(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cout << "Error opening file: " << filename << endl;
		return;
	}

	string title;
	string genre;
	int year;
	float rating;

	while (getline(file, title) && getline(file, genre) && file >> year >> rating) {
		file.ignore();
		addMovie(title, genre, year, rating);
	}
	file.close();
	cout << "Movies loaded successfully from " << filename << endl;
}

};
	int main() {
	MovieDatabase mdb;
	mdb.loadData("movieData.txt");
	int userInput;
	string title;
	string genre;
	int year;
	float rating;
	string filename;


	do {
		cout << "\nChoose from the options below : " << endl;
		cout << "1. Add new movies" << endl;
		cout << "2. Search by movie title" << endl;
		cout << "3. Search by release year" << endl;
		cout << "4. Search by genre" << endl;
		cout << "5. Display all movies" << endl;
		cout << "6. Remove a movie" << endl;
		cout << "7. Exit" << endl;
		cout << endl;
		cout << "Enter your choice: ";
		cin >> userInput;
		cin.ignore();

		switch (userInput) {
		case 1:
			cout << "What movie would you like to add:" << endl;
			cout << "Title: ";
			getline(cin, title);
			cout << "Genre: ";
			getline(cin, genre);
			cout << "Release Year: ";
			cin >> year;
			cout << "Rating: ";
			cin >> rating;
			cin.ignore();
			mdb.addMovie(title, genre, year, rating);
			break;
		case 2:
			cout << "Search the movie title: ";
			getline(cin, title);
			break;
		case 3:
			cout << "Enter a release year: ";
			cin >> year;
			break;
		case 4:
			cout << "Enter the genre below: ";
			getline(cin, genre);
			break;
		case 5:
			cout << "Here are all the movies: " << endl;
			cout << "movieData.txt";
			break;
		case 6:
			cout << "Enter movie you want to remove: " << endl;
			getline(cin, title);
			mdb.removeMovie(title);
			break;
		case 7:
			return 0;
		default:
			cout << "Invalid choice. Choose between 1 and 7." << endl;
			break;
		}


	} while (userInput != 7);

	
	return 0;
}
