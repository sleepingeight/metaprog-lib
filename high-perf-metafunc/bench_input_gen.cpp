#include <fstream>
#include <string>
#include <iostream>
#include <random>



int main()
{
    std::string filename = "BenchmarkInputs.h";

    std::ofstream fout(filename);
    if(!fout)
    {
        std::cerr << "Error opening file for writing\n";
        return 1;
    }


    fout << "#ifndef BENCHMARK_INPUTS\n";
    fout << "#define BENCHMARK_INPUTS\n\n";

    fout << "#include \"TypeList.h\"\n\n";
    fout << "namespace ss\n";
    fout << "{\n\n";
    fout << "template <int>\n";
    fout << "struct dummy {};\n\n";


    // generating random inputs
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> prob(0.0, 1.0);

    auto print = [&](int n) {
        fout << "using input" << n << "_different = type_list<";
        for (int i = 0; i < n; i++) {
            if(prob(gen) < 0.05) {
                fout << "void" << (i == n-1 ? "" : ", ");
            }
            else {
                fout << "dummy<" << i+1 << ">" << (i == n-1 ? "" : ", ");
            }
            if((i+1)%15 == 0) fout << "\n\t\t\t\t\t";
        }
        fout << ">;\n\n\n";
    };

    int num = 2;

    for(int i = 0; i < 17; i++){
        print(num);
        num *= 2;
    }
    
    print(50000);

    print(10);
    print(18);
    print(20);
    print(22);
    print(24);

    

    



    fout << "\n\n}\n";  // namespace closing bracket

    fout << "\n#endif";


    fout.close();



    return 0;
}