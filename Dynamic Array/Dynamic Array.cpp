#include <iostream>
using namespace std;

// Adds a number to the end — if full, doubles capacity first
void push_back(int*& data, int& size, int& capacity, int val) {
	if (size == capacity) {
		capacity *= 2;
		int* newData = new int[capacity];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	data[size++] = val;
}

// Removes the last element — just decreases size by 1
void pop_back(int& size) {
	size--;
}

// Returns the element at a given index
void get(int* data, int index) {
	cout << "The element at " << index << " is " << data[index] << endl;
}

// Prints all current elements
void print(int* data, int size) {
	cout << "Your dynamic array: [";
	for (int i = 0; i < size; i++) {
		cout << data[i];
		if (i != size - 1) {
			cout << ", ";
		}
	}
	cout << "]";
	cout << endl;
}

// Frees the heap memory when you're done
void cleanup(int* data) {
	delete[] data;
}

int main() {

	int* data = new int[2];
	int size = 0, capacity = 2;
	int choice = 0;

	cout << "*****************************************" << endl;
	cout << "Welcome to the dynamic array app!!" << endl;

	do {

		cout << "\n";
		cout << "What operations do you want to perform?" << endl;
		cout << "1) Add an element" << endl;
		cout << "2) Pop an element" << endl;
		cout << "3) Get an element by index" << endl;
		cout << "4) Print all elements" << endl;
		cout << "5) Delete the dynamic array" << endl;
		cout << "6) Exit" << endl;
		cout << "Enter operation number: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int num;
			cout << "Enter a number to add: ";
			cin >> num;
			push_back(data, size, capacity, num);
			break;
		}
		case 2: {
			pop_back(size);
			cout << "Element removed!" << endl;
			break;
		}
		case 3: {
			int num;
			cout << "Enter the element's index: ";
			cin >> num;
			get(data, num);
			break;
		}
		case 4: {
			print(data, size);
			break;
		}
		case 5: {
			cleanup(data);
			cout << "Array cleared!" << endl;
			break;
		}
		case 6: {
			break;
		}
		default: {
			cout << "Invalid input" << endl;
		}
		}

	} while (choice != 6);

	cout << "\n";
	cout << "Thank you for using the dynamic array app!" << endl;
	cout << "*****************************************" << endl;

}