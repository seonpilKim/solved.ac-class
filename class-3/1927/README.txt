[1927] 최소 힙 (https://www.acmicpc.net/problem/1927)

문제
----
널리 잘 알려진 자료구조 중 최소 힙이 있다. 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
----
첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 자연수는 231보다 작다.

출력
----
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

풀이
----
 - 힙(Heap)
   > 완전 이진 트리의 일종, 우선순위 큐를 위해 만들어진 자료구조
   > 여러 값중 최댓값 or 최솟값을 빠르게 찾아내기 위해 만들어진 자료구조
   > 중복된 값을 허용함 (이진탐색트리는 불허)
   > 종류 : MaxHeap, MinHeap
 - 시간복잡도
   > Insert : O(logN)
   > Delete : O(logN)
   > Heap Sort : O(NlogN)
 - Heap Sort 장점
    > Worst case에도 O(NlogN) 보장.
    > 최댓값 or 최솟값만 필요할 때 유용.
 - Heap Sort 단점
    > 데이터들의 상태에 따라 상대적으로 느린 정렬속도.
    > unstable sort