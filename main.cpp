#include "func.hpp"

//#define EPSILON 0.001
//#define SQR(x) ( (x) * (x) )

//sscanf - точно почитать!!!
//считывание из файла
//вывод в файл

//#define NDEBUG

//добавить аргументы командной строки
int main (int argc, char *argv[]) {
    char *nameFile;
    if (argc > 1) nameFile = argv[1];
    else
    {
    printf("Не задано имя файла\n");
    return 1;
    }
    FILE *file = fopen(nameFile, "r");

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
