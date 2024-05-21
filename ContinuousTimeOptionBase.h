//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#ifndef DAILYC_CONTINUOUSTIMEOPTIONBASE_H
#define DAILYC_CONTINUOUSTIMEOPTIONBASE_H

#include "ContinuousTimeOption.h"
#include "BlackScholesModel.h"

class ContinuousTimeOptionBase:public ContinuousTimeOption {
    double maturity;
    double strike;
public:
    virtual ~ContinuousTimeOptionBase(){}

    double getMaturity() const {
        return maturity;
    }

    void setMaturity(double maturity){
        this->maturity=maturity;
    }

    double getStrike() const{
        return strike;
    }

    void setStrike(double strike) {
        this->strike=strike;
    }

    virtual double price(const BlackScholesModel& model) const;
};


#endif //DAILYC_CONTINUOUSTIMEOPTIONBASE_H
