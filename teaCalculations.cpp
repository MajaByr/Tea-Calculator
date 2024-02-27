#include "teaCalculations.h"

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
