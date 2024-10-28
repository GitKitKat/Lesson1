#include <iostream>

using namespace std;

struct Rectangle {

	int height = 0;
	int width = 0;

};

void changeRectangle(Rectangle& RectA, Rectangle RectB);
void logRectangle(Rectangle& RectA, Rectangle RectB);

int task3() {

	Rectangle RectangleA;
	Rectangle RectangleB;

	cout << "Before 'changeRectangle' is called." << endl;
	logRectangle(RectangleA,RectangleB);
	changeRectangle(RectangleA,RectangleB);
	cout << "\nAfter 'changeRectangle' is called." << endl;
	changeRectangle(RectangleA, RectangleB);
	logRectangle(RectangleA, RectangleB);

	compArea(RectangleA, RectangleB);

	return 0;
}

void changeRectangle(Rectangle& RectA, Rectangle RectB) {

	RectA.height = 20;
	RectA.width = 25;

	RectB.height = 31;
	RectB.width = 36;

}

void logRectangle(Rectangle& RectA, Rectangle RectB) {

	cout << "The values of Rectangle A are: " << "width " << RectA.width << " and height " << RectA.height << endl;
	cout << "The values of Rectangle B are: " << "width " << RectB.width << " and height " << RectB.height << endl;

}

void compArea(Rectangle& RectA, Rectangle& RectB) {

	int areaRectA = RectA.width * RectA.height;
	int areaRectB = RectB.width * RectB.height;

	if (areaRectA >= areaRectB) {
		cout << "\nThe area of Rectangle A, " << areaRectA << ", is larger than or equal to that of Rectangle B, " << areaRectB << endl;
	} else {
		cout << "\nThe area of Rectangle B, " << areaRectB << ", is larger than that of Rectangle A, " << areaRectA << endl;
	}

}