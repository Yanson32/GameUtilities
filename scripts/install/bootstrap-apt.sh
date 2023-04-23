#!/bin/sh
#This script installs dependencies using the apt package manager

#Update the system
sudo apt install update -y
sudo apt install upgrade -y
sudo apt autoremove -y
sudo apt autoclean -y


#Install dependencies
sudo apt install graphviz -y
sudo apt install libsfml-dev -y
sudo apt install cmake -y
sudo apt install build-essential -y
sudo apt install git -y
sudo apt install libx11-dev -y
sudo apt install curl -y
sudo apt install git -y

