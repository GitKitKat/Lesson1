#include "Car.h"

int carObject() {

	Car myCar;
	myCar.SetYear(2020);
	myCar.Service();

	Car CaydensCar;
	CaydensCar.SetYear(2015);
	CaydensCar.Service();

	Car* BrendonsCar = new Car();
	BrendonsCar->SetYear(2018); 

	return 0;
}