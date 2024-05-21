//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#include "BlackScholesModel.h"
#include "mathlib.h"

using namespace std;

BlackScholesModel::BlackScholesModel():drift(0.0),stockPrice(0.0),
                    volatility(0.0),riskFreeRate(0.0),date(0.0){};

DoubleVector BlackScholesModel::generateRiskNeutralPricePath(double toDate, int nSteps) const {
    return generatePricePath(toDate,nSteps,riskFreeRate);
}

DoubleVector BlackScholesModel::generatePricePath(double toDate, int nSteps) const {
    return generatePricePath(toDate,nSteps,drift);
}

DoubleVector BlackScholesModel::generatePricePath(double toDate, int nSteps,double drift) const {
    DoubleVector path(nSteps,0.0);
    DoubleVector epsilon= randn(nSteps);
    double dt=(toDate-date)/nSteps;
    double a=(drift-volatility*volatility*0.5)*dt;
    double b=volatility* sqrt(dt);
    double currentLogS=log(stockPrice);
    for(int i=0; i<nSteps;i++){
        double dLogS=a+b*epsilon[i];
        double logS=currentLogS+dLogS;
        path[i]=exp(logS);
        currentLogS=logS;
    }
    return path;
}
