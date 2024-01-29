
#include<stdio.h>
#include<math.h>
#include"classes.h"

float t_max = 5.0f;
float t_step = 0.1f;

template <typename waveObject>

void simulate(waveObject wave)
{
    float time = 0.0f;
    int step_counter = 1;

    while (time <= t_max)
	{
		float amplitude = wave.result(time);
        printf("(%f,%f),", time, amplitude);
		time += t_step;
		step_counter++;
	}
    printf("\n\n\n");
}

void simulate_add(SineBuilder wave1, SineBuilder wave2)
{
    float time = 0.0f;
	float t_max = 2.0f;
	float t_step = 0.01f;
	int step_counter = 1;

    while (time <= t_max)
	{
		float amplitude1 = wave1.result(time);
		float amplitude2 = wave2.result(time);

        printf("(%f,%f),", time, amplitude1+amplitude2);
		printf("Step %d, Amplitude 1 = %f, Amplitude 2 = %f \n", step_counter, amplitude1, amplitude2);
        
		time += t_step;
		step_counter++;
	}
;
}


int main()
{
	SineBuilder wave1 = SineBuilder(1,0.5);
	SineBuilder wave2 = SineBuilder(1);
    SquareBuilder wave3 = SquareBuilder(1,0.3);
	TriangleBuilder wave4 = TriangleBuilder(0.5);

    simulate(wave1);
	simulate(wave2);
	simulate(wave3);
	simulate(wave4);

    return 0;
}