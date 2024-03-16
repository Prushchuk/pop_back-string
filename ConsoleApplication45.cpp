#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:
    MyString(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }

    ~MyString() {
        delete[] data;
    }

    void pop_back() {
        if (length > 0) {
            data[length - 1] = '\0';
            --length;
        }
    }

    MyString& operator+=(const MyString& other) {
        char* newData = new char[length + other.length + 1];
        strcpy_s(newData, length + other.length + 1, data);
        strcat_s(newData, length + other.length + 1, other.data);
        delete[] data;
        data = newData;
        length += other.length;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
        os << myStr.data;
        return os;
    }
};

int main() {
    MyString str("Hello");
    std::cout << "Before: " << str << std::endl;
    str.pop_back();
    std::cout << "After: " << str << std::endl;

    MyString str1("Hello");
    MyString str2(" world");
    str1 += str2;
    std::cout << "After concatenation: " << str1 << std::endl;

}