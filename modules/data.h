// Creator: Davy (Dawei) Chen
// Time: August 8th, 2020
// Email: cndv3996@163.com

#ifndef SWT_DATA_H
#define SWT_DATA_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include "./common.h"

namespace swt
{
    const char* help_cppbrain[] = {
            "# CPP-BRAIN helps you enjoy C++ coding a bit more :) #",
            "CPP-BRAIN library consists modules of 'swt::CPPBrain', 'swt::CPPBrainx' and 'swt::CPPBrainxx'\n\n-Created by Davy Chen\n-Since August 8th, 2020\n-In the hot weather of Guangzhou",
            "# Help of swt::CPPBrain (module without using template)",
            ""
    };

    const char* help_join[] = {
            "join",
            "std::string join(const std::vector<std::string>& strs, const char* delimiter);",
            "Return a joined string separated by a delimiter.",
            "std::vector<std::string> strs = {\"Berlin\", \"Shanghai\", \"Inner Mongolia\"};\nstd::string str = swt::CPPBrain::join(strs, \", \");"
    };

    const char* help_split[] = {
            "split",
            "std::vector<std::string> split(const char* str, const char* delimiter);",
            "Return a strings array sliced from source string by a delimiter.",
            "const char* text = \"Taylor Swift,Vivian Chow,Pace Wu,Gina Jin,,Jasmine Sun,Sophia Lu,En Chin,Cindy Fei Mok\";\nstd::vector<std::string> texts = swt::CPPBrain::split(text, \",\");"
    };

    const char* help_range[] = {
            "range",
            "std::vector<int> range(const int stop);\nstd::vector<int> range(const int start, const int stop, const int step = 1);",
            "Return an int array in a range.",
            "// 0, 1, 2, 3, 4\nstd::vector<int> vec1 = swt::CPPBrain::range(5);"
    };

    const char* help_loop[] = {
            "loop",
            "bool loop(int& index);",
            "Works with 'while' operator, guarantees assigned times of loops.",
            "int i = 5;\nwhile (swt::CPPBrain::loop(i)) {};"
    };

    const char* help_loop_to[] = {
            "loop_to",
            "bool loop_to(int& index, const int to_val);",
            "Works with 'while' operator, loops from initial 'index' value to 'to_val' by 1 ascendingly.",
            "int i = 0;\nwhile (swt::CPPBrain::loop_to(i, 5)) {};"
    };

    const char* help_loop_to_by[] = {
            "loop_to_by",
            "bool loop_to_by(int& index, const int to_val, const int by_val);",
            "Works with 'while' operator, loops from initial 'index' value to 'to_val' by 'by_val' ascendingly or descendingly.",
            "int i = 0;\nwhile (swt::CPPBrain::loop_to_by(i, 10, 2)) {};\n\nint j = 10;\nwhile (swt::CPPBrain::loop_to_by(i, 0, -2)) {};"
    };

    const char* help_loop_index[] = {
            "loop_index",
            "int loop_index(const int index);\nint loop_index(const int index, const int to_val);\nint loop_index(const int index, const int to_val, const int by_val);",
            "Works with 'loop', 'loop_to', 'loop_to_by' APIs correspondingly. Result of unmatched usage is undefined.",
            "int i = 5;\nwhile (swt::CPPBrain::loop(i))\n{\n    printf(\"Loop index: %d\\n\", swt::CPPBrain::loop_index(i));\n}\n\nint j = 0;\nwhile (swt::CPPBrain::loop_to(j, 5))\n{\n    printf(\"Loop index: %d\\n\", swt::CPPBrain::loop_index(j, 5));\n}\n\nint k = 0;\nwhile (swt::CPPBrain::loop_to_by(k, 10, 2))\n{\n    printf(\"Loop index: %d\\n\", swt::CPPBrain::loop_index(k, 10, 2));\n}\n\nint m = 10;\nwhile (swt::CPPBrain::loop_to_by(m, 0, -2))\n{\n    printf(\"Loop index: %d\\n\", swt::CPPBrain::loop_index(m, 0, -2));\n}"
    };

    const char* help_print[] = {
            "print",
            "void print(std::initializer_list<std::string> values, const char* delimiter = \", \");",
            "Print undetermined counts of std::string(s) to console with or without a delimiter.",
            "swt::CPPBrain::print({ \"CPPBrain\", \"CPPBrainx\", \"CPPBrainxx\"}, \" / \");"
    };

    const char* help_print_return[] = {
            "print_return",
            "void print_return(const int counts = 1);",
            "Print return(s) to console.",
            "print_return();\n\nprint_return(2);"
    };

    const char* help_push_strings[] = {
            "push_strings",
            "void push_strings(std::vector<std::string>& dest, std::initializer_list<std::string> strs);",
            "Push undetermined counts of strings into a container.",
            "std::vector<std::string> strs1;\nswt::CPPBrain::push_strings(strs1, {\"Cat\", \"loves\", \"desserts.\"});"
    };

    const char* help_help[] = {
            "help",
            "void help();",
            "Print Help information of module 'swt::CPPBrain' to console.",
            "swt::CPPBrain::help();"
    };

    const char* help_version[] = {
            "version",
            "void version();",
            "Print Version information to console.",
            "swt::CPPBrain::version();"
    };

    const char* help_cppbrainx[] = {
            "# CPP-BRAIN helps you enjoy C++ coding a bit more :) #",
            "CPP-BRAIN library consists modules of 'swt::CPPBrain', 'swt::CPPBrainx' and 'swt::CPPBrainxx'\n\n-Created by Davy Chen\n-Since August 8th, 2020\n-In the hot weather of Guangzhou",
            "# Help of swt::CPPBrainx (module with 1 template data type)",
            ""
    };

    const char* help_x_delete_elements[] = {
            "delete_elements",
            "std::vector<T> delete_elements(std::vector<T>& source, std::vector<T> elements, bool is_return_deleted = false);\nstd::vector<T> delete_elements(std::vector<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);\nstd::vector<T> delete_elements(std::list<T>& source, std::vector<T> elements, bool is_return_deleted = false);\nstd::vector<T> delete_elements(std::list<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);\nstd::vector<T> delete_elements(std::set<T>& source, std::vector<T> elements, bool is_return_deleted = false);\nstd::vector<T> delete_elements(std::set<T>& source, std::initializer_list<T> elements, bool is_return_deleted = false);",
            "Delete undetermined counts of elements from a container, and optionally return deleted elements(allocated memory unreleased).",
            "std::set<int> set1 = { 2024, 2025, 2026, 2027, 2028 };\n// Left: 2024, 2026, 2028\nswt::CPPBrainx<int>::delete_elements(set1, { 2025, 2027 });"
    };

    const char* help_x_delete_elements_by_indices[] = {
            "delete_elements_by_indices",
            "std::vector<T> delete_elements_by_indices(std::vector<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);\nstd::vector<T> delete_elements_by_indices(std::vector<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);\nstd::vector<T> delete_elements_by_indices(std::list<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);\nstd::vector<T> delete_elements_by_indices(std::list<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);\nstd::vector<T> delete_elements_by_indices(std::set<T>& source, std::vector<size_t> indices, bool is_return_deleted = false);\nstd::vector<T> delete_elements_by_indices(std::set<T>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);",
            "Delete undetermined counts of elements from a container by their indices, and optionally return deleted elements(allocated memory unreleased).",
            "std::vector<float> vec2 = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};\n// Left: 0.1f, 0.3f, 0.5f\nswt::CPPBrainx<float>::delete_elements_by_indices(vec2, {1, 3});"
    };

    const char* help_x_map[] = {
            "map",
            "std::vector<T> map(const std::vector<T>& source, T (*map_func)(T));\nstd::vector<T> map(const std::list<T>& source, T (*map_func)(T));\nstd::vector<T> map(const std::set<T>& source, T (*map_func)(T));\nstd::vector<T> map(const std::initializer_list<T>& source, T (*map_func)(T));",
            "Take in an array of values, process each single data by Lambda function, then return the processed array.",
            "std::vector<float> sqrts = swt::CPPBrainx<float>::map({ 1.0f, 2.0f, 4.0f, 8.0f, 16.0f }, [](float value) {\n    return sqrt(value);\n});"
    };

    const char* help_x_to_vector[] = {
            "to_vector",
            "std::vector<T> to_vector(const std::list<T>& source);\nstd::vector<T> to_vector(const std::set<T>& source);\nstd::vector<T> to_vector(const std::initializer_list<T>& source);",
            "Convert another kind of container to std::vector.",
            "std::list<double> list2 = { 0.12, 0.23, 0.34, 0.45, 0.56 };\nstd::vector<double> vec3 = swt::CPPBrainx<double>::to_vector(list2);"
    };

    const char* help_x_sum[] = {
            "sum",
            "T sum(std::initializer_list<T> args);\nT sum(std::vector<T> args);\nT sum(std::list<T> args);\nT sum(std::set<T> args);",
            "Return the sum of variadic number of inputs using std initializer.",
            "int sum1 = swt::CPPBrainx<int>::sum({ 1, 2, 3, 4, 5, 6 });\n\nstd::vector<float> inputs1 = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };\nfloat sum2 = swt::CPPBrainx<float>::sum(inputs1);"
    };

    const char* help_x_join[] = {
            "join",
            "std::string join(const std::vector<T>& values, const char* delimiter);\nstd::string join(const std::list<T>& values, const char* delimiter);\nstd::string join(const std::set<T>& values, const char* delimiter);",
            "Connect elements in a container into a string, and separated by a delimiter string.",
            "std::list<double> list2 = { 0.12, 0.23, 0.34, 0.45, 0.56 };\nstd::string t6 = swt::CPPBrainx<double>::join(list2, \", \");"
    };

    const char* help_x_to_string[] = {
            "to_string",
            "std::string to_string(T value);",
            "Convert input value to a std::string and return.",
            "std::string t1 = swt::CPPBrainx<double>::to_string(3.1415926);"
    };

    const char* help_x_to_type[] = {
            "to_type",
            "std::string to_type(T value);",
            "Return input value's type in a std::string.",
            "std::string t1 = swt::CPPBrainx<double>::to_type(3.1415926);"
    };

    const char* help_x_print[] = {
            "print",
            "void print(std::vector<T> values, const char* delimiter = \", \");\nvoid print(std::list<T> values, const char* delimiter = \", \");\nvoid print(std::set<T> values, const char* delimiter = \", \");\nvoid print(std::initializer_list<T> values, const char* delimiter = \", \");",
            "Print undetermined counts of values or elements in a container to console with or without a delimiter.",
            "std::vector<int> vec2 = {0, 1, 2, 3, 4, 5};\nswt::CPPBrainx<int>::print(vec2);"
    };

    const char* help_x_push_elements[] = {
            "push_elements",
            "void push_elements(std::vector<T>& dest, std::initializer_list<T> elements);\nvoid push_elements(std::list<T>& dest, std::initializer_list<T> elements);\nvoid push_elements(std::set<T>& dest, std::initializer_list<T> elements);",
            "Push undetermined counts of values into a container.",
            "std::list<double> list2;\nswt::CPPBrainx<double>::push_elements(list2, { 0.12, 0.23, 0.34, 0.45, 0.56 });"
    };

    const char* help_x_release[] = {
            "release",
            "void release(T& resource);\nvoid release(std::vector<T>& resource);\nvoid release(std::list<T>& resource);\nvoid release(std::set<T>& resource);\nvoid release(std::initializer_list<T>& resource);",
            "Release undetermined type of memory resource(a single pointer or undetermined counts in a container) allocated by new operator.",
            "Vancouver* city = new Vancouver;\nswt::CPPBrainx<Vancouver*>::release(city);\n\nstd::map<int, Vancouver*> map1;\nswt::CPPBrainxx<int, Vancouver*>::push_elements(map1, {2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2029},\n{new Vancouver(2020), new Vancouver(2021), new Vancouver(2022), new Vancouver(2023), new Vancouver(2024),\nnew Vancouver(2025), new Vancouver(2026), new Vancouver(2027), new Vancouver(2028), new Vancouver(2029) });\nstd::vector<Vancouver*> refs = swt::CPPBrainxx<int, Vancouver*>::values(map1);\nswt::CPPBrainx<Vancouver*>::release(refs);"
    };

    const char* help_x_release_arr[] = {
            "release_arr",
            "void release_arr(T& resource);",
            "Release undetermined type memory resource array allocated by new [].",
            "Guangzhou* cities = new Guangzhou[5];\nswt::CPPBrainx<Guangzhou*>::release_arr(cities);"
    };

    const char* help_x_help[] = {
            "help",
            "void help();",
            "Print Help information of module 'swt::CPPBrainx' to console.",
            "swt::CPPBrainx<int>::help();"
    };

    const char* help_x_version[] = {
            "version",
            "void version();",
            "Print Version information to console.",
            "swt::CPPBrainx<int>::version();"
    };

    const char* help_cppbrainxx[] = {
            "# CPP-BRAIN helps you enjoy C++ coding a bit more :) #",
            "CPP-BRAIN library consists modules of 'swt::CPPBrain', 'swt::CPPBrainx' and 'swt::CPPBrainxx'\n\n-Created by Davy Chen\n-Since August 8th, 2020\n-In the hot weather of Guangzhou",
            "# Help of swt::CPPBrainx (module with 2 template data types)",
            ""
    };

    const char* help_xx_keys[] = {
            "keys",
            "std::vector<T1> keys(const std::map<T1, T2>& source);",
            "Retrieve keys of a std::map into a std::vector.",
            "std::vector<int> keys1 = swt::CPPBrainxx<int, Vancouver*>::keys(map1);"
    };

    const char* help_xx_delete_elements[] = {
            "delete_elements",
            "std::vector<T2> delete_elements(std::map<T1, T2>& source, std::vector<T1> keys, bool is_return_deleted = false);\nstd::vector<T2> delete_elements(std::map<T1, T2>& source, std::initializer_list<T1> keys, bool is_return_deleted = false);",
            "Delete undetermined counts of elements from a std::map by its keys, and optionally return deleted elements(allocated memory unreleased).",
            "std::vector<Vancouver*> deleted = swt::CPPBrainxx<int, Vancouver*>::delete_elements(map1, {2022, 2024, 2026, 2028}, true);"
    };

    const char* help_xx_delete_elements_by_indices[] = {
            "delete_elements_by_indices",
            "std::vector<T2> delete_elements_by_indices(std::map<T1, T2>& source, std::vector<size_t> indices, bool is_return_deleted = false);\nstd::vector<T2> delete_elements_by_indices(std::map<T1, T2>& source, std::initializer_list<size_t> indices, bool is_return_deleted = false);",
            "Delete undetermined counts of elements from a std::map by its indices, and optionally return deleted elements(allocated memory unreleased).",
            "std::vector<Vancouver*> deleted = swt::CPPBrainxx<int, Vancouver*>::delete_elements_by_indices(map1, {2, 4, 6, 8}, true);"
    };

    const char* help_xx_values[] = {
            "values",
            "std::vector<T2> values(const std::map<T1, T2>& source);",
            "Retrieve values of a std::map into a std::vector.",
            "std::vector<Vancouver*> refs = swt::CPPBrainxx<int, Vancouver*>::values(map1);"
    };

    const char* help_xx_push_elements[] = {
            "push_elements",
            "void push_elements(std::map<T1, T2>& dest, std::initializer_list<T1> keys, std::initializer_list<T2> values);",
            "Push undetermined counts of key-value pairs into a std::map.",
            "std::map<int, Vancouver*> map1;\nswt::CPPBrainxx<int, Vancouver*>::push_elements(map1, {2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2029},\n{new Vancouver(2020), new Vancouver(2021), new Vancouver(2022), new Vancouver(2023), new Vancouver(2024),\nnew Vancouver(2025), new Vancouver(2026), new Vancouver(2027), new Vancouver(2028), new Vancouver(2029) });"
    };

    const char* help_xx_help[] = {
            "help",
            "void help();",
            "Print Help information of module 'swt::CPPBrainxx' to console.",
            "swt::CPPBrainxx<int, int>::help();"
    };

    const char* help_xx_version[] = {
            "version",
            "void version();",
            "Print Version information to console.",
            "swt::CPPBrainxx<int, int>::version();"
    };

    const char** help_group_[] = {
        help_cppbrain,
        help_join,
        help_split,
        help_range,
        help_loop,
        help_loop_to,
        help_loop_to_by,
        help_loop_index,
        help_print,
        help_push_strings,
        help_print_return,
        help_help,
        help_version
    };

    const char** help_group_x[] = {
        help_cppbrainx,
        help_x_delete_elements,
        help_x_delete_elements_by_indices,
        help_x_map,
        help_x_to_vector,
        help_x_sum,
        help_x_join,
        help_x_to_string,
        help_x_to_type,
        help_x_print,
        help_x_push_elements,
        help_x_release,
        help_x_release_arr,
        help_x_help,
        help_x_version
    };

    const char** help_group_xx[] = {
        help_cppbrainxx,
        help_xx_keys,
        help_xx_delete_elements,
        help_xx_delete_elements_by_indices,
        help_xx_values,
        help_xx_push_elements,
        help_xx_help,
        help_xx_version
    };

    const char* help_categories[] = {
        "",
        "Prototype(s):  ",
        "Functionality: ",
        "Example(s):    "
    };

    class DataManager
    {
    public:
        static void help_all();
        static void version();

    public:
        static void help_();
        static void help_x();
        static void help_xx();

    private:
        static void help(const char*** content, int counts);

    private:
        static const int main_version = 1;
        static const int sub_version = 0;
        static const int sub_sub_version = 20240820;

    };

    void DataManager::help_all()
    {
        help_();
        help_x();
        help_xx();
    }

    void DataManager::help(const char*** content, int counts)
    {
        for (int i = 0; i < counts; i++)
        {
            for (int j = 0; j < (sizeof(help_cppbrain) / sizeof(char*)); j++)
            {
                if (content[i][0][0] == '#')
                {
                    if (strlen(content[i][j]))
                    {
                        std::vector<std::string> v1 = CommonComponents::split(content[i][j], "\n");
                        for (auto str: v1)
                        {
                            std::cout << str << std::endl;
                        }
                        std::cout << std::endl;
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        // Only the first line(API name) has no indent
                        std::cout << "/" << content[i][j] << "/" << std::endl;
                    }
                    else
                    {
                        std::cout << "  -" << help_categories[j] << std::endl;

                        std::vector<std::string> v1 = CommonComponents::split(content[i][j], "\n");
                        for (auto str: v1)
                        {
                            std::cout << "    " << str << std::endl;
                        }
                        std::cout << std::endl;
                    }
                }
            }
            std::cout << std::endl << std::endl;
        }
    }

    void DataManager::help_()
    {
        help(help_group_, sizeof(help_group_) / sizeof(char**));
    }

    void DataManager::help_x()
    {
        help(help_group_x, sizeof(help_group_x) / sizeof(char**));
    }

    void DataManager::help_xx()
    {
        help(help_group_xx, sizeof(help_group_xx) / sizeof(char**));
    }

    void DataManager::version()
    {
        std::cout << main_version << "." << sub_version << "." << sub_sub_version << std::endl;
    }

};

#endif // SWT_DATA_H
