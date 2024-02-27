#ifndef TEACALCULATIONS_H
#define TEACALCULATIONS_H

enum TeaType { Black, Green, White, Oolong };

int calculateTemperature( TeaType type );
int calculateTime( TeaType type, int strength, int brewNo ); //returns time in seconds

struct minMaxTime {
    double min;
    double max;
};



#endif // TEACALCULATIONS_H
