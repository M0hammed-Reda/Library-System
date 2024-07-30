#include <iostream>
#include <algorithm>
using namespace std;

struct Book {
    int id;
    string name;
    int quantity;
    int borrowed_quantity;
    Book() {
        id = 0;
        quantity = 0;
        borrowed_quantity = 0;
    }
};

struct User {
    int id;
    string name;
    User() {
        id = 0;
    }
};

struct Library {
    Book books[100];
    int book_index = 0;
    User users[100];
    int user_index = 0;
    string result[100];
    string users_borrowed[100][100]{ "\0" };
    int borrowed_book[100]{ 0 };
    int B_inx = 0;
    int U_inx = 0;

    bool static compare_name(Book& a, Book& b) {
        return a.name < b.name;
    }

    bool static compare_id(Book& a, Book& b) {
        return a.id < b.id;
    }

    void add_book() {
        int id;
        string name;
        int quantity;
        
        cout << "Enter Book info: ID & Name & Total quantity: ";
        cin >> id >> name >> quantity;

        books[book_index].id = id;
        books[book_index].name = name;
        books[book_index].quantity = quantity;
        book_index++;
    }
    

    void add_user() {
        int id;
        string name;

        cout << "Enter User Name & National id: ";
        cin >> name >> id;

        users[user_index].id = id;
        users[user_index].name = name;
        user_index++;
    }

    void prefix_search() {
        string prefix;
        cout << "Enter Book name prefix: ";
        cin >> prefix;

        for (int i = 0; i < book_index; i++) {
            if (books[i].name.find(prefix) == 0) {
                cout << books[i].name << endl;
            }
        }
    }

    void print_library_by_id() {
        sort(books, books + book_index, compare_id);
        int j = 0;
        for (int i = 0; i < book_index; i++) {
            cout << "id = " << books[i].id << " , name : " << books[i].name
                << " , total quantity = " << books[i].quantity << " , total borrowed = " << books[i].borrowed_quantity << endl;
        }
    }

    void sort_library_by_name() {
        sort(books, books + book_index, compare_name);
        int j = 0;
        for (int i = 0; i < book_index; i++) {
            cout << "id = " << books[i].id << " , name : " << books[i].name
                << " , total quantity = " << books[i].quantity << " , total borrowed = " << books[i].borrowed_quantity << endl;
        }
    }

    void borrow_book() {
        string _name;
        string _book;
        cout << "Enter user name and book name : ";
        cin >> _name >> _book;

        for (int i = 0; i < book_index; i++) {
            if (books[i].name == _book && books[i].quantity == 0) {
                 cout << "There isn't no book for now!\n";
                break;
            }
            else if (books[i].name == _book && books[i].quantity > 0) {
                borrowed_book[B_inx] = i;
                B_inx++;
                books[i].borrowed_quantity++;
                books[i].quantity--;
                for (int j = 0; j < user_index; j++) {
                    if (users[j].name == _name) {
                        users_borrowed[borrowed_book[U_inx]][U_inx] = _name;
                        U_inx++;
                    }
                }
            }
        }
    }

    void print_who_borrowed_book() {
        string book;
        cout << "Enter Book name : ";
        cin >> book;

        for (int i = 0; i < book_index; i++) {
            if (books[i].name == book) {
                for (int j = 0; j < U_inx; j++) {
                    if (users_borrowed[i][j] != users_borrowed[i][j+1])
                        cout << users_borrowed[i][j] << endl;
                }
                break;
            }
        }
    }

    void return_book() {
        string _name;
        string _book;
        cout << "Enter user name and book name : ";
        cin >> _name >> _book;

        int rb = 0;
        for (; rb < book_index; rb++) {
             if (books[rb].name == _book) {
                B_inx--;
                books[rb].quantity++;
                books[rb].borrowed_quantity--;
             }
        }

        string temp[100][100];
        int inx = 0;

        for (int j = 0; j < borrowed_book[B_inx]; j++) {
            if (j != rb) {
                for (int k = 0; k < U_inx; k++) {
                    temp[inx][j] = users_borrowed[j][k];
                }
                ++inx;
            }
        }
        
        for (int i = 0; i < borrowed_book[B_inx] - 1; ++i) {
            for (int j = 0; j < U_inx; ++j) {
                users_borrowed[i][j] = temp[i][j];
            }
        }
    }

    void print_users() {
        for (int i = 0; i < user_index; i++) {
            cout << "user : " << users[i].name << " has id : " << users[i].id << " and he borrowed books ids :  ";
            for (int j = 0; j < user_index; j++) {
                for (int k = 0; k < U_inx; k++) {
                    if (users_borrowed[j][k] == users[i].name) {
                        cout << books[j].id << "  ";
                    }
                }
            }
            cout << endl;
        }
    }
};

struct LibrarySystem {

    void menu() {
        cout << "\nLibrary menu : \n\n";
        cout << "1) Add Book.\n";
        cout << "2) Search Book by predix.\n";
        cout << "3) Print who borrowed book by name.\n";
        cout << "4) Print libray by id.\n";
        cout << "5) Print libray by name.\n";
        cout << "6) Add User.\n";
        cout << "7) User borrow book.\n";
        cout << "8) User retunr book.\n";
        cout << "9) Print Users.\n";
        cout << "10) Exit.\n";
    }

    void run() {
        Library library;
        while (true) {
            menu();
            int op;
            cout << "\nEnter your menu choice [1 : 10]: ";
            cin >> op;
            
            switch (op) {
                case 1:
                    library.add_book();
                    break;
                case 2:
                    library.prefix_search();
                    break;
                case 3:
                    library.print_who_borrowed_book();
                    break;
                case 4:
                    library.print_library_by_id();
                    break;
                case 5:
                    library.sort_library_by_name();
                    break;
                case 6:
                    library.add_user();
                    break;
                case 7:
                    library.borrow_book();
                    break;
                case 8:
                    library.return_book();
                    break;
                case 9:
                    library.print_users();
                    break;
                case 10:
                    exit(0);
                    break;
                default:
                    cout << "Invalid Choice! Try again.\n";
                    break;
                    break;
            }
        }
    }
};

int main()
{
    LibrarySystem library;
    library.run();
}
