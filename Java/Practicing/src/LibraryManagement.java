
class Library{
    String[] books;
    int no_of_books;
    Library() {
        this.books = new String[100];
        int no_of_books = 0;
    }

    void addBook(String book){
        this.books[no_of_books] = book;
        no_of_books++;
        System.out.println(book + " has been added");
    }

    void showAvailableBooks(){
        System.out.println("Available books are:");
        for (String book: this.books) {
            if (book == null) continue;
            System.out.println("* " + book);
        }
    }

    void issueBook(String book){
        for (int i=0; i<this.books.length; i++) {
            if (this.books[i].equals(book)) {
                System.out.println(book + " has been issued!");
                this.books[i] = null;
                return;
            }
        }

        System.out.println("This book is not available");
    }

    void returnBook(String book) {
        for (int i=0; i<this.books.length; i++) {
            if (this.books[i] == null) {
                this.books[i] = book;
                System.out.println(book + " has been returned");
                return;
            }
        }
    }
}
public class LibraryManagement {
    public static void main(String[] args) {
        // You have to implement a library using Java Class Library
        // Methods: addBook, issueBook, showAvailableBooks
        // Properties: Array to store the available books
        // Array to store the issued books

        Library centralLibrary = new Library();
        centralLibrary.addBook("C++");
        centralLibrary.addBook("Algorithms");
        centralLibrary.showAvailableBooks();
        centralLibrary.issueBook("C++");
        centralLibrary.showAvailableBooks();
        centralLibrary.returnBook("C++");
        centralLibrary.showAvailableBooks();
    }
}
