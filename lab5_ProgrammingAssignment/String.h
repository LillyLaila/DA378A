#ifndef STRING_H
#define STRING_H

#include <iostream>  // For std::ostream
#include <cstddef>   // For size_t
#include <cassert>   // For assert

class String {
public:
    String();
    String(const String& rhs);
    String(const char* cstr);
    ~String();

    String& operator=(const String& rhs);

    char& operator[](size_t i);
    const char& operator[](size_t i) const;

    size_t size() const;
    size_t capacity() const;

    void push_back(char c);
    const char* data() const;
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
    friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
    char* str;
    size_t kapacitet;
    size_t storlek;

    void Invariant() const;
    void reallocate(size_t new_cap);
};

#endif // STRING_H
