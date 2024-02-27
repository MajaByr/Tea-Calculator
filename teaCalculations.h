#ifndef TEACALCULATIONS_H
#define TEACALCULATIONS_H

enum TeaType { Black, Green, White, Oolong };

struct minMaxTime {
    double min;
    double max;
};

struct minMaxCoffeine {
    double min;
    double max;
};

int calculateTemperature( TeaType type );
int calculateTime( TeaType type, int strength, int brewNo ); //returns time in seconds
double calculateCoffeine( TeaType type, int size, int brewNo );
double calculateWaitingTime( int size, double outTemp, double liqTemp, double expTemp );
double* calculateProportions( double cold, double hot, double exp);

minMaxCoffeine coffeineInType( TeaType type ); //of 240ml


#endif // TEACALCULATIONS_H
