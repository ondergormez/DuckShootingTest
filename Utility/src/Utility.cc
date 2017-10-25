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

#include "Utility.hh"

/*
 * Global Defitions
 */

/*
 * Constructor
 */
Utility::Utility()
{

}

/*
 * Destructer
 */
Utility::~Utility()
{

}

/*
 * Display Vector
 */
void Utility::DisplayVector(std::vector<double> &vectorToBeDisplayed)
{
    std::cout << "Size: " << vectorToBeDisplayed.size() << std::endl;
    for (uint32_t i = 0; i < vectorToBeDisplayed.size(); ++i)
        std::cout << vectorToBeDisplayed[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

/*
 * Display Matrix
 */
void Utility::DisplayMatrix(std::vector<std::vector<double>> &matrixToBeDisplayed)
{
    std::cout << "A " << matrixToBeDisplayed.size() << " * " <<
    matrixToBeDisplayed[0].size() << " matrix will be displayed:" << std::endl;
    
    for (uint32_t i = 0; i < matrixToBeDisplayed.size(); ++i) {
        for (uint32_t k = 0; k < matrixToBeDisplayed[i].size(); ++k) {
            std::cout << matrixToBeDisplayed[i][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


vector<double> Utility::linspace(double startNumber, double endNumber, uint32_t nPoints){
    vector<double> tempLinspace;

    for( uint32_t i = 0 ; i < nPoints ; ++i ){
        tempLinspace.push_back( startNumber + ( ( i * ( endNumber - startNumber ) / (nPoints-1) ) ) );
    }

    return(tempLinspace);
}

// // replacement of a minimal set of functions:
// void* operator new(std::size_t sz) {
//     std::printf("global op new called, size = %zu\n",sz);
//     return std::malloc(sz);
// }

// void operator delete(void* ptr) noexcept
// {
//     std::puts("global op delete called");
//     std::free(ptr);
// }