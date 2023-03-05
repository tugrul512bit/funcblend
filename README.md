# funcblend
Blend two functions smoothly around a point, with a smoothing distance for 99.99% convergence on both sides(functions).

```C++
    // converge 99.99% at points x=400(to f1(x)=x function) and x=600(to f2(x)=x*2)
    // from 400 to 600: transition area (500-100, 500+100)
    for(double x = 0;x<1000; x+=5)
        std::cout << x<<":::" << blend4(
                        x,
                        x*2.0,
                        500.0,
                        100.0,
                        x) << std::endl;
```

