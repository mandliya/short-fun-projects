/*
 * Program to convert binary to decimal and decimal to binary
 * Using string to represent binary numbers, so we can do conversion for very large number
 */

#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>


long long  binaryToDecimal( std::string bin )
{
    std::reverse(bin.begin(), bin.end());
    long long deci = 0;
    long long base = 1;
    for( auto & c : bin ) {
        if ( c == '1' ) {
            deci += base;
        }
        base *= 2;
    }
    return deci;
}

std::string decimalToBinary( long long int deci ) {
    std::stringstream ss;
    std::string result;
    while ( deci != 0 ) {
        ss << ( deci % 2 );
        deci /= 2;
    }
    result = ss.str();
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::cout << "What conversion would you like to do : "
              << "\n1. Binary to Decimal"
              << "\n2. Decimal to Binary"
              << "\nEnter choice: ";
    int c;
    std::cin >> c;
    switch(c)
    {
        case 1:
        {
            std::cout << "Enter a binary number:";
            std::string bin;
            std::cin >> bin;
            std::cout << "Binary to decimal conversion\n";
            std::cout << bin << " ---> " << binaryToDecimal(bin) << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Enter a decimal number:";
            long long deci;
            std::cin >> deci;
            std::cout << "Decimal to binary  conversion\n";
            std::cout << deci << " ---> " << decimalToBinary(deci) << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice\n";
    }
    return 0;
}
