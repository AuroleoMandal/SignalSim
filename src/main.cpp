
#include<stdio.h>
#include<math.h>
#include"classes.h"

float t_max = 5.0f;
float t_step = 0.05f;

//returns amplitude as a function of time
template <typename waveObject, typename waveVariables>
void simulate(waveObject wave, waveVariables v )
{
    float time = 0.0f;

    while (time <= t_max)
	{
		float amplitude = wave.result(time, v);
        printf("(%f,%f),", time, amplitude);
		time += t_step;
	}
    printf("\n\n\n");
}


// //returns resultant of two amplitudes as a function of time
// template <typename waveObject1, typename waveObject2>
// void simulate_add(waveObject1 wave1, waveObject2 wave2)
// {
//     float time = 0.0f;

//     while (time <= t_max)
// 	{
// 		float amplitude1 = wave1.result(time);
// 		float amplitude2 = wave2.result(time);

//         printf("(%f,%f),", time, amplitude1+amplitude2);

// 		time += t_step;
// 	}
// ;
// }


int main()
{
//{frequency, amplitude, bias, phi, high_state, low_state, duty_cycle, peak}

	WaveBuilder::WaveVariables sine_params;
	SineBuilder sine1 = SineBuilder(sine_params);

	WaveBuilder::WaveVariables square_params{1, 2};
    SquareBuilder square2 = SquareBuilder(square_params);

	WaveBuilder::WaveVariables triangle_params;
	TriangleBuilder triangle3 = TriangleBuilder(triangle_params);


	simulate(sine1, sine_params);
	simulate(square2, square_params);
	simulate(triangle3, triangle_params);
	//simulate_add(wave2,wave3);

    return 0;
}