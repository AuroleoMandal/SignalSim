
#include<stdio.h>
#include<math.h>
#include"classes.h"

float t_max = 5.0f;
float t_step = 0.05f;


//returns amplitude as a function of time
template <typename waveObject>
void simulate(waveObject wave)
{
    float time = 0.0f;

    while (time <= t_max)
	{
		float amplitude = wave.result(time);
        printf("(%f,%f),", time, amplitude);
		time += t_step;
	}
    printf("\n\n\n");
}


//returns resultant of two amplitudes as a function of time
template <typename waveObject1, typename waveObject2>
void simulate_add(waveObject1 wave1, waveObject2 wave2)
{
    float time = 0.0f;

    while (time <= t_max)
	{
		float amplitude1 = wave1.result(time);
		float amplitude2 = wave2.result(time);

        printf("(%f,%f),", time, amplitude1+amplitude2);

		time += t_step;
	}
;
}


int main()
{
	SineBuilder wave1 = SineBuilder(1,0.5);
	SineBuilder wave2 = SineBuilder(1);
    SquareBuilder wave3 = SquareBuilder(2);
	TriangleBuilder wave4 = TriangleBuilder(0.5);

    simulate(wave1);
	simulate(wave2);
	simulate(wave3);
	simulate(wave4);
	simulate_add(wave2,wave3);

    return 0;
}