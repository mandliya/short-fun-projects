/*
 *Creates  matrix-like screen using C++ threads.

 *Reference - http://www.quora.com/What-is-the-best-C++-code-that-you-have-ever-written/answer/Sumit-Sahrawat-1?srid=p2CT&share=1
  
 *Added my own- Instead of using constant width I used winsize + ioctl to detect terminal width

 *Use "Green on Black" as terminal setting
*/

#include<iostream>
#include<sys/ioctl.h>
#include<chrono>  //time library
#include<string>
#include<thread>
#include<cstdlib>

const int width = 158;      //width of terminal window
const int flipsPerLine = 5; //No. of columns changed per line
const int msSleep = 30;     //Delay between lines in milisecond

int main()
{
    srand(time_t(NULL));    //random seed
    bool switches[width] = {true};
    const std::string randChars = "1234567890/*-+.,./;[]\\=_~`!@#$%^&*()";
    const auto glen = randChars.size();
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    while(true)
    {
        for(int i = 0; i != w.ws_col; ++i)
        {
            if(switches[i])
                std::cout<<randChars[rand() % glen];
            else
                std::cout<<' ';
        }
        std::cout<<std::endl;
        for(int i = 0; i != flipsPerLine; ++i)
        {
            int x = rand() % w.ws_col;
            switches[x] = !switches[x]; //toggle switch;
            std::this_thread::sleep_for(std::chrono::milliseconds(msSleep));
        }
    }
    return 0;
}



