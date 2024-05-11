#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory>

class Book {
protected:
    std::string title;
    std::string author;
    double price;

public:
    Book(const std::string& title, const std::string& author, double price)
        : title(title), author(author), price(price) {}

    virtual void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Price: $" << price;
    }

    virtual ~Book() = default;

    // Accessor methods
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }
};

class DigitalBook : public Book {
    double fileSize;

public:
    DigitalBook(const std::string& title, const std::string& author, double price, double fileSize)
        : Book(title, author, price), fileSize(fileSize) {}

    void display() const override {
        Book::display();
        std::cout << ", File Size: " << fileSize << "MB";
    }
};

class Inventory {
    std::vector<std::shared_ptr<Book>> books;

public:
    void addBook(const std::shared_ptr<Book>& book) {
        books.push_back(book);
    }

    void listBooks() const {
        for (const auto& book : books) {
            book->display();
            std::cout << std::endl;
        }
    }

    void saveToFile(const std::string& filename) const {
        try {
            std::ofstream file(filename);
            if (!file) {
                throw std::runtime_error("Cannot open file for writing.");
            }
            for (const auto& book : books) {
                file << "Title: " << book->getTitle()
                     << ", Author: " << book->getAuthor()
                     << ", Price: $" << book->getPrice()
                     << std::endl;
            }
            file.close();
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

int main() {
    Inventory inventory;

    inventory.addBook(std::make_shared<Book>("1984", "George Orwell", 19.99));
    inventory.addBook(std::make_shared<DigitalBook>("Brave New World", "Aldous Huxley", 9.99, 2.5));

    std::cout << "Listing all books:" << std::endl;
    inventory.listBooks();

    inventory.saveToFile("inventory.txt");

    return 0;
}
