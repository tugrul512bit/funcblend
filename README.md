# funcblend
Blend two functions smoothly around a point, with a smoothing distance for 99.99% convergence on both sides(functions).

```C++
// converge 99.99% at points x=400(to f1(x)=x function) and x=600(to f2(x)=x*2)
for(double x = 0;x<1000; x+=5)
{
    double f1 = x;
    double f2 = x*2.0;
    double transitionPoint = 500.0;
    double transitionDistance=100.0;
    std::cout << x<<":::" << 
    blend4(f1, f2, transitionPoint, transitionDistance, x) 
    << std::endl;
}
```

