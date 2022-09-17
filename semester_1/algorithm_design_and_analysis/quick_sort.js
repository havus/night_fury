function partition(array, start, end) {
  // VAR start: as a pivot
  let storedIndex = start + 1; // this is target index will be right place to store the pivot

  for (let i = start + 1; i <= end; i++) {
    if (array[i] < array[start]) {
      [array[storedIndex], array[i]] = [array[i], array[storedIndex]];
      storedIndex++;
    }
  }

  [array[start], array[storedIndex-1]] = [array[storedIndex-1], array[start]];

  return storedIndex-1;
}

function quickSort(array, start, end) {
  if (start < end) {
    const pivotPosition = partition(array, start, end);

    console.log(String(array));

    quickSort(array, start, pivotPosition - 1);
    quickSort(array, pivotPosition + 1, end);
  }
}

// const myArray = [1, 2, 10, 8, 20, 1, 3, 4, 2, 5, 10];
// const myArray = ['a', 'e', 'f', 'g', 'h', 'd', 'i', 'j'];
const myArray = ['nilai1', 'total1', 'total5', 'nilai2', 'qty2', 'qty4', 'ppn1', 'ppn2'];
quickSort(myArray, 0, myArray.length - 1);

console.log(myArray);
