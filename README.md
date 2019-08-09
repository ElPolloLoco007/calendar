
https://www.youtube.com/watch?v=9zyVvZIn5tY

## Coloring code in terminal   
|         | foreground | background |
| ------- | ---------- | ---------- |
| black   | 30         | 40         |
| red     | 31         | 41         |
| green   | 32         | 42         |
| yellow  | 33         | 43         |
| blue    | 34         | 44         |
| magenta | 35         | 45         |
| cyan    | 36         | 46         |
| white   | 37         | 47         |

| command         | code | comment                                     |
| --------------- | ---- | ------------------------------------------- |
| reset           | 0    | (everything back to normal)                 |
| bold/bright     | 1    | (often a brighter shade of the same colour) |
| underline       | 4    |                                             |
| inverse         | 7    | (swap foreground and background colours)    |
| bold/bright off | 21   |                                             |
| underline off   | 24   |                                             |
| inverse off     | 27   |                                             |

#### Example 
```
 string xx = "7";
  cout << "\033[31m" << xx << "\033[0m\n";
```
