#include <iostream>
using namespace std;

struct book
{
    string bookTitle;
    string bookAuthor;
    string bookGenre;
    string bookEdition;
    short publishedYear;
    long long int isbnCode;
    struct book* prev;
    struct book* next;
};

struct book* head = nullptr;

void store(string title, string author, string genre, string edition, short year, long long int isbn)
{
    struct book* newBook = new book();
    newBook->bookTitle = title;
    newBook->bookAuthor = author;
    newBook->bookGenre = genre;
    newBook->bookEdition = edition;
    newBook->publishedYear = year;
    newBook->isbnCode = isbn;
    newBook->prev = nullptr;
    newBook->next = nullptr;

    if (head == nullptr) {
        head = newBook;
    }
    else {
        struct book* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBook;
        newBook->prev = temp;
    }

    cout << "Book stored successfully!" << endl;
}

void deleteBook(long long int isbn) {
    if (head == nullptr) {
        cout << "Library is empty. No book to delete." << endl;
        return;
    }

    struct book* temp = head;

    if (temp->isbnCode == isbn) {
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        cout << "Book deleted successfully!" << endl;
        return;
    }

    while (temp != nullptr && temp->isbnCode != isbn) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Book not found in the library." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Book deleted successfully!" << endl;
}

void editBook(long long int isbn)
{
    if (head == nullptr) {
        cout << "Library is empty. No book to edit." << endl;
        return;
    }

    struct book* temp = head;

    while (temp != nullptr) {
        if (temp->isbnCode == isbn) {
            string author, genre, edition;
            short year;
            long long int newIsbn;

            cout << "Enter the new author: ";
            cin>>author;

            temp->bookAuthor = author;

            cout << "Enter the new genre: ";
            cin>>genre;
            temp->bookGenre = genre;

            cout << "Enter the new edition: ";
            cin>>edition;
            temp->bookEdition = edition;

            cout << "Enter the new published year: ";
            cin >> year;
            temp->publishedYear = year;

            cout << "Enter the new ISBN code: ";
            cin >> newIsbn;
            temp->isbnCode = newIsbn;

            cout << "Book edited successfully!" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Book not found in the library." << endl;
}

void searchByTitle(string title)
{
    struct book* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->bookTitle == title) {
            cout << "Book found:" << endl;
            cout << "Title: " << temp->bookTitle << endl;
            cout << "Author: " << temp->bookAuthor << endl;
            cout << "Genre: " << temp->bookGenre << endl;
            cout << "Edition: " << temp->bookEdition << endl;
            cout << "Published Year: " << temp->publishedYear << endl;
            cout << "ISBN: " << temp->isbnCode << endl;
            cout << endl;
            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "No books found with the given title." << endl;
    }
}

void searchByAuthor(string author)
{
    struct book* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->bookAuthor == author) {
            cout << "Book found:" << endl;
            cout << "Title: " << temp->bookTitle << endl;
            cout << "Author: " << temp->bookAuthor << endl;
            cout << "Genre: " << temp->bookGenre << endl;
            cout << "Edition: " << temp->bookEdition << endl;
            cout << "Published Year: " << temp->publishedYear << endl;
            cout << "ISBN: " << temp->isbnCode << endl;
            cout << endl;
            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "No books found with the given author." << endl;
    }
}

void displayBooks()
{
    if (head == nullptr) {
        cout << "Library is empty. No books to display." << endl;
        return;
    }

    cout << "Books in the library:" << endl;

    struct book* temp = head;

    while (temp != nullptr) {
        cout << "Title: " << temp->bookTitle << endl;
        cout << "Author: " << temp->bookAuthor << endl;
        cout << "Genre: " << temp->bookGenre << endl;
        cout << "Edition: " << temp->bookEdition << endl;
        cout << "Published Year: " << temp->publishedYear << endl;
        cout << "ISBN: " << temp->isbnCode << endl;
        cout << endl;

        temp = temp->next;
    }
}

int main() {
    int userChoice;

    cout << "Welcome!" << endl;

    while (true) {
        cout << "Log in as:" << endl;
        cout << "1. Authorized person" << endl;
        cout << "2. Librarian" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            string authorizedPassword;
            cout << "Enter the authorized person password: ";
            cin >> authorizedPassword;

            if (authorizedPassword == "ABCD1234") {
                cout << "Welcome, authorized user!" << endl;

                // Prompt for authorized person actions
                int authorizedChoice;
                cout << "Choose an action:" << endl;
                cout << "1. Store a book" << endl;
                cout << "2. Delete a book" << endl;
                cout << "3. Edit a book" << endl;
                cout << "4. Search books by title" << endl;
                cout << "5. Search books by author" << endl;
                cout << "6. Display all books" << endl;
                cout << "7. Go back to the main menu" << endl;
                cout << "Enter your choice: ";
                cin >> authorizedChoice;

                switch (authorizedChoice) {
                    case 1: {
                          string title, author, genre, edition;
                    short year;
                    long long int isbn;

                    cout << "Enter the book title: ";
                    cin>>title;


                    cout << "Enter the book author: ";
                    cin>> author;

                    cout << "Enter the book genre: ";
                    cin>>genre;

                    cout << "Enter the book edition: ";
                    cin>> edition;

                    cout << "Enter the published year: ";
                    cin >> year;

                    cout << "Enter the ISBN code: ";
                    cin >> isbn;

                    store(title, author, genre, edition, year, isbn);
                    break;
                }

                    case 2: {
                    long long int isbn;
                    cout << "Enter the ISBN code of the book to delete: ";
                    cin >> isbn;
                    deleteBook(isbn);
                        break;
                    }
                    case 3: {
                    long long int isbn;
                    cout << "Enter the ISBN code of the book to edit: ";
                    cin >> isbn;
                    editBook(isbn);
                        break;
                    }
                    case 4: {
                    string title;
                    cout << "Enter the book title to search: ";
                    cin>>title;
                    searchByTitle(title);
                        break;
                    }
                    case 5: {
                                            string author;
                    cout << "Enter the author name to search: ";
                    cin>>author;
                    searchByAuthor(author);
                        break;
                    }
                    case 6: {
                        displayBooks();
                        break;
                    }
                    case 7: {
                        // Go back to the main menu
                        break;
                    }
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
            } else {
                cout << "Incorrect password. Access denied." << endl;
            }
        } else if (userChoice == 2) {
            string librarianPassword;
            cout << "Enter the librarian password: ";
            cin >> librarianPassword;

            if (librarianPassword == "1234ABCD") {
                cout << "Welcome, librarian!" << endl;

                // Prompt for librarian actions
                int librarianChoice;
                cout << "Choose an action:" << endl;
                cout << "1. Search books by title" << endl;
                cout << "2. Search books by author" << endl;
                cout << "3. Display all books" << endl;
                cout << "4. Go back to the main menu" << endl;
                cout << "Enter your choice: ";
                cin >> librarianChoice;

                switch (librarianChoice) {
                    case 1: {
                    string title;
                    cout << "Enter the book title to search: ";
                    cin>>title;
                    searchByTitle(title);
                        break;
                    }
                    case 2: {
                    string author;
                    cout << "Enter the author name to search: ";
                    cin>>author;
                    searchByAuthor(author);
                        break;
                    }
                    case 3: {
                        displayBooks();
                        break;
                    }
                    case 4: {
                        // Go back to the main menu
                        break;
                    }
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
            } else {
                cout << "Incorrect password. Access denied." << endl;
            }
        } else if (userChoice == 3) {
            // Exit the program
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}

