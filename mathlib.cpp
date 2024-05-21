//
// Created by Jordan MOMO JUPOU on 16/05/2024.
//

#include "mathlib.h"
#include <cassert>

DoubleVector linspace(double from, double to, int numPoints){
    assert(numPoints>=2);
    DoubleVector ret(numPoints,0.0);
    double step=(to-from)/(numPoints-1);
    double current=from;
    for (int i=0;i<numPoints;i++){
        ret[i]=current;
        current+=step;
    }
    return ret;
}

double sum(const DoubleVector& v){
    double total=0.0;
    int n=v.size();
    for(int i=0;i<n;i++){
        total+=v[i];
    }
    return total;
}

double mean(const DoubleVector& v){
    int n=v.size();
    assert(n>0);
    return sum(v)/n;
}

double standardDeviation( const DoubleVector v, bool population ) {
    int n = v.size();
    double total = 0.0;
    double totalSq = 0.0;
    for (int i=0; i<n; i++) {
        total+=v[i];
        totalSq+=v[i]*v[i];
    }
    if (population)  {
        assert( n > 0 );
        return sqrt( (totalSq - total*total/n)/n );
    } else {
        assert( n > 1 );
        return sqrt( (totalSq - total*total/n)/(n-1) );
    }
}

double min( const DoubleVector& v){
    double minimun=v[0];
    int n=v.size();
    assert(n>0);
    for (int i=1;i<n;i++){
        if (v[i]<minimun){
            minimun=v[i];
        }

    }
    return minimun;

}

double maximun( const DoubleVector& v){
    double maximun=v[0];
    int n=v.size();
    assert(n>0);
    for (int i=1;i<n;i++){
        if (v[i]>maximun){
            maximun=v[i];
        }

    }
    return maximun;

    return maximun;

}

DoubleVector randuniform( int n){
    DoubleVector ret(n,0.0);
    for(int i=0;i<n;i++){
        int randInt=rand();
        ret[i]=(randInt+0.5)/(RAND_MAX+1.0);
    }
    return ret;
}

DoubleVector randn(int n){
    DoubleVector v= randuniform(n);
    for (int i=0;i<n;i++){
        v[i]= norminv(v[i]);
    }
    return v;
}

DoubleVector sort( const DoubleVector& v ) {
    DoubleVector copy(v);
    std::sort( copy.begin(), copy.end() );
    return copy;
}

double prctile( const DoubleVector& v, double percentage ) {
    // See the text for a precise specification
    //
    assert( percentage >=0.0 );
    assert( percentage <=100.0 );
    int n = v.size();
    DoubleVector sorted = sort( v );

    int indexBelow = (int)(n* percentage/100.0 - 0.5);
    int indexAbove = indexBelow + 1;
    if (indexAbove > n-1 ) {
        return sorted[n-1];
    } if (indexBelow<0) {
        return sorted[0];
    }
    double valueBelow = sorted[ indexBelow ];
    double valueAbove = sorted[ indexAbove ];
    double percentageBelow = 100.0*(indexBelow+0.5)/n;
    double percentageAbove = 100.0*(indexAbove+0.5)/n;
    if (percentage<=percentageBelow) {
        return valueBelow;
    }
    if (percentage>=percentageAbove) {
        return valueAbove;
    }
    double correction = (percentage - percentageBelow)*(valueAbove-valueBelow)/(percentageAbove-percentageBelow);
    return valueBelow + correction;
}
const double PI = 3.14159265358979323846;
const double ROOT_2_PI = sqrt( 2.0 * PI );



/*  Constants required for Moro's algorithm */
static const double a0 = 2.50662823884;
static const double a1 = -18.61500062529;
static const double a2 = 41.39119773534;
static const double a3 = -25.44106049637;
static const double b1 = -8.47351093090;
static const double b2 = 23.08336743743;
static const double b3 = -21.06224101826;
static const double b4 = 3.13082909833;
static const double c0 = 0.3374754822726147;
static const double c1 = 0.9761690190917186;
static const double c2 = 0.1607979714918209;
static const double c3 = 0.0276438810333863;
static const double c4 = 0.0038405729373609;
static const double c5 = 0.0003951896511919;
static const double c6 = 0.0000321767881768;
static const double c7 = 0.0000002888167364;
static const double c8 = 0.0000003960315187;

static inline double hornerFunction( double x, double a0, double a1) {
    return a0 + x*a1;
}

static inline double hornerFunction( double x, double a0, double a1, double a2) {
    return a0 + x*hornerFunction( x, a1, a2);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3) {
    return a0 + x*hornerFunction( x, a1, a2, a3);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                                     double a5) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                                     double a5, double a6) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                                     double a5, double a6, double a7) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7);
}

static inline double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                                     double a5, double a6, double a7, double a8) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7, a8);
}

double normcdf( double x ) {
    if (x<0) {
        return 1-normcdf(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = hornerFunction(k,
                                 0.0, 0.319381530, -0.356563782,
                                 1.781477937,-1.821255978,1.330274429);
    double approx = 1.0 - 1.0/ROOT_2_PI * exp(-0.5*x*x) * poly;
    return approx;
}

double norminv( double x ) {
    // We use Moro's algorithm
    double y = x - 0.5;
    if (y<0.42 && y>-0.42) {
        double r = y*y;
        return y*hornerFunction(r,a0,a1,a2,a3)/hornerFunction(r,1.0,b1,b2,b3,b4);
    } else {
        double r;
        if (y<0.0) {
            r = x;
        } else {
            r = 1.0 - x;
        }
        double s = log( -log( r ));
        double t = hornerFunction(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
        if (x>0.5) {
            return t;
        } else {
            return -t;
        }
    }
}

double integral( RealFunction& f, double a, double b, int nPoints){
    double h=(b-a)/nPoints;
    double x=a+0.5*h;
    double total=0.0;
    for (int i=0;i<nPoints;i++){
        double y=f.evaluate(x);
        total+=y;
        x+=h;
    }
    return h*total;
}