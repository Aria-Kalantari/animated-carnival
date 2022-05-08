#include "BigNum.cpp"
#include <iostream>

int main(void)
{
    BigNum num1("99999999999999999999");
    BigNum num2("+1234567890");
    BigNum num3("-9876543210");
    BigNum num4("-9999999999");
    BigNum num5(123456789);
    BigNum num6("1000000000000000001");
    BigNum num7("500");
    BigNum num8("-123123123123123123123123123123123123123123123123123123123123123");
    BigNum num9("-1231231231231231231231231231231231231231231231231231231231231231");
    BigNum num10("-12312312312312312312312312312312312312312312312312312312312312312");

    BigNum sum;
    BigNum difference;
    BigNum product;
    BigNum quotient;
    BigNum remainder;  

    std::cout << (num1 + num3 - num5 * num6);

    std::cout << std::endl << "******************************************************************** operator+ ********************************************************************" << std::endl;

    sum = num1 + num1;
    std::cout << "sum = num1 + num1              ==>" << " sum = " << sum << std::endl;

    sum = num2 + num3;
    std::cout << "sum = num2 + num3              ==>" << " sum = " << sum << std::endl;

    sum = num1 + num4;
    std::cout << "sum = num1 + num4              ==>" << " sum = " << sum << std::endl;

    sum = num1 + 1;
    std::cout << "sum = num2 + 1                 ==>" << " sum = " << sum << std::endl;

    sum = 1 + num1;
    std::cout << "sum = 1 + num3                 ==>" << " sum = " << sum << std::endl;

    sum = num4 + num5;
    std::cout << "sum = num4 + num5              ==>" << " sum = " << sum << std::endl;

    sum = num4 + (-5000000000);
    std::cout << "sum = num4 + (-5000000000)     ==>" << " sum = " << sum << std::endl;


    std::cout << std::endl << "******************************************************************** operator- ********************************************************************" << std::endl;

    difference = num1 - num1;
    std::cout << "difference = num1 - num1         ==>" << " difference = " << difference << std::endl;

    difference = num2 - num3;
    std::cout << "difference = num2 - num3         ==>" << " difference = " << difference << std::endl;

    difference = num1 - num4;
    std::cout << "difference = num1 - num4         ==>" << " difference = " << difference << std::endl;

    difference = num6 - 1;
    std::cout << "difference = num6 - 1            ==>" << " difference = " << difference << std::endl;

    difference = 1 - num6;
    std::cout << "difference = 1 - num6            ==>" << " difference = " << difference << std::endl;

    difference = num4 - num5;
    std::cout << "difference = num4 - num5         ==>" << " difference = " << difference << std::endl;

    sum = num4 - (+5000000000);
    std::cout << "sum = num4 - (+5000000000)       ==>" << " difference = " << difference << std::endl;


    std::cout << std::endl << "******************************************************************** operator* ********************************************************************" << std::endl;

    product = num1 * num1;
    std::cout << "product = num1 * num1              ==>" << " product = " << product << std::endl;

    product = num2 * num3;
    std::cout << "product = num2 * num3              ==>" << " product = " << product << std::endl;

    product = num1 * num4;
    std::cout << "product = num1 * num4              ==>" << " product = " << product << std::endl;

    product = num1 * 1;
    std::cout << "product = num2 * 0                 ==>" << " product = " << product << std::endl;

    product = 1 * num1;
    std::cout << "product = 0 * num3                 ==>" << " product = " << product << std::endl;

    product = num4 * num5;
    std::cout << "product = num4 * num5              ==>" << " product = " << product << std::endl;

    product = num4 * (-5000000000);
    std::cout << "product = num4 * (-5000000000)     ==>" << " product = " << product << std::endl;


    std::cout << std::endl << "******************************************************************** operator/ ********************************************************************" << std::endl;

    quotient = num1 / num1;
    std::cout << "quotient = num1 / num1              ==>" << " quotient = " << quotient << std::endl;

    quotient = num2 / num3;
    std::cout << "quotient = num2 / num3              ==>" << " quotient = " << quotient << std::endl;

    quotient = num1 / num4;
    std::cout << "quotient = num1 / num4              ==>" << " quotient = " << quotient << std::endl;

    try
    {
        quotient = num1 / 0;
        std::cout << "quotient = num1 / 0                 ==>" << " quotient = " << quotient << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }

    quotient = 0 / num1;
    std::cout << "quotient = 1 / num3                 ==>" << " quotient = " << quotient << std::endl;

    quotient = num4 / num5;
    std::cout << "quotient = num4 / num5              ==>" << " quotient = " << quotient << std::endl;

    quotient = num4 / (-50000);
    std::cout << "quotient = num4 / (-50000)          ==>" << " quotient = " << quotient << std::endl;


    std::cout << std::endl << "******************************************************************** operator% ********************************************************************" << std::endl;

    remainder = num1 % num1;
    std::cout << "remainder = num1 % num1              ==>" << " remainder = " << remainder << std::endl;

    remainder = num2 % num3;
    std::cout << "remainder = num2 % num3              ==>" << " remainder = " << remainder << std::endl;

    remainder = num1 % num4;
    std::cout << "remainder = num1 % num4              ==>" << " remainder = " << remainder << std::endl;

    try
    {
        remainder = num1 % 0;
        std::cout << "remainder = num1 % 0                 ==>" << " remainder = " << remainder << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }

    remainder = 0 % num1;
    std::cout << "remainder = 0 % num3                 ==>" << " remainder = " << remainder << std::endl;

    remainder = num4 % num5;
    std::cout << "remainder = num4 % num5              ==>" << " remainder = " << remainder << std::endl;

    remainder = num4 % (-50000);
    std::cout << "remainder = num4 % (-50000)          ==>" << " remainder = " << remainder << std::endl;


    std::cout << std::endl << "******************************************************************** operator> ********************************************************************" << std::endl;

    std::cout << std::boolalpha << "num1 > num1         ==> " << (num1 > num1) << std::endl;
    std::cout << std::boolalpha << "num3 > num2         ==> " << (num3 > num2) << std::endl;
    std::cout << std::boolalpha << "num4 > num2         ==> " << (num4 > num2) << std::endl;
    std::cout << std::boolalpha << "num1 > 0            ==> " << (num1 > 0) << std::endl;
    std::cout << std::boolalpha << "num5 > (-50000)     ==> " << (num5 > (-50000)) << std::endl;
    std::cout << std::boolalpha << "(-50000) > num5     ==> " << ((-50000) > num5) << std::endl;


    std::cout << std::endl << "******************************************************************** operator>= ********************************************************************" << std::endl;

    std::cout << std::boolalpha << "num1 >= num1         ==> " << (num1 >= num1) << std::endl;
    std::cout << std::boolalpha << "num3 >= num2         ==> " << (num3 >= num2) << std::endl;
    std::cout << std::boolalpha << "num4 >= num2         ==> " << (num4 >= num2) << std::endl;
    std::cout << std::boolalpha << "num1 >= 0            ==> " << (num1 >= 0) << std::endl;
    std::cout << std::boolalpha << "num5 >= (-50000)     ==> " << (num5 >= (-50000)) << std::endl;
    std::cout << std::boolalpha << "(-50000) >= num5     ==> " << ((-50000) >= num5) << std::endl;


    std::cout << std::endl << "******************************************************************** operator< ********************************************************************" << std::endl;

    std::cout << std::boolalpha << "num1 < num1         ==> " << (num1 < num1) << std::endl;
    std::cout << std::boolalpha << "num3 < num2         ==> " << (num3 < num2) << std::endl;
    std::cout << std::boolalpha << "num4 < num2         ==> " << (num4 < num2) << std::endl;
    std::cout << std::boolalpha << "num1 < 0            ==> " << (num1 < 0) << std::endl;
    std::cout << std::boolalpha << "num5 < (-50000)     ==> " << (num5 < (-50000)) << std::endl;
    std::cout << std::boolalpha << "(-50000) < num5     ==> " << ((-50000) < num5) << std::endl;


    std::cout << std::endl << "******************************************************************** operator<= ********************************************************************" << std::endl;

    std::cout << std::boolalpha << "num1 <= num1         ==> " << (num1 <= num1) << std::endl;
    std::cout << std::boolalpha << "num3 <= num2         ==> " << (num3 <= num2) << std::endl;
    std::cout << std::boolalpha << "num4 <= num2         ==> " << (num4 <= num2) << std::endl;
    std::cout << std::boolalpha << "num1 <= 0            ==> " << (num1 <= 0) << std::endl;
    std::cout << std::boolalpha << "num5 <= (-50000)     ==> " << (num5 <= (-50000)) << std::endl;
    std::cout << std::boolalpha << "(-50000) <= num5     ==> " << ((-50000) <= num5) << std::endl;


    std::cout << std::endl << "******************************************************************** operator== ********************************************************************" << std::endl;

    std::cout << std::boolalpha << "num1 == num1         ==> " << (num1 == num1) << std::endl;
    std::cout << std::boolalpha << "num3 == num2         ==> " << (num3 == num2) << std::endl;
    std::cout << std::boolalpha << "num4 == num2         ==> " << (num4 == num2) << std::endl;
    std::cout << std::boolalpha << "num1 == 0            ==> " << (num1 == 0) << std::endl;
    std::cout << std::boolalpha << "num5 == (-50000)     ==> " << (num5 == (-50000)) << std::endl;
    std::cout << std::boolalpha << "(-50000) == num5     ==> " << ((-50000) == num5) << std::endl;


    std::cout << std::endl << "******************************************************************** operator!= ********************************************************************" << std::endl;

    std::cout << std::boolalpha << "num1 != num1         ==> " << (num1 != num1) << std::endl;
    std::cout << std::boolalpha << "num3 != num2         ==> " << (num3 != num2) << std::endl;
    std::cout << std::boolalpha << "num4 != num2         ==> " << (num4 != num2) << std::endl;
    std::cout << std::boolalpha << "num1 != 0            ==> " << (num1 != 0) << std::endl;
    std::cout << std::boolalpha << "num5 != (-50000)     ==> " << (num5 != (-50000)) << std::endl;
    std::cout << std::boolalpha << "(-50000) != num5     ==> " << ((-50000) != num5) << std::endl;


    std::cout << std::endl << "******************************************************************** operator>> ********************************************************************" << std::endl;

    try
    {
        std::cin >> num7;
        std::cout << num7 << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << '\n';
    }


    std::cout << std::endl << "******************************************************************** operator[] ********************************************************************" << std::endl;

    try
    {
        std::cout << "num3[0] = " << num3[0] << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << '\n';
    }

    std::cout << "num3[1] = " << num3[1] << std::endl;
    std::cout << "num3[5] = " << num3[5] << std::endl;

    try
    {
        std::cout << "num3[11] = " << num3[11] << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << error.what() << '\n';
    }


    std::cout << std::endl << "**************************************************************** printWithDelimeter ****************************************************************" << std::endl;

    std::cout << "num8.printWithDelimeter()      ==> ";
    num8.printWithDelimeter();

    std::cout << "num9.printWithDelimeter()      ==> ";
    num9.printWithDelimeter();

    std::cout << "num10.printWithDelimeter()     ==> ";
    num10.printWithDelimeter();

    std::cout << std::endl;

    return 0;
}
