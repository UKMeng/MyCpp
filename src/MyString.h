//
// Created by ukm on 2025/8/26.
//

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

namespace MyCpp
{
    class MyString
    {
    public:
        MyString();
        MyString(const char* str);

        ~MyString();

        MyString(const MyString& other);  // 拷贝构造函数 深拷贝
        MyString& operator=(const MyString& other); // 拷贝赋值运算符 深拷贝
        MyString(MyString&& other) noexcept; // 移动构造函数
        MyString& operator=(MyString&& other) noexcept; // 移动赋值运算符

        size_t Size() const;
        size_t Capacity() const;
        bool IsEmpty() const;

        const char* Cstr() const;

        char& operator[](size_t index);
        const char& operator[](size_t index) const;

        MyString& operator+=(const MyString& other);

    private:
        char* m_data;
        size_t m_size;
        size_t m_capacity;
    };

    std::ostream& operator<<(std::ostream& os, const MyString& str);

} // MyCpp


#endif //MYSTRING_H
