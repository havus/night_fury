/**
 * Theory understanding:
 * 
 *    if amount >= coin
 *     current_amount - current_coin
 * 
 *    coin 1:
 *     1 - 1 = 0 kita liat index 0 adalah 1, maka masukkan 1
 *     2 - 1 = 1 kita liat index 1 adalah 1, maka masukkan 1 di amount 2
 *    coin 2:
 *     if 0 >= 2 false; next
 *     if 1 >= 2 false; next
 *     if 2 >= 2 true; 2 - 2 = 0; kita liat index 0 adalah 1, maka kita tambahkan 1 di amount 2
 *     if 3 >= 2 true; 3 - 2 = 1; kita liat index 1 adalah 1, maka kita tambahkan 1 di amount 3
 *     if 4 >= 2 true; 4 - 2 = 2; kita liat index 2 adalah 2, maka kita tambahkan 2 di amount 4
 *     if 5 >= 2 true; 5 - 2 = 3; kita liat index 3 adalah 2, maka kita tambahkan 2 di amount 5
 *     if 6 >= 2 true; 6 - 2 = 4; kita liat index 4 adalah 3, maka kita tambahkan 3 di amount 6
 *     if 7 >= 2 true; 7 - 2 = 5; kita liat index 5 adalah 3, maka kita tambahkan 3 di amount 7
 *    coin 5:
 *     if 4 >= 5 false; next
 *     if 5 >= 5 true; 5 - 5 = 0; kita liat index 0 adalah 1, maka kita tambahkan 1 di amount 5
 *     if 6 >= 5 true; 6 - 5 = 1; kita liat index 1 adalah 1, maka kita tambahkan 1 di amount 6
 * 
 *     coin = [1,2,5]
 *         0  1  2  3  4  5  6  7  8  9  10  11  12  13
 *         ---------------------------------------------
 *     1   1  1  1  1  1  1  1  1  1  1   1   1   1   1
 *     2   1  1  2  2  3  3  4  4  5  5   6   6   7   7
 *     5   1  1  2  2  3  4  5  6  7  8  10  11  13  14
 *    ----------------------------------------------------------------------
 *    ---------------------------- OTHER CASE ------------------------------
 *    ----------------------------------------------------------------------
 *    coin = [3,5,12]
 * 
 *     if amount >= coin
 *       current_amount - current_coin
 *    coin 3:
 *     if 1 >= 3 false; next
 *     if 2 >= 3 false; next
 *     if 3 >= 3 true; 3 - 3 = 0; kita liat index 0 adalah 1, maka kita tambahkan 1 di amount 3
 *    coin 5:
 *     if 4 >= 5 false; next
 *     if 5 >= 5 true; 5 - 5 = 0; kita liat index 0 adalah 1, maka kita tambahkan 1 di amount 5
 *     if 6 >= 5 true; 6 - 5 = 1; kita liat index 1 adalah 0, maka kita tambahkan 0 di amount 6
 *    coin 12:
 *     if 11 >= 12 false; next
 *     if 12 >= 12 true; 12 - 12 = 0; kita liat index 0 adalah 1, maka kita tambahkan 1 di amount 12
 * 
 *         0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23
 *         -------------------------------------------------------------------------------------
 *     3   1  0  0  1  0  0  1  0  0  1   0   0   1   0   0   1   0   0   1   0   0   1   0   0
 *     5   1  0  0  1  0  1  1  0  1  1   1   1   1   1   1   1   1   1   2   1   1   2   1   2
 *     12  1  0  0  1  0  1  1  0  1  1   1   1   2   1   1   2   1   2   3   1   2   3   2   3
 * 
 *    change:
 *         0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23
 *        --------------------------------------------------------------------------------------
 *         1  0  0  1  0  1  1  0  1  1   1   1   2   1   1   2   1   2   3   1   2   3   2   3
 * 
 */


/**
 * This function will calculate total change of coin
 *  Created by: havus
 * 
 * @param {Integer} totalAmount 
 * @param {Array of Integer} coins 
 * @returns Integer
 */

function calculateMaxChange(totalAmount, coins) {
  let combinations = [];

  // fill array with initial value 0
  for (let i = 0; i <= totalAmount; i++) {
    combinations[i] = 0;
  }

  // initialize 1 to index 0;
  combinations[0] = 1;

  // core logic here
  for (let i = 0; i < coins.length; i++) {
    const currentCoin = coins[i];

    for (let j = 1; j < combinations.length; j++) {
      if (j >= currentCoin) {
        combinations[j] += combinations[j - currentCoin];
      }
    }
  }

  return combinations[totalAmount];
}



/**
 * This function will print result after calculate total change of coin
 * 
 * @param {Integer} totalAmount 
 * @param {Array of Integer} coins 
 */

function calculateAndPrint(totalAmount, coins) {
  const totalChanges = calculateMaxChange(totalAmount, coins);

  let fullText = `Column ${totalAmount} is ${totalChanges}, means coins change value of ${totalAmount}`;
  fullText += ` can be formed using coins ${coins.join(', ')} with maximum ${totalChanges} changes.`;

  console.log(
    `Column ${totalAmount} is ${totalChanges}, means coins change value of ${totalAmount} can be formed using coins ${coins.join(', ')} with maximum `,
    '\x1b[32m', `${totalChanges} changes.`,
    '\x1b[0m', '\n'
  );
}

// test case 1
const coins1 = [3,5,12];
calculateAndPrint(6, coins1); // 1
calculateAndPrint(23, coins1); // 3

// test case 2
const coins2 = [1,2,5];
calculateAndPrint(5, coins2); // 4
calculateAndPrint(12, coins2); // 13

// test case 3
console.log('TEST CASE: IDR');

const rupiah = [1, 5, 50, 200, 500, 1_000, 2_000, 5_000, 10_000, 20_000, 50_000, 100_000];
calculateAndPrint(123_456, rupiah); // 1283884539549348

console.log('TEST CASE: IDR -> USD');

// test case 4
// 100 cent is 1 dollar
//            1 dollar = 15_290.70 per 8 oct 2022
// pembulatan 1 dollar = 15_000.00
// 123.456 rupiah = 8,07 dollar = 807 cent
const usd = [1, 5, 10, 25, 50, 100, 200, 500, 1_000, 2_000, 5_000, 10_000]; // in cent
calculateAndPrint(807, usd); // 1067831
