# CPP-BRAIN: Convenient C++ APIs to make your life longer

CPP-BRAIN C++ library consists of modules of `swt::brain`, `swt::brainx` and `swt::brainxx`

-Created by Davy Chen, Since August 8th, 2020, In the hot weather of Guangzhou

## Example 1, ONE line of pointer release:
Use:
```cpp
#include "CPP-BRAIN/cppbrain.h"

Shanghai* city1 = new Shanghai;
// This line
swt::brainx<Shanghai*>::release(city1);
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
Kirkland* cities = new Kirkland[5];
// This line
swt::brainx<Kirkland*>::release_arr(cities);
```
Instead of:
```cpp
if (cities)
{
    delete [] cities;
    cities = nullptr;
}
```
## Example 2, Simplified loop condition, mimic Python's range:
Use:
```cpp
int i = 5;
while (swt::brain::loop(i))
{
    // Do something 5 times, save your brain
}
```
Or, use:
```cpp
for (auto i : swt::brain::range(5))
{
    // Do something 5 times
}
```
Instead of:
```cpp
for (int i = 0; i < 5; i++)
{
    // Do something 5 times
}
```
## Example 3, ONE line of string splitting and joining:
Use:
```cpp
const char* names = "Taylor Swift,Vivian Chow,Pace Wu,Gina Jin,,Jasmine Sun,Sophia Lu,En Chin,Cindy Fei Mok";
// This line
std::vector<std::string> giant_names = swt::brain::split(names, ",");
```
Instead of:
```cpp
// You can imagine using C++
```
Use:
```cpp
std::vector<std::string> giant_names = {"Taylor Swift", "Vivian Chow", "Pace Wu", "Gina Jin", "Jasmine Sun", "Sophia Lu", "En Chin", "Cindy Fei Mok"};
// This line
std::string giant_names_in_a_row = swt::brainx<std::string>::join(giant_names, "|");

// If you like, use this to print to console
swt::brain::print({ giant_names_in_a_row });
```
Instead of:
```cpp
// You can imagine
```
## Example 4, Container's multi-elements deletion:
Use:
```cpp
std::list<int> list1 = { 2024, 2025, 2026, 2027, 2028 };
// Left: 2024, 2026, 2028
swt::brainx<int>::delete_elements_by_indices(list1, { 1, 3 });
```
Instead of:
```cpp
// You can imagine
```

## Example 5, Container's multi-elements deletion and memory release:
Use:
```cpp
class City {};
class Montreal : public City {};
class Guangzhou : public City {};
class Seattle : public City {};

std::list<City*> cool_cities = { new Montreal , new Guangzhou , new Seattle };
// This line
std::vector<City*> hot_cities = swt::brainx<City*>::delete_elements_by_indices(cool_cities, { 1 }, true);

// Release: Guangzhou
swt::brainx<City*>::release(hot_cities);
// Release: Montreal, Seattle
swt::brainx<City*>::release(cool_cities);
```
Instead of:
```cpp
// You can imagine
```
## Example 6, ONE line of array processing, mimic JavaScript's map Function:
Use:
```cpp
// Input radii of circles and a Lambda function to calculate their areas
std::vector<float> areas = swt::brainx<float>::map({ 1.0f, 2.0f, 4.0f, 8.0f, 16.0f }, [](float radius) {
        // Area formula of Circle
        return 3.1415926f * radius * radius;
    });
```
Instead of:
```cpp
// You can imagine
```

## Example 7, Clamp a value:
Use:
```cpp
const int test_month = 15;
// This line, both ends of the range are inclusive
const int a_valid_month = swt::brainx<int>::clamp(test_month, 1, 12);
```
Instead of:
```cpp
// You can imagine
```

## Example 8, Trigger a function based on a value:
Use:
```cpp
class Gates { public: void is() { swt::brain::print({ "Co-founder of Microsoft." }); } };
const Gates* bill = new Gates;
// This line
swt::brainx<Gates*>::if_true(bill, [](Gates* bill) {
        bill->is();
    });
```
Instead of:
```cpp
// You can imagine
```

## Example 9, Tell if a value lies in a range:
Use:
```cpp
const int test_year = 2024;
// This line, the range is 2000(inclusive) to 3000(exclusive)
const bool is_21th_century = swt::brainx<int>::in_range_i_e(test_year, 2000, 3000);
```
Instead of:
```cpp
// You can imagine
```

## Documents
Please use the following code to check the Help documents:
```cpp
swt::brain::help();
```

## More examples, more APIs
Please check:
[examples\Examples.cpp](https://github.com/davychxn/CPP-BRAIN/blob/main/examples/Examples.cpp)

## Tested
```
1. Windows 11 & Visual Studio C++ 2022
2. Windows 11 & Visual Studio C++ 2019 & Qt 5.15.2
   Windows 11 & Visual Studio C++ 2019 & Qt 6.5.3
   Windows 11 & MingGW & Qt 5.15.2
   Windows 11 & MingGW & Qt 6.5.3
```

## History
- October 26th, 2024 - Version 1 is frozen, Version 2 is current development version.
```
Major changes are class names are shortened:
swt::CPPBrain -> swt::brain
swt::CPPBrainx -> swt::brainx
swt::CPPBrainxx -> swt::brainxx
```

## Culture
Question: Why do we use "swt" as the namespace of the project?

Answer: "swt" is short for "sweet". The adjective stands for a longing for the dream life in your mind where the persistent dream has been developed since the your very first taste to the beauty of the world and human. While through all the rains and storms in your life the flame of the dream has yet been put out.

Wish sweet smiles, sweet people, sweet places, sweet moments, sweet stories, sweet endings to sweet you in everyday.
