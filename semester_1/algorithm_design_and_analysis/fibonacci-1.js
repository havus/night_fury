let counter = 0;

function fibo(n) {
  counter++;
  if (n == 0 || n == 1) {
    return n;
  }
  return fibo(n-1) + fibo(n-2);
}
//  n = 3
//  function fibo(n) {
//    if (n == 0 || n == 1) {
//      return n;
//    }
//    return 1 + 1
//    return (function fibo(2) {
//      if (2 == 0 || 2 == 1) {
//        return 2;
//      }
//      return 1 + 0
//      return (function fibo(1) {
//        if (1 == 0 || 1 == 1) {
//          return 1;
//        }
//        return fibo(n-1) + fibo(n-2);
//      }) + (function fibo(0) {
//        if (0 == 0 || 0 == 1) {
//          return 0;
//        }
//        return fibo(n-1) + fibo(n-2);
//      });
//    }) + (function fibo(1) {
//      if (1 == 0 || 1 == 1) {
//        return 1;
//      }
//      return fibo(n-1) + fibo(n-2);
//    });
//  }

for (let i = 0; i < 10; i++) {
  console.log(fibo(i));
}
console.log(`counter: ${counter}`);