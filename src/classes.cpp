#define pi 3.1415
#include<math.h>
#include"classes.h"

float SineBuilder::result(float t)
{
	float a = sin((t * frequency + phi )* pi);
	return a;
}

float SquareBuilder::result(float t)
{
    float high_period = time_period*duty_cycle;
    if((fmodf(t, time_period)<high_period))
    {
        return high_state;
    }
	else
    return low_state;
}

float TriangleBuilder::result(float t)
{
    float a;
    float high_period = time_period*duty_cycle;

    if((fmodf(t, time_period)<high_period))
    {
        a = (fmodf(t, time_period)*abs(((high_state-low_state)/high_period)))+low_state;
        return a;
    }
	else
    {
        a = (fmodf(t, time_period)*((high_state-low_state)/(time_period-high_period)));
        return a;
    }
}

