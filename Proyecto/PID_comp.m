clear
clc

Gp = tf([295.3, 6.047],[1, 0.9665,0.02342])

kp=0.00836
ki=0.0121
kd=0

kc=kp
Tao_I = kc/ki
Tao_D=kd/kc

Gc = kc + tf([kc],[Tao_I 0]) + tf([kc*Tao_D 0], [1])

G_CL = Gp*Gc/(1+Gp+Gc);
[y,t] = step(G_CL)