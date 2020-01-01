load PCPlusControl.hdl,
output-file PCPlusControl.out,
output-list time%S1.4.1 in%D1.6.1 reset%B2.1.2 j%B1.3.1 zr%B2.1.2 ng%B2.1.2 out%D1.6.1;

set in 0;
set reset 0;
set j %B000;
set zr 0;
set ng 0;
tick;
output;
tock;
output;

set in 1;
tick;
output;
tock;
output;

set in 2;
tick;
output;
tock;
output;

set in 3;
set reset 1;
tick;
output;
tock;
output;

set reset 0;
set in 0;
set zr 1;
tick;
output;
tock;
output;

set in 10;
set zr 1;
set j %B010;
tick;
output;
tock;
output;

set in 20;
set zr 0;
set j %B010;
tick;
output;
tock;
output;
