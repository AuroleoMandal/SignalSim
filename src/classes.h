class WaveBuilder
{
	public:
		float f;
};

//Class for sine waves with overloaded constructors
class SineBuilder:public WaveBuilder
{
    public:
        float frequency;
        float phi = 0.0f;
        float result(float t);

        SineBuilder(float f, float p)
        {
            frequency = f;
            phi = p;
        }

        SineBuilder(float f)
        {
            frequency = f;
        }
};

//Class for square waves with overloaded constructors
class SquareBuilder:public WaveBuilder
{
    public:
        float d_ratio = 0.5;
        float high_state = 1;
        float low_state = -1;
        float phi = 0;
        float time_period;
        float duty_cycle = d_ratio;

        float result(float t);

        SquareBuilder(float f)
        {
            float t = 1/f;
            time_period = t;
        } 

        SquareBuilder(float f, float d)
        {
            float t = 1/f;
            time_period = t;
            duty_cycle = d;
        } 

        SquareBuilder(float f, float d, float h, float l)
        {
            float t = 1/f;
            time_period = t;
            high_state = h;
            low_state = l;
            time_period = t;
            duty_cycle = d;
        }
};

//Class for triangle waves with overloaded constructors
class TriangleBuilder:public WaveBuilder
{
    public:
        float time_period;
        float d_ratio = 0.5;
        float high_state = -3;
        float low_state = -5;
        float phi = 0;
        float duty_cycle = d_ratio;

        float result(float t);

        TriangleBuilder(float f)
        {
            float t = 1/f;
            time_period = t;
        }

};