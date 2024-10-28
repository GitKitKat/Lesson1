#include <iostream>

using namespace std;

void callPerson(string name, int age, float height);

struct Person {

	string name;
	int age;
	float height; // in meters

}; // avoid instancing after the struct: (ie struct A {} objA, objB; ) 

int task1() {

	Person PersonA;
	Person PersonB;

	PersonA.name = "Specter";
	PersonA.age = 20;
	PersonA.height = 1.62f;

	PersonB.name = "Laurentina";
	PersonB.age = 22;
	PersonB.height = 1.65f;

	cout << "The size of the Person structure is: " << sizeof(Person) << " bytes.\n\n";

	cout << "The details of Person A are: " << endl;
	string* nameptr = &PersonA.name;
	int* ageptr = &PersonA.age;
	float* heightptr = &PersonA.height;
	callPerson(*nameptr, *ageptr, *heightptr);

	cout << "\nThe details of Person B are: " << endl;
	nameptr = &PersonB.name;
	ageptr = &PersonB.age;
	heightptr = &PersonB.height;
	callPerson(*nameptr, *ageptr, *heightptr);

	return 0;
}

void callPerson(string name, int age, float height) { 

	cout << "Name: " << name << "\nAge: " << age << "\nHeight: " << height << endl;

}