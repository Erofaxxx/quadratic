//
//  func.hpp
//  quadratic
//
//  Created by Stepan Kaldyshev on 25.08.2022.
//
//HEADER GUARDS
#ifndef func_hpp
#define func_hpp

#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <string.h>


#define SQR(x) ( (x) * (x) )


/*!
 \brief The function imperfective how correct  funcion quadratic works
 \param [in] cofs 3 coefficients a, b, c
 \param [in] otv Answer
 \param [in] file read file
 */
void tests(struct coeff *cofs, struct out *otv, FILE *file );

/*!
 \brief The function read from the file coefficients and right answers
 \param [in] cofs 3 coefficients a, b, c
 \param [in] right_otv  Right answer
 \param [in] file Read file
 */
bool input_str(struct coeff *cofs, struct out *right_otv  ,FILE *file);

/*!
 \brief The functioin imperfective quadraitc function for correct work ( Is the quadratic answer equal to right answer?)
 \param [in,out] otv Answer of quadratic function
 \param [in] right_otv Right answer
 \param [in] cofs 3 coefficients a, b, c
 \return If answer of quadratic function is equal to right answer - return true, else - return false
 */
bool one_test(struct out *otv, struct out right_otv, struct coeff *cofs );

/*!
\brief Function clears the buffer
 */
void clean_buff();

/*!
\brief The function accepts 3 coefficients from the user.
\param [in,out] cofs 3 coefficients
 \return Counted 3 numbers or not ( if input 'e' - return false, else - return true and continue try get 3 coefficients )
 */
bool input_3(struct coeff *cofs );

/*!
 \brief The function output the answer
 \param [in] otv Answer
 */
void output(struct out otv);

/*!
 \brief The function solves the linear equation
 \param [in] cofs 3 coefficients a, b, c
 \param [out] otv Answer
 */
void linear_equation(struct coeff cofs, struct out *otv);

/*!
 \brief The function solves quadratic equation when argument b is null
 \param [in] cofs 3 coefficients a, b, c
 \param [out] otv Answer
 */
void without_b(struct coeff cofs, struct out *otv);

/*!
 \brief The function solves quadratic equation when argument c is null
 \param [in] cofs 3 coefficients a, b, c
 \param [out] otv Answer
 */
void without_c(struct coeff cofs, struct out *otv);

/*!
 \brief The function solves quadratic equation when arguments a, b, c aren't null
 \param [in] cofs 3 coefficients a, b, c
 \param [out] otv Answer
 */
void usual_quadratic(struct coeff cofs, struct out *otv);

/*!
 \brief Count the discriminant
 \param [in] cofs 3 coefficients a, b, c
 \return discriminant value
 */
double discriminant(struct coeff cofs);

/*!
 \brief Function solves all types of quadratic equations
 \param [in] cofs 3 coefficients a, b, c
 \param [out] otv Answer
 */
void quadratic(struct coeff cofs, struct out *otv);

/*!
 \brief The function compare two double nums
 \param [in] x First double num which should to compare
 \param [in] y Second double nun which shoul to compare
 \return Are two numbers equal
 */
bool compare(const double x,const double y);

/*!
 \brief The function include input function, solve the quadratic equation and output the answer to user in terminal
 \param [in,out] cofs 3 coefficients a, b, c
 \param [in,out] otv Answer
 */
void cycle_quadratic(struct coeff *cofs, struct out *otv);

///Coefficients in quadratic equation a*x^2 + b*x + c = 0
struct coeff{
        double a = NAN; ///<Argument a
        double b = NAN; ///<Argument b
        double c = NAN; ///<Argument c
};

///Answer
struct out{
        double p = NAN; ///<The first solution ( if exist )
        double q = NAN; ///<The second solution ( if exist )
        int cnt  = 0;   ///<Count of solutions
};

///Count of solutions
enum count_solutions
{
    ALL_NUMBERS   = -1,///<Means the solution is all real numbers
    NO_SOLUTION   = 0, ///<Means it's no solution
    ONE_SOLUTION  = 1, ///<Means it's only one solution
    TWO_SULUTIONS = 2  ///<Means it's two solutions
};
///Errors
enum ERRORS {
    
    NO_FILE_NAME_ERROR = 2 ///<File name don't input
    
};

#endif /* func_hpp */
