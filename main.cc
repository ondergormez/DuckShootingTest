/**
 * Copyright (C) 2017 Önder Görmez

 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see 
 * http://www.gnu.org/licenses/.

 * For any questions, please contact me @ ondergormez@gmail.com.
 */

/*
 * The number of ducks should be variable
 * The number of hunters should be constant
 *
 */

#include <iostream>
#include "DuckShootingTest.hh"
#include "prng_uniform.hh"

using namespace std;
using namespace os_prng_tests::in_progress;

/*
 * Global Defitions
 */

int main(void)
{
    uint32_t numberOfDucks = 10;

    cout << "Hello" << endl;
    cout << "Please enter the number of ducks:" << endl;
    //cin >> numberOfDucks; /* TODO: Fix this */
    
    DuckShootingTest *instance = new DuckShootingTest(numberOfDucks);
    
    return 0;
}