//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#include "ContinuousTimeOptionBase.h"
#include "ContinuousTimeOptionBase.h"
#include "MonteCarloPricer.h"
#include "UpAndOutOption.h"
#include "mathlib.h"

double ContinuousTimeOptionBase::price(const BlackScholesModel& model) const{
    MonteCarloPricer pricer;
    return pricer.price(*this, model);
}