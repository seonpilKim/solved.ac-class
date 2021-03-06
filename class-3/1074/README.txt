[1074] Z

문제
----
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

만약, N > 1이 라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.


입력
----
첫째 줄에 정수 N, r, c가 주어진다.

출력
----
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
----
1 ≤ N ≤ 15
0 ≤ r, c < 2N
시간제한 : 0.5초

풀이
----
현재 재귀함수가 커버하는 정사각형 영역을 식별하기 위해 시작점(x, y)와 길이가 필요하다.

예를들어 8*8 정사각형의 탐색 순서를 따져보면,
8*8 정사각형의 Z -> 4*4 정사각형의 Z 4개 ->  2*2 정사각형의 Z 16개 -> 1*1 정사각형 64개 순서로 재귀호출이 필요하다.

또한, 시간 제한을 고려하여 불필요한 재귀 호출을 조금이라도 줄이기 위해 조치가 필요하다.
현재 재귀호출을 하고있는 정사각형의 범위 내에 입력한 (row, col)이 포함되어있지 않으면 그 영역은 재귀호출하지 않고 리턴하며, 해당 영역에 포함된 점의 개수를 결과값에 더해주었다.

추가로, exit(0)은 호출한 시점에서 전체 application을 즉시 종료시킨다.
그렇기에 재귀함수에서 원하는 값을 찾고, 출력한 이후에 프로그램을 곧바로 종료시키기 위해 return이 아닌, exit(0)을 사용하였다.
만약 exit(0)위치에서 return을 사용하였다면, 해당 재귀함수만 종료시키고, 현재 재귀함수를 호출한 재귀함수가 이어서 수행되어 결국 원하는 값을 찾은 이후에도 1*1 정사각형의 총 개수만큼 재귀함수를 호출하게된다.