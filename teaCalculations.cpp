#include "teaCalculations.h"
#include <cstdlib>
#include <cmath>

int calculateTime( TeaType type, int strength, int brewNo )
{
    minMaxTime basicTime;
    basicTime.max=0;
    basicTime.min=0;

    switch ( type )
    {
        case Black: basicTime.min=3; basicTime.max=5; break;
        case Green: basicTime.min=2; basicTime.max=4; break;
        case White: basicTime.min=2; basicTime.max=3; break;
        case Oolong: basicTime.min=2; basicTime.max=5; break;
    }

    double brewTime = basicTime.min + (basicTime.max-basicTime.min)*(brewNo/3)+strength/99*basicTime.min;

    return (int)(brewTime*60+0.5);
}

double calculateCoffeine( TeaType type, int size, int brewNo )
{
    minMaxCoffeine mmCof = coffeineInType(type);
    return ( mmCof.max - (brewNo-1)/2 * (mmCof.max-mmCof.min) ) * size / 240;
}

minMaxCoffeine coffeineInType( TeaType type ) //of 240ml
{
    minMaxCoffeine mmCof;
    switch (type)
    {
        case Black: mmCof.min=40; mmCof.max=70; break;
        case Green: mmCof.min=20; mmCof.max=45; break;
        case White: mmCof.min=15; mmCof.max=30; break;
        case Oolong: mmCof.min=30; mmCof.max=50; break;
    }
    return mmCof;
}


int calculateTemperature( TeaType type )
{
    switch( type )
    {
    case Black: return 90;
    case Green: return 80;
    case White: return 75;
    case Oolong: return 95;
    default: return 80;
    }
}

double calculateWaitingTime( int size, double outTemp, double liqTemp, double expTemp )
{
    return -26*log((expTemp-outTemp)/(liqTemp-outTemp))*size/150;
}

double* calculateProportions( double cold, double hot, double exp)
{
    double* tab = (double*)calloc(2, sizeof(double));

    double a = ( hot - exp )/( hot - cold );
    tab[0] = a; //cold
    tab[1] = (1-a);
    return tab;
}
