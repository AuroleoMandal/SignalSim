#define pi 3.1415
#include<stdio.h>
#include<math.h>
class WaveBuilder
{
	public:
		int f;

		WaveBuilder(int input_f)
		{
			f = input_f;
		}

		float result(float t)
		{
			float a = sin(t * f * pi);
			return a;
		}

};

void simulate(WaveBuilder wave)
{
    float time = 0.0f;
	float t_max = 2.0f;
	float t_step = 0.01f;
	int step_counter = 1;

    while (time <= t_max)
	{
		float amplitude = wave.result(time);

        printf("(%f,%f),", time, amplitude);
		//printf("Step %d, Amplitude 1 = %f, Amplitude 2 = %f \n", step_counter, amplitude1, amplitude2);

		time += t_step;
		step_counter++;
	}
}

void simulate_add(WaveBuilder wave1, WaveBuilder wave2)
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
		//printf("Step %d, Amplitude 1 = %f, Amplitude 2 = %f \n", step_counter, amplitude1, amplitude2);

		time += t_step;
		step_counter++;
	}
}

int main()
{
	WaveBuilder wave1 = WaveBuilder(2);
	WaveBuilder wave2 = WaveBuilder(1);

	simulate(wave1);
    printf("\n\n");
    simulate(wave2);
    printf("\n\n");
    simulate_add(wave1,wave2);

return 0;
}