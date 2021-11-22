# include "Vector.hpp"
# include <vector>

// int main(void) {

//     Vector<int> a(5);
//     std::vector<int> dyalhum(5);
//     // for (int i=0; i< 5; i++) {
    
//     //     std::cout << a[i] << std::endl;
//     // }
//     // while(1);
//     std::cout << a.max_size() << std::endl;
//     a.resize(5);
//     a.resize(8,100);

//     dyalhum.resize(5);
//     dyalhum.resize(8,100);
//     // for (int i=0; i < a.size(); i++) {
//     //     std::cout << a[i] << std::endl;
//     // }
//     // a.clear();
//     // dyalhum.clear();
//     // ++dyalhum[0];
//     // ++a[0];

    
//     // a.push_back(222);
//     // a.push_back(200);
//     // a.push_back(666);
//     // a.push_back(888);
//     // a.pop_back();
//     // a.pop_back();

//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();
//     // a.pop_back();

//     // a.resize(12);
//     try {
//     for (int i=0; i < a.size(); i++) {
//         // i = 555;
//         std::cout << a[i] << std::endl;
//     }
//     }
//     catch (std::exception & e) {
//         std::cout << e.what() << std::endl;
//     }
//     std::cout << "**********************\n";
//     try {
//         for (int i=0; i < dyalhum.size(); i++) {
//             // i = 555;
//             std::cout << dyalhum[i] << std::endl;
//         }
//     }
//     catch (std::exception & e) {
//         std::cout << e.what() << std::endl;
//     }
//     return (0);
// // }
//  int main() {
    
//    std::vector<int *> p;
//    Vector<int > g(6);
//    Vector<int >::iterator it;
//    g.push_back(25);
//    g.push_back(25);
//    g.push_back(25);
//    g.push_back(25);
//    g.push_back(25);


//    // std::cout << *it << std::endl;
//    std::cout << g.size() << std::endl;
//    // std::cout << g.size() << std::endl;
//    for (it = g.begin(); it != g.end(); it++){
   
//       std::cout << *it << std::endl;
//    }
//     std::cout << "org max_size " << p.max_size() << std::endl;
//     std::cout << "new max_size " << g.max_size() << std::endl;
    
    
int main ()
{
  unsigned int i;
  Vector<int> foo (3,100);   // three ints with a value of 100
  Vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (Vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (Vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
//  }
// int main()
// {
//     // Create a vector containing integers
//     Vector<int> v = { 7, 5, 16, 8 };
 
//     // Add two more integers to vector
//     v.push_back(25);
//     v.push_back(13);
 
//     // Print out the vector
//     std::cout << "v = { ";
//     for (int n : v) {
//         std::cout << n << ", ";
//     }
//     std::cout << "}; \n";