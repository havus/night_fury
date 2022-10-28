"use strict"

class Sudoku {
  constructor(board_string) {
    this.str = board_string;
    this.arrMulti = this.generateArrMultiDimension();
  }

  sleep(milliseconds) {
    var start = new Date().getTime();
    for (var i = 0; i < 1e7; i++) {
      if ((new Date().getTime() - start) > milliseconds) {
        break;
      }
    }
  }

  // Returns a string representing the current state of the board
  board(arr) {
    let result = '+-----------------------------------+\n';
    
    for (let i = 0; i < arr.length; i++) {
      result += '| ';

      for (let j = 0; j < arr[i].length; j++) {
        if (arr[i][j] === 0) {
          result += ' ' + ' | ';
        } else {
          result += arr[i][j] + ' | ';
        }
      }
      
      if (i !== arr.length - 1) {
        result += '\n|---|---|---|---|---|---|---|---|---|\n';
      } 
    }
    result += '\n+-----------------------------------+\n';

    return result;
  }

  checkHorizontal(x, arr, num) {
    for (let i = 0; i < arr[x].length; i++) {
      if (arr[x][i] === num) {
        return false;
      }
    }

    return true;
  }

  checkVertical(y, arr, num) {
    for (let i = 0; i < arr.length; i++) {
      if (arr[i][y] === num) {
        return false;
      }
    }

    return true;
  }

  checkBox(x, y, arr, num) {
    let modX = x % 3;
    let modY = y % 3;
    for (let i = x - modX; i < (x - modX) + 3; i++) {
      for (let j = y - modY; j < (y - modY) + 3; j++) {
        if (arr[i][j] === num) {
          return false;
        }
      }
    }

    return true;
  }

  fullCheck(x, y, arr, num) {
    if (!this.checkHorizontal(x, arr, num) || !this.checkVertical(y, arr, num) || !this.checkBox(x, y, arr, num)) {
      return false;
    }

    return true;
  }

  calculateNull(arr) {
    let result = [];
    for (let i = 0; i < arr.length; i++) {
      for (let j = 0; j < arr[i].length; j++) {
        if (arr[i][j] === 0) {
          let temp = String(i) + String(j);
          result.push(temp);
          // console.log(temp);
        }
      }
    }

    return result;
  }

  solve() {
    let arrNull = this.calculateNull(this.arrMulti);
    let next = true;

    for (let i = 0; i < arrNull.length; i++) {
      let ketemu  = false;
      let coor    = this.arrMulti[arrNull[i][0]][arrNull[i][1]];

      let x = Number(arrNull[i][0]);
      let y = Number(arrNull[i][1]);

      if (next) {
        for (let j = coor + 1; j < 10; j++) {
          if (this.fullCheck(arrNull[i][0], arrNull[i][1], this.arrMulti, j)) {
            this.arrMulti[arrNull[i][0]][arrNull[i][1]] = j;
            ketemu  = true;
            next    = true;
            break;
          }
        }

        if (!ketemu) {
          if (i === 0) {
            return 'Tidak dapat di selesaikan';
          }
          this.arrMulti[arrNull[i][0]][arrNull[i][1]] = 0;

          next = false;
          i -= 2;this.arrMulti
        }
      } else {
        for (let j = coor + 1; j < 10; j++) {
          if (this.fullCheck(arrNull[i][0], arrNull[i][1], this.arrMulti, j)) {
            this.arrMulti[arrNull[i][0]][arrNull[i][1]] = j;
            ketemu = true;
            next = true;
            break;
          }
        }

        if (!ketemu) {
          if (i === 0) return 'Tidak dapat di selesaikan';

          this.arrMulti[x][y] = 0;
          next = false;
          i -= 2;
        }
      }
      console.log(this.board(this.arrMulti));
      this.sleep(10);
      console.clear();
    }
    return this.board(this.arrMulti);
  }

  generateArrMultiDimension() {
    let boardSudoku = [];

    for (let i = 0; i < this.str.length; i += 9) {
      let arr = [];
      for (let j = i; j < i+9; j++) {
        arr.push(Number(this.str[j]));
      }
      boardSudoku.push(arr);
    }

    return boardSudoku;
  }
}

const board_string = `530070000600195000098000060800060003400803001700020006060000280000419005000080079`;

let game = new Sudoku(board_string);
console.log(game.solve());


// let boardTest = [
//   [5, 3, 0, 0, 7, 0, 0, 0, 0],
//   [6, 0, 0, 1, 9, 5, 0, 0, 0],
//   [0, 9, 8, 0, 0, 0, 0, 6, 0],
//   [8, 0, 0, 0, 6, 0, 0, 0, 3],
//   [4, 0, 0, 8, 0, 3, 0, 0, 1],
//   [7, 0, 0, 0, 2, 0, 0, 0, 6],
//   [0, 6, 0, 0, 0, 0, 2, 8, 0],
//   [0, 0, 0, 4, 1, 9, 0, 0, 5],
//   [0, 0, 0, 0, 8, 0, 0, 7, 9]
// ]