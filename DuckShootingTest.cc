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

#include "DuckShootingTest.hh"
#include "Utility.hh"
#include "prng_uniform.hh"
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;
using namespace os_prng_tests::in_progress;

/*
 * Global Defitions
 */

/*
 * Constructor
 */
DuckShootingTest::DuckShootingTest(uint32_t numberOfDucks)
{
    NumberOfDucks = numberOfDucks;
#ifndef NDEBUG
    cout << "\nDuckShootingTest class instance created!\n" << endl;
#endif
    ResultStruct *resultObject = nullptr;                                                                                           /* TODO: Fix this */
    Core(resultObject);                                                                                                             /* TODO: Put the function call at the right place */
}

/*
 * Destructer
 */
DuckShootingTest::~DuckShootingTest()
{

}

/*
 * Core Function
 */
ResultStruct_t * DuckShootingTest::Core(ResultStruct_t *resultObject)
{
    vector<double> numberOfTests = vector<double>(10); /*TODO: Value must be 100*/
    uint32_t numberOfHunters = 2; /*TODO: Value must be 10*/

    vector<double> lam = Utility::linspace(3.0, 8.0, 31);
    vector<double> p = Utility::linspace(0.05, 0.95, 31);
    vector<vector<double>> resultMatrix = vector<vector<double>>(lam.size(), vector<double>(p.size()));

#ifndef NDEBUG
    cout << "Number Of Tests: " << numberOfTests.size() << endl;
    cout << "Number Of Hunters: " << numberOfHunters << endl;
    cout << "lam = " << lam.size() << endl;
    cout << "p = " << p.size() << endl;

    //Utility::DisplayVector<double>(lam);
    //Utility::DisplayVector<double>(p);
    //Utility::DisplayMatrix<double>(resultMatrix);
#endif



    for (int kk = 0; kk < lam.size(); ++kk) { /* NOTE: Rows' of resultMatrix*/ /*TODO: Change this with resultMatrix[0].Size()*/
        for (int ll = 0; ll < p.size(); ++ll) { /* NOTE: Columns' of resultMatrix*/ /*TODO: Change this with resultMatrix column size*/

            /* TODO: Delete This */
#ifndef NDEBUG
            if (kk == 0 && ll == 0) {
                cout << "Created Number Of Tests Vector: " << endl;
                cout << "Size: " << numberOfTests.size() << endl;
                cout << endl;
                Utility::DisplayVector<double>(numberOfTests);
            }
#endif

            for (int mm = 0; mm < numberOfTests.size(); ++mm) {
                vector<vector<double>> temp;

                int32_t poisResult = PRNG_Uniform::PoissonRandom(lam[kk]);

                if (!poisResult) {
                    numberOfTests[mm] = 0.0;
                }
                else {

                    temp = MatrixFillWith(poisResult, numberOfHunters, -99.0); /* TODO: Fix this */
                   for (int i = 0; i < temp.size(); ++i) {
                       vector<vector<int>> targets = randi(temp.size(), numberOfHunters, 1);
                       for (int nn = 0; nn < temp.size(); ++nn) {
                           uint32_t numberOfEqualIndex = findNumberOfEqualIndexCount(targets, nn);
                           if (numberOfEqualIndex) {
                               vector<double> *tempVector = PRNG_Uniform::getNumbers(numberOfEqualIndex); /* TODO: Fix this usage */
                               for (uint32_t os = 0; os < numberOfEqualIndex; ++os) {
                                   temp[nn][os] = (*tempVector)[os]; /* TODO: Find more accurate way */
                               }
                           }
                       }
#ifndef NDEBUG
                       //Utility::DisplayMatrix<double>(temp);
#endif                        
                   }
                }
                vector<uint32_t> indicesAll = vector<uint32_t>(Utility::numel(temp));
                for (uint32_t i = 0; i < indicesAll.size(); ++i) {
                    indicesAll[i] = i;        
                }

                Utility::DisplayMatrix<double>(temp);

                vector<uint32_t> indices_m99 = findNumberOfEqualIndexes(temp, -99);
                Utility::DisplayVector<uint32_t>(indices_m99);

                vector<uint32_t> indices_not_m99 = Utility::setdiff(indicesAll, indices_m99);
                Utility::DisplayVector<uint32_t>(indices_not_m99);

                vector<uint32_t> indices_one = findNumberOfWithInRangeIndexes(temp, 0.0, p[ll]);
                Utility::DisplayVector<uint32_t>(indices_one);
            }
        }
    }
    // for kk = 1:size(res,1)
    //     for ll = 1:size(res,2)
    //         for mm = 1:noTests

    //             if isempty(tmp)
    //             else
    //                 targets = randi( size(tmp,1) , noHunters , 1 );
    //                 for nn = 1:size(tmp,1)
    //                     number = numel( find( targets == nn ) );
    //                     if number > 0
    //                         tmp(nn,1:number) = rand(1,number);
    //                     end
    //                     clear number;
    //                 end % for nn
    //                 clear targets;
    //             end
    //             indices_all     = 1:numel(tmp);
    //             indices_m99     = find( tmp == -99 );
    //             indices_not_m99 = setdiff( indices_all , indices_m99 );
    //             indices_one     = find( (tmp >= 0.0) & (tmp < p(ll)) );
    //             indices_zero    = setdiff( indices_not_m99 , indices_one );
                
    //             tmp( indices_one )  = 1;
    //             tmp( indices_zero ) = 0;
    //             tmp( indices_m99 )  = 0;
                
    //             tests(mm) = numel( find( sum(tmp,2) > 0 ) );
                
    //             clear tmp;
    //         end % for mm
    //         res(kk,ll) = sum(tests) / numel(tests);
    //         clear tests;
    //     end % for ll
    // end % for kk

    resultObject->Lam = lam;
    resultObject->P = p;
    resultObject->ResultMatrix = resultMatrix;
#ifndef NDEBUG
    Utility::DisplayMatrix<double>(resultObject->ResultMatrix);
#endif
    return resultObject;
}

vector<vector<double>> DuckShootingTest::MatrixFillWith(uint32_t numOfRows, uint32_t numOfColmns, double filledWith)
{
    vector< double > tempRow;
    vector< vector<double> > onesVector;

    for( int i = 0 ; i < numOfColmns ; ++i){
        tempRow.push_back(filledWith);
    }

    for( int j = 0 ; j < numOfRows ; ++j){
        onesVector.push_back(tempRow);
    }

    return onesVector;
}

vector<vector<int>> DuckShootingTest::randi(uint32_t numberRange, uint32_t numOfRows, uint32_t numOfColmns)
{
    vector<vector<int>> randomMatrix;
    vector<int> tempRow;
    vector<double> *tempRowDouble;

    for (int j = 0; j < numOfRows; ++j) {
        tempRowDouble = PRNG_Uniform::getNumbers(numOfColmns);

        for (int k = 0; k < (*tempRowDouble).size(); ++k)
            (*tempRowDouble)[k] *= numberRange;

        for (int k = 0; k < (*tempRowDouble).size(); ++k) {
            tempRow.push_back((int)(*tempRowDouble)[k]);
        }

        randomMatrix.push_back(tempRow);
    }
    return randomMatrix;
}

uint32_t DuckShootingTest::findNumberOfEqualIndexCount(vector<vector<int>> &targets, uint32_t numberToBeSearched)
{
    uint32_t count = 0;

    for (int i = 0; i < targets.size(); ++i) {
        for (int j = 0; j < targets[0].size(); ++j) {
            if (targets[i][j] == numberToBeSearched) {
                ++count;
            }
        }
    }
    
    return count;
}

// a = [3, 4, 5;
//      4, 0, 4];
// findNumberOfEqualIndexes(a, 4);
//results = {1, 2, 5}
vector<uint32_t> DuckShootingTest::findNumberOfEqualIndexes(vector<vector<double>> &targets, double numberToBeSearched)
{
    // vector<vector<int>> indexMatrix; // NOTE: different method
    // vector<int> tempCol;

    // for (int i = 0; i < targets.size(); ++i) {
    //     for (int j = 0; j < targets[0].size(); ++j) {
    //         if (targets[i][j] == numberToBeSearched) {
    //             tempCol.push_back(i);
    //             tempCol.push_back(j);
    //             indexMatrix.push_back(tempCol);
    //             tempCol.clear();
    //         }
    //     }
    // }

    double epsilon = 0.001;
    vector<uint32_t> indexVector;

     for (int i = 0; i < targets[0].size(); ++i) {
         for (int j = 0; j < targets.size(); ++j) {
             if (abs(targets[j][i] - numberToBeSearched) < epsilon) {
                indexVector.push_back(i  * targets.size() + j);          /*TODO: Check this with huge array*/
             }
         }
     }
    
    // vector<int32_t> tempVector;  // NOTE: different method test
    // tempVector.push_back(10);
    // tempVector.push_back(20);
    // tempVector.push_back(30);

    // uint32_t counter = 0;
    // vector<uint32_t>::iterator myIterator;
    // for (auto it = tempVector.begin(); it != tempVector.end(); ++it, ++counter) {
    //     //it = std::find_if(it, tempVector.end(), [&](int32_t num1, int32_t num2) ->
    //         //int { return num1 == num2; } (numberToBeSearched, *it));
    // }

    
    return indexVector;
}

vector<uint32_t> DuckShootingTest::findNumberOfWithInRangeIndexes(vector<vector<double>> &targets, double greaterOrEqualThan, double lessThan)
{
    vector<uint32_t> indexVector;

    for (int i = 0; i < targets[0].size(); ++i) {
        for (int j = 0; j < targets.size(); ++j) {
            if ((targets[j][i] - greaterOrEqualThan >= 0.0) && (targets[j][i] - lessThan < 0.0)) {
                indexVector.push_back(i  * targets.size() + j);          /*TODO: Check this with huge array*/
            }
        }
    }
    return indexVector;
}