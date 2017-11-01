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
    vector<double> numberOfTests = vector<double>(100);
    uint32_t numberOfHunters = 10;

    vector<double> lam = Utility::linspace(3.0, 8.0, 31);
    vector<double> p = Utility::linspace(0.05, 0.95, 31);
    vector<vector<double>> resultMatrix = vector<vector<double>>(lam.size(), vector<double>(p.size()));

#ifndef NDEBUG
    cout << "Number Of Tests: " << numberOfTests.size() << endl;
    cout << "Number Of Hunters: " << numberOfHunters << endl;
    cout << "lam = " << lam.size() << endl;
    cout << "p = " << p.size() << endl;

    //Utility::DisplayVector(lam);
    //Utility::DisplayVector(p);
    //Utility::DisplayMatrix(resultMatrix);

    /*TODO: Delete this test code*/
    //vector<int> deneme;
    //vector<vector<int>> localMatrix;
    //deneme.push_back(3);
    //deneme.push_back(4);
    //deneme.push_back(5);
    //localMatrix.push_back(deneme);
    //deneme.clear();
    //deneme.push_back(5);
    //deneme.push_back(4);
    //deneme.push_back(4);
    //localMatrix.push_back(deneme);
    //deneme.clear();
    //vector<vector<int>> indexes = findNumberOfEqualIndexes(localMatrix, 4);
    //uint32_t rowNumber, colNumber;

    //rowNumber = indexes[2][0];
    //colNumber = indexes[2][1];
#endif



    for (int kk = 0; kk < lam.size(); ++kk) { /* NOTE: Rows' of resultMatrix*/ /*TODO: Change this with resultMatrix[0].Size()*/
        for (int ll = 0; ll < p.size(); ++ll) { /* NOTE: Columns' of resultMatrix*/ /*TODO: Change this with resultMatrix column size*/

            /* TODO: Delete This */
#ifndef NDEBUG
            if (kk == 0 && ll == 0) {
                cout << "Created Number Of Tests Vector: " << endl;
                cout << "Size: " << numberOfTests.size() << endl;
                cout << endl;
                Utility::DisplayVector(numberOfTests);
            }
#endif

            for (int mm = 0; mm < numberOfTests.size(); ++mm) {
                vector<vector<double>> temp;

                int32_t poisResult = PRNG_Uniform::PoissonRandom(lam[kk]);

                if (!poisResult) {
                    numberOfTests[mm] = 0.0;
                }
                else {

                    temp = MatrixFillWith(poisResult, numberOfHunters, -99.0);
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
                        Utility::DisplayMatrix(temp);
#endif                        
                    }
                }
                vector<double> indicesAll = vector<double>(temp.size());
                vector<uint32_t> indices_m99;
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
    Utility::DisplayMatrix(resultObject->ResultMatrix);
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
//      4, 4, 5];
// findNumberOfEqualIndexes(a, 4);
//results = {(0,1), (1, 1), (1,2)}
vector<vector<int>> DuckShootingTest::findNumberOfEqualIndexes(vector<vector<int32_t>> &targets, uint32_t numberToBeSearched)
{
    vector<vector<int>> indexMatrix;
    vector<int> tempCol;

    for (int i = 0; i < targets.size(); ++i) {
        for (int j = 0; j < targets[0].size(); ++j) {
            if (targets[i][j] == numberToBeSearched) {
                tempCol.push_back(i);
                tempCol.push_back(j);
                indexMatrix.push_back(tempCol);
                tempCol.clear();
            }
        }
    }
    
    // vector<int32_t> tempVector;
    // tempVector.push_back(10);
    // tempVector.push_back(20);
    // tempVector.push_back(30);

    // uint32_t counter = 0;
    // vector<uint32_t>::iterator myIterator;
    // for (auto it = tempVector.begin(); it != tempVector.end(); ++it, ++counter) {
    //     //it = std::find_if(it, tempVector.end(), [&](int32_t num1, int32_t num2) ->
    //         //int { return num1 == num2; } (numberToBeSearched, *it));
    // }
    
    return indexMatrix;
}





// classdef duck_shooting_test < ee_solns_demos.testers.GenericTester

//     properties(SetAccess=private,GetAccess=public)
//         lam
//         p
//         res
//     end % properties

//     methods(Access=public)
//         function obj = duck_shooting_test()
// %              import os_numerical_composite.testers.d_20170204_2252.*
        
//             title       = '';
//             description = ...
//                 { ...
//                     'Prob 1st 5e 7.51 - hunters shooting ducks' ...
//                 };
            
//             flag_in_realquick     = 0;
//             flag_expected_to_fail = 0;
//             flag_plottable        = 1;
            
//             obj@ee_solns_demos.testers.GenericTester ...
//                 ( ...
//                     title , ...
//                     description , ...
//                     flag_in_realquick , ...
//                     flag_expected_to_fail , ...
//                     flag_plottable ...
//                 );
//         end
        
//         function delete(obj)
//         end
//     end % methods
    
//     % axis and figure setters for pub quality plots.
//     % Indeed these have to be static, but I do not want to deal with further imports
//     % whenever I happen to relocate these tests themselves.
//     methods( Access=private )
    
//         function os_setAxes( obj , h_axes , FontSize , varargin )
//             LineWidth = 4;
//             if ( nargin >= 4 )
//                 LineWidth = varargin{1};
//             end
//             set( h_axes , 'units' , 'normalized' )
//             set( h_axes , 'Box' ,'on' , 'FontName' , 'Arial' , ...
//                 'FontSize' , FontSize , 'FontWeight' , 'bold' , 'LineWidth' , LineWidth )
//         end % function
        
//         function os_setFigure( obj , h_figure )
//             set( h_figure , 'units' , 'normalized' , 'Position' , [0 0 1 1] );
//             style = hgexport('factorystyle');
//             style.Bounds = 'tight';
//             hgexport( h_figure , '.tmpmatlab' , style , 'applystyle' , true );
//         end % function
    
//     end % methods


// function [ xInfo , yInfo , zInfo , zAvInfo ] = ...
//     computeFill3Triangles( obj , edgePtsL , edgePtsW , zValues )
    
//     import ee_solns_demos.utilities.data_containers.d_20170423_1211.*
        
//     pts = zeros( size(edgePtsW.data , 1) * size(edgePtsL.data , 1) , 3);
            
//     pts(:,1) = kron( ones( size(edgePtsW.data,1) , 1 ) , edgePtsL.data );
//     pts(:,2) = kron( edgePtsW.data , ones( size(edgePtsL.data,1) , 1 ) );
//     pts(:,3) = zValues.data;

//     triangles = zeros( 2 * (numel(edgePtsW.data)-1) * (numel(edgePtsL.data)-1) , 3 );
            
//     for kk = 1:numel(edgePtsW.data)-1
//         for ll = 1:numel(edgePtsL.data)-1
                
//             indTriTemp = ...
//                 (kk-1) * 2 * (numel(edgePtsL.data)-1) ...
//                 + ...
//                 2 * ll - 1;
                    
//             triangles(indTriTemp,:) = [ (kk-1)*numel(edgePtsL.data)+ll (kk-1)*numel(edgePtsL.data)+ll+1 (kk)*numel(edgePtsL.data)+ll+1 ];
        
//             indTriTemp = indTriTemp + 1;
//             triangles(indTriTemp,:) = [ (kk-1)*numel(edgePtsL.data)+ll (kk)*numel(edgePtsL.data)+ll (kk)*numel(edgePtsL.data)+ll+1 ];
        
//         end % for
//     end % for

//     % instantiate x y z container handlers
//     xInfo   = matrix_container();
//     yInfo   = matrix_container();
//     zInfo   = matrix_container();
//     zAvInfo = matrix_container();
            
//     xInfo.data = zeros( 3 , size(triangles,1) );
//     yInfo.data = xInfo.data;
//     zInfo.data = xInfo.data;

//     zAvInfo.data = zeros( 1 , size(triangles,1) );

//     for kk = 1:size(triangles,1)
//         ptsIndices = triangles(kk,:);
//         tmp = pts(ptsIndices,:);
//         xInfo.data(:,kk) = tmp(:,1);
//         yInfo.data(:,kk) = tmp(:,2);
//         zInfo.data(:,kk) = tmp(:,3);
    
//         zAvInfo.data(kk) = sum(zInfo.data(:,kk)) / 3;
//     end % for

// end % function

//     end % methods
    
//     methods(Access=public)
    
// function run(obj,varargin)
// obj.core()
// end % function

// function run_with_plots(obj,varargin)
// import ee_solns_demos.utilities.data_containers.d_20170423_1211.*

// FontSize = 16;

// flag_save = 0;

// flag_quality_pub = 0;
// if ( nargin >= 2 ) && ( varargin{1} > 0 )
//     flag_quality_pub = 1;
// end

// obj.core()

// % sort of a template for figures
// %{
// figure;

// os_setAxes( obj , gca , FontSize );
    
// grid on;
// title('')

// if flag_quality_pub;
//     os_setFigure( obj , gcf );
// end

// if flag_save; print -djpeg90 FileName; end;
// %}

// if 1
//     edgePtsL = matrix_container();
//     edgePtsW = matrix_container();
//     pmfData  = matrix_container();
    
//     edgePtsL.data = obj.lam';
//     edgePtsW.data = obj.p';
    
//     tmp = obj.res;
//     pmfData.data  = tmp(:);

//     [ xInfo , yInfo , zInfo , zAvInfo ] = ...
//         computeFill3Triangles( obj , edgePtsL , edgePtsW , pmfData );

//     figure;

//     ff = fill3( xInfo.data , yInfo.data , zInfo.data , zAvInfo.data );
//     set( ff , 'edgecolor' , 'none' )

//     hold on;

//     zStep = 2;
//     zFactor = 2.5;
//     zlimmax = ceil( max( max( obj.res ) ) / zStep ) * zStep;
//     zlimmin = -ceil( zlimmax * zFactor / zStep ) * zStep;
//     locBelowPlane = zlimmin;
//     ffplane = fill3( xInfo.data , yInfo.data , locBelowPlane + zeros( size(xInfo.data) ) , zAvInfo.data );
//     set( ffplane , 'edgecolor' , 'none' )

//     hold off;

//     xlim([obj.lam(1) obj.lam(end)])
//     ylim([obj.p(1) obj.p(end)])
//     zlim( [ locBelowPlane zlimmax ] )
//     view( -37.5 , 30 )
//     os_setAxes( obj , gca , FontSize );
//     grid on;
    
//     xlabel( 'lambda' )
//     ylabel( 'p' )
//     title( sprintf( 'Expected Number of Ducks Shot Dead' ) )
            
//     if flag_quality_pub;
//         os_setFigure( obj , gcf );
//     end
// end % if    

// end % function

//     end % methods
    
// end % classdef