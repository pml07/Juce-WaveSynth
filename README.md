# WaveSynth

#### 1. 將sine wave改成square wave

![](https://i.imgur.com/1XiuUCQ.png)
* Think 1: 利用current angle θ  
    (1) 0+2πf < θ < π+2πf , 給value = 1  
    (2) π+2πf < θ < 2π+2πf , 給value = -1  
* Think 2: 利用sin(θ)  
    (1) 0+2πf < θ < π+2πf , 此時sin(θ) > 0 , 給value = 1  
    (2) π+2πf < θ < 2π+2πf , 此時sin(θ) < 0 , 給value = -1  

#### 2. 將sine wave改成triangle wave

![](https://i.imgur.com/ZO3QkVV.png)
* Think: 利用斜率  
  (1) 角度從0+2πf到π/2+2πf時， 斜率m = 2/π  
  (2) 角度從π/2+2πf到π+2πf時， 斜率m = -2/π  
  (3) 角度從π+2πf到3π/2+2πf時， 斜率m = -2/π  
  (4) 角度從3π/2+2πf到2π+2πf時， 斜率m = 2/π  

#### 3. 將sine wave改成sawtooth wave
![](https://i.imgur.com/bPovjrV.png)
* Think: 利用斜率m = 1/π   
