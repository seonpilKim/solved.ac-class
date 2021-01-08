[1463] 1로 만들기

문제
----
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
----
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

출력
----
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

풀이
----
Top-down 재귀호출 알고리즘을 이용하였다.
각 3가지 연산에 대한 최솟값을 해당 인덱스의 dp배열에 저장하였다.

또한, 배열 선언을 할 때 정적배열의 크기가 너무 크다면 Stack 영역에 있어야 할 지역변수의 공간이 이웃한 다른 영역을 침범하는 Memory Access Exception이 발생 할 수 있다.
이를 위해 크기가 큰 정적배열을 전역변수로 선언하면, Data(bss) 영역으로 메모리 할당이 되어 Stack overflow를 방지 할 수 있게된다.
 - 참고 : https://perfectacle.github.io/2017/02/09/C-ref-004/

!주의
 - Visual Studio에서 제공되는 C/C++ 컴파일러의 Debug mode에 사용되는 정보가 많아지면서 기본 설정상태에서 Stack Frame의 size가 많이 커졌다.
 - 그래서 재귀호출을 너무 많이 사용하는 경우, Stack Overflow가 생각보다 빠르게 발생하게 된다.
 - 본인이 작성한 코드도 재귀호출이 5000회조차 돌아가지 못하고 Stack Overflow가 발생하였다.
 - 따라서 재귀호출을 정말 간단한 루틴에 사용하면 반복문을 사용하는 코드가 더 복잡해지고 조금만 계산을 많이 하는 루틴에 사용하면 Stack Overflow가 발생하는 문제를 겪기 때문에 조심해서 사용하는 것이 좋다.

- 참고 : http://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221423058988&categoryNo=0&parentCategoryNo=82&viewDate=%C2%A4tPage=1&postListTopCurrentPage=1&from=postView