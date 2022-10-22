// source: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

function minCoins(coins, m, v) {  
  // table[i] will be storing
  // the minimum number of coins
  // required for i value. So
  // table[V] will have result

  let table = new Array(V+1);

  // Initialize first table value as zero
  table[0] = 0;

  // Initialize all table values as Infinite except for the first one
  for (let i = 1; i <= V; i++) {
    table[i] = Number.MAX_VALUE;
  }

  // Compute minimum coins required for all
  // values from 1 to V
  for (let i = 1; i <= V; i++) {
    // Go through all coins smaller than i
    for (let j = 0; j < m; j++) {
      if (coins[j] <= i) {
        let sub_res = table[i - coins[j]];
        if (sub_res != Number.MAX_VALUE && sub_res + 1 < table[i]) {
          table[i] = sub_res + 1;  
        }
      }   
    }
  }

  if (table[V] == Number.MAX_VALUE) {
    return -1;
  }

  return table[V];
}

// let coins = [ 9, 6, 5, 1 ];
// let V = 11;

let coins = [1, 5, 10, 25, 50, 100];
let V     = 146;
let m     = coins.length;

console.log("Minimum coins required is " + minCoins(coins, m, V) );

console.log('\n------------------------------------------');
const V2 = 269;
console.log("Minimum coins required is " + minCoins(coins, m, V2) );
