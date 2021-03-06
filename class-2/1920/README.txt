[1920] 수 찾기

문제
----
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
----
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
----
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

제한
----
시간 제한 : 2초

풀이
----
대량의 자료를 보관하고 검색을 빠르게 하기위해 연관 컨테이너를 사용하였다.
연관 컨테이너로는 Map, Hashmap 등이 있는데, 이 중에서 Map을 사용하였다.

Map은 Red Black Tree 알고리즘을 이용하여 정렬된 상태로 <key, value>를 관리한다.
HashMap은 Hash Table과 Hash Function을 이용하여 정렬하지 않은 상태로 <key, value>를 관리한다.

- Time complexity(Search)
 1. Map : Worst case - O(n), Best case - O(logn)
 2. HashMap : Worst case - O(n), Best case - O(1) 

추가로, HashMap은 검색 속도가 map에 비해 빠른 편이지만, 저장한 자료가 적을 시에는 메모리 낭비와 검색 시 overhead가 발생한다.