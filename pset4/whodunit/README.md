# Questions

## What's `stdint.h`?

Sets the bit size of integers with definitions such as int32_t.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are predifined variable sizes. All systems will read them the same.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 byte, DWORD = 4 bytes, LONG = 4 bytes, WORD = 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

As far as I can tell it appears to be: 0x4D42 (but I could be wrong).

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the entire bitmap file including bi.biSizeImage & bf.bfOffBits.
biSize is the size of the image alone.

## What does it mean if `biHeight` is negative?

It means that the bitmap is a top-down device-independent bitmap.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If 'inptr' does not exist due to a problem such as insufficient memory.

## Why is the third argument to `fread` always `1` in our code?

It is reading one bit at a time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

It assigns 3.
3 pixels * 3 bytes = 9 + 3 bytes of padding = 12.
The scanline must be a multiple of 4.

## What does `fseek` do?

Controls the cursor position.

## What is `SEEK_CUR`?

`SEEK_CUR` is an integer constant which specifies that the offset is relative to the current file position.

## Whodunit?

It was Professor Plum with the candlestick in the Library.
