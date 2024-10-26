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
    class brainx
    {
    public:
        /**
         * @brief Delete undetermined count of elements from a container, and optionally return deleted elements(allocated memory unreleased).
         */
        static std::vector<T> delete_elements(std::vector<T>& source, std::vector<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::vector<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::list<T>& source, std::vector<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::list<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::set<T>& source, std::vector<T> elements, bool is_return_deleted = false);
        static std::vector<T> delete_elements(std::set<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);
        /**
         * @brief Delete undetermined count of elements from a container by their indices, and optionally return deleted elements(allocated memory unreleased).
         */
        static std::vector<T> delete_elements_by_indices(std::vector<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::vector<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::list<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::list<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::set<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T> delete_elements_by_indices(std::set<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        /**
         * @brief Take in an array of values, process each single data by Lambda function, then return the processed array.
         */
        static std::vector<T> map(const std::vector<T>& source, T (*map_func)(T));
        static std::vector<T> map(const std::list<T>& source, T (*map_func)(T));
        static std::vector<T> map(const std::set<T>& source, T (*map_func)(T));
        static std::vector<T> map(const std::initializer_list<T>& source, T (*map_func)(T));
        /**
         * @brief Convert another kind of container to std::vector.
         */
        static std::vector<T> to_vector(const std::list<T>& source);
        static std::vector<T> to_vector(const std::set<T>& source);
        static std::vector<T> to_vector(const std::initializer_list<T>& source);
        /**
         * @brief Connect elements in a container into a string, and separated by a delimiter string.
         */
        static std::string join(const std::vector<T>& values, const char* delimiter);
        static std::string join(const std::list<T>& values, const char* delimiter);
        static std::string join(const std::set<T>& values, const char* delimiter);
        /**
         * @brief Convert input value to a std::string and return.
         */
        static std::string to_string(const T value);
        /**
         * @brief Return input value's type in a std::string.
         */
        static std::string to_type(const T value);
        /**
         * @brief Return a new value based on input value, but clamped between the range ends. The order of range ends can be either ascending or descending.
         */
        static T clamp(const T value, const T range_end1, const T range_end2);
        /**
         * @brief Return the sum of variadic number of inputs using std initializer.
         */
        static T sum(const std::initializer_list<T>& args);
        static T sum(const std::vector<T>& args);
        static T sum(const std::list<T>& args);
        static T sum(const std::set<T>& args);
        /**
         * @brief Tell if input value lies between the range ends exclusively. The order of range ends can be either ascending or descending.
         */
        static bool in_range_e(const T value, const T range_end1, const T range_end2);
        /**
         * @brief Tell if input value lies between the range ends inclusively. The order of range ends can be either ascending or descending.
         */
        static bool in_range_i(const T value, const T range_end1, const T range_end2);
        /**
         * @brief Tell if input value lies between the range_left exclusively and range_right inclusively. range_left must not be greater than range_right.
         */
        static bool in_range_e_i(const T value, const T range_left, const T range_right);
        /**
         * @brief Tell if input value lies between the range_left inclusively and range_right exclusively. range_left must not be greater than range_right.
         */
        static bool in_range_i_e(const T value, const T range_left, const T range_right);
        /**
         * @brief If input value is true then call input function.
         */
        static void if_true(const T value, void (*custom_func)(const T value));
        /**
         * @brief If input value is false then call input function.
         */
        static void if_false(const T value, void (*custom_func)(const T value));
        /**
         * @brief If input value is null then call input function.
         */
        static void if_null(const T value, void (*custom_func)(const T value));
        /**
         * @brief If input value is nullptr then call input function.
         */
        static void if_nullptr(const T value, void (*custom_func)(const T value));
        /**
         * @brief Print undetermined count of values or elements in a container to console with or without a delimiter.
         */
        static void print(const std::vector<T>& values, const char* delimiter = ", ");
        static void print(const std::list<T>& values, const char* delimiter = ", ");
        static void print(const std::set<T>& values, const char* delimiter = ", ");
        static void print(const std::initializer_list<T>& values, const char* delimiter = ", ");
        /**
         * @brief Push undetermined count of values into a container.
         */
        static void push_elements(std::vector<T>& dest, std::initializer_list<T> elements);
        static void push_elements(std::list<T>& dest, std::initializer_list<T> elements);
        static void push_elements(std::set<T>& dest, std::initializer_list<T> elements);
        /**
         * @brief Release undetermined type of memory resource(a single pointer or undetermined counts in a container) allocated by new operator.
         */
        static void release(T& resource);
        static void release(std::vector<T>& resource);
        static void release(std::list<T>& resource);
        static void release(std::set<T>& resource);
        static void release(std::initializer_list<T>& resource);
        /**
         * @brief Release undetermined type memory resource array allocated by new [].
         */
        static void release_arr(T& resource);
        /**
         * @brief Print Help information of module 'swt::brainx' to console.
         */
        static void help();
        /**
         * @brief Print Version information to console.
         */
        static void version();

    private:
        /**
         * @brief Please do not call.
         */
        static void print_function1(T value, const char* delimiter = ", ", bool is_first = true);

    };

    template <typename T>
    std::vector<T> brainx<T>::delete_elements(std::vector<T>& source, std::vector<T> elements, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements(std::vector<T>& source, std::initializer_list<T> elements, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements_by_indices(std::vector<T>& source, std::vector<size_t> indices, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements_by_indices(std::vector<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = brainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T>
    std::vector<T> brainx<T>::delete_elements(std::list<T>& source, std::vector<T> elements, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements(std::list<T>& source, std::initializer_list<T> elements, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements_by_indices(std::list<T>& source, std::vector<size_t> indices, bool is_return_deleted)
    {
        std::vector<T> deleted;

        // Sort descendingly
        std::sort(indices.begin(), indices.end(), [](const size_t a, const size_t b) {return a > b; });
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
    std::vector<T> brainx<T>::delete_elements_by_indices(std::list<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = brainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T>
    std::vector<T> brainx<T>::delete_elements(std::set<T>& source, std::vector<T> elements, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements(std::set<T>& source, std::initializer_list<T> elements, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements_by_indices(std::set<T>& source, std::vector<size_t> indices, bool is_return_deleted)
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
    std::vector<T> brainx<T>::delete_elements_by_indices(std::set<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = brainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T>
    std::vector<T> brainx<T>::to_vector(const std::list<T>& source)
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            v1.push_back(val);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> brainx<T>::map(const std::vector<T>& source, T (*map_func)(T))
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
    std::vector<T> brainx<T>::map(const std::list<T>& source, T (*map_func)(T))
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
    std::vector<T> brainx<T>::map(const std::set<T>& source, T (*map_func)(T))
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
    std::vector<T> brainx<T>::map(const std::initializer_list<T>& source, T (*map_func)(T))
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
    std::vector<T> brainx<T>::to_vector(const std::set<T>& source)
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            v1.push_back(val);
        }

        return v1;
    }

    template <typename T>
    std::vector<T> brainx<T>::to_vector(const std::initializer_list<T>& source)
    {
        std::vector<T> v1;

        for (auto val: source)
        {
            v1.push_back(val);
        }

        return v1;
    }

    template <typename T>
    T brainx<T>::sum(const std::initializer_list<T>& args)
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
    T brainx<T>::sum(const std::vector<T>& args)
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
    T brainx<T>::sum(const std::list<T>& args)
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
    T brainx<T>::sum(const std::set<T>& args)
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
    T brainx<T>::clamp(const T value, const T range_end1, const T range_end2)
    {
        T range_left = std::min(range_end1, range_end2);
        T range_right = std::max(range_end1, range_end2);
        T val = std::max(value, range_left);
        val = std::min(val, range_right);

        return val;
    }

    template <typename T>
    bool brainx<T>::in_range_e(const T value, const T range_end1, const T range_end2)
    {
        T range_left = std::min(range_end1, range_end2);
        T range_right = std::max(range_end1, range_end2);

        return value > range_left && value < range_right;
    }

    template <typename T>
    bool brainx<T>::in_range_i(const T value, const T range_end1, const T range_end2)
    {
        T range_left = std::min(range_end1, range_end2);
        T range_right = std::max(range_end1, range_end2);

        return value >= range_left && value <= range_right;
    }

    template <typename T>
    bool brainx<T>::in_range_e_i(const T value, const T range_left, const T range_right)
    {
        if (range_left > range_right)
        {
            throw "Invalid arguments order, should be ascending.";
        }

        return value > range_left && value <= range_right;
    }

    template <typename T>
    bool brainx<T>::in_range_i_e(const T value, const T range_left, const T range_right)
    {
        if (range_left > range_right)
        {
            throw "Invalid arguments order, should be ascending.";
        }

        return value >= range_left && value < range_right;
    }

    template <typename T>
    void brainx<T>::if_true(const T value, void (*custom_func)(T value))
    {
        if (value)
        {
            (*custom_func)(value);
        }
    }

    template <typename T>
    void brainx<T>::if_false(const T value, void (*custom_func)(T value))
    {
        if (!value)
        {
            (*custom_func)(value);
        }
    }

    template <typename T>
    void brainx<T>::if_null(const T value, void (*custom_func)(T value))
    {
        if (value == NULL)
        {
            (*custom_func)(value);
        }
    }

    template <typename T>
    void brainx<T>::if_nullptr(const T value, void (*custom_func)(T value))
    {
        if (value == nullptr)
        {
            (*custom_func)(value);
        }
    }

    template <typename T>
    std::string brainx<T>::join(const std::vector<T>& values, const char* delimiter)
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
    std::string brainx<T>::join(const std::list<T>& values, const char* delimiter)
    {
        std::vector<T> v1 = brainx<T>::to_vector(values);
        return join(v1, delimiter);
    }

    template <typename T>
    std::string brainx<T>::join(const std::set<T>& values, const char* delimiter)
    {
        std::vector<T> v1 = brainx<T>::to_vector(values);
        return join(v1, delimiter);
    }

    template <typename T>
    std::string brainx<T>::to_string(T value)
    {
        std::stringstream buffer;
        buffer << value;
        return buffer.str();
    }

    template <typename T>
    std::string brainx<T>::to_type(T value)
    {
        std::string t1 = typeid(T).name();
        return t1;
    }

    template <typename T>
    void brainx<T>::print(const std::vector<T>& values, const char* delimiter)
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
    void brainx<T>::print(const std::list<T>& values, const char* delimiter)
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
    void brainx<T>::print(const std::set<T>& values, const char* delimiter)
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
    void brainx<T>::print(const std::initializer_list<T>& values, const char* delimiter)
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
    void brainx<T>::push_elements(std::vector<T>& dest, std::initializer_list<T> elements)
    {
        for (auto element: elements)
        {
            dest.push_back(element);
        }
    }

    template <typename T>
    void brainx<T>::push_elements(std::list<T>& dest, std::initializer_list<T> elements)
    {
        for (auto element: elements)
        {
            dest.push_back(element);
        }
    }

    template <typename T>
    void brainx<T>::push_elements(std::set<T>& dest, std::initializer_list<T> elements)
    {
        for (auto element: elements)
        {
            dest.insert(element);
        }
    }

    template <typename T>
    void brainx<T>::release(T& resource)
    {
        if (resource)
        {
            delete resource;
            resource = nullptr;
        }
    }

    template <typename T>
    void brainx<T>::release(std::vector<T>& resource)
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
    void brainx<T>::release(std::list<T>& resource)
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
    void brainx<T>::release(std::set<T>& resource)
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
    void brainx<T>::release(std::initializer_list<T>& resource)
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
    void brainx<T>::release_arr(T& resource)
    {
        if (resource)
        {
            delete [] resource;
            resource = nullptr;
        }
    }

    template <typename T>
    void brainx<T>::help()
    {
        DataManager::help_x();
    }

    template <typename T>
    void brainx<T>::version()
    {
        DataManager::version();
    }

    template <typename T>
    void brainx<T>::print_function1(T value, const char* delimiter, bool is_first)
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
