# td-notification

[![sampctl](https://img.shields.io/badge/sampctl-td--notification-2f2f2f.svg?style=for-the-badge)](https://github.com/ThePez/td-notification)

This Include allows you to create TextDraw Notifications

![td-notification](https://i.ibb.co/pLH38H0/sa-mp-928.png)

## Installation

Simply install to your project:

```bash
sampctl package install ThePez/td-notification
```

Include in your code and begin using the library:

```pawn
#define TDN_MODE_DEFAULT
#include <td-notification>
```

## Usage

* `MAX_TDN`: set how many TextDraw will be shown in TextDraw's Notification
* `TDN_POS_X`: TextDraw notifications will be at the position set on the X axis
* `TDN_POS_Y`: TextDraw notifications will be at the position set on the Y axis
* `TDN_FONT`: TextDraw Notification will have the set font
* `TDN_LETTER_SIZE_X`: TextDraw notifications will have the set font size on the X axis
* `TDN_LETTER_SIZE_Y`: TextDraw notifications will have the set font size on the Y axis
* `TDN_SIZE`: TextDraw notifications will have the set width size
* `TDN_COLOR`: TextDraw notifications will have the set font color
* `TDN_COLOR_BOX`: TextDraw notifications will have the set box color
* `TDN_PROPORTIONAL`: TextDraw notifications will have the set proportional
* `TDN_DISTANCE`: TextDraw notifications will have the set distance
* `MAX_TDN_TEXT`: TextDraw notifications will have a maximum the set text
* `TDN_MODE_DOWN`: TextDraw notifications will scroll down
* `TDN_MODE_UP`: TextDraw notifications will scroll up
* `TDN_TIME`: TextDraw notifications will hide at the set time

* `TDN_MODE_DEFAULT`: TextDraw notifications will use the default settings

Function

```pawn
ShowTDN(playerid, const reason[];
```

Shows a textdraw with the set text

Normal functioning: the TextDraw will be automatically hidden, with the time set in `TDN_TIME` (no need to use `HideTDN`)

*   Returns 1, if the textdraw is shown, perfectly
*   Returns -1, if the text drawing could not be displayed (there are as many TextDraws displayed as set in `MAX_TDN`)

```pawn
ShowTDN_Manual(playerid, const reason[];
```

Shows a textdraw with the set text

Manual functioning: the TextDraw will not automatically hide, you must use `HideTDN`

*   Returns 0 - (`MAX_TDN` - 1), if the textdraw is shown, perfectly, will return the id of the TextDraws (the id you will use in `HideTDN`)
*   Returns -1, if the text drawing could not be displayed (there are as many TextDraws displayed as set in `MAX_TDN`)

```pawn
HideTDN(playerid, TDN);
```

Hides the textdraw

You must pass the id that returned the function ShowTDN_Manual

*   Returns 1, if the textdraw was hidden, perfectly
*   Returns 0, if the id passed in the function was not found

## Testing

To test, simply run the package:

```bash
sampctl package run
```

## Credits

* [ThePez](https://github.com/ThePez) - Creator of the include
* [NaS](https://github.com/Naseband) - helped me gather information to make the include, also helped me somewhere in the code
* [Kristo](https://github.com/kristoisberg) - Creator of the [samp-td-string-width](https://github.com/kristoisberg/samp-td-string-width) include, it helped me to calculate the width of the TextDraw
* [Y_less](https://github.com/y-less) - Creator of the [YSI](https://github.com/pawn-lang/YSI-Includes) include