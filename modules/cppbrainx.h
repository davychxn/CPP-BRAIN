// Creator: Davy (Dawei) Chen
// Time: August 8th, 2020
// Email: cndv3996@163.com

#ifndef SWT_CPP_BRAINX_H
#define SWT_CPP_BRAINX_H

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <vector>
#include <list>
#include <set>
#include <string>

#include "./data.h"

namespace swt
{
    template <typename T>
    class CPPBrainx
    {
    public:
        static std::vector<T> delete_elements(std::vector<T>& source, std::vector<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::vector<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::list<T>& source, std::vector<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::list<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::set<T>& source, std::vector<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::set<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::vector<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::vector<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::list<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::list<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::set<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::set<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> map(const std::vector<T>& source, T (*map_func)(T));
        static std::vector<T> map(const std::list<T>& source, T (*map_func)(T));
        static std::vector<T> map(const std::set<T>& source, T (*map_func)(T));
        static std::vector<T> map(const std::initializer_list<T>& source, T (*map_func)(T));
        static std::vector<T> to_vector(const std::list<T>& source);
        static std::vector<T> to_vector(const std::set<T>& source);
        static std::vector<T> to_vector(const std::initializer_list<T>& source);
        static T sum(const std::initializer_list<T>& args);
        static T sum(const std::vector<T>& args);
        static T sum(const std::list<T>& args);
        static T sum(const std::set<T>& args);
        static std::string join(const std::vector<T>& values, const char* delimiter);
        static std::string join(const std::list<T>& values, const char* delimiter);
        static std::string join(const std::set<T>& values, const char* delimiter);
        static std::string to_string(const T value);
        static std::string to_type(const T value);
        static void print(const std::vector<T>& values, const char* delimiter = ", ");
        static void print(const std::list<T>& values, const char* delimiter = ", ");
        static void print(const std::set<T>& values, const char* delimiter = ", ");
        static void print(const std::initializer_list<T>& values, const char* delimiter = ", ");
        static void push_elements(std::vector<T>& dest, std::initializer_list<T> elements);
        static void push_elements(std::list<T>& dest, std::initializer_list<T> elements);
        static void push_elements(std::set<T>& dest, std::initializer_list<T> elements);
        static void release(T& resource);
        static void release(std::vector<T>& resource);
        static void release(std::list<T>& resource);
        static void release(std::set<T>& resource);
        static void release(std::initializer_list<T>& resource);
        static void release_arr(T& resource);
        static void help();
        static void version();

    private:
        static void print_function1(T value, const char* delimiter = ", ", bool is_first = true);

    };

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements(std::vector<T>& source, std::vector<T> elements, bool is_return_deleted)
    {
        std::vector<T> deleted;

        for (auto element: elements)
        {
            auto pos = std::find(source.begin(), source.end(), element);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(*pos);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements(std::vector<T>& source, std::initializer_list<T> elements, bool is_return_deleted)
    {
        std::vector<T> deleted;

        for (auto element: elements)
        {
            auto pos = std::find(source.begin(), source.end(), element);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(*pos);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements_by_indices(std::vector<T>& source, std::vector<size_t> indices, bool is_return_deleted)
    {
        std::vector<T> deleted;

        // Sort descendingly
        std::sort(indices.begin(), indices.end(), [](const int a, const int b) {return a > b; });
        for (auto index: indices)
        {
            // Erase from back to front
            if (index < source.size())
            {
                auto it = source.begin();
                std::advance(it, index);
                if (is_return_deleted)
                {
                    deleted.push_back(*it);
                }
                source.erase(it);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements_by_indices(std::vector<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = CPPBrainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements(std::list<T>& source, std::vector<T> elements, bool is_return_deleted)
    {
        std::vector<T> deleted;

        for (auto element: elements)
        {
            auto pos = std::find(source.begin(), source.end(), element);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(*pos);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements(std::list<T>& source, std::initializer_list<T> elements, bool is_return_deleted)
    {
        std::vector<T> deleted;

        for (auto element: elements)
        {
            auto pos = std::find(source.begin(), source.end(), element);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(*pos);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements_by_indices(std::list<T>& source, std::vector<size_t> indices, bool is_return_deleted)
    {
        std::vector<T> deleted;

        // Sort descendingly
        std::sort(indices.begin(), indices.end(), [](const int a, const int b) {return a > b; });
        for (auto index: indices)
        {
            // Erase from back to front
            if (index < source.size())
            {
                auto it = source.begin();
                std::advance(it, index);
                if (is_return_deleted)
                {
                    deleted.push_back(*it);
                }
                source.erase(it);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements_by_indices(std::list<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = CPPBrainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements(std::set<T>& source, std::vector<T> elements, bool is_return_deleted)
    {
        std::vector<T> deleted;

        for (auto element: elements)
        {
            auto pos = source.find(element);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(*pos);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements(std::set<T>& source, std::initializer_list<T> elements, bool is_return_deleted)
    {
        std::vector<T> deleted;

        for (auto element: elements)
        {
            auto pos = source.find(element);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(*pos);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements_by_indices(std::set<T>& source, std::vector<size_t> indices, bool is_return_deleted)
    {
        std::vector<T> deleted;

        // Sort descendingly
        std::sort(indices.begin(), indices.end(), [](const int a, const int b) {return a > b; });
        for (auto index: indices)
        {
            // Erase from back to front
            if (index < source.size())
            {
                auto it = source.begin();
                std::advance(it, index);
                if (is_return_deleted)
                {
                    deleted.push_back(*it);
                }
                source.erase(it);
            }
        }

        return deleted;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::delete_elements_by_indices(std::set<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = CPPBrainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::to_vector(const std::list<T>& source)
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            v1.push_back(val);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::map(const std::vector<T>& source, T (*map_func)(T))
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            T val1 = (*map_func)(val);
            v1.push_back(val1);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::map(const std::list<T>& source, T (*map_func)(T))
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            T val1 = (*map_func)(val);
            v1.push_back(val1);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::map(const std::set<T>& source, T (*map_func)(T))
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            T val1 = (*map_func)(val);
            v1.push_back(val1);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::map(const std::initializer_list<T>& source, T (*map_func)(T))
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            T val1 = (*map_func)(val);
            v1.push_back(val1);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::to_vector(const std::set<T>& source)
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            v1.push_back(val);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> CPPBrainx<T>::to_vector(const std::initializer_list<T>& source)
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            v1.push_back(val);
        }

        return v1;
    }

    template <typename T>
    T CPPBrainx<T>::sum(const std::initializer_list<T>& args)
    {
        if (args.size() == 0)
        {
            throw "Invalid input.";
        }

        T sumVal = 0;
        for (auto val: args)
        {
            sumVal += val;
        }

        return sumVal;
    }

    template <typename T>
    T CPPBrainx<T>::sum(const std::vector<T>& args)
    {
        if (args.size() == 0)
        {
            throw "Invalid input.";
        }

        T sumVal = 0;
        for (auto val: args)
        {
            sumVal += val;
        }

        return sumVal;
    }

    template <typename T>
    T CPPBrainx<T>::sum(const std::list<T>& args)
    {
        if (args.size() == 0)
        {
            throw "Invalid input.";
        }

        T sumVal = 0;
        for (auto val: args)
        {
            sumVal += val;
        }

        return sumVal;
    }

    template <typename T>
    T CPPBrainx<T>::sum(const std::set<T>& args)
    {
        if (args.size() == 0)
        {
            throw "Invalid input.";
        }

        T sumVal = 0;
        for (auto val: args)
        {
            sumVal += val;
        }

        return sumVal;
    }

    template <typename T>
    std::string CPPBrainx<T>::join(const std::vector<T>& values, const char* delimiter)
    {
        std::vector<std::string> v1;

        for (auto val: values)
        {
            std::string t1 = to_string(val);
            v1.push_back(t1);
        }

        return swt::CommonComponents::join(v1, delimiter);
    }

    template <typename T>
    std::string CPPBrainx<T>::join(const std::list<T>& values, const char* delimiter)
    {
        std::vector<T> v1 = CPPBrainx<T>::to_vector(values);
        return join(v1, delimiter);
    }

    template <typename T>
    std::string CPPBrainx<T>::join(const std::set<T>& values, const char* delimiter)
    {
        std::vector<T> v1 = CPPBrainx<T>::to_vector(values);
        return join(v1, delimiter);
    }

    template <typename T>
    std::string CPPBrainx<T>::to_string(T value)
    {
        std::stringstream buffer;
        buffer << value;
        return buffer.str();
    }

    template <typename T>
    std::string CPPBrainx<T>::to_type(T value)
    {
        std::string t1 = typeid(T).name();
        return t1;
    }

    template <typename T>
    void CPPBrainx<T>::print(const std::vector<T>& values, const char* delimiter)
    {
        bool isFirst = true;

        for (auto val: values)
        {
            print_function1(val, delimiter, isFirst);
            isFirst = false;
        }

        CommonComponents::print_return();
    }

    template <typename T>
    void CPPBrainx<T>::print(const std::list<T>& values, const char* delimiter)
    {
        bool isFirst = true;

        for (auto val: values)
        {
            print_function1(val, delimiter, isFirst);
            isFirst = false;
        }

        CommonComponents::print_return();
    }

    template <typename T>
    void CPPBrainx<T>::print(const std::set<T>& values, const char* delimiter)
    {
        bool isFirst = true;

        for (auto val: values)
        {
            print_function1(val, delimiter, isFirst);
            isFirst = false;
        }

        CommonComponents::print_return();
    }

    template <typename T>
    void CPPBrainx<T>::print(const std::initializer_list<T>& values, const char* delimiter)
    {
        bool isFirst = true;

        for (auto val: values)
        {
            print_function1(val, delimiter, isFirst);
            isFirst = false;
        }

        CommonComponents::print_return();
    }

    template <typename T>
    void CPPBrainx<T>::push_elements(std::vector<T>& dest, std::initializer_list<T> elements)
    {
        for (auto element: elements)
        {
            dest.push_back(element);
        }
    }

    template <typename T>
    void CPPBrainx<T>::push_elements(std::list<T>& dest, std::initializer_list<T> elements)
    {
        for (auto element: elements)
        {
            dest.push_back(element);
        }
    }

    template <typename T>
    void CPPBrainx<T>::push_elements(std::set<T>& dest, std::initializer_list<T> elements)
    {
        for (auto element: elements)
        {
            dest.insert(element);
        }
    }

    template <typename T>
    void CPPBrainx<T>::release(T& resource)
    {
        if (resource)
        {
            delete resource;
            resource = nullptr;
        }
    }

    template <typename T>
    void CPPBrainx<T>::release(std::vector<T>& resource)
    {
        for (auto ref: resource)
        {
            if (ref)
            {
                delete ref;
            }
        }

        resource.clear();
    }

    template <typename T>
    void CPPBrainx<T>::release(std::list<T>& resource)
    {
        for (auto ref: resource)
        {
            if (ref)
            {
                delete ref;
            }
        }

        resource.clear();
    }

    template <typename T>
    void CPPBrainx<T>::release(std::set<T>& resource)
    {
        for (auto ref: resource)
        {
            if (ref)
            {
                delete ref;
            }
        }

        resource.clear();
    }

    template <typename T>
    void CPPBrainx<T>::release(std::initializer_list<T>& resource)
    {
        for (auto ref: resource)
        {
            if (ref)
            {
                delete ref;
            }
        }

        resource.clear();
    }

    template <typename T>
    void CPPBrainx<T>::release_arr(T& resource)
    {
        if (resource)
        {
            delete [] resource;
            resource = nullptr;
        }
    }

    template <typename T>
    void CPPBrainx<T>::help()
    {
        DataManager::help_x();
    }

    template <typename T>
    void CPPBrainx<T>::version()
    {
        DataManager::version();
    }

    template <typename T>
    void CPPBrainx<T>::print_function1(T value, const char* delimiter, bool is_first)
    {
        if (!is_first)
        {
            std::cout << delimiter << value;
        }
        else
        {
            std::cout << value;
        }
    }

};

#endif // SWT_CPP_BRAINX_H
