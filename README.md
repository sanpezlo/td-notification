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
#include <td-notification>
```

## Usage

```pawn
ShowTDNotification(playerid, const reason[]);
```

## Testing

To test, simply run the package:

```bash
sampctl package run
```

## Credits

* [ThePez](https://github.com/ThePez) - Creator of the include
* [Kristo](https://github.com/kristoisberg) - Creator of the [samp-td-string-width](https://github.com/kristoisberg/samp-td-string-width) include, it helped me to calculate the width of the TextDraw
* [Y_less](https://github.com/y-less) - Creator of the [YSI](https://github.com/pawn-lang/YSI-Includes) include
* [NaS](https://github.com/Naseband) - fixed the function UpdateTDNotifications and LinesTDNotification