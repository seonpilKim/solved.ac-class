[18870] 좌표 압축 (https://www.acmicpc.net/problem/18870)

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	2618	1514	1107	59.072%

문제
----
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
----
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
----
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

제한
----
1 ≤ N ≤ 1,000,000
-10^9 ≤ Xi ≤ 10^9

풀이
----
입력과 출력이 많은 경우 std::cout, std::cin 을 사용하는 것 보다는 printf, scanf를 사용하는 편이 거의 시간초과가 나지 않는다.

혹은 아래의 코드를 추가해서 cout, cin을 사용해도 된다.
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

data와 index를 객체화한 배열과, 좌표압축값을 저장한 배열을 생성하여 해결하였다.
pm배열을 data에 따라 오름차순으로 정렬하고, 차례대로 rm배열의 해당 index에 좌표압축하여 값을 저장하였다.