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

using namespace std;
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
void Utility::DisplayVector(vector<double> &vectorToBeDisplayed)
{
    cout << "Size: " << vectorToBeDisplayed.size() << endl;
    for (uint32_t i = 0; i < vectorToBeDisplayed.size(); ++i)
        cout << vectorToBeDisplayed[i] << " ";
    cout << endl;
    cout << endl;
}

/*
 * Display Matrix
 */
void Utility::DisplayMatrix(vector<vector<double>> &matrixToBeDisplayed)
{
    cout << "A " << matrixToBeDisplayed.size() << " * " <<
    matrixToBeDisplayed[0].size() << " matrix will be displayed:" << endl;
    
    for (uint32_t i = 0; i < matrixToBeDisplayed.size(); ++i) {
        for (uint32_t k = 0; k < matrixToBeDisplayed[i].size(); ++k) {
            cout << matrixToBeDisplayed[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


vector<double> Utility::linspace(double startNumber, double endNumber, uint32_t nPoints){
    vector<double> tempLinspace;

    for( uint32_t i = 0 ; i < nPoints ; ++i ){
        tempLinspace.push_back( startNumber + ( ( i * ( endNumber - startNumber ) / (nPoints-1) ) ) );
    }

    return(tempLinspace);
}