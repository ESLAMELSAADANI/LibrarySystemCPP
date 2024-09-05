// LibrarySystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
const int max_books = 100;
int ids[max_books];
string title[max_books];
string author[max_books];
bool availability[max_books];
int bookCount = 0;

void addBook() {
	if (bookCount >= max_books) {
		cout << "Library is fulll, can not add more books\n";
		return;
	}
	cout << "Enter Book ID : \n";
	cin >> ids[bookCount];
	cin.ignore();
	cout << "Enter Book Title: \n";
	getline(cin, title[bookCount]);
	cout << "Enter Book Author : \n";
	getline(cin, author[bookCount]);
	availability[bookCount] = true;
	bookCount++;
	cout << "Book Added Successfully\n";
}
int searchBook(int id) {
	for (int i = 0; i < bookCount; i++) {
		if (ids[i] == id) {
			return i;
		}
	}
	return -1;
}
void removeBook(int id) {
	int index = searchBook(id);
	if (index == -1) {
		cout << "Book not found\n";
		return;
	}
	for (int i = index; i < bookCount - 1; i++) {
		ids[i] = ids[i + 1];
		title[i] = title[i + 1];
		author[i] = author[i + 1];
		availability[i] = availability[i + 1];
	}
	bookCount--;
	cout << "Book removes successfully\n";

}
void updateBook(int id) {
	int index = searchBook(id);
	if (index == -1) {
		cout << "Book not found\n";
		return;
	}
	cout << "Enter New Title: \n";
	cin.ignore();
	getline(cin, title[index]);

	cout << "Enter new Author: \n";
	getline(cin, author[index]);

	cout << "Book Updated Successfully\n";
}
void borrowBook(int id) {
	int index = searchBook(id);
	if (index == -1) {
		cout << "Book Not Found\n";
		return;
	}
	if (!availability[index]) {
		cout << "Book Is Already borrowed\n";
		return;
	}
	availability[index] = false;
	cout << "Book Borrowed Successfully\n";
}
void returnBook(int id) {
	int index = searchBook(id);
	if (index == -1) {
		cout << "Book Not Found\n";
		return;
	}
	if (availability[index]) {
		cout << "Book is already available\n";
		return;
	}
	availability[index] = true;
	cout << "Book returned successfully\n";
}
void displayBooks() {
	if (bookCount == 0) {
		cout << "No Book Available In Library\n";
		return;
	}
	cout << "\nList Of Books In The Library:\n";
	for (int i = 0; i < bookCount; i++) {
		cout << "ID: " << ids[i] << ", Title: " << title[i] << ", Author: " << author[i] << ", Availability: " << (availability[i] ? "Available" : "Borrowed") << endl;
	}
}
int main()
{
	int choice, id;
	
	while (true) {
		cout << "\n1.Add Book\n2.Remove Book\n3.Update Book\n4.Borrow Book\n5.Return Book\n6.Display Book\n7.Exit\n";
		cout << "Enter Your Choice: \n";
		cin >> choice;

		switch (choice) {
		case 1:
			addBook();
			break;
		case 2:
			cout << "Enter Book ID To Remove:\n";
			cin >> id;
			removeBook(id);
			break;
		case 3:
			cout << "Enter Book ID To Update:\n";
			cin >> id;
			updateBook(id);
			break;
		case 4:
			cout << "Enter Book ID To Borrow:\n";
			cin >> id;
			borrowBook(id);
			break;
		case 5:
			cout << "Enter Book ID To Return:\n";
			cin >> id;
			returnBook(id);
			break;
		case 6:
			displayBooks();
			break;
		case 7:
			return 0;
		default:
			cout << "Invalid Choice. Please try again\n";
		}
	}
}

