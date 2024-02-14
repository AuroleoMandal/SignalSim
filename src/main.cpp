#include <stdio.h>
#include <math.h>
#include "classes.h"
#include <vector>

float t_max = 5.0f;
float t_step = 0.01f;

//returns amplitude as a function of time
void simulate(const WaveBuilder& wave)
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

void simulate_add(std::vector<WaveBuilder*>& waveArray)
{
    float time = 0.0f;

    while (time <= t_max)
	{
        float sum = 0.0f;
        for(int i = 0; i < waveArray.size(); i++)
        {
            float amplitude = waveArray[i]->result(time);
            sum += amplitude;
        }

        printf("(%f,%f),", time, sum);
        time += t_step;
	}
    printf("\n\n\n");
}



void run()
{
    //{frequency, amplitude, bias, phi, high_state, low_state, duty_cycle, peak}

    // SineBuilder sine1 = SineBuilder({frequency: 0.59});
    // SineBuilder sine2 = SineBuilder({frequency: 1.37});
    // SineBuilder sine3 = SineBuilder({frequency: 2, phi: 0.5});
    // SineBuilder sine4 = SineBuilder({frequency: 3.2});

    // SquareBuilder square2 = SquareBuilder({high_state: 3, low_state: 1});

	// TriangleBuilder triangle3 = TriangleBuilder({amplitude: 1.0f});

	// simulate(sine1);
	// simulate(square2);
	// simulate(triangle3);

    // WaveBuilder waves[5] = {sine1, sine2, sine3, sine4, square2};
    std::vector<WaveBuilder*> waves;
    waves.push_back(new SineBuilder({frequency: 0.59}));
    waves.push_back(new SineBuilder({frequency: 1.37}));
    waves.push_back(new SineBuilder({frequency: 2, phi: 0.5}));
    waves.push_back(new SineBuilder({frequency: 3.2}));
    waves.push_back(new SquareBuilder({high_state: 5, low_state: -5}));

	simulate_add(waves);
}

int main()
{
    run();
    return 0;
}