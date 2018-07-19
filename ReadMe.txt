PRIMARY
=======================

    This file describes the installation and configuration for WDT-DIO Linux Driver.

    This project contains the following subdirectories:
    --------------------------------------------------------------------------------------
    include/     contains the header file
    resource/    icon 
    script/    linux script
    software/     IPC DIO software
	src/		source file



BUILD
=======================
	1.
	Change work directory to root(contains CMakeLists.txt)

	2.
	mkdir build && cd build

	3.
	cmake ..

	4.
	copy SysWatch.desktop to ~/.config/autostart

