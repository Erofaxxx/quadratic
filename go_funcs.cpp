#include "func.hpp"

//
//void start_programm(struct coeff *cofs, struct out *otv, FILE *file)
//{
//    printf("Test mode - 't', user mode  - 'u', exit - 'e'. \n");
//    char str = 0;
//    scanf("%c", &str);
//
//    if (str == 't')
//    {
//        tests(cofs, otv, file);
//    }
//    else if (str == 'u' )
//    {
//        cycle_quadratic(cofs, otv, file);
//    }
//    else if( str == 'e' )
//    {
//        abort();
//    }
//    else{
//        printf("Please, type only 't' or 'u'. \n");
//        fflush(stdin);
//        start_programm(cofs, otv, file);
//    }
//}

void quadratic( struct coeff cofs, struct out *otv){

    assert (isfinite(cofs.a));
    assert (isfinite(cofs.b));
    assert (isfinite(cofs.c));
    
    assert (otv != NULL);
    
    if ( !compare( cofs.a, 0) )
    {
        if ( compare(cofs.b, 0) )
        {
            without_b( cofs, otv );
        }
        else
        {
            if ( compare(cofs.c, 0) )
            {
                without_c( cofs, otv);
            }
            else
            {
                usual_quadratic(cofs, otv);
            }
        }
    }
    else
    {
        linear_equation( cofs, otv);
    }
}

bool one_test(struct out *otv, struct out right_otv, struct coeff *cofs )
{
    assert(otv != NULL);
    assert(isfinite(right_otv.cnt));
    
    quadratic( *cofs, otv);
    
    switch (otv->cnt)
    {
        case ALL_NUMBERS:
            if (right_otv.cnt == ALL_NUMBERS) return true;
            else return false;
            
        case NO_SOLUTION:
            if (right_otv.cnt ==  NO_SOLUTION) return true;
            else return false;
        
        case ONE_SOLUTION:
            assert(isfinite(right_otv.p));
            
            if (right_otv.cnt ==  ONE_SOLUTION && compare(right_otv.p, otv->p) ) return true;
            else return false;
        
        case TWO_SULUTIONS:
            assert(isfinite(right_otv.p));
            assert(isfinite(right_otv.q));
            
            if (right_otv.cnt ==  TWO_SULUTIONS && compare(right_otv.p, otv->p) && compare(right_otv.q, otv->q) ) return true;
            else return false;
        
        default:
            return false;
            break;
    }
}

bool input_str(struct coeff *cofs, struct out *right_otv  ,FILE *file)
{
    assert(cofs != NULL);
    assert(right_otv != NULL);
    assert(file != NULL);
    
    if ( fscanf( file, "%lg%lg%lg%d", &cofs->a, &cofs->b, &cofs->c, &right_otv->cnt) == 4 )
    {
        switch (right_otv->cnt)
        {
            case ONE_SOLUTION:
                fscanf(file, "%lg", &right_otv->p);
                break;
            case TWO_SULUTIONS:
                fscanf(file,"%lg%lg", &right_otv->p, &right_otv->q );
                break;
            default:
                break;
        }
        return true;
    }
    else return false;
}

void tests(struct coeff *cofs, struct out *otv, FILE *file )
{
    assert(file != NULL);
    assert(cofs != NULL);
    assert(otv  != NULL);
    
    struct out right_otv {};
    
    while (input_str(cofs, &right_otv, file) )
    {
        if (one_test(otv, right_otv, cofs) )
        {
            printf("Passsed\n");
        }
        else
        {
            printf("Not passsed\n");
        }
    }
}
