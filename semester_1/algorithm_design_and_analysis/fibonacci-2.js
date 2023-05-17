const allFibo = [];
let counter = 0;

function fibo(n) {
  counter++;

  if (n == 0 || n == 1) {
    return n;
  }
  if (allFibo[n]) {
    return allFibo[n];
  }

  allFibo[n] = fibo(n - 1) + fibo(n - 2);

  return allFibo[n];
}

for (let i = 0; i < 10; i++) {
  console.log(fibo(i));
}
console.log(`counter: ${counter}`);
