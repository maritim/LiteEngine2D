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
		echo "The installation was interupted because there is no know package manager."
	fi
}

if [[ `uname` == "Linux" ]]; then
	dep_ubuntu="libsdl2-image-dev libsdl2-dev"

	length=$(echo $dep_ubuntu | wc -w)

	for pkg in $dep_ubuntu; do
	    #if hash ${pkg} 2>/dev/null; then
		    echo "Installing ${pkg}..."
		    InstallDependency ${pkg}
		#else
		#	echo "${pkg} already installed. Do nothing."
		#fi
	done

elif [[ `uname` == "Darwin"* ]]; then

	if hash brew 2>/dev/null; then
		/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
	fi

	brew update

	dep_apple="sdl2 sdl2_image"

	length=$(echo $dep_apple | wc -w)

	for pkg in $dep_apple; do
	    if brew list -1 | grep -q "^${pkg}\$"; then
			echo "${pkg} already installed. Do nothing."
		else
			echo "Installing ${pkg}..."
			brew install --yes ${pkg}
		fi
	done

fi
