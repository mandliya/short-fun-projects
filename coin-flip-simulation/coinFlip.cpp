/*
 * C++11 Program to simulate a coin flip using Bernoulli's distribution 
 */

#include<iostream>
#include<sstream>
#include<random>
#include<vector>

int main()
{
    int n;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::bernoulli_distribution dist;
    std::cout << "Enter Number of flips: ";
    std::cin >> n;
    std::vector<bool> vec;
    vec.reserve(n);
    int heads = 0, tails = 0;
    std::stringstream ss;
    for ( int i = 0; i < n ; ++i) {
        vec.push_back( dist(mt) );
        if ( vec[i] ) {
            ++heads;
            ss << "H";
        } else {
            ++tails;
            ss << "T";
        }
    }

    std::cout << "Total heads : " << heads << " Total tails : " << tails
              << "\n" << ss.str() << std::endl;

    return 0;

}
