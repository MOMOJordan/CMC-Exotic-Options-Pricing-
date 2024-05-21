//
// Created by Jordan MOMO JUPOU on 15/05/2024.
//

#ifndef DAILYC_KNOCKOUTOPTION_H
#define DAILYC_KNOCKOUTOPTION_H

#pragma once

#include "ContinuousTimeOptionBase.h"

class KnockoutOption: public ContinuousTimeOptionBase {
    double barrier;
public:
    virtual ~KnockoutOption(){}

    double getBarrier() const{
        return barrier;
    }

    void setBarrier(double barrier){
    this->barrier=barrier;
    }

    bool isPathDependent() const{
        return true;
    }
};


#endif //DAILYC_KNOCKOUTOPTION_H
