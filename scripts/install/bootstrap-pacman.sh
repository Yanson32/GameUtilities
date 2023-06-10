#!/bin/sh
#This script installes all dependencies using the pacman package manager 

#Update the system
sudo pacman -Syu --noconfirm

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

