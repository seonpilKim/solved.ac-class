[2407] 조합 (https://www.acmicpc.net/problem/2407)

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초		128 MB		13954	3911	3343		34.765%

문제
----
nCm을 출력한다.

입력
----
n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)

출력
----
nCm을 출력한다.

풀이
----
조합(Combination) : 서로 다른 n개의 원소 중에서 순서에 상관없이 r개를 선택하는 것

 - 성질
1. nCr = nCn-r
2. nCr = n-1Cr-1 + n-1Cr

2번 성질을 이용하여 조합함수를 "Recursive Call" 방식으로 구현하였으며, 연산속도 향상을 위해 계산한 값들을 "Memoization" 하였다.
또한, 결과값이 c++ 자료형의 최대크기인 8 byte으로도 표현할 수 없는 수준의 큰 값이 나올 수 있으므로  string 클래스를 이용하여 "BigInteger" 함수도 구현하였다.

p.s) Memoization을 하지 않으면, stack overflow 혹은 time limit exceed 위험이 존재한다.
