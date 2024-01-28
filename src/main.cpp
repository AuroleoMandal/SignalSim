#define pi 3.1415
#include<stdio.h>
#include<math.h>
#include <vector>
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

std::vector<float> simulate(WaveBuilder wave)
{
    float time = 0.0f;
	float t_max = 2.0f;
	float t_step = 0.01f;
	int step_counter = 1;

    std::vector<float> amps;

    while (time <= t_max)
	{
		float amplitude = wave.result(time);
        
        amps.push_back(amplitude);

		time += t_step;
		step_counter++;
	}

    return amps;
}

std::vector<float> simulate_add(WaveBuilder wave1, WaveBuilder wave2)
{
    float time = 0.0f;
	float t_max = 2.0f;
	float t_step = 0.01f;
	int step_counter = 1;

    std::vector<float> amps;

    while (time <= t_max)
	{
		float amplitude1 = wave1.result(time);
		float amplitude2 = wave2.result(time);

        // printf("(%f,%f),", time, amplitude1+amplitude2);
		//printf("Step %d, Amplitude 1 = %f, Amplitude 2 = %f \n", step_counter, amplitude1, amplitude2);
        
        amps.push_back(amplitude1+amplitude2);

		time += t_step;
		step_counter++;
	}

    return amps;
}

void update(std::vector<float>& amps)
{
    int height = 41;

    int** arr = new int*[height];
    for(int i = 0; i < height; i++)
        arr[i] = new int[amps.size()];


    //fill with 0
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < amps.size(); j++)
            arr[i][j] = 0;
    }

    for(int j = 0; j < amps.size(); j++)
    {
        int trans_amp = int((height-1)/2 * (amps[j] + 1));
        //printf("%d -> %d\n", trans_amp);
        arr[trans_amp][j] = 1;
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < amps.size(); j++)
        {
            if(arr[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    } 
    
    for(int i = 0; i < height; i++)
    {
        free(arr[i]);
    }

    free(arr);
    
}

int main()
{
	WaveBuilder wave1 = WaveBuilder(2);
	WaveBuilder wave2 = WaveBuilder(1);

    std::vector<float> amps = simulate(wave1);

    update(amps);

    return 0;
}