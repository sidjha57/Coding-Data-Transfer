E1 = input ('Source # 1 Voltage Mag. = ');
a1 = input ('Source # 1 Phase Angle = ');
E2 = input('Source # 2 Voltage Mag. = '); 
a2 = input('Source # 2 Phase Angle = ');
R = input('Line Resistance = '); 
X = input('Line Reactance = ');
Z = R +j*X;   % Line impedance
a1= (-40:10:30)';  
a1r = a1*pi/180;  % Convert degree to radian
k = length(a1);
a2 = ones(k, 1)*a2;  % Create col. array of same length for a2
a2r = a2*pi/180; % Convert degree to radian
V1 = E1*cos (a1r)+j*E1*sin(a1r);
V2 = E2*cos (a2r)+j*E2*sin(a2r);
I12 = (V1-V2)./Z; I21=-I12;
S1 = V1.*conj(I12);
P1= real(S1); Q1= imag(S1);
S2 = V2.*conj(I21); 
P2= real(S2); Q2 = imag(S2); 
SL = S1+S2; 
PL = real(SL); QL = imag(SL);
A=a1-a2;
Result1 = [A, P1, P2, PL];
disp(' A   P-1   P-2   P-L')
disp(Result1)
plot (A, P1, A, P2, A,PL)
xlabel('Angle difference a1-a2')
ylabel(' P, Watts ');