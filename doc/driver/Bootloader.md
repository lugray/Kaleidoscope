# kaleidoscope::driver::bootloader

We rarely have to work with or care about the bootloader from the user firmware,
but there's one scenario when we do: if we want to reset the device, and put it
into bootloader (programmable) mode, we need to do that in a bootloader-specific
manner.

This driver provides a number of helpers that implement the reset functionality
for various bootloaders.

## Using the driver

To use the driver, we need to include the header, from the hardware plugin of
our keyboard:

```c++
#include <kaleidoscope/driver/Bootloader.h>
```

Next, we create a (private) member variable, based on the bootloader of our choice:

```c++
kaleidoscope::driver::bootloader::avr::Caterina bootloader_;
```

And then we can implement a thin wrapper for the bootloader's `resetDevice()` method:

```c++
void resetDevice() {
  bootloader_.resetDevice();
}
```

## Methods provided by all bootloader drivers

### `.resetDevice()`

> Resets the device, and forces it into bootloader (programmable) mode.

## List of bootloaders

All of the drivers below live below the `kaleidoscope::driver::bootloader`
namespace.

## `avr::Caterina`:

Used by many (most?) arduino MCUs.

### `avr::HalfKay`

Used by the Teensy2.

### `avr::FLIP`

Used by the ATMega32U4 MCUs by default, unless another bootloader has been
flashed on them. For this driver to work, one also needs to define the
`KALEIDOSCOPE_BOOTLOADER_FLIP` macro before including the driver header, for
technical reasons.
