# WaveSynth

#### 1. 將sine wave改成square wave

<img width="600" height="350" src="https://i.imgur.com/1XiuUCQ.png"/>

* Think 1: 利用current angle θ  
    (1) 0+2πf < θ < π+2πf , 給value = 1  
    (2) π+2πf < θ < 2π+2πf , 給value = -1  
* Think 2: 利用sin(θ)  
    (1) 0+2πf < θ < π+2πf , 此時sin(θ) > 0 , 給value = 1  
    (2) π+2πf < θ < 2π+2πf , 此時sin(θ) < 0 , 給value = -1  

#### 2. 將sine wave改成triangle wave

<img width="600" height="350" src="https://user-images.githubusercontent.com/81510945/135837621-ed0ffa60-42a3-4bb4-8874-eb08d650b0ed.png"/>

* Think: 利用斜率  
  (1) 角度從0+2πf到π/2+2πf時， 斜率m = 2/π  
  (2) 角度從π/2+2πf到π+2πf時， 斜率m = -2/π  
  (3) 角度從π+2πf到3π/2+2πf時， 斜率m = -2/π  
  (4) 角度從3π/2+2πf到2π+2πf時， 斜率m = 2/π  

#### 3. 將sine wave改成sawtooth wave

<img width="600" height="350" src="https://i.imgur.com/bPovjrV.png"/>

* Think: 利用斜率m = 1/π   
