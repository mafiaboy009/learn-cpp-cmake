#!/bin/bash

BASEDIR=`pwd`
BUILDDIR=../../build

rm javaNative.class
javah javaNative
mkdir -p ${BUILDDIR}
cd ${BUILDDIR}
make cppNative
cd ${BASEDIR}
javac javaNative.java
java -Djava.library.path=${BUILDDIR}/interface/java-native/. javaNative.java
