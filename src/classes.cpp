#define pi 3.1415
#include "stdio.h"
#include <math.h>
#include "classes.h"

float WaveBuilder::result(float t) const
{
    return 0.0f;
}

//returns amplitude of sin wave at a particular time
float SineBuilder::result(float t) const
{
	float a = sin(((2 * t * var.frequency) + var.phi )* pi);
	return a*var.amplitude + var.bias;
}

//returns amplitude of square wave at a particular time
float SquareBuilder::result(float t) const
{
    float high_period = var.time_period*var.duty_cycle;

    if(fmodf(t, var.time_period)<high_period)
        return var.high_state;

	else
        return var.low_state;
}

float TriangleBuilder::result(float t) const
{
    float a;
    float high_period = var.time_period * var.duty_cycle;

    if((fmodf(t, var.duty_cycle)<high_period))
    {
        a = fmodf(t, var.time_period)*(var.peak/high_period)-(var.peak/2);
        return a*var.amplitude + var.bias;
    }
	else
    {
        a = fmodf(t, var.time_period)*(-var.peak)/(var.time_period-high_period)+2*var.peak-(var.peak/2);
        return a*var.amplitude + var.bias;
    }
}

