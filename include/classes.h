struct WaveVariables
{
    float frequency = 1.0f, amplitude = 1.0f, bias = 0.0f, phi = 0.0f;
    float high_state = 1.0f, low_state = -1.0f, duty_cycle = 0.5f, peak = 2*1.0f;

    float time_period = 1/frequency;
};

class WaveBuilder
{
public:
    WaveVariables var;

    WaveBuilder(){};

    WaveBuilder(WaveVariables var)
    {
        this->var = var;
    }

    virtual float result(float) const;
};

//Class for sine waves with overloaded constructors
class SineBuilder : public WaveBuilder
{
public:
    SineBuilder(WaveVariables var): WaveBuilder(var){};
    SineBuilder(): WaveBuilder(){};

    float result(float) const override;
};

//Class for square waves with overloaded constructors
class SquareBuilder : public WaveBuilder
{
public:
    SquareBuilder(WaveVariables var): WaveBuilder(var){};
    SquareBuilder(): WaveBuilder(){};

    float result(float) const override;
};

//Class for triangle waves with overloaded constructors
class TriangleBuilder : public WaveBuilder
{
public:
    TriangleBuilder(WaveVariables var): WaveBuilder(var){};
    TriangleBuilder(): WaveBuilder(){};
    
    float result(float) const override;
};