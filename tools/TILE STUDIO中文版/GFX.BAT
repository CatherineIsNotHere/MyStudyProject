@echo off
if exist Untitled.dat del Untitled.dat
DAT -a -t BMP -c1 -bpp 16 -s1 Untitled.dat gfx\Tiles1.bmp
DAT -a -t BMP -c1 -bpp 16 -s1 Untitled.dat gfx\Tiles5.bmp
DAT -a -t BMP -c1 -bpp 16 -s1 Untitled.dat gfx\Tiles2.bmp
ren Untitled.dat Untitled.dat