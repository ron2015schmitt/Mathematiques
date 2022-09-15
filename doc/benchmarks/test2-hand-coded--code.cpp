for (size_t k = 0; k < N; k++) {
  x[k] = double(k) / double(N - 1);
}
for (size_t k = 0; k < N*N; k++) {
  A[k] = sin(double(k)*pi/double(N*N));
}
size_t step = 0;
for (size_t r = 0; r < N; r++) {
  y[r] = 0;
  for (size_t c = 0; c < N; c++) {
    y[r] += A[step++] * x[c];
  }
}
