function merge(arr, lowParam, midParam, highParam) {
  let highIndex = lowParam; // init with low index first, will be increment later
  let lowIndex  = lowParam;
  let midIndex  = midParam +1;
  let tempArray = [];

  console.log('arr', arr.toString());
  // console.log(`${lowParam} - ${highParam}: ${arr.slice(lowParam, highParam + 1)}`);

  while ((highIndex <= midParam) && (midIndex <= highParam)) {
    if (arr[highIndex] <= arr[midIndex]) {
      tempArray[lowIndex] = arr[highIndex];
      highIndex++;
    } else {
      tempArray[lowIndex] = arr[midIndex];
      midIndex++;
    }
    lowIndex++;
  }

  if (highIndex > midParam) {
    for (let k = midIndex; k <= highParam; k++) {
      tempArray[lowIndex] = arr[k];
      lowIndex++;
    }
  } else {
    for (let k = highIndex; k <= midParam; k++) {
      tempArray[lowIndex] = arr[k];
      lowIndex++;
    }
  }
  // debugger
  // node inspect ./dir/to-path/file.js
  // debug> sb(32)
  // debug> repl
  // > tempArray
  // ctrl + c
  // .exit

  // console.log(`tempArray: ${tempArray}, ${lowParam} - ${highParam}`);
  for (let k = lowParam; k <= highParam; k++) {
    arr[k] = tempArray[k];
  }
  // console.log('arr', arr.toString());
}

function mergeSort(arr, low, high) {
  if (low < high) {
    const mid = Math.floor((low + high) / 2);

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
  }
}

const myArray = [399, 283, 1281, 1382, 2335, 8343, 4903, 3459];
mergeSort(myArray, 0, myArray.length - 1);

console.log(myArray);
