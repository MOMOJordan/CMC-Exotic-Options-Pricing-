//
// Created by Jordan MOMO JUPOU on 15/05/2024.
//
#include  "KnockoutOption.h"

#ifndef DAILYC_UPANDOUTOPTION_H
#define DAILYC_UPANDOUTOPTION_H


class UpAndOutOption:public KnockoutOption {
public:
    double payoff(const DoubleVector & prices) const;

    double price(const BlackScholesModel& model) const {
        if (model.stockPrice >= getBarrier()) return  0;
        return  KnockoutOption::price(model);
    }
};


#endif //DAILYC_UPANDOUTOPTION_H
