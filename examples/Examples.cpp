// Creator: Davy (Dawei) Chen
// Time: August 17th, 2024
// Email: cndv3996@163.com

#include "../cppbrain.h"

int main()
{
    /* # Module # - brain */
    swt::brain::print({ "# Module #", "brain"}, " - ");
    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'split' and 'join': (EG-001) */
    swt::brain::print({ "-Example of 'split' and 'join': (EG-001)" });

    const char* text = "January,February,March,April,,May,June,July,August,,September";
    // *** This line *** //
    std::vector<std::string> texts = swt::brain::split(text, ",");
    for (auto str : texts)
    {
        swt::brain::print({ str });
    }

    swt::brain::print_return();

    // *** This line *** //
    std::string text1 = swt::brainx<std::string>::join(texts, "|");
    swt::brain::print({ text1 });

    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'range': (EG-001-001) */
    swt::brain::print({ "-Example of 'range': (EG-001-001)" });

    // *** This line *** //
    for (auto i : swt::brain::range(5))
    {
        swt::brainx<int>::print({i});
    }

    swt::brain::print_return();

    // *** This line *** //
    for (auto i : swt::brain::range(2020, 2030, 2))
    {
        swt::brainx<int>::print({ i });
    }

    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'loop' and 'loop_index': (EG-002) */
    swt::brain::print({ "-Example of 'loop' and 'loop_index': (EG-002)" });

    int i = 5;
    // *** This line *** //
    while (swt::brain::loop(i))
    {
        // 4, 3, 2, 1, 0
        printf("Loop index: %d\n", swt::brain::loop_index(i));
    }

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'loop_to' and 'loop_index': (EG-003) */
    swt::brain::print({ "-Example of 'loop_to' and 'loop_index': (EG-003)" });

    i = 0;
    // *** This line *** //
    while (swt::brain::loop_to(i, 5))
    {
        // 0, 1, 2, 3, 4
        printf("Loop index: %d\n", swt::brain::loop_index(i, 5));
    }

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'loop_to_by' and 'loop_index': (EG-004) */
    swt::brain::print({ "-Example of 'loop_to_by' and 'loop_index': (EG-004)" });

    i = 0;
    // *** This line *** //
    while (swt::brain::loop_to_by(i, 10, 2))
    {
        // 0, 1, 2, 3, 4
        printf("Loop index: %d\n", swt::brain::loop_index(i, 10, 2));
    }

    swt::brain::print_return();

    i = 10;
    // *** This line *** //
    while (swt::brain::loop_to_by(i, 0, -2))
    {
        // 4, 3, 2, 1, 0
        printf("Loop index: %d\n", swt::brain::loop_index(i, 0, -2));
    }

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'print' and 'print_return': (EG-005) */
    swt::brain::print({ "-Example of 'print' and 'print_return': (EG-005)" });

    swt::brainx<std::string>::print({ "My", "name", "is", "bad-temper."}, " ");

    swt::brainx<int>::print({ 2, 0, 2, 4, 0, 8, 1, 5 });

    std::vector<int> vec2 = { 0, 1, 2, 3, 4, 5 };
    swt::brainx<int>::print(vec2);

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'push_strings': (EG-006) */
    swt::brain::print({ "-Example of 'push_strings': (EG-006)" });

    std::vector<std::string> cats;
    // *** This line *** //
    swt::brain::push_strings(cats, {"Lulu", "Momo", "Fortune", "Rocky", "Scars"});

    for (auto cat : cats)
    {
        swt::brain::print({cat});
    }

    swt::brain::print_return(2);
    
    

    /* # Module # - brainx */
    swt::brain::print({ "# Module #", "brainx" }, " - ");
    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'delete_elements': (EGX-001) */
    swt::brain::print({ "-Example of 'delete_elements': (EGX-001)"});

    std::set<int> set1 = { 2024, 2025, 2026, 2027, 2028 };
    // *** This line *** //
    swt::brainx<int>::delete_elements(set1, { 2025, 2027 });
    swt::brainx<int>::print(set1);

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'delete_elements_by_indices': (EGX-002) */
    swt::brain::print({ "-Example of 'delete_elements_by_indices': (EGX-002)", "No outputs" }, " ");

    class City {};
    class Montreal : public City {};
    class Guangzhou : public City {};
    class Seattle : public City {};

    std::list<City*> list1 = { new Montreal , new Guangzhou , new Seattle };
    // *** This line *** //
    std::vector<City*> deleted1 = swt::brainx<City*>::delete_elements_by_indices(list1, { 1 }, true);
    swt::brainx<City*>::release(deleted1);
    swt::brainx<City*>::release(list1);

    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'map': (EGX-002-001) */
    swt::brain::print({ "-Example of 'map': (EGX-002-001)" });

    // *** This line *** //
    std::vector<float> areas = swt::brainx<float>::map({ 1.0f, 2.0f, 4.0f, 8.0f, 16.0f }, [](float radius) {
            // Calculate the area of a circle from its radius
            return 3.1415926f * radius * radius;
        });

    swt::brainx<float>::print(areas);
    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'to_vector': (EGX-003) */
    swt::brain::print({ "-Example of 'to_vector': (EGX-003)" });

    std::set<float> set2 = { 2024.01f, 2025.02f, 2026.03f, 2027.04f, 2028.05f };
    // *** This line *** //
    std::vector<float> vec3 = swt::brainx<float>::to_vector(set2);
    swt::brainx<float>::print(vec3);

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'sum': (EGX-004) */
    swt::brain::print({ "-Example of 'sum': (EGX-004)" });

    // *** This line *** //
    int sum1 = swt::brainx<int>::sum({ 1, 2, 3, 4, 5, 6 });

    std::vector<float> inputs1 = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };
    // *** This line *** //
    float sum2 = swt::brainx<float>::sum(inputs1);

    swt::brain::print({ swt::brainx<int>::to_string(sum1), swt::brainx<float>::to_string(sum2) });
    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'in_range_e', 'in_range_i', 'in_range_e_i', 'in_range_i_e': (EGX-004-001) */
    swt::brain::print({ "-Example of 'in_range_e', 'in_range_i', 'in_range_e_i', 'in_range_i_e': (EGX-004-001)" });

    const int fiscal_year = 2024;
    // *** This line *** //
    const bool is_young = swt::brainx<int>::in_range_e_i(fiscal_year - 1989, 0, 100);

    if (is_young)
    {
        swt::brain::print({ "Taylor is young in ",  swt::brainx<int>::to_string(fiscal_year), "."}, "");
    }
    else
    {
        swt::brain::print({ "Taylor is not old in ",  swt::brainx<int>::to_string(fiscal_year), "."}, "");
    }
    
    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'join': (EGX-005) */
    swt::brain::print({ "-Example of 'join': (EGX-005)" });

    std::vector<int> vec4 = {123, 234, 345, 456, 567};
    // *** This line *** //
    std::string t1 = swt::brainx<int>::join(vec4, "-");
    swt::brain::print({ t1 });

    swt::brain::print_return();

    /* --------------------------------------- */
    /* Example of 'clamp': (EGX-005-001) */
    swt::brain::print({ "-Example of 'clamp': (EGX-005-001)" });

    // *** This line *** //
    float clamped = swt::brainx<float>::clamp(2025.1224f, 2024.0214f, 2024.0501f);
    swt::brainx<float>::print({ clamped });

    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'to_string': (EGX-006) */
    swt::brain::print({ "-Example of 'to_string': (EGX-006)" });

    // *** This line *** //
    std::string t2 = swt::brainx<double>::to_string(0.123456);
    swt::brain::print({ t2 });

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'to_type': (EGX-007) */
    swt::brain::print({ "-Example of 'to_type': (EGX-007)" });

    // *** This line *** //
    std::string t3 = swt::brainx<double>::to_type(0.123456);
    swt::brain::print({ t3 });

    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'if_true', 'if_false', 'if_null', 'if_nullptr': (EGX-007-001) */
    swt::brain::print({ "-Example of 'if_true': (EGX-007-001)" });

    class Gates
    {
        public:
        void Clear(const char* target)
        {
            swt::brain::print({ "Done with ", target, "!" }, "");
        }
        std::string With()
        {
            return "Vaccine";
        }
    };

    Gates* william = new Gates;
    // *** This line *** //
    swt::brainx<Gates*>::if_true(william, [](Gates* bill) {
            bill->Clear("Mosquitoes");
        });

    swt::brain::print_return();

    /* ----------------------------- */

    Gates* daughter = nullptr;
    // *** This line *** //
    std::string method1 = swt::brainxx<Gates*, std::string>::if_false(william, [](Gates* bill) {
            return std::string("net");
        }, william->With());

    // *** This line *** //
    std::string method2 = swt::brainxx<Gates*, std::string>::if_nullptr(daughter, [](Gates* phoebe) {
            return std::string("texting dad");
        }, "emailing dad");

    swt::brain::print({ "He utilises ", method1, ", ", "while she utilises ", method2, " to clear mosquitoes." }, "");

    swt::brain::print_return();
    
    /* --------------------------------------- */
    /* Example of 'print': (EGX-008) */
    swt::brain::print({ "-Example of 'print': (EGX-008)" });

    std::list<int> list2 = {200, 201, 202, 203, 204};
    // *** This line *** //
    swt::brainx<int>::print(list2);

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'push_elements': (EGX-009) */
    swt::brain::print({ "-Example of 'push_elements': (EGX-009)" });

    std::vector<float> vec5;
    // *** This line *** //
    swt::brainx<float>::push_elements(vec5, { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f });

    swt::brainx<float>::print(vec5);

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'release' and 'release_arr': (EGX-010) */
    swt::brain::print({ "-Example of 'release' and 'release_arr': (EGX-010)" });

    class Kirkland {};
    class Shanghai {};
    class Macau {};
    Kirkland* city1 = new Kirkland;
    Shanghai* city2 = new Shanghai;
    Macau* casinos = new Macau[6];
    std::vector<Shanghai*> crabs = {new Shanghai, new Shanghai, new Shanghai};
    // *** These lines *** //
    swt::brainx<Kirkland*>::release(city1);
    swt::brainx<Shanghai*>::release(city2);
    swt::brainx<Macau*>::release_arr(casinos);
    swt::brainx<Shanghai*>::release(crabs);

    // Pointers to integer to print out if they are released
    swt::brainx<long long>::print({(long long)city1, (long long)city2, (long long)casinos, (long long)crabs.size()});
    swt::brain::print_return(2);
    
    

    /* # Module # - brainxx */
    swt::brain::print({ "# Module #", "brainxx" }, " - ");
    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'keys' and 'values': (EGXX-001) */
    swt::brain::print({ "-Example of 'keys' and 'values': (EGXX-001)" });

    class Vancouver
    {
    public:
        Vancouver(int year) { m_year = year; }
        void check() { swt::brainx<int>::print({ m_year }); }

    private:
        int m_year = 2024;

    };

    // Creat a std::map
    std::map<int, Vancouver*> map1;
    swt::brainxx<int, Vancouver*>::push_elements(map1, { 2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2029 },
        { new Vancouver(2020), new Vancouver(2021) , new Vancouver(2022) , new Vancouver(2023) , new Vancouver(2024) ,
          new Vancouver(2025), new Vancouver(2026) , new Vancouver(2027) , new Vancouver(2028) , new Vancouver(2029) });

    // *** This line *** //
    std::vector<int> keys1 = swt::brainxx<int, Vancouver*>::keys(map1);
    // *** This line *** //
    std::vector<Vancouver*> vals1 = swt::brainxx<int, Vancouver*>::values(map1);

    swt::brainx<int>::print(keys1);

    for (auto val : vals1)
    {
        val->check();
    }
    // Release memory
    swt::brainx<Vancouver*>::release(vals1);

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'delete_elements' and 'delete_elements_by_indices': (EGXX-002) */
    swt::brain::print({ "-Example of 'delete_elements' and 'delete_elements_by_indices': (EGXX-002)" });

    swt::brain::print({ "Please reference the example of: (EGX-001) and (EGX-002)" });

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'push_elements': (EGXX-003) */
    swt::brain::print({ "-Example of 'push_elements': (EGXX-003)" });

    swt::brain::print({ "Please reference the example of: (EGXX-001)" });

    swt::brain::print_return();
    
    
    /* --------------------------------------- */
    /* Example of 'version': (EGXX-005) */
    swt::brain::print({ "-Example of 'version': (EGXX-005)" });

    // *** This line *** //
    swt::brain::version();
    swt::brain::print_return();
}
