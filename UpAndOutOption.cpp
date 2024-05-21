//
// Created by Jordan MOMO JUPOU on 15/05/2024.
//

#include "UpAndOutOption.h"
#include "KnockoutOption.h"

using  namespace std;

double UpAndOutOption::payoff(const DoubleVector &prices) const {
    int n=prices.size();
    for (int i=0;i<n;i++){
        if (prices[i]>getBarrier()){
            return 0.0;
        };
    }
    double stockAtMaturity=prices.back();
    if (stockAtMaturity>getStrike()){
        return stockAtMaturity-getStrike();
    } else{
        return 0.0;
    }
}
