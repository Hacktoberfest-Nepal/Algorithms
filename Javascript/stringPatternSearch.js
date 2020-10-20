/*
*************** String Pattern Search Algorithm *************

Given a text and a pattern, write a function  that shows how many times the patter occurs  in the text

stringPatternSearch('lollipop', 'lol') ========> 1
stringPatternSearch('lolol', 'lol') ========> 2
*/

function stringPatternSearch(text, pattern) {
  let count = 0;
  for (let i = 0; i < text.length; i++) {
    for (let j = 0; j < pattern.length; j++) {
      const patternChar = pattern[j];
      if (patternChar !== text[i + j]) {
        break;
      }
      if (j === pattern.length - 1) {
        count++;
      }
    }
  }
  return count;
}

// Time Complexity ========> O(n * m)
// Space complexity =======> O(1)
