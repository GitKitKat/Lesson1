#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// 16 characters across, 11 down
constexpr auto row = 11;
constexpr auto column = 16;

// function to move a dot through the maze
int mazeRunner(char arr[r][c]);
void mazeCompleted();

int main() {

	ifstream infMaze("Maze.txt");
	char charMaze[row][column];
	string mazeLine;

	if (!infMaze) {
		cout << "The text file, 'Maze.txt', couldn't be opened." << endl;
		return 0;

	}
	else {

		for (int i = 0; i < row; i++) {

			getline(infMaze, mazeLine);
			for (int j = 0; j < column; j++) {

				charMaze[i][j] = mazeLine[j];
				cout << charMaze[i][j];

			}

			cout << endl;
		}
		infMaze.close();
	}





	return 0;
}

int mazeRunner(char arr[r][c]) {

	char runner[2];

	if (arr[r][c + 1] == " ") {

		runner[0] = r;
		runner[1] = c + 1;

	}
	else if (arr[r + 1][c] == " ") {

		runner[0] = r + 1;
		runner[1] = c;

	} 
	else if (arr[r][c - 1] == " ") {

		runner[0] = r;
		runner[1] = c - 1;

	}
	else if (arr[r - 1][c] == " ") {

		runner[0] = r - 1;
		runner[1] = c;

	}

	return runner;
}

void mazeCompleted() {



}