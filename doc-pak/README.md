# Calendar for terminal

This project is to show a calendar in the terminal, every time you start your terminal with the CRUD functionality.

old version: https://www.youtube.com/watch?v=9zyVvZIn5tY

## How to

To add a event directly go to the executable file in the bin folder and type

```
./calendar general 14-09-2022 14:00 1 message
```

if:

- Type is not written General will be set.
- Date is not typed, today will be the date.
- Time it not written, no time will be displayed.
- Priority is not written, 0 will be written.

### To make it automatic in the terminal in Ubuntu

Copy the executable file into fx /usr/shared/local

example:

```
sudo cp -f <YourPath>>/calendar/bin/calendar /usr/local/bin

```

Then add the location into your bashrc file:

```
sudo echo "/usr/local/bin/calendar" >>~/.bashrc
```

also add this function to your bash file:

```
function calendar()
{
   '/usr/local/bin/calendar' $@
}
```

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
