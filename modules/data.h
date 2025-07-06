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
        static void help(const char* html_name);

    private:
        static const int main_version = 2;
        static const int sub_version = 0;
        static const int sub_sub_version = 20241026;

    };

    void DataManager::help_all()
    {
        help_();
        help_x();
        help_xx();
    }

    void DataManager::help(const char* html_name)
    {
        std::cout << "Please reference class definition in \"" << html_name << "\"." << std::endl;
    }

    void DataManager::help_()
    {
        help("docs\\html\\index.html");
    }

    void DataManager::help_x()
    {
        help("docs\\html\\index.html");
    }

    void DataManager::help_xx()
    {
        help("docs\\html\\index.html");
    }

    void DataManager::version()
    {
        std::cout << main_version << "." << sub_version << "." << sub_sub_version << std::endl;
    }

};

#endif // SWT_DATA_H
