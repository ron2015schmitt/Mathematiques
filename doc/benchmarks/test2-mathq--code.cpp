x = linspace<double>(0, 1, N);
for (size_t k = 0; k < N*N; k++) {
  A[k] = sin(double(k)*pi/double(N*N));
}
y = A | x;
