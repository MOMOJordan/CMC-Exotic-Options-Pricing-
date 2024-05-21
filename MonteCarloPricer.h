//
// Created by Jordan MOMO JUPOU on 18/05/2024.
//

#ifndef DAILYC_MONTECARLOPRICER_H
#define DAILYC_MONTECARLOPRICER_H

#pragma once

#include "stdafx.h"
#include "ContinuousTimeOption.h"
#include "BlackScholesModel.h"

class MonteCarloPricer {
public:
    int nScenarios;

    int nSteps;

    MonteCarloPricer();

    double price(const ContinuousTimeOption& option,
                 const BlackScholesModel& model);



};


#endif //DAILYC_MONTECARLOPRICER_H
