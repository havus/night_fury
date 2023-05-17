/**
 * 
 * note from author:
 * - Emphasize SOLID principle
 * - Javascript docs comment ref: https://developer.wordpress.org/coding-standards/inline-documentation-standards/javascript/
 * 
 * made with <3 by havus
 */


/**
 * Function to categorize chars based on their frequncies
 *
 * @param   {String}  str
 * @return  {Object}  result is with keys are characters, and values are their frequncies
 */
function categorizeChar(str) {
  if (!str) {
    return {};
  }

  const arrStr = str.split('');
  const result = {};

  for (let i = 0; i < arrStr.length; i++) {
    const currentChar = arrStr[i];

    if (result[currentChar]) {
      result[currentChar] += 1
    } else {
      result[currentChar] = 1
    }
  }

  return result;
}

/**
 * Function to categorize chars based on their frequncies
 *
 * @param   {Object}  frequencies is an object categories of char by their frequencies
 * @return  {Object}  result is with keys are characters, and values are their frequncies
 */
function sortByFrequencies(frequencies) {
  const result = {};
  let sortable = [];

  for (const key in frequencies) {
    sortable.push([key, frequencies[key]]);
  }

  // sortable = [['a', 1], ['b', 2]];
  sortable.sort((a, b) => a[1] - b[1]);

  for (let i = 0; i < sortable.length; i++) {
    const currentChar = sortable[i][0];

    result[currentChar] = sortable[i][1];
  }

  return result;
}

function detectAllKeysWithAsterisk(arr) {
  for (let i = 0; i < arr.length; i++) {
    if (!arr[i].includes('*')) {
      return false;
    }
  }

  return true;
}

function buildHuffmanTree(huffmanObject) {
  const objectKeysHuffman = Object.keys(huffmanObject);

  if (detectAllKeysWithAsterisk(objectKeysHuffman)) {
    return objectKeysHuffman;
  }
}

function main(str) {
  const objectResult = categorizeChar(str);
  const sortedResult = sortByFrequencies(objectResult);
  const sortedResultKeys = Object.keys(sortedResult);

  const twoBeginingKeys = {
    [sortedResultKeys[0]]: sortedResult[sortedResultKeys[0]],
    [sortedResultKeys[1]]: sortedResult[sortedResultKeys[1]],
  };

  // {'he': 2}

  return twoBeginingKeys;
}

console.log(main('hello  world'));

