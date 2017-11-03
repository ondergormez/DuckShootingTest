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

vector<double> Utility::linspace(double startNumber, double endNumber, uint32_t nPoints){
    vector<double> tempLinspace;

    for( uint32_t i = 0 ; i < nPoints ; ++i ){
        tempLinspace.push_back( startNumber + ( ( i * ( endNumber - startNumber ) / (nPoints-1) ) ) );
    }

    return(tempLinspace);
}

vector<uint32_t> Utility::setdiff(std::vector<uint32_t>a, std::vector<uint32_t>b) {
	vector<uint32_t>result;

	int findFlag = 0;

	for (unsigned int i = 0; i < a.size(); ++i) {

		for (unsigned int j = 0; j < b.size(); ++j) {
			if (a[i] == b[j]) {
				++findFlag;
			}
		}

		if (findFlag == 0) {
			for (unsigned int k = 0; k < result.size(); ++k) {
				if (a[i] == result[k]) {
					++findFlag;
				}
			}

			if (findFlag == 0) {
				result.push_back(a[i]);
			}
			else {
				findFlag = 0;
			}

		}
		else {
			findFlag = 0;
		}
	}
	return(result);
}

unsigned int Utility::numel(std::vector<double> inputParam) {
	return(inputParam.size());
}

unsigned int Utility::numel(std::vector<std::vector<double>> inputParam) {
	return(inputParam.size()*inputParam[0].size());
}

