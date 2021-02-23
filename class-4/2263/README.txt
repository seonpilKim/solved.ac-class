[2263] 트리의 순회 (https://www.acmicpc.net/problem/2263)

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
5 초		128 MB		9611	3701	2517		36.906%

문제
----
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

입력
----
첫째 줄에 n(1≤n≤100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

출력
----
첫째 줄에 프리오더를 출력한다.

풀이
----
먼저, 각 순회의 성질을 파악해야 한다.

 - Preorder traversal : root -> left subtree -> right subtree
 - Inorder traversal : left subtree -> root -> right subtree
 - Postorder traversal : left subtree -> right subtree -> root

후위순회의 끝에는 항상 root가 위치하며, 중위순회에서 root의 양 옆에는 각각 subtree가 존재하고,
전위순회의 첫 부분에는 항상 root가 위치한다.

현재 subtree의 root를 출력하고, 왼쪽과 오른쪽 subtree를 재귀호출하는 방식으로 전위순회를 구현하였다.

재귀호출 시, 중위순회와 후위순회에 대해 각각의 subtree 범위를 구해서 인자로 전달하는 것이 중요하다.
 - 중위순회의 경우, root의 양 옆이 subtree이므로, 현재 subtree의 root index만 찾으면 각각 subtree의 범위를 지정해줄 수 있다.
 - 후위순회의 경우, left subtree에 대해서는 left subtree의 크기만큼 범위를 지정해주고, right subtree에 대해서는 left subtree의 크기를 뺀 나머지 범위를 지정해주면 된다.




