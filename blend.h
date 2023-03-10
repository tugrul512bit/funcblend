#include<iostream>
#include<cmath>

// function 1 becomes function 2 around blendPoint, computes f(x)
template<typename Func1, typename Func2>
double blend1(Func1 f1, Func2 f2,double blendPoint, double x)
{
    double mult1 =0.5 + 0.5 * std::tanh(blendPoint - x);
    double mult2 =1.0-mult1;
    double result = f1(x) * mult1 + f2(x) * mult2;
    return result;
}

// function-blending takes narrower or wider distance to reach f1 or f2
template<typename Func1, typename Func2>
double blend2(Func1 f1, Func2 f2,double blendPoint, double transitionSmoothness, double x)
{
    double mult1 =0.5 + 0.5 * std::tanh((blendPoint - x)/transitionSmoothness);
    double mult2 =1.0-mult1;
    double result = f1(x) * mult1 + f2(x) * mult2;
    return result;
}

// blending is applied directly on return values of functions
double blend3(double f1, double f2,double blendPoint, double transitionSmoothness, double x)
{
    double mult1 =0.5 + 0.5 * std::tanh((blendPoint - x)/transitionSmoothness);
    double mult2 =1.0-mult1;
    double result = f1 * mult1 + f2 * mult2;
    return result;
}

// blending with distance for 99.99% approach on real value, (blendPoint-distance,blendPoint+distance)=converged 99.99%
/*
   f1(x)----------\
                   \
                    \
                     \
                      \
                      |\
                      | \
                      |  \
                      x   \--------------- f2(x)
                  <--> <-->
              distance distance
*/
double blend4(double f1, double f2,double blendPoint, double transitionDistance, double x)
{
    double limitDistanceX = 4.95172; // tanhx = 0.9999
    double scale = 1.075*transitionDistance / limitDistanceX;
    double mult1 =0.5 + 0.5 * std::tanh((blendPoint - x)/scale);
    double mult2 =1.0-mult1;
    double result = f1 * mult1 + f2 * mult2;
    return result;
}

int main()
{
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend1(
                        [](double input){ return input * input; },
                        [](double input){ return input + 10.0;},
                        5.0,
                        x) << std::endl;
                        
    std::cout<<"---------------------------------"<<std::endl;
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend1(
                        [](double input){ return input ; },
                        [](double input){ return input * 2.0;},
                        5.0,
                        x) << std::endl;    
                        
                        
    std::cout<<"---------------------------------"<<std::endl;                        
    
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend2(
                        [](double input){ return input ; },
                        [](double input){ return input * 2.0;},
                        5.0,
                        2.0,
                        x) << std::endl;       
                        
    std::cout<<"---------------------------------"<<std::endl;                        
    
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend2(
                        [](double input){ return input ; },
                        [](double input){ return input * 2.0;},
                        5.0,
                        4.0,
                        x) << std::endl;        
                        
                        
    std::cout<<"---------------------------------"<<std::endl;                        
    
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend2(
                        [](double input){ return input ; },
                        [](double input){ return input * 2.0;},
                        5.0,
                        0.2,
                        x) << std::endl;          
                        
                        
    std::cout<<"---------------------------------"<<std::endl;                        
    
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend2(
                        [](double input){ return input ; },
                        [](double input){ return input * 2.0;},
                        5.0,
                        0.1,
                        x) << std::endl;                          
                        
    std::cout<<"---------------------------------"<<std::endl;                        
    
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend2(
                        [](double input){ return input ; },
                        [](double input){ return input * 2.0;},
                        5.0,
                        0.05,
                        x) << std::endl;            
                        
    std::cout<<"---------------------------------"<<std::endl;                        
    
    
    for(double x = 0;x<10; x+=0.1)
        std::cout << x<<":::" << blend3(
                        x,
                        x*2.0,
                        5.0,
                        0.05,
                        x) << std::endl; 
    
    std::cout<<"---------------------------------"<<std::endl;      
    
    // converge 99.99% at points x=400(to y=x) and x=600(to y=x*2)
    for(double x = 0;x<1000; x+=5)
        std::cout << x<<":::" << blend4(
                        x,
                        x*2.0,
                        500.0,
                        100.0,
                        x) << std::endl;   
 return 0;   
}
