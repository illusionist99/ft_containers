# include "Vector.hpp"


int main(void) {

    Vector<int> a(5);

    // for (int i=0; i< 5; i++) {
    
    //     std::cout << a[i] << std::endl;
    // }
    // while(1);
    std::cout << a.max_size() << std::endl;
    a.resize(5);
    a.resize(8,100);
    // for (int i=0; i < a.size(); i++) {
    //     std::cout << a[i] << std::endl;
    // }
    a.clear();
    a.push_back(222);
    a.push_back(200);
    a.push_back(666);
    a.push_back(888);
    a.pop_back();
    a.pop_back();

    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();

    // a.resize(12);
    try {
    for (int i=0; i < a.size(); i++) {
        // i = 555;
        std::cout << a[i] << std::endl;
    }
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}