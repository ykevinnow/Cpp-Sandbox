/**
 * 
 * 
 */
 #include <iostream>
 #include <string>
 
 template<typename T>
 inline void PRINT_ELEMENTS(const T& coll,
                            const std::string& sep="")
 {
     std::cout << sep;
     for (const auto item : coll) {
         std::cout << item << " ";
     }
     std::cout << std::endl;
 };

 template <typename T>
 class print
 {
public:
     void operator()(const T& elem) {
         std::cout << elem << ' ';
     }
 };