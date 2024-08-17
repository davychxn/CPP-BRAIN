// Creator: Davy (Dawei) Chen
// Time: August 8th, 2020
// Email: cndv3996@163.com

#ifndef SWT_CPP_BRAINXX_H
#define SWT_CPP_BRAINXX_H

#include <vector>
#include <map>

#include "./data.h"

namespace swt
{
    template <typename T1, typename T2>
    class CPPBrainxx
    {
    public:
        static std::vector<T1> keys(const std::map<T1, T2>& source);
        static std::vector<T2> delete_elements(std::map<T1, T2>& source, std::vector<T1> keys, bool is_return_deleted = false);
        static std::vector<T2> delete_elements(std::map<T1, T2>& source, std::initializer_list<T1> keys, bool is_return_deleted = false);
        static std::vector<T2> delete_elements_by_indices(std::map<T1, T2>& source, std::vector<size_t> indices, bool is_return_deleted = false);
        static std::vector<T2> delete_elements_by_indices(std::map<T1, T2>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);
        static std::vector<T2> values(const std::map<T1, T2>& source);
        static void push_elements(std::map<T1, T2>& dest, std::initializer_list<T1> keys, std::initializer_list<T2> values);
        static void help();
        static void version();

    };

    template <typename T1, typename T2>
    std::vector<T1> CPPBrainxx<T1, T2>::keys(const std::map<T1, T2>& source)
    {
        std::vector<T1> keys1;

        for (auto val: source)
        {
            keys1.push_back(val.first);
        }

        return keys1;
    }

    template <typename T1, typename T2>
    std::vector<T2> CPPBrainxx<T1, T2>::delete_elements(std::map<T1, T2>& source, std::vector<T1> keys, bool is_return_deleted)
    {
        std::vector<T2> deleted;

        for (auto key: keys)
        {
            auto pos = source.find(key);
            if (pos != source.end())
            {
                if (is_return_deleted)
                {
                    deleted.push_back(pos->second);
                }
                source.erase(pos);
            }
        }

        return deleted;
    }

    template <typename T1, typename T2>
    std::vector<T2> CPPBrainxx<T1, T2>::delete_elements(std::map<T1, T2>& source, std::initializer_list<T1> keys, bool is_return_deleted)
    {
        std::vector<T1> keys1 = CPPBrainx<T1>::to_vector(keys);
        return delete_elements(source, keys1, is_return_deleted);
    }

    template <typename T1, typename T2>
    std::vector<T2> CPPBrainxx<T1, T2>::delete_elements_by_indices(std::map<T1, T2>& source, std::vector<size_t> indices, bool is_return_deleted)
    {
        std::vector<T2> deleted;

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
                    deleted.push_back(it->second);
                }
                source.erase(it);
            }
        }

        return deleted;
    }

    template <typename T1, typename T2>
    std::vector<T2> CPPBrainxx<T1, T2>::delete_elements_by_indices(std::map<T1, T2>& source, std::initializer_list<size_t> indices, bool is_return_deleted)
    {
        std::vector<size_t> indices1 = CPPBrainx<size_t>::to_vector(indices);
        return delete_elements_by_indices(source, indices1, is_return_deleted);
    }

    template <typename T1, typename T2>
    std::vector<T2> CPPBrainxx<T1, T2>::values(const std::map<T1, T2>& source)
    {
        std::vector<T2> values1;

        for (auto val: source)
        {
            values1.push_back(val.second);
        }

        return values1;
    }

    template <typename T1, typename T2>
    void CPPBrainxx<T1, T2>::push_elements(std::map<T1, T2>& dest, std::initializer_list<T1> keys, std::initializer_list<T2> values)
    {
        if (keys.size() != values.size())
        {
            throw "Invalid input.";
        }

        auto it = values.begin();
        for (auto key: keys)
        {
            dest[key] = *it;
            it++;
        }
    }

    template <typename T1, typename T2>
    void CPPBrainxx<T1, T2>::help()
    {
        DataManager::help_xx();
    }

    template <typename T1, typename T2>
    void CPPBrainxx<T1, T2>::version()
    {
        DataManager::version();
    }

};

#endif // SWT_CPP_BRAINXX_H
