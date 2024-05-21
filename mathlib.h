//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#ifndef DAILYC_MATHLIB_H
#define DAILYC_MATHLIB_H

#include "stdafx.h"
#include "RealFunction.h"



DoubleVector linspace (double from, double to, int numPoints);
double sum(const DoubleVector& v);

double mean(const DoubleVector& v);

double sigma(const DoubleVector& v);

double min(const DoubleVector& v);

double max(const DoubleVector& v);

double prctile(const DoubleVector& v,double percentage);

DoubleVector sort(const DoubleVector& v);

DoubleVector randuniform(int n);

DoubleVector randn(int n);

void rng( const std::string  setting);

double normcdf(double x);

double norminv(double x);

void plot(const std::string& fileName, const DoubleVector& x, const DoubleVector& y);

void hist(const std::string& fileName, const DoubleVector& values, int numBins= 10);

double integral(RealFunction& f, double a, double b, int nSteps);



#endif //DAILYC_MATHLIB_H
