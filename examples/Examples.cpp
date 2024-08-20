// Creator: Davy (Dawei) Chen
// Time: August 17th, 2024
// Email: cndv3996@163.com

#include "../cppbrain.h"

int main()
{
    /* # Module # - CPPBrain */
    swt::CPPBrain::print({ "# Module #", "CPPBrain"}, " - ");
    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'split' and 'join': (EG-001) */
    swt::CPPBrain::print({ "-Example of 'split' and 'join': (EG-001)" });

    const char* text = "Taylor Swift,Vivian Chow,Pace Wu,Gina Jin,,Jasmine Sun,Sophia Lu,En Chin,Cindy Fei Mok";
    std::vector<std::string> texts = swt::CPPBrain::split(text, ",");
    for (auto str : texts)
    {
        swt::CPPBrain::print({ str });
    }

    swt::CPPBrain::print_return();

    std::string text1 = swt::CPPBrainx<std::string>::join(texts, "|");
    swt::CPPBrain::print({ text1 });

    swt::CPPBrain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'range': (EG-001-001) */
    swt::CPPBrain::print({ "-Example of 'range': (EG-001-001)" });

    for (auto i : swt::CPPBrain::range(5))
    {
        swt::CPPBrainx<int>::print({i});
    }

    swt::CPPBrain::print_return();

    for (auto i : swt::CPPBrain::range(2020, 2030, 2))
    {
        swt::CPPBrainx<int>::print({ i });
    }

    swt::CPPBrain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'loop' and 'loop_index': (EG-002) */
    swt::CPPBrain::print({ "-Example of 'loop' and 'loop_index': (EG-002)" });

    int i = 5;
    // Here
    while (swt::CPPBrain::loop(i))
    {
        // 4, 3, 2, 1, 0
        printf("Loop index: %d\n", swt::CPPBrain::loop_index(i));
    }

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'loop_to' and 'loop_index': (EG-003) */
    swt::CPPBrain::print({ "-Example of 'loop_to' and 'loop_index': (EG-003)" });

    i = 0;
    while (swt::CPPBrain::loop_to(i, 5))
    {
        // 0, 1, 2, 3, 4
        printf("Loop index: %d\n", swt::CPPBrain::loop_index(i, 5));
    }

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'loop_to_by' and 'loop_index': (EG-004) */
    swt::CPPBrain::print({ "-Example of 'loop_to_by' and 'loop_index': (EG-004)" });

    i = 0;
    while (swt::CPPBrain::loop_to_by(i, 10, 2))
    {
        // 0, 1, 2, 3, 4
        printf("Loop index: %d\n", swt::CPPBrain::loop_index(i, 10, 2));
    }

    swt::CPPBrain::print_return();

    i = 10;
    while (swt::CPPBrain::loop_to_by(i, 0, -2))
    {
        // 4, 3, 2, 1, 0
        printf("Loop index: %d\n", swt::CPPBrain::loop_index(i, 0, -2));
    }

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'print' and 'print_return': (EG-005) */
    swt::CPPBrain::print({ "-Example of 'print' and 'print_return': (EG-005)" });

    swt::CPPBrainx<std::string>::print({ "My", "name", "is", "bad-temper."}, " ");

    swt::CPPBrainx<int>::print({ 2, 0, 2, 4, 0, 8, 1, 5 });

    std::vector<int> vec2 = { 0, 1, 2, 3, 4, 5 };
    swt::CPPBrainx<int>::print(vec2);

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'push_strings': (EG-006) */
    swt::CPPBrain::print({ "-Example of 'push_strings': (EG-006)" });

    std::vector<std::string> cats;
    swt::CPPBrain::push_strings(cats, {"Lulu", "Momo", "Fortune", "Rocky", "Scars"});

    for (auto cat : cats)
    {
        swt::CPPBrain::print({cat});
    }

    swt::CPPBrain::print_return(2);
    
    

    /* # Module # - CPPBrainx */
    swt::CPPBrain::print({ "# Module #", "CPPBrainx" }, " - ");
    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'delete_elements': (EGX-001) */
    swt::CPPBrain::print({ "-Example of 'delete_elements': (EGX-001)"});

    std::set<int> set1 = { 2024, 2025, 2026, 2027, 2028 };
    swt::CPPBrainx<int>::delete_elements(set1, { 2025, 2027 });
    swt::CPPBrainx<int>::print(set1);

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'delete_elements_by_indices': (EGX-002) */
    swt::CPPBrain::print({ "-Example of 'delete_elements_by_indices': (EGX-002)", "No outputs" }, " ");

    class City {};
    class Montreal : public City {};
    class Guangzhou : public City {};
    class Seattle : public City {};

    std::list<City*> list1 = { new Montreal , new Guangzhou , new Seattle };
    // Here
    std::vector<City*> deleted1 = swt::CPPBrainx<City*>::delete_elements_by_indices(list1, { 1 }, true);
    swt::CPPBrainx<City*>::release(deleted1);
    swt::CPPBrainx<City*>::release(list1);

    swt::CPPBrain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'map': (EGX-002-001) */
    swt::CPPBrain::print({ "-Example of 'map': (EGX-002-001)" });

    std::vector<float> areas = swt::CPPBrainx<float>::map({ 1.0f, 2.0f, 4.0f, 8.0f, 16.0f }, [](float radius) {
            // Calculate the area of a circle from its radius
            return 3.1415926f * radius * radius;
        });

    swt::CPPBrainx<float>::print(areas);
    swt::CPPBrain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'to_vector': (EGX-003) */
    swt::CPPBrain::print({ "-Example of 'to_vector': (EGX-003)" });

    std::set<float> set2 = { 2024.01f, 2025.02f, 2026.03f, 2027.04f, 2028.05f };
    std::vector<float> vec3 = swt::CPPBrainx<float>::to_vector(set2);
    swt::CPPBrainx<float>::print(vec3);

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'sum': (EGX-004) */
    swt::CPPBrain::print({ "-Example of 'sum': (EGX-004)" });

    int sum1 = swt::CPPBrainx<int>::sum({ 1, 2, 3, 4, 5, 6 });

    std::vector<float> inputs1 = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };
    float sum2 = swt::CPPBrainx<float>::sum(inputs1);

    swt::CPPBrain::print({ swt::CPPBrainx<int>::to_string(sum1), swt::CPPBrainx<float>::to_string(sum2) });
    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'join': (EGX-005) */
    swt::CPPBrain::print({ "-Example of 'join': (EGX-005)" });

    std::vector<int> vec4 = {123, 234, 345, 456, 567};
    std::string t1 = swt::CPPBrainx<int>::join(vec4, "-");
    swt::CPPBrain::print({ t1 });

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'to_string': (EGX-006) */
    swt::CPPBrain::print({ "-Example of 'to_string': (EGX-006)" });

    std::string t2 = swt::CPPBrainx<double>::to_string(0.123456);
    swt::CPPBrain::print({ t2 });

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'to_type': (EGX-007) */
    swt::CPPBrain::print({ "-Example of 'to_type': (EGX-007)" });

    std::string t3 = swt::CPPBrainx<double>::to_type(0.123456);
    swt::CPPBrain::print({ t3 });

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'print': (EGX-008) */
    swt::CPPBrain::print({ "-Example of 'print': (EGX-008)" });

    std::list<int> list2 = {200, 201, 202, 203, 204};
    swt::CPPBrainx<int>::print(list2);

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'push_elements': (EGX-009) */
    swt::CPPBrain::print({ "-Example of 'push_elements': (EGX-009)" });

    std::vector<float> vec5;
    swt::CPPBrainx<float>::push_elements(vec5, { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f });

    swt::CPPBrainx<float>::print(vec5);

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'release' and 'release_arr': (EGX-010) */
    swt::CPPBrain::print({ "-Example of 'release' and 'release_arr': (EGX-010)" });

    class Kirkland {};
    class Shanghai {};
    class Macau {};
    Kirkland* city1 = new Kirkland;
    Shanghai* city2 = new Shanghai;
    Macau* casinos = new Macau[6];
    std::vector<Shanghai*> crabs = {new Shanghai, new Shanghai, new Shanghai};
    
    swt::CPPBrainx<Kirkland*>::release(city1);
    swt::CPPBrainx<Shanghai*>::release(city2);
    swt::CPPBrainx<Macau*>::release_arr(casinos);
    swt::CPPBrainx<Shanghai*>::release(crabs);

    // Pointers to integer to print out if they are released
    swt::CPPBrainx<long long>::print({(long long)city1, (long long)city2, (long long)casinos, (long long)crabs.size()});
    swt::CPPBrain::print_return(2);
    
    

    /* # Module # - CPPBrainxx */
    swt::CPPBrain::print({ "# Module #", "CPPBrainxx" }, " - ");
    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'keys' and 'values': (EGXX-001) */
    swt::CPPBrain::print({ "-Example of 'keys' and 'values': (EGXX-001)" });

    class Vancouver
    {
    public:
        Vancouver(int year) { m_year = year; }
        void check() { swt::CPPBrainx<int>::print({ m_year }); }

    private:
        int m_year = 2024;

    };

    // Creat a std::map
    std::map<int, Vancouver*> map1;
    swt::CPPBrainxx<int, Vancouver*>::push_elements(map1, { 2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2029 },
        { new Vancouver(2020), new Vancouver(2021) , new Vancouver(2022) , new Vancouver(2023) , new Vancouver(2024) ,
          new Vancouver(2025), new Vancouver(2026) , new Vancouver(2027) , new Vancouver(2028) , new Vancouver(2029) });

    // Here
    std::vector<int> keys1 = swt::CPPBrainxx<int, Vancouver*>::keys(map1);
    // And here
    std::vector<Vancouver*> vals1 = swt::CPPBrainxx<int, Vancouver*>::values(map1);

    swt::CPPBrainx<int>::print(keys1);

    for (auto val : vals1)
    {
        val->check();
    }
    // Release memory
    swt::CPPBrainx<Vancouver*>::release(vals1);

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'delete_elements' and 'delete_elements_by_indices': (EGXX-002) */
    swt::CPPBrain::print({ "-Example of 'delete_elements' and 'delete_elements_by_indices': (EGXX-002)" });

    swt::CPPBrain::print({ "Please reference the example of: (EGX-001) and (EGX-002)" });

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'push_elements': (EGXX-003) */
    swt::CPPBrain::print({ "-Example of 'push_elements': (EGXX-003)" });

    swt::CPPBrain::print({ "Please reference the example of: (EGXX-001)" });

    swt::CPPBrain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'help': (EGXX-004) */
    swt::CPPBrain::print({ "-Example of 'help': (EGXX-004)" });

    swt::CPPBrain::help();
    swt::CPPBrainx<int>::help();
    swt::CPPBrainxx<int, int>::help();
    
    
    /* --------------------------------------- */
    /* Example of 'version': (EGXX-005) */
    swt::CPPBrain::print({ "-Example of 'version': (EGXX-005)" });

    swt::CPPBrain::version();
    swt::CPPBrain::print_return();
}
