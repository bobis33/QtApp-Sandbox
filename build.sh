#!/bin/bash

function clean() {
    if [ -d "build" ]; then
        rm -rf build/*
        echo "build directory has been removed."
    else
        echo "build directory does not exist."
    fi
    if [ -d ".doxygen" ]; then
        rm -rf .doxygen/*
        echo ".doxygen directory has been removed."
    else
        echo ".doxygen directory does not exist."
    fi
    if [ -f "qtsandbox" ]; then
        rm qtsandbox
        echo "qtsandbox binary has been removed."
    else
        echo "qtsandbox binary does not exist."
    fi
}

function build() {
    debug=$1
    if [ ! -d "build" ]; then
        mkdir -p build
    fi
    if [ "$debug" == "true" ]; then
        cmake -S . -Bbuild -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DUSE_CLANG_TIDY=ON && cmake --build build
    else
        cmake -S . -Bbuild -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build build
    fi
}

if [ $# -eq 0 ]; then
    echo "Usage $0 build [debug] | clean | format"
    exit 1
fi

case $1 in
    build)
        if [ "$2" == "debug" ]; then
            build true
        else
            build false
        fi
        ;;
    clean)
        clean
        ;;
    format)
      cmake --build build --target clangformat
      ;;
    *)
        echo "Usage $0 build [debug] | clean"
        exit 1
        ;;
esac
