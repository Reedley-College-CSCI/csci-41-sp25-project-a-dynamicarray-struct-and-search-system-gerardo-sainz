#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

bool checkUserYear = false;
bool checkUserRating = false;

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

void searchMovieTitle(const string& title) {
		bool found = false;
		
		DWORD startTime = GetTickCount();

		for (int i = 0; i < size; ++i) {
			if(movies[i].title == (title)) {
				cout << "\nTitle: " << movies[i].title << endl;
				cout << "Genre: " << movies[i].genre << endl;
				cout << "Year: " << movies[i].year << endl;
				cout << "Rating: " << movies[i].rating << endl;
				found = true;
				break;
			}

		}

			DWORD endTime = GetTickCount();
			DWORD searchTime = endTime - startTime;


		if (!found) {
			cout << "Movie not found in database." << endl;
			cout << "Make sure first letter of each word is capitalized and not misspelled." << endl;
		}

		cout << "Search time: " << searchTime << " milliseconds" << endl;
	}

void searchMovieGenre(const string& genre) {
	bool found = false;

		DWORD startTime = GetTickCount();

		for (int i = 0; i < size; ++i) {
			if(movies[i].genre == (genre)) {
				cout << "\nTitle: " << movies[i].title << endl;
				cout << "Genre: " << movies[i].genre << endl;
				cout << "Year: " << movies[i].year << endl;
				cout << "Rating: " << movies[i].rating << endl;
				found = true;
			}
		}

		DWORD endTime = GetTickCount();
		DWORD searchTime = endTime - startTime;

		if (!found) {
			cout << "genre " << genre << " not found in database." << endl;
			cout << "Make sure first letter is capitalized and spelled correctly." << endl;
		}

		cout << "Search time: " << searchTime << " milliseconds" << endl;
}

void searchMovieYear(const int& year) {
	bool found = false;

	DWORD startTime = GetTickCount();


		for (int i = 0; i < size; ++i) {
			if(movies[i].year == (year)) {
				cout << "\nTitle: " << movies[i].title << endl;
				cout << "Genre: " << movies[i].genre << endl;
				cout << "Year: " << movies[i].year << endl;
				cout << "Rating: " << movies[i].rating << endl;
				found = true;
			}
		}

	DWORD endTime = GetTickCount();
	DWORD searchTime = endTime - startTime;

		if (!found) {
			cout << "No Movie from " << year << " found in database." << endl;
		}

		cout << "Search time: " << searchTime << " milliseconds" << endl;
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
			cout << "Error updating file after removal." << endl;
		}
	}
	else {
		cout << "Movie " << title << " not found." << endl;
		cout << "Make sure first letter of each word is capitalized and not misspelled." << endl;
	}
}

void loadData(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cout << "Error opening file: " << filename << endl;
		return;
	}

	size = 0;

	string title;
	string genre;
	int year;
	float rating;

	while (getline(file, title) && getline(file, genre) && file >> year >> rating) {
		file.ignore();
		if (size == capacity) {
			resize(2 * capacity);
		}
		movies[size].title = title;
		movies[size].genre = genre;
		movies[size].year = year;
		movies[size].rating = rating;
		size++;
	}
	file.close();
	cout << "Movies loaded successfully from " << filename << endl;
}

void displayDatabase() {
	for(int i = 0; i < size; ++i){
		cout << "\nTitle: " << movies[i].title << " | Genre: " << movies[i].genre << " | Year: " << movies[i].year << " | Rating: " << movies[i].rating << endl;
	}
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

		cout << "\n------ Reedley's Movie Database ------" << endl;

	do {
		cout << "\nChoose from the options below : " << endl;
		cout << "1. Search by Movie Title" << endl;
		cout << "2. Search by Genre" << endl;
		cout << "3. Search by Release Year" << endl;
		cout << "4. Add New Movie" << endl;
		cout << "5. Remove A Movie" << endl;
		cout << "6. Display All Movies" << endl;
		cout << "7. Exit" << endl;
		cout << endl;
		cout << "Enter your choice: ";
		
		if (!(cin >> userInput)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "You must enter an integer." << endl;
			continue;
		}
		cin.ignore();
		

		switch (userInput) {
		case 1:
			cout << "Search the movie title: ";
			getline(cin, title);
			mdb.searchMovieTitle(title);
			break;
		case 2:
			cout << "Enter the genre below: ";
			getline(cin, genre);
			mdb.searchMovieGenre(genre);
			break;
		case 3:
			cout << "Enter a release year: ";
			if (!(cin >> year)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "You must enter an integer." << endl;
				continue;
			}
			cin.ignore();
			mdb.searchMovieYear(year);
			break;
		case 4:
			cout << "What movie would you like to add (capitalize first letter of each word):" << endl;
			cout << "Title: ";
			getline(cin, title);
			cout << "Genre (only one genre): ";
			getline(cin, genre);
			do{
				cout << "Release Year: ";
				if (!(cin >> year)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "You must enter an valid year." << endl;
				} else {
					checkUserYear = true;
				}
			} while(checkUserYear == false);
				cin.ignore();
			do{
				cout << "Rating (0.0/10): ";
				if (!(cin >> rating)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "You must enter an valid rating." << endl;
				} else {
					checkUserRating = true;
				}
			} while(checkUserRating == false);
				cin.ignore();
			mdb.addMovie(title, genre, year, rating);
			break;
		case 5:
			cout << "Enter movie you want to remove: " << endl;
			getline(cin, title);
			mdb.removeMovie(title);
			break;
		case 6:
			cout << "Here are all the movies in the database: " << endl;
			mdb.displayDatabase(); 
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
