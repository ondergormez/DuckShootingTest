clear all;
clc;
format long e
rng('shuffle','twister')

noTests = 10;

noHunters = 4;

lam = linspace( 3 , 8 , 31 );
p   = linspace( 0.05 , 0.95 , 31 );
res = zeros( numel(lam) , numel(p) );

for kk = 1:size(res,1) % satir sayisini ifade ediyor
    for ll = 1:size(res,2) % sutun sayisini ifade ediyor
        tests = zeros( 1 , noTests );
        for mm = 1:noTests
        
            tmp = -99 * ones( poissrnd( lam(kk) ) , noHunters );
            
            if isempty(tmp)
                tests(mm) = 0;
            else
                targets = randi( size(tmp,1) , noHunters , 1 );
                for nn = 1:size(tmp,1) %satırların sayısını ifade ediyor
                    number = numel( find( targets == nn ) );
                    if number > 0
                        tmp(nn,1:number) = rand(1,number);
                    end
                    clear number;
                end % for nn
                clear targets;
            end
            indices_all     = 1:numel(tmp);
            indices_m99     = find( tmp == -99 );
            indices_not_m99 = setdiff( indices_all , indices_m99 );
            indices_one     = find( (tmp >= 0.0) & (tmp < p(ll)) );
            indices_zero    = setdiff( indices_not_m99 , indices_one );
            
            tmp( indices_one )  = 1;
            tmp( indices_zero ) = 0;
            tmp( indices_m99 )  = 0;
            
            tests(mm) = numel( find( sum(tmp,2) > 0 ) );
            
            %clear tmp;
        end % for mm
        res(kk,ll) = sum(tests) / numel(tests);
        clear tests;
    end % for ll
end % for kk