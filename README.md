# CPP-BRAIN provides straightforward APIs to make your C++ coding easier

CPP-BRAIN library consists modules of 'swt::CPPBrain', 'swt::CPPBrainx' and 'swt::CPPBrainxx'

-Created by Davy Chen, Since August 8th, 2020, In the hot weather of Guangzhou

# Example 1:
Use:
```cpp
#include "CPP-BRAIN/cppbrain.h"

Shanghai* city1 = new Shanghai;
// This line
swt::CPPBrainx<Shanghai*>::release(city1);
```
Instead of:
```cpp
if (city1)
{
    delete city1;
    city1 = nullptr;
}
```
Use:
```cpp
Kirkland* citys = new Kirkland[5];
// This line
swt::CPPBrainx<Kirkland*>::release_arr(citys);
```
Instead of:
```cpp
if (citys)
{
    delete [] citys;
    citys = nullptr;
}
```
# Example 2:
Use:
```cpp
int i = 5;
while (swt::CPPBrain::loop(i))
{
    // Do something 5 times, save your brain
}
```
Instead of:
```cpp
for (int i = 0; i < 5; i++)
{
    // Do something 5 times
}
```
# Example 3:
Use:
```cpp
const char* names = "Taylor Swift,Vivian Chow,Pace Wu,Gina Jin,,Jasmine Sun,Sophia Lu,En Chin,Cindy Fei Mok";
// This line
std::vector<std::string> giant_names = swt::CPPBrain::split(names, ",");
```
Instead of:
```cpp
// You can imagine using C++
```
Use:
```cpp
std::vector<std::string> giant_names = {"Taylor Swift", "Vivian Chow", "Pace Wu", "Gina Jin", "Jasmine Sun", "Sophia Lu", "En Chin", "Cindy Fei Mok"};
// This line
std::string giant_names_in_a_row = swt::CPPBrainx<std::string>::join(giant_names, "|");
swt::CPPBrain::print({ giant_names_in_a_row });
```
Instead of:
```cpp
// You can imagine
```
# Example 4:
Use:
```cpp
std::set<int> list1 = { 2024, 2025, 2026, 2027, 2028 };
// Left: 2024, 2026, 2028
swt::CPPBrainx<int>::delete_elements_by_indices(list1, { 1, 3 });
```
Instead of:
```cpp
// You can imagine
```

# Documents
Please use the following code to check the Help documents:
```cpp
swt::CPPBrain::help();
swt::CPPBrainx<int>::help();
swt::CPPBrainxx<int, int>::help();
```

# Examples
Check:
```
examples\Examples.cpp
```

# Tested
```
1. Windows 11 & Visual Studio C++ 2022
```
