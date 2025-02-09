My movie database project does have a dynamic array that resizes itself if the capacity is ever reached which doubles the capacity and transfers the data to the new array. 
The loadData function in my project reads the data from the external file "movieData.txt" and inputs them into the dynamic array. 
The addMovie function allows the user to input new movies by inputing the title, genre, release year, and rating
The removeMovie function goes through the dynamic array and gets rid of the movie and its genre, year, and rating using the title inputed by a user.
I do have a Movie struct with the string data types for the movie title, and genre, then int data type for the movies release year, and a float data type for the movie rating.
The movie struct is used in my MovieDatabase class throughout the functions 
The data in the text file is orgainzed by following the format of title, line under that genre, then year, and then rating.
My user interface is pretty user friendly, and does give them the option to search by movie title, genre, year, and it gives them the option to add or remove a movie if they want. I do provide guides to where they couldve inputed something wrong that would lead to undesired results, and the option to quit the program is also there.
My project does have three search function that can use the movies title, genre, and year to find if that movie is in the database
Using the gettickcount function it does seem that my linear search function does take 0 milliseconds if it just looks for one movie, but take 15-16 milliseconds if it has to find more then one movie when it searches by genre and year.
I would say that capitalization is my only problem but I do say what the format of the inputs should be, still the program wouldnt break is someone used wrong capitalization, but the search would have to have that exact same input to find it.
My project wouldnt have many runtime exceptions as if it doesnt know what the input is it just doesnt accept it and takes the user back to the options menu.
The rubric for this project did provide good feedback on what to add to make sure I get full points, as I did forget somethings like the gettick function, two different data types for the strcut, what options the user was available to do like searching and adding, etc. The feedback on the project idea did also help me narrow done the broadness of what I wanted to include for the data.
