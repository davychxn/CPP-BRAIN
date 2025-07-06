// Creator: Davy (Dawei) Chen
// Time: August 8th, 2020
// Email: cndv3996@163.com

#ifndef SWT_COMMON_H
#define SWT_COMMON_H

#include <iostream>
#include <vector>
#include <string>

namespace swt
{
    /**
     * Inherited by class brain.
     * Please do not call directly, use class brain instead.
     */
    class CommonComponents
    {
    private:
        CommonComponents();
    public:
        /**
         * @brief Return a joined string separated by a delimiter.
         */
        static std::string join(const std::vector<std::string>& strs, const char* delimiter);
        /**
         * @brief Return a strings array sliced from source string by a delimiter.
         */
        static std::vector<std::string> split(const char* str, const char* delimiter);
        /**
         * @brief Return a continuous int array in a range.
         */
        static std::vector<int> range(const int stop);
        static std::vector<int> range(const int start, const int stop, const int step = 1);
        /**
         * @brief Works with 'while' operator, guarantees assigned count of loops.
         */
        static bool loop(int& index);
        /**
         * @brief Works with 'while' operator, loops from initial 'index' value to 'to_val' by 1 ascendingly.
         */
        static bool loop_to(int& index, const int to_val);
        /**
         * @brief Works with 'while' operator, loops from initial 'index' value to 'to_val' by 'by_val' ascendingly or descendingly.
         */
        static bool loop_to_by(int& index, const int to_val, const int by_val);
        /**
         * @brief Works with 'loop', 'loop_to', 'loop_to_by' APIs correspondingly. Result of unmatched usage is undefined.
         */
        static int loop_index(const int index);
        static int loop_index(const int index, const int to_val);
        static int loop_index(const int index, const int to_val, const int by_val);
        /**
         * @brief Print undetermined count of std::string(s) to console with or without a delimiter.
         */
        static void print(std::initializer_list<std::string> values, const char* delimiter = ", ");
        /**
         * @brief Print return(s) to console.
         */
        static void print_return(const int counts = 1);
        /**
         * @brief Push undetermined count of strings into a container.
         */
        static void push_strings(std::vector<std::string>& dest, std::initializer_list<std::string> strs);

    private:
        /**
         * @brief Please do not call.
         */
        static void print_function1(const std::string value, const char* delimiter = ", ", bool is_first = true);

    };

    std::string CommonComponents::join(const std::vector<std::string>& strs, const char* delimiter)
    {
        std::string t1;
        int size = (int)strs.size();
        for (auto str: strs)
        {
            t1 += str;
            size--;
            if (size > 0)
            {
                t1 += delimiter;
            }
        }

        return t1;
    }

    std::vector<std::string> CommonComponents::split(const char* str, const char* delimiter)
    {
        std::vector<std::string> v1;
        if (str == nullptr || delimiter == nullptr)
        {
            return v1;
        }
        // String length is 0
        if ((*str) == 0 || (*delimiter) == 0)
        {
            return v1;
        }

        std::string t1 = str;
        int delimiterLen = (int)strlen(delimiter);
        int pos = 0;
        int lastPos = 0;
        while (true)
        {
            pos = (int)t1.find(delimiter, pos);
            if (pos == std::string::npos)
            {
                // The last slice
                int len1 = (int)t1.size() - lastPos;
                if (len1 >= 0)
                {
                    std::string t2 = t1.substr(lastPos);
                    v1.push_back(t2);
                }
                break;
            }

            int len1 = pos - lastPos;
            if (len1 >= 0)
            {
                std::string t2 = t1.substr(lastPos, len1);
                v1.push_back(t2);
            }

            pos += delimiterLen;
            lastPos = pos;
        }

        return v1;
    }

    std::vector<int> CommonComponents::range(const int stop)
    {
        std::vector<int> v1;
        for (int i = 0; i < stop; i++)
        {
            v1.push_back(i);
        }

        return v1;
    }

    std::vector<int> CommonComponents::range(const int start, const int stop, const int step)
    {
        std::vector<int> v1;
        for (int i = start; i < stop; i += step)
        {
            v1.push_back(i);
        }

        return v1;
    }

    bool CommonComponents::loop(int& index)
    {
        if (index <= 0)
        {
            return false;
        }
        else
        {
            index--;
            return true;
        }
    }

    bool CommonComponents::loop_to(int& index, int to_val)
    {
        if (index >= to_val)
        {
            return false;
        }
        else
        {
            index++;
            return true;
        }
    }

    bool CommonComponents::loop_to_by(int& index, int to_val, int by_val)
    {
        if (by_val == 0)
        {
            throw "Invalid BY value.";
        }

        if (by_val > 0)
        {
            if (index >= to_val)
            {
                return false;
            }
        }
        else
        {
            if (index <= to_val)
            {
                return false;
            }
        }

        index += by_val;
        return true;
    }

    int CommonComponents::loop_index(const int index)
    {
        return index;
    }

    int CommonComponents::loop_index(const int index, const int to_val)
    {
        return index - 1;
    }

    int CommonComponents::loop_index(const int index, const int to_val, const int by_val)
    {
        if (by_val == 0)
        {
            throw "Invalid BY value.";
        }

        int result;
        if (by_val > 0)
        {
            result = (index - by_val) / by_val;
        }
        else
        {
            result = index / by_val;
        }

        result = result > 0 ? result : -result;
        return result;
    }

    void CommonComponents::print(std::initializer_list<std::string> values, const char* delimiter)
    {
        bool isFirst = true;

        for (auto val: values)
        {
            print_function1(val, delimiter, isFirst);
            isFirst = false;
        }

        CommonComponents::print_return();
    }

    void CommonComponents::print_return(const int counts)
    {
        int i = counts;
        while(loop(i))
        {
            std::cout << std::endl;
        }
    }

    void CommonComponents::push_strings(std::vector<std::string>& dest, std::initializer_list<std::string> strs)
    {
        for (auto str: strs)
        {
            dest.push_back(str);
        }
    }

    void CommonComponents::print_function1(const std::string value, const char* delimiter, bool is_first)
    {
        std::string t1 = value;

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

#endif // SWT_COMMON_H
