

% exampleCannon.m Script to run Simulink Model of Firing a Cannon
clear variables
m = 5; % mass of canon ball
D = -0.02; % Drag coeff
theta = 20; % Launch angle in degrees
y0 = 0; % Launch Height (m)
V0 = 100; % Initial velocity (m/s)
s = sim('cannon1','StopTime','25','MaxStep','0.01');
r = s.get('simout');
x = r(:,1);
y = r(:,2);
%% Logical to find where positive
L = find(y>=0);
plot(x(L),y(L))
xlabel('Distance (m)'); ylabel('Height (m)')
axis([0 max(x(L))*1.1 0 max(y)*1.1])
subtitle = sprintf(' The Ball is launched from %0.1f m at %0.1f degrees and %0.1f m/s',y0,theta,V0);
title({'Path  of Cannon Ball';subtitle})
txt = sprintf('Ball is  stopped at x=%0.1f m',x(length(L)));
text(max(x)/3,max(y)/5,txt)
