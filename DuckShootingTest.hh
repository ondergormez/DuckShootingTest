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

#ifndef __DUCK_SHOOTING_TEST__HH__
#define __DUCK_SHOOTING_TEST__HH__

#include <cstdint>
#include <iostream>
#include <vector>

/*
* Note:
* In general, avoid putting using directives in header files (*.h)
* because any file that includes that header will bring everything
* in the namespace into scope, which can cause name hiding and name
* collision problems that are very difficult to debug.
*/

/*
 * Core Function
 */
typedef struct ResultStruct {
    std::vector<double> &Lam;
    std::vector<double> &P;
    std::vector<std::vector<double>> &ResultMatrix;
    ResultStruct(std::vector<double> &lam,
                 std::vector<double> &p,
                 std::vector<std::vector<double>> &resultMatrix)
                 : Lam(lam), P(p), ResultMatrix(resultMatrix)
    {
    }
} ResultStruct_t;

/**
 * <p>
 *
 * This class implements the Duck Shooting Test algorithm.
 *
 * </p>
 *
 * @author Önder Görmez
 * @version 0.1
 * @since October 11, 2017
 *
 */
class DuckShootingTest
{
private:
    uint32_t NumberOfDucks;
    ResultStruct_t * Core(ResultStruct_t *resultObject);
    
public:
    DuckShootingTest(uint32_t numberOfDucks);
    ~DuckShootingTest();
    std::vector<std::vector<int>> randi(uint32_t numberRange, uint32_t numOfRows, uint32_t numOfColmns);
    uint32_t findNumberOfEqualIndexCount(std::vector<std::vector<int>> &targets, uint32_t numberToBeSearched);
    std::vector<std::vector<double>::iterator> findNumberOfEqualIndexes(std::vector<std::vector<double>> &targets, double numberToBeSearched);
    std::vector<uint32_t> findNumberOfWithInRangeIndexes(std::vector<std::vector<double>> &targets, double greaterOrEqualThan, double lessThan);
    std::vector<std::vector<double>> MatrixFillWith(uint32_t numOfRows, uint32_t numOfColmns, double filledWith);
};

#endif /* __DUCK_SHOOTING_TEST__HH__ */
