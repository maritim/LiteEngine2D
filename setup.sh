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
		echo /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
	fi

	dep_apple = "sdl2 sdl2_image"

	length = $(echo $dep_apple | wc -w)

	for pkg in $dep_apple; do
	    if hash ${pkg} 2>/dev/null; then
		    echo "Installing ${pkg}..."
		    brew install --yes ${pkg}
		else
			echo "${pkg} already installed. Do nothing."
		fi
	done

fi

# Untested code
# Replace the above code with this for apple installation.

# if [[ `uname` == 'Darwin' ]]; then
# 	hash brew 2>/dev/null || { echo >&2 "Installing homebrew..."; /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"; }
# 	echo "Updating...";
# 	brew update;
# 	echo "Installing dependencies...";
# 	brew install sdl sdl_image;
# fi
