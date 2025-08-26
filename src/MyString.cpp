//
// Created by ukm on 2025/8/26.
//

#include "MyString.h"

#include <cstring>
#include <utility>

namespace MyCpp
{
    MyString::MyString() : m_data(new char[1]), m_size(0), m_capacity(0)
    {
        m_data[0] = '\0';
    }

    MyString::MyString(const char* str)
    {
        if (str == nullptr)
        {
            m_data = new char[1];
            m_data[0] = '\0';
            m_size = 0;
            m_capacity = 0;
        }
        else
        {
            m_size = strlen(str);
            m_capacity = m_size;
            m_data = new char[m_capacity + 1];
            strcpy(m_data, str);
        }
    }

    MyString::~MyString()
    {
        delete[] m_data;
    }

    MyString::MyString(const MyString& other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new char[m_capacity + 1];
        strcpy(m_data, other.m_data);
    }

    MyString& MyString::operator=(const MyString &other)
    {
        if (this != &other)
        {
            MyString temp(other);
            std::swap(m_data, temp.m_data);
            std::swap(m_size, temp.m_size);
            std::swap(m_capacity, temp.m_capacity);
        }

        return *this;
    }

    MyString::MyString(MyString&& other) noexcept
        : m_data(other.m_data), m_size(other.m_size), m_capacity(other.m_capacity)
    {
        // 置空，避免被析构函数释放内存
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    MyString &MyString::operator=(MyString &&other) noexcept
    {
        if (this != &other)
        {
            delete[] m_data;

            m_data = other.m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.m_data = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }

        return *this;
    }



    size_t MyString::Size() const
    {
        return m_size;
    }

    size_t MyString::Capacity() const
    {
        return m_capacity;
    }

    bool MyString::IsEmpty() const
    {
        return m_size == 0;
    }

    const char* MyString::Cstr() const
    {
        return m_data;
    }

    std::ostream& operator<<(std::ostream& os, const MyString& str)
    {
        os << str.Cstr();
        return os;
    }

} // MyCpp