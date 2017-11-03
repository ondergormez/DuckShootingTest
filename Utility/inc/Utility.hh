/**
 * Copyright (C) 2015 Önder Görmez

 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see 
 * http://www.gnu.org/licenses/.

 * For any questions, please contact me @ ondergormez@gmail.com.
 */

#ifndef __UTILITY__HH__
#define __UTILITY__HH__

#include <iostream>
#include <vector>

/*
* Note:
* In general, avoid putting using directives in header files (*.h)
* because any file that includes that header will bring everything
* in the namespace into scope, which can cause name hiding and name
* collision problems that are very difficult to debug.
*/

/**
 * <p>
 *
 * This class implements the utility methods.
 *
 * </p>
 *
 * @author Önder Görmez
 * @version 0.1
 * @since October 11, 2017
 *
 */
class Utility
{
private:


public:
    Utility();
    ~Utility();

    /*
    * Display Vector
    */
    template<typename Type>
    static void DisplayVector(std::vector<Type> &vectorToBeDisplayed)
    {
        cout << "Size: " << vectorToBeDisplayed.size() << endl;
        for (uint32_t i = 0; i < vectorToBeDisplayed.size(); ++i)
            cout << vectorToBeDisplayed[i] << " ";
        cout << endl;
        cout << endl;
    };

    /*
    * Display Matrix
    */
    template<typename Type>
    static void DisplayMatrix(std::vector<std::vector<Type>> &matrixToBeDisplayed)
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
    };

	static std::vector<double> linspace(double startNumber, double endNumber, uint32_t nPoints);
	static std::vector<uint32_t> setdiff(std::vector<uint32_t>a, std::vector<uint32_t>b);
	static unsigned int numel(std::vector<double> inputParam);
	static unsigned int numel(std::vector<std::vector<double>> inputParam);
};

#endif /* __UTILITY__HH__ */
