E1 = input ('Source # 1 VoltAge MAg. = ');
A1 = input ('Source # 1 PhAse Angle = ');
E2 = input('Source # 2 VoltAge MAg. = '); 
A2 = input('Source # 2 PhAse Angle = ');
R = input('Line ResistAnce = '); 
X = input('Line ReActAnce = ');

Z = R +j*X;   % Line impedance

A1= (-40:10:30)';  
A1r = A1*pi/180;  
k = length(A1);

A2 = ones(k, 1)*A2;  % creating ones Array
A2r = A2*pi/180; 

V1 = E1*cos (A1r)+j*E1*sin(A1r);
V2 = E2*cos (A2r)+j*E2*sin(A2r);

I12 = (V1-V2)./Z; I21=-I12;

S1 = V1.*conj(I12);

P1= real(S1); Q1= imag(S1);

S2 = V2.*conj(I21); 

P2= real(S2); Q2 = imag(S2); 

SL = S1+S2; 
PL = real(SL); QL = imag(SL);

A=A1-A2;

Result1 = [A, P1, P2, PL];

disp(' A   P-1   P-2   P-L')
disp(Result1)

plot (A, P1, A, P2, A,PL)

xlabel('Angle difference A1-A2')
ylabel(' P, WAtts ');