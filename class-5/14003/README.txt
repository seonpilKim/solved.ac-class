[14003] 가장 긴 증가하는 부분 수열 5 (https://www.acmicpc.net/problem/14003)

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
3 초		512 MB		7838	2875	1992		38.015%

문제
----
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 LIS = {10, 20, 30, 50} 이고, 길이는 4이다.

입력
----
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

출력
----
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.

풀이
----
이 문제는 조건을 정확하게 이해하는 것이 중요하다.
 - 수열 A의 순서는 바뀌어서는 안되며, 중간 중간에 원소를 제거함으로써 길이가 가장 긴 증가수열을 형성해야 함.

* LIS(Longest Increasing Subsequence) Algorithm
수열 A를 (value, increasing length) 형태로 sequence배열에 입력한다.
부분수열 S를 담을 int형 배열을 생성하고, sequence배열을 0~N까지 돌면서 각 value를 subseq배열에 Binary search(이분 탐색)하여 나온 index에 대입한다.
이 때,  sequence배열의 increasing length에 value를 저장한 subseq의 index를 대입함으로써 증가수열길이를 저장할 수 있다.
최종적으로 sequence배열 뒤쪽부터 순서대로 탐색하며 value를 stack에 담았다가 LIFO방식으로 LIS 원소들을 출력하였다.

 - Time Complexity : O(n*log n)

 
