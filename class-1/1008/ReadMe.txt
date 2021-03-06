[1008] A/B

문제
----
두 정수 A와 B를 입력받은 다음, A/B를 출력하는 프로그램을 작성하시오.

입력
----
첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
----
첫째 줄에 A/B를 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10^(-9) 이하이면 정답이다.

풀이
----
컴퓨터에서 10진수를 2진수로 변환할 때, 구조적인 문제로 인해 오차가 발생할 수 있다.
실제로 수학적 계산이 많고 중요한 프로그램의 경우 반드시 이러한 오차를 신경써주어야 한다.
float, double의 상대오차는 약 10^(-7), 10^(-15)이다.
상대오차가 10^(-9) 이하에서 발생하는 경우는 double에 해당하므로 double을 사용해야하며,
C/C++의 경우 실수의 자릿수를 지정하지 않으면 std::cout은 (정수+소수점) 6자리까지만 출력하므로 std::cout.precision 메소드를 이용하여 반드시 자릿수를 지정해주어야 한다.
추가로 ios::fixed는 실수를 고정소수점 형태로 출력하라는 의미이며, 부동소수점 표기는 ios::scientific이다.