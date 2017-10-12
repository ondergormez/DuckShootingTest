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

#define PRINT_INFOS

using namespace std;

/*
 * Core Function
 */
typedef struct ResultStruct {
    std::vector<double> &Lam;
    std::vector<double> &P;
    std::vector<std::vector<double>> &ResultMatrix;
    ResultStruct(std::vector<double> &lam, std::vector<double> &p, std::vector<std::vector<double>> &resultMatrix) : Lam(lam), P(p), ResultMatrix(resultMatrix)
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
    ResultStruct_t *Core();

public:
    DuckShootingTest();
    ~DuckShootingTest();
    bool PoissonRandom(double);
    std::vector<std::vector<double>> &randi(uint32_t numberRange, uint32_t numOfRows, uint32_t numOfColmns);
};

#endif /* __DUCK_SHOOTING_TEST__HH__ */
