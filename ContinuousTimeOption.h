//
// Created by Jordan MOMO JUPOU on 18/05/2024.
//

#ifndef DAILYC_CONTINUOUSTIMEOPTION_H
#define DAILYC_CONTINUOUSTIMEOPTION_H

#pragma once

#include "stdafx.h"

class ContinuousTimeOption {
public:
    virtual ~ContinuousTimeOption(){};
    virtual double getMaturity() const =0;
    virtual double payoff(const DoubleVector & stockPrices
            ) const=0;
    virtual bool isPathDependent() const=0;
};


#endif //DAILYC_CONTINUOUSTIMEOPTION_H
