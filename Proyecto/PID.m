clear
clc

Gp = tf([295.3, 6.047],[1, 0.9665,0.02342])
Gc = pidtune(Gp, 'PID')
pidTuner(Gp,Gc)

