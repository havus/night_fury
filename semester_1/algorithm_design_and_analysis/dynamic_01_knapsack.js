
/**
 * 
 * Author:                  havus
 * YouTube ref:             https://youtu.be/nLmhmB6NzcM
 * Spreadsheet Simulation:  https://docs.google.com/spreadsheets/d/1Da4dV80nDq2IhPyhOuuRnXPy5HSVTKZallBSsUjkSE0/edit?usp=sharing
 * 
 * thank me later :)
 * 
 */

function spacePad(num, places) {
  // ref: https://stackoverflow.com/questions/2998784/how-to-output-numbers-with-leading-zeros-in-javascript
  return String(num).padStart(places, ' ');
}

function initBoard(row, col) {
  const result = [];

  for (let i = 0; i < row; i++) {
    const column = [];

    for (let j = 0; j <= col; j++) {
      column.push(0);
    }

    result.push(column);
  }

  return result;
}

function printBoard(arr, items) {
  // define max digit length for better printer
  let maxDigit = 1;

  for (let i = 0; i < arr.length; i++) {
    const maxDigitLengthInRow = Math.max(...arr[i]).toString().length;

    if (maxDigitLengthInRow > maxDigit) {
      maxDigit = maxDigitLengthInRow;
    }
  }

  // Technique can be used to deep copy literal values (boolean, number, string) and literal structures (array, object)
  //  ref: https://stackoverflow.com/questions/7486085/copy-array-by-value
  //  failed still have reference in second dimesion when we try [...arr] should be [[...arr[0]], [...arr[1]]] etc.
  const boardWithHeader = JSON.parse(JSON.stringify(arr));

  // https://stackoverflow.com/questions/3746725/how-to-create-an-array-containing-1-n
  boardWithHeader.unshift(Array.from(Array(arr[0].length).keys()));

  for (let i = 0; i < boardWithHeader.length; i++) {
    let itemName = i == 0 ? '-' : items[i-1].name;

    boardWithHeader[i].unshift(itemName);
  }

  for (let i = 0; i < boardWithHeader.length; i++) {
    // [...Array(10).keys()]
    //=> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    const row = boardWithHeader[i].map(el => spacePad(el, maxDigit)).join(' | ');

    if (i == 0) {
      console.log([...Array(row.length).keys()].fill('-').join(''));
    }

    console.log(row);
    console.log([...Array(row.length).keys()].fill('-').join(''));
  }
}

/**
 * 
 * @param {Array[Object]} arrayOfObject
 * @param {Number} n
 * @returns {Array 2 dimensions} board
 */
function solve(arrayOfObject, n) {
  const board = initBoard(arrayOfObject.length, n);

  for (let i = 0; i < board.length; i++) {
    for (let j = 1; j < board[i].length; j++) {
      /**
       * Formula:
       *  #note: B is board
       * 
       *  B{i,w} = max { B[ i-1, w ] | B[ i-1, w - w[i] ] + p[i] }
       * 
       *  i = 1; j = 7
       *  B{i,w} = max { B[ 1-1, 7 ] | B[ 1-1, 7 - 7 ] + 45 }
       */

      const currentPayload = arrayOfObject[i];

      let val1 = board[i-1] ? board[i-1][j] : 0;
      let val2 = (board[i-1] ? board[i-1][j - currentPayload.weight] : 0) + currentPayload.profit;

      if (j - currentPayload.weight < 0) {
        val2 = 0;
      }

      board[i][j] = Math.max(val1, val2);
    }
  }

  return board;
}

function collectItems(board, items, itemName, weight) {
  // coordinate x = weight
  // coordinate y = itemName

  const x = weight;
  const y = items.map(object => object.name).indexOf(itemName);
  const collectedItems = [];

  let maxProfit = board[y][x];
  // 255 - 75 = 180
  // 180 - 35 = 145
  // E pass
  // 145 - 40 = 105

  for (let i = board.length - 1; i >= 0; i--) {
    const indexSelected = board[i].lastIndexOf(maxProfit);

    if (i - 1 >= 0) {
      if (board[i][indexSelected] > board[i-1][indexSelected]) {
        collectedItems.push({...items[i]});
        maxProfit -= items[i].profit;
      }

      continue;
    }

    // focus in index 0
    if (maxProfit - items[i].profit >= 0) {
      collectedItems.push({...items[i]});
      maxProfit -= items[i].profit;
    }
  }

  return collectedItems;
}

/* TEST CASE: Check for above function */
let n = 29;
let payload = [
  { name: 'A', profit: 45, weight: 7 },
  { name: 'B', profit: 35, weight: 5 },
  { name: 'C', profit: 25, weight: 2 },
  { name: 'D', profit: 40, weight: 5 },
  { name: 'E', profit: 55, weight: 10 },
  { name: 'F', profit: 35, weight: 3 },
  { name: 'G', profit: 75, weight: 6 },
];

const resultBoard = solve(payload, n);
printBoard(resultBoard, payload);

console.log(collectItems(resultBoard, payload, 'G', 29).map(el => el.name).sort());
