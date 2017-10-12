/*
 * Kuş sayısı değişken olacak
 * Hunter sayısı sabit olacak
 *
 */
#include <stdio.h>
#include "Utility\inc\prng_uniform.hh"
#include "DuckShootingTest.hh"

using namespace os_prng_tests::in_progress;

int main(void)
{
    int a = 0;

    std::cout << "Merhaba\n" << std::endl;
    std::cout << "Kus sayisini giriniz:" << std::endl;
    //std::cin >> a;
    a = 10;
    //std::cout << "Girilen kus sayisi:" << a << "' dir!"<< std::endl;
    
    DuckShootingTest * instance = new DuckShootingTest();
    

    //PRNG_Uniform instance = new PRNG_Uniform();
    
    return 0;
}