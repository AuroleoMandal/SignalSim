class WaveBuilder
{
	public:

        struct WaveVariables
        {
//{frequency, amplitude, bias, phi, high_state, low_state, duty cycle, peak}
        float frequency = 1.0f, amplitude = 1.0f, bias = 0.0f, phi = 0.0f;
        float high_state = 1.0f, low_state = -1.0f, duty_cycle = 0.5f, peak = 2*1.0f;


        float f = 1/frequency;
        float time_period = f;
        }var;
        

};

//Class for sine waves with overloaded constructors
class SineBuilder:public WaveBuilder
{
    public:
        float result(float, struct WaveVariables);

        SineBuilder(struct WaveVariables)
        {
        }


};

//Class for square waves with overloaded constructors
class SquareBuilder:public WaveBuilder
{
    public:

        float result(float, struct WaveVariables);

        SquareBuilder(struct WaveVariables)
        {
        }
};

//Class for triangle waves with overloaded constructors
class TriangleBuilder:public WaveBuilder
{
    public:

        float result(float, struct WaveVariables);

        TriangleBuilder(struct WaveVariables)
        {
        }

};