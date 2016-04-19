#!/bin/bash

function InstallDependency
{
	if [ -f /etc/debian_version ]; then
		sudo apt-get install --yes $1
	elif [ -f /etc/arch-release ]; then
		sudo pacman -S $1
	elif [ -f /etc/fedora-ralease ]; then
		sudo yum install $1
	else
		echo "The installation was interupted because there is no known package manager."
	fi
}

if [[ `uname` == "Linux" ]]; then
	dep_ubuntu="libsdl2-image-dev libsdl2-dev"

	for pkg in $dep_ubuntu; do
		if dpkg -l "$pkg" &> /dev/null; then
			echo "Package '$pkg' already installed. Do nothing."
		else
			echo "Package '$pkg' is not installed. Installing..."
			InstallDependency $pkg
		fi
	done

elif [[ `uname` == "Darwin"* ]]; then

	if hash brew 2>/dev/null; then
		echo "Package brew is not installed. Installing..."
		/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
	fi

	echo "Package brew is updating..."
	brew update

	dep_apple="sdl2 sdl2_image"

	for pkg in $dep_apple; do
	    if brew list -1 | grep -q "^${pkg}\$"; then
			echo "Package '$pkg' already installed. Do nothing."
		else
			echo "Package '$pkg' is not installed. Installing..."
			brew install --yes ${pkg}
		fi
	done

fi
