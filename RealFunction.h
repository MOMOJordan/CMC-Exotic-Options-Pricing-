//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#ifndef DAILYC_REALFUNCTION_H
#define DAILYC_REALFUNCTION_H

#pragma once


class RealFunction {
public:
    virtual ~RealFunction() {};

    virtual double evaluate( double x ) = 0;
};


#endif //DAILYC_REALFUNCTION_H
