//
// Created by Jordan MOMO JUPOU on 18/05/2024.
//

#include "MonteCarloPricer.h"

using namespace std;

MonteCarloPricer::MonteCarloPricer() :nScenarios(10000),nSteps(10){
}

double MonteCarloPricer::price(const ContinuousTimeOption &option, const BlackScholesModel &model) {
    int nSteps=this->nSteps;
    if (!option.isPathDependent()){
        nSteps=1;
    };
    double total=0.0;
    for(int i=0; i<nScenarios; i++){
        DoubleVector path = model.generateRiskNeutralPricePath(option.getMaturity(),nSteps);
        double payoff=option.payoff(path);
        total+=payoff;
    }
    double mean=total/nScenarios;
    double r=model.riskFreeRate;
    double  T=option.getMaturity()-model.date;
    return exp(-r*T)*mean;
}