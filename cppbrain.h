// Creator: Davy (Dawei) Chen
// Time: August 8th, 2020
// Email: cndv3996@163.com

#ifndef SWT_CPP_BRAIN_H
#define SWT_CPP_BRAIN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <typeinfo>

#include "./modules/data.h"
#include "./modules/common.h"
#include "./modules/cppbrainx.h"
#include "./modules/cppbrainxx.h"

namespace swt
{
    class CPPBrain: public CommonComponents
    {
    public:
        static void help();
        static void version();
        
    };

    void CPPBrain::help()
    {
        DataManager::help_();
    }

    void CPPBrain::version()
    {
        DataManager::version();
    }

};

#endif // SWT_CPP_BRAIN_H
