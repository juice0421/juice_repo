//이전에는 모든 쌍을 살펴보면서 합이 100이 되는 쌍의 존재 여부를 확인했지만 이번에는 수를 차례로 하나씩 읽으면서 <<이전에>> 등장한 수 중에서 지금 보고 있는 수와 더해 100이 되는 수를 찾는다. 여기서 핵심 포인트는 각 수의 등장 여부를 체크하는 배열을 만드는 것이다. 이 배열에서 해당 인덱스의 수가 이전에 등장한 적인 있으면 값이 0, 있으면 1일 것이다.
int func2(int arr[], int N){
  int occur[101] = {};
  for(int i = 0; i < N; i++){
    if(occur[100-arr[i]] == 1)
      return 1;
    occur[arr[i]] = 1;
  }
  return 0;
}