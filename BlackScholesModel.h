//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#ifndef DAILYC_BLACKSCHOLESMODEL_H
#define DAILYC_BLACKSCHOLESMODEL_H
#pragma once
#include "stdafx.h"

class BlackScholesModel {
    std::vector<double> generatePricePath(double toDate, int nSteps, double drift) const;
public:
    BlackScholesModel();
    double drift;
    double stockPrice;
    double volatility;
    double riskFreeRate;
    double date;

    std::vector<double> generatePricePath(double toDate,int nSteps) const;
    std::vector<double> generateRiskNeutralPricePath(double toDate,int nSteps) const;
};


#endif //DAILYC_BLACKSCHOLESMODEL_H
