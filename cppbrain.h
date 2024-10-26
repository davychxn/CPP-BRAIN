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
    /**
     * CPP-BRAIN helps you enjoy C++ coding a bit more :)
     * CPP-BRAIN library consists modules of 'swt::CPPBrain', 'swt::CPPBrainx' and 'swt::CPPBrainxx'
     * - Created by Davy Chen
     * - Since August 8th, 2020
     * - In the hot weather of Guangzhou
     */
    class CPPBrain: public CommonComponents
    {
    public:
        /**
         * @brief Print Help information of module 'swt::CPPBrain' to console.
         */
        static void help();
        /**
         * @brief Print Version information to console.
         */
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
