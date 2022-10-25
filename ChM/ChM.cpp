#include "myVector.h"
#include "lentMatrix.h"
#include <math.h>
int main()
{
    std::ifstream input;
    std::ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    if (!input.is_open() || !output.is_open()) {
        std::cout << "Files not open";
        return 0;
    }
    else {
        std::srand(time(0)); 
        /*output.precision(20);*/
        for (int i = 10; i <= 1000000; i*=10) {
            double a=1.0/i, b=i;
            int k;
            k = rand() % (i - 2) + 1;
            lentMatrix matr(i, k);
            lentMatrix matr1(i, k);
            myVector x_correct(i);
            x_correct.randomFilling(a, b);
            matr.randomFilling(a, b);
            matr1 = matr;
            myVector f_correct(i);
            f_correct = matr1 * x_correct;
            //output << "matr(" << i << ") = \n" << matr;
            myVector x_calculated(i);
            //output << "x_correct(" << i << ") = \n" << x_correct << "f_correct(" << i << ") = \n" << f_correct;
            x_calculated = matr.solution(f_correct);
            //output << "x_calculated(" << i << ") = \n" << x_calculated << "f_calculated(" << i << ") = \n" << matr1 * x_calculated;
            output << "norm_of_(x_calculated-x_correct)(" << i << ") = " << (x_calculated - x_correct).norm() << "\n\n";
        }
        for (int i = 10; i <= 1000000; i*=10) {
            double a = 1.0 / 10, b = 10;
            int k;
            k = rand() % (i - 2) + 1;
            lentMatrix matr(i, k);
            lentMatrix matr1(i, k);
            myVector x_correct(i);
            x_correct.randomFilling(a, b);
            //x_correct.setOnes();
            matr.HilbertFilling();
            matr1 = matr;
            myVector f_correct(i);
            f_correct = matr1 * x_correct;
            //output << "matr(" << i << ") = \n" << matr;
            myVector x_calculated(i);
            //output << "x_correct(" << i << ") = \n" << x_correct << "f_correct(" << i << ") = \n" << f_correct;
            x_calculated = matr.solution(f_correct);
            //output << "x_calculated(" << i << ") = \n" << x_calculated << "f_calculated(" << i << ") = \n" << matr1 * x_calculated;
            output << "norm_of_(x_calculated-x_correct)(" << i << ") = " << (x_calculated - x_correct).norm() << "\n\n";
        }
    }
}