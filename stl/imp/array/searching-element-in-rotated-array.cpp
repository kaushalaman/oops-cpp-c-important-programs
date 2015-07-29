int FindSortedArrayRotation(int A[], int N) {
  int L = 0;
  int R = N - 1;
  
  while (A[L] > A[R]) {
    int M = L + (R - L) / 2;
    if (A[M] > A[R])
      L = M + 1;
    else
      R = M;
  }
  return L;
}