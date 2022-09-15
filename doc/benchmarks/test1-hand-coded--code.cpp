for (size_t k = 0; k < N; k++) {
  x[k] = double(k) / double(N - 1);
}
for (size_t k = 0; k < N; k++) {
  f[k] = 1 + 10 * x[k] + exp(i * (2 * pi + pi * sin(2 * pi * x[k] + pi / 6)));
}
