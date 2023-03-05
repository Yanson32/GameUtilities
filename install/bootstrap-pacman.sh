#!/bin/bash
#This script install all dependencies for this package on arch linux

#install a compiler
sudo pacman -S gcc --noconfirm

#install make
sudo pacman -S make --noconfirm

#install cmake
sudo pacman -S cmake --noconfirm

#install doxygen
sudo pacman -S doxygen --noconfirm

#install sfml 
sudo pacman -S sfml --noconfirm

sudo ldconfig

