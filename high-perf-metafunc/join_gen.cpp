#include <iostream>


int main()
{
    std::cout << "struct join<";
    for(int i = 0; i < 64; i++){
        std::cout << "type_list<T" << i << "s...>, "; 
        if((i+1)%3 == 0) std::cout << "\n\t\t";
    }
    std::cout << "MORE_LISTS...> : \n";

    std::cout << "\t\tjoin<type_list<";
    for(int i = 0; i < 64; i++){
        std::cout << "T" << i << "s ..." << (i == 63 ? ">, " : ", ");
        if((i+1)%6 == 0) std::cout << "\n\t\t\t\t";
    }
    std::cout << "MORE_LISTS...> \n{\n};\n\n";
}