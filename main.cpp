//TODO
//1.enum errors
//2.doxygen
//3.readme
//4.make
//5.compilation flags

#include "func.hpp"

//#define EPSILON 0.001
//#define SQR(x) ( (x) * (x) )

//sscanf - точно почитать!!!
//считывание из файла
//вывод в файл

//#define NDEBUG

//добавить аргументы командной строки
int main (int argc, char *argv[]) {
    char *name_file;
    if (argc > 1) name_file = argv[1];
    else
    {
    printf("Не задано имя файла: %d\n", NO_FILE_NAME_ERROR);
        
    return NO_FILE_NAME_ERROR;
    }
    
    FILE *file = fopen(name_file, "r");

    //FILE *file = fopen("test.txt", "r");
    
    struct coeff cofs {};
    
    struct out otv {};

#ifdef NDEBUG
    
    tests(&cofs, &otv, file);
    
#else
    
    cycle_quadratic(&cofs, &otv, file);
    
#endif
    
    fclose(file);
    
    //start_programm(&cofs, &otv, file);
    
    return 0;
}
