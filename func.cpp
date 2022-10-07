#include "func.hpp"

//#define assert //

const double EPSILON = 0.001;


bool compare(const double x, const double y)
{
    return ( fabs(x - y) < EPSILON );
}

void clean_buff()
{
    //scanf("%*[^\n]");
    fflush(stdin);
}

bool input_3(struct coeff *cofs){
    
    assert (cofs != NULL);
    //assert (1 == 0);
    
    printf("Input 3 coefficients a, b, c. If you wanna exit programm - print 'e'. \n");
   
    while (scanf ( "%lf%lf%lf", &cofs->a, &cofs->b, &cofs->c) != 3)
    {
        char str = 0;
        scanf("%c", &str);
        
        if (str == 'e')
        {
            return false;
        }
        
        fflush (stdin);
        
        printf ("Please, input three double nums: \n");
    }
    
    fflush (stdin);
    return true;
}

void output(struct out otv){
    
    switch (otv.cnt)
    {
        case NO_SOLUTION:
            printf("No one solution! \n");
            //return NO_SOLUTION;
            break;
        case ONE_SOLUTION:
            printf("One solution: x = %lg \n", otv.p);
            //return ONE_SOLUTION;
            break;
        case TWO_SULUTIONS:
            printf("Two solves: x1 = %lg , x2 = %lg \n", otv.p, otv.q);
            //return TWO_SULUTIONS;
            break;
        case ALL_NUMBERS:
            printf("All real numbers!!! \n");
            //return -ALL_NUMBERS;
            break;
        default:
            //return -2;
            break;
        }
}

void linear_equation(struct coeff cofs, struct out *otv)
{
    assert( isfinite(cofs.a));
    assert( isfinite(cofs.b));
    assert( isfinite(cofs.c));
    
    if (compare(cofs.b, 0) && !compare( cofs.c, 0 ) )
    {
        otv->cnt = NO_SOLUTION;
    }
    else if(compare( cofs.c, 0 ) && compare(cofs.b, 0) )
    {
        otv->cnt = ALL_NUMBERS;
    }
    else
    {
        if ( compare(cofs.c, 0) )
        {
            otv->p = 0;
        }
        else
        {
            otv->p = -cofs.c / cofs.b;
        }
        otv->cnt = ONE_SOLUTION;
    }
}

void without_b(struct coeff cofs, struct out *otv)
{
    assert( isfinite(otv->cnt));
    
    if ( compare(cofs.c, 0) )
    {
        otv->p   = 0;
        otv->cnt = ONE_SOLUTION;
    }
    
    else if ( (cofs.a * cofs.c) < 0 )
    {
        otv->p =  sqrt( -cofs.c / cofs.a );
        otv->q = -sqrt( -cofs.c / cofs.a );
        
        otv->cnt = TWO_SULUTIONS;
    }
    
    else{
        otv->cnt = NO_SOLUTION;
    }
}

void without_c(struct coeff cofs, struct out *otv)
{
    assert( isfinite(otv->cnt));
    
    otv->p   = 0;
    otv->q   = - cofs.b / cofs.a;
    otv->cnt = TWO_SULUTIONS;
}

void usual_quadratic(struct coeff cofs, struct out *otv){
    
    assert(isfinite(cofs.a));
    assert(isfinite(cofs.b));
    assert(isfinite(cofs.c));
    
    assert(otv != NULL);
    
    double discrim = discriminant(cofs);

    if (discrim < 0 )
    {
        otv->cnt = NO_SOLUTION;
    }
    
    else if ( compare(discrim, 0) )
    {
        otv->p   = -cofs.b / (2 * cofs.a);
        otv->cnt = ONE_SOLUTION;
    }
    
    else
    {
        discrim = sqrt (discrim);
        
        otv->p   = (- cofs.b + sqrt(discriminant(cofs))) / (2 * cofs.a);
        otv->q   = (- cofs.b - sqrt(discriminant(cofs))) / (2 * cofs.a);
        otv->cnt = TWO_SULUTIONS;
    }
}

double discriminant(struct coeff cofs)
{
    assert(isfinite(cofs.a));
    assert(isfinite(cofs.b));
    assert(isfinite(cofs.c));
    
    return ( SQR(cofs.b) - 4 * cofs.a * cofs.c );
}


void cycle_quadratic(struct coeff *cofs, struct out *otv){
    
    assert(cofs != NULL);
    assert(otv != NULL);

    while (input_3( cofs ) )
    {
        quadratic( *cofs , otv );
        output(*otv);
    }
}
